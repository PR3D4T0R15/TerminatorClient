#include "loginwindow.h"
#include "ui_loginwindow.h"
#include "network.h"
#include "newuser.h"
#include <QMessageBox>
#include <QApplication>
#include <qDebug>
#include <QJsonDocument>

loginWindow::loginWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::loginWindow)
{
    ui->setupUi(this);
}

loginWindow::~loginWindow()
{
    delete ui;
}

void loginWindow::on_pushButton_login_clicked()
{
    QString username = ui->lineEdit_login->text();
    QString password = ui->lineEdit_pass->text();

    if (username == "" && password == "")
    {
        QMessageBox::critical(this, "BĹÄ„D", "Puste pola hasĹ‚a i nazwy uĹĽytkownika");
        return;
    }

    networkAPI net;
    bool status = net.CheckLogin(username, password);

    if (!status)
    {
        QMessageBox::critical(this, "BĹÄ„D", "ZĹ‚y login lub hasĹ‚o");
        return;
    }
    else
    {
        emit LoginSucces(username, password);
        this->hide();
    }

}

void loginWindow::on_pushButton_new_clicked()
{
    newUser window;
    window.exec();
}
