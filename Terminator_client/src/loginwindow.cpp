#include "loginwindow.h"
#include "network.h"
#include "ui_loginwindow.h"
#include <QMessageBox>

loginWindow::loginWindow(QWidget *parent) :
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

    networkAPI net;
    bool status = net.CheckLogin(username, password);

    if (!status)
    {
        QMessageBox::critical(this, QString::fromUtf8("B£AD LOGOWANIA"), tr("Zly login lub haslo"));
    }
    else
    {
        this->hide();
    }

}

