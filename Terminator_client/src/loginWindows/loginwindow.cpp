#include "loginwindow.h"
#include "network.h"
#include "newUser/newuser.h"
#include "ui_loginwindow.h"
#include <QMessageBox>
#include <QApplication>
#include <qDebug>
#include <QJsonDocument>

loginWindow::loginWindow(QWidget* parent) :
    QMainWindow(parent),
    ui(new Ui::loginWindow)
{
    ui->setupUi(this);
    QPixmap pix(":/Terminator_client/src/img/logo.png");
    ui->label_img->setPixmap(pix);
    ui->label_img->setScaledContents(true);
    
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

void loginWindow::on_pushButton_nowy_clicked()
{
    newUser window;
    window.exec();
}

