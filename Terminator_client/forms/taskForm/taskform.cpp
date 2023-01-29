#include "taskform.h"
#include "ui_taskform.h"
#include <QTimer>
#include "mainWindow/mainwindow.h"

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

QString taskForm::GetText()
{
    return ui->lineEdit_name->text();
}

void taskForm::SetCheck(bool status)
{
    ui->checkBox_isdone->setChecked(status);
}

int taskForm::GetCheck()
{
    return ui->checkBox_isdone->checkState();
}

void taskForm::DisableEdit()
{
    ui->lineEdit_name->setReadOnly(true);
    ui->lineEdit_name->setDisabled(true);
    ui->lineEdit_name->setStyleSheet("background-color: rgba(0, 0, 0, 1)");
    ui->lineEdit_name->setStyleSheet("color: rgb(0, 0, 0)");
}

void taskForm::on_pushButton_delete_clicked()
{
    emit ButtonClickedTask(ui->lineEdit_name->text());
    emit TaskChanged();
}

void taskForm::on_lineEdit_name_editingFinished()
{
    ui->lineEdit_name->setReadOnly(true);
    ui->lineEdit_name->setDisabled(true);
    ui->lineEdit_name->setStyleSheet("background-color: rgba(0, 0, 0, 1)");
    ui->lineEdit_name->setStyleSheet("color: rgb(0, 0, 0)");
    emit TaskChanged();
}


void taskForm::on_checkBox_isdone_stateChanged(int arg1)
{
    emit TaskChanged();
}

