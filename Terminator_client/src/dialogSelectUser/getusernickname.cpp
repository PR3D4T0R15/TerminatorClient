#include "getusernickname.h"
#include "ui_getusernickname.h"

getUserNickname::getUserNickname(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::getUserNickname)
{
    ui->setupUi(this);
}

getUserNickname::~getUserNickname()
{
    delete ui;
}

void getUserNickname::on_pushButton_clicked()
{
    emit SendData(ui->lineEdit->text(), ui->lineEdit_2->text());
}

