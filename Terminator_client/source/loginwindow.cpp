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
        QMessageBox::critical(this, "BŁĄD", "Puste pola hasła i nazwy użytkownika");
        return;
    }

    networkAPI net;
    bool status = net.CheckLogin(username, password);

    if (!status)
    {
        QMessageBox::critical(this, "BŁĄD", "Zły login lub hasło");
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
