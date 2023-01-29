#include "listform.h"
#include "ui_listform.h"
#include <QTimer>

listForm::listForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::listForm)
{
    ui->setupUi(this);
    ui->lineEdit_name->setFocus();
    QTimer::singleShot(0, ui->lineEdit_name, SLOT(setFocus()));
}

listForm::~listForm()
{
    delete ui;
}

void listForm::SetText(QString text)
{
    ui->lineEdit_name->setText(text);
}

QString listForm::GetText()
{
    return ui->lineEdit_name->text();
}

void listForm::DisableEdit()
{
    ui->lineEdit_name->setReadOnly(true);
    ui->lineEdit_name->setDisabled(true);
    ui->lineEdit_name->setStyleSheet("background-color: rgba(0, 0, 0, 1)");
    ui->lineEdit_name->setStyleSheet("color: rgb(0, 0, 0)");
}

void listForm::on_lineEdit_name_editingFinished()
{
    ui->lineEdit_name->setReadOnly(true);
    ui->lineEdit_name->setDisabled(true);
    ui->lineEdit_name->setStyleSheet("background-color: rgba(0, 0, 0, 1)");
    ui->lineEdit_name->setStyleSheet("color: rgb(0, 0, 0)");

    emit ListCreated(ui->lineEdit_name->text());
}

void listForm::on_pushButton_delete_clicked()
{
    emit ButtonClickedList(ui->lineEdit_name->text());
}

