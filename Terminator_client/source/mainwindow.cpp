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
#include <sendtouser.h>
#include <QMEssageBox>
#include <QTableWidget>

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

void mainWindow::ShowWindow(QString username, QString password)
{
    logedLogin = username;
    logedPass = password;

    mainWindow::show();
}