#include "taskform.h"
#include "ui_taskform.h"
#include <QTimer>

taskForm::taskForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::taskForm)
{
    ui->setupUi(this);
    ui->lineEdit_name->setFocus();
    QTimer::singleShot(0, ui->lineEdit_name, SLOT(setFocus()));
}

taskForm::~taskForm()
{
    delete ui;
}

void taskForm::SetText(QString text)
{
    ui->lineEdit_name->setText(text);
}

void taskForm::SetCheck(bool status)
{
    ui->checkBox_isdone->setChecked(status);
}

void taskForm::on_lineEdit_name_editingFinished()
{
    ui->lineEdit_name->setReadOnly(true);
}

