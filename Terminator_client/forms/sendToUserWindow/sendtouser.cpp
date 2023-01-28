#include "sendtouser.h"
#include "ui_sendtouser.h"
#include "network.h"

sendToUser::sendToUser(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::sendToUser)
{
    ui->setupUi(this);
    ui->label_errorMessage->setText("");
}

sendToUser::~sendToUser()
{
    delete ui;
}

void sendToUser::SetData(QString user, QString pass)
{
    username = user;
    password = pass;
}

void sendToUser::on_buttonBox_accepted()
{
    QString listName = ui->lineEdit_list->text();
    QString destUser = ui->lineEdit_username->text();
    
    emit SendData(destUser, listName);
}


void sendToUser::on_buttonBox_rejected()
{
    this->destroy(true, false);
}

