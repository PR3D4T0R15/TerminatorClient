#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QJsonDocument>
#include <QJsonObject>
#include "network.h"
#include <QLineEdit>
#include <QCheckBox>
#include <QPushButton>
#include <QObject>

mainWindow::mainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::mainWindow)
{
    ui->setupUi(this);

    ui->tableWidget_lists->horizontalHeader()->hide();
    ui->tableWidget_lists->setColumnWidth(0, 30);
    ui->tableWidget_lists->setColumnWidth(1, 14);
    ui->tableWidget_lists->horizontalHeader()->setStretchLastSection(true);
    ui->tableWidget_lists->setShowGrid(false);
    ui->tableWidget_lists->setStyleSheet("QTableView::item{border - bottom: 1px solid #d6d9dc;}");


    ui->tableWidget_tasks->horizontalHeader()->hide();
    ui->tableWidget_tasks->setColumnWidth(0, 30);
    ui->tableWidget_tasks->setColumnWidth(1, 14);
    ui->tableWidget_tasks->horizontalHeader()->setStretchLastSection(true);
    ui->tableWidget_lists->setShowGrid(false);
    ui->tableWidget_lists->setStyleSheet("QTableView::item{border - bottom: 1px solid #d6d9dc;}");

    QPixmap add(":/Terminator_client/src/img/add.png");
    QPixmap remove(":/Terminator_client/src/img/remove.png");
    QPixmap send(":/Terminator_client/src/img/send.png");

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

void mainWindow::AddToList(QString name, int status)
{
    int row = ui->tableWidget_lists->rowCount();
    ui->tableWidget_lists->setRowCount(row + 1);
    
    QTableWidgetItem* item[] = {
        new QTableWidgetItem(),
        new QTableWidgetItem(),
        new QTableWidgetItem(),
    };

    QPushButton* deleteIcoLists = new QPushButton;
    QPixmap remove(":/Terminator_client/src/img/remove.png");
    QIcon IcoRemove(remove);
    deleteIcoLists->setIcon(IcoRemove);
    deleteIcoLists->setIconSize(QSize(25, 25));
    ui->tableWidget_lists->setCellWidget(row, 0, deleteIcoLists);

    QObject::connect(deleteIcoLists, &QPushButton::clicked, this, &mainWindow::OnClickedLists);

    QCheckBox* completeBoxLists = new QCheckBox;
    ui->tableWidget_lists->setCellWidget(row, 1, completeBoxLists);

    QLineEdit* nameFieldLists = new QLineEdit;
    nameFieldLists->setFrame(false);
    ui->tableWidget_lists->setCellWidget(row, 2, nameFieldLists);

    nameFieldLists->setText(name);

    if (status == 1)
    {
        completeBoxLists->setChecked(true);
    }

}

void mainWindow::AddtoTasks(QString name)
{
    int row = ui->tableWidget_tasks->rowCount();
    ui->tableWidget_tasks->setRowCount(row + 1);

    QTableWidgetItem* item[] = {
        new QTableWidgetItem(),
        new QTableWidgetItem(),
    };

    QPushButton* deleteIcoTasks = new QPushButton;
    QPixmap remove(":/Terminator_client/src/img/remove.png");
    QIcon IcoRemove(remove);
    deleteIcoTasks->setIcon(IcoRemove);
    deleteIcoTasks->setIconSize(QSize(25, 25));
    ui->tableWidget_tasks->setCellWidget(row, 0, deleteIcoTasks);

    QObject::connect(deleteIcoTasks, &QPushButton::clicked, this, &mainWindow::OnClickedTasks);

    QLineEdit* nameFieldTasks = new QLineEdit;
    nameFieldTasks->setFrame(false);
    ui->tableWidget_tasks->setCellWidget(row, 2, nameFieldTasks);

    nameFieldTasks->setText(name);
}

void mainWindow::ShowWindow(QString username, QString password)
{
    logedLogin = username;
    logedPass = password;

    networkAPI net;
    listNames = net.GetData(username, password, "", "all");

    mainWindow::show();
}

void mainWindow::on_pushButton_addLists_clicked()
{
    AddToList("test", 1);
}


void mainWindow::on_pushButton_sendLists_clicked()
{

}


void mainWindow::on_pushButton_addTask_clicked()
{
    AddtoTasks("test");
}

void mainWindow::OnClickedLists()
{
    QWidget* w = qobject_cast<QWidget*>(sender()->parent());
    if (w) {
        int row = ui->tableWidget_lists->indexAt(w->pos()).row();
        ui->tableWidget_lists->removeRow(row);
        ui->tableWidget_lists->setCurrentCell(0, 0);
    }
}

void mainWindow::OnClickedTasks()
{
    QWidget* w = qobject_cast<QWidget*>(sender()->parent());
    if (w) {
        int row = ui->tableWidget_tasks->indexAt(w->pos()).row();
        ui->tableWidget_tasks->removeRow(row);
        ui->tableWidget_tasks->setCurrentCell(0, 0);
    }
}