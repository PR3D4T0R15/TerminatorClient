#include "newuser.h"
#include "ui_newuser.h"

newUser::newUser(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::newUser)
{
    ui->setupUi(this);
}

newUser::~newUser()
{
    delete ui;
}
