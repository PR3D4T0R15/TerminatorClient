#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QJsonDocument>
#include <QJsonObject>
#include "network.h"

mainWindow::mainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::mainWindow)
{
    ui->setupUi(this);

    ui->tableWidget_lists->horizontalHeader()->hide();
    ui->tableWidget_lists->setColumnWidth(0, 50);
    ui->tableWidget_lists->horizontalHeader()->setStretchLastSection(true);


    ui->tableWidget_tasks->horizontalHeader()->hide();
    ui->tableWidget_tasks->setColumnWidth(0, 50);
    ui->tableWidget_tasks->setColumnWidth(0, 50);
    ui->tableWidget_tasks->horizontalHeader()->setStretchLastSection(true);

    QPixmap add(":/Terminator_client/src/img/add.png");
    QPixmap remove(": / Terminator_client / src / img / remove.png");
    QPixmap send(":/Terminator_client/src/img/send.png");

    QIcon IcoAdd(add);
    QIcon IcoRemove(remove);
    QIcon IcoSend(send);

    ui->pushButton_sendList->setIcon(IcoSend);
    ui->pushButton_sendList->setIconSize(QSize(20, 20));

    ui->pushButton_addLists->setIcon(IcoAdd);
    ui->pushButton_addLists->setIconSize(QSize(20, 20));

    ui->pushButton_addLists->setIcon(IcoAdd);
    ui->pushButton_addLists->setIconSize(QSize(20, 20));
}

mainWindow::~mainWindow()
{
    delete ui;
    
}

void mainWindow::ShowWindow(QString username, QString password)
{
    logedLogin = username;
    logedPass = password;

    networkAPI net;
    listNames = net.GetData(username, password, "", "all");

    mainWindow::show();
}