#include "sendtouser.h"
#include "ui_sendtouser.h"

sendToUser::sendToUser(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::sendToUser)
{
    ui->setupUi(this);
}

sendToUser::~sendToUser()
{
    delete ui;
}
