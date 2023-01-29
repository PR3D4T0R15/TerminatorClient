#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include "network.h"
#include <QLineEdit>
#include <QCheckBox>
#include <QPushButton>
#include <QObject>
#include "sendToUserWindow/sendtouser.h"
#include "taskForm/taskform.h"
#include "listForm/listform.h"
#include <QMEssageBox>
#include <QTableWidget>
#include <QDebug>

mainWindow::mainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::mainWindow)
{
    ui->setupUi(this);

    QPixmap add(":/Terminator_client/img/add.png");
    QPixmap remove(":/Terminator_client/img/remove.png");
    QPixmap send(":/Terminator_client/img/send.png");

    QIcon IcoAdd(add);
    QIcon IcoRemove(remove);
    QIcon IcoSend(send);

    ui->pushButton_sendLists->setIcon(IcoSend);
    ui->pushButton_sendLists->setIconSize(QSize(30, 45));

    ui->pushButton_addLists->setIcon(IcoAdd);
    ui->pushButton_addLists->setIconSize(QSize(25, 25));

    ui->pushButton_addTask->setIcon(IcoAdd);
    ui->pushButton_addTask->setIconSize(QSize(25, 25));
}

mainWindow::~mainWindow()
{
    delete ui;
    
}

void mainWindow::AddToTasks(QString text, bool status, bool byUser)
{
    taskForm *task = new taskForm();
    task->SetText(text);
    task->SetCheck(status);

    if (byUser == false)
    {
        task->DisableEdit();
    }
    
    QListWidgetItem *item = new QListWidgetItem();
    item->setSizeHint(task->sizeHint());

    ui->listWidget_tasks->addItem(item);
    ui->listWidget_tasks->setItemWidget(item, task);

    QObject::connect(task, &taskForm::ButtonClickedTask, this, &mainWindow::DeleteTask);
}

void mainWindow::AddToList(QString text, bool byUser)
{
    listForm* list = new listForm();
    list->SetText(text);

    if (byUser == false)
    {
        list->DisableEdit();
    }

    QListWidgetItem* item = new QListWidgetItem();
    item->setSizeHint(list->sizeHint());

    ui->listWidget_lists->addItem(item);
    ui->listWidget_lists->setItemWidget(item, list);

    QObject::connect(list, &listForm::ButtonClickedList, this, &mainWindow::DeleteList);
}

void mainWindow::LoadLists()
{
    networkAPI net;
    listNames = net.GetData(logedLogin, logedPass, "", "all");
}

void mainWindow::ShowLists()
{
    for (int i = 0; i < listNames.count(); i++)
    {
        QJsonObject list = listNames.at(i).toObject();
        QString name = list.value("name").toString();

        AddToList(name, false);
    }
}

void mainWindow::LoadTasks(QString listName)
{
    networkAPI net;
    currentList = net.GetData(logedLogin, logedPass, listName, "one");
}

void mainWindow::ShowTasks()
{
    ui->listWidget_tasks->clear();
    for (int i = 0; i < currentList.count(); i++)
    {
        QJsonObject list = currentList.at(i).toObject();
        QString name = list.value("nazwa").toString();
        QString status = list.value("status").toString();

        if (status == "TRUE")
        {
            AddToTasks(name, true, false);
        }
        else if (status == "FALSE")
        {
            AddToTasks(name, false, false);
        }
    }
}

void mainWindow::ShowWindow(QString username, QString password)
{
    logedLogin = username;
    logedPass = password;

    mainWindow::show();
    LoadLists();
    ShowLists();
}

void mainWindow::on_pushButton_addTask_clicked()
{
    AddToTasks("testowy jeden", true, true);
}

void mainWindow::on_pushButton_addLists_clicked()
{
    AddToList("Do zrobienia", true);
}

void mainWindow::DeleteList(QString text)
{
    int rows = ui->listWidget_lists->count();
    for (int i = 0; i < rows; i++)
    {
        QListWidgetItem* itemLists = ui->listWidget_lists->item(i);
        listForm* itemList = dynamic_cast<listForm*>(ui->listWidget_lists->itemWidget(itemLists));
        if (itemList->GetText() == text)
        {
            delete itemLists;
            break;
        }
    }
}

void mainWindow::DeleteTask(QString text)
{
    int rows = ui->listWidget_tasks->count();
    for (int i = 0; i < rows; i++)
    {
        QListWidgetItem *itemTasks = ui->listWidget_tasks->item(i);
        taskForm *itemTask = dynamic_cast<taskForm*>(ui->listWidget_tasks->itemWidget(itemTasks));
        if (itemTask->GetText() == text)
        {
            delete itemTasks;
            break;
        }
    }
}

void mainWindow::RecevieDataDestUSer(QString destUser, QString listName)
{
    if (destUser == "" || listName == "")
    {
        QMessageBox::critical(this, "BŁĄD", "Puste pola nazwy użytkownika i nazwy listy");
        return;
    }

    networkAPI net;
    bool status = net.CopyData(logedLogin, logedPass, listName, destUser);

    if (!status)
    {
        QMessageBox::critical(this, "BŁĄD", "Nie skopiowano listy. Wystąpił problem");
    }
}

void mainWindow::on_pushButton_sendLists_clicked()
{
    sendToUser dialog;
    QObject::connect(&dialog, &sendToUser::SendData, this, &mainWindow::RecevieDataDestUSer);
    dialog.setModal(true);
    dialog.SetData(logedLogin, logedPass);
    dialog.exec();
    

}

void mainWindow::on_listWidget_lists_itemActivated(QListWidgetItem* item)
{
    listForm* itemList = dynamic_cast<listForm*>(ui->listWidget_lists->itemWidget(item));
    QString name = itemList->GetText();

    LoadTasks(name);
    ShowTasks();
}
