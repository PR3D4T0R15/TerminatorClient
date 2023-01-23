#include "dialogselectuser.h"
#include "ui_dialogselectuser.h"

dialogSelectUser::dialogSelectUser(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dialogSelectUser)
{
    ui->setupUi(this);
}

dialogSelectUser::~dialogSelectUser()
{
    delete ui;
}
