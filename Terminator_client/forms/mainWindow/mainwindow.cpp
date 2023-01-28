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

void mainWindow::AddToTasks(QString text, bool status)
{
    taskForm *task = new taskForm();
    task->SetText(text);
    task->SetCheck(status);
    
    QListWidgetItem *item = new QListWidgetItem();
    item->setSizeHint(task->sizeHint());

    ui->listWidget_tasks->addItem(item);
    ui->listWidget_tasks->setItemWidget(item, task);

    QObject::connect(task, &taskForm::ButtonClickedTask, this, &mainWindow::DeleteTask);
}

void mainWindow::AddToList(QString text)
{
    listForm* list = new listForm();
    list->SetText(text);

    QListWidgetItem* item = new QListWidgetItem();
    item->setSizeHint(list->sizeHint());

    ui->listWidget_lists->addItem(item);
    ui->listWidget_lists->setItemWidget(item, list);

    QObject::connect(list, &listForm::ButtonClickedList, this, &mainWindow::DeleteList);
}

void mainWindow::ShowWindow(QString username, QString password)
{
    logedLogin = username;
    logedPass = password;

    mainWindow::show();
}

void mainWindow::on_pushButton_addTask_clicked()
{
    AddToTasks("testowy jeden", true);
}


void mainWindow::on_pushButton_addLists_clicked()
{
    AddToList("Do zrobienia");
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

