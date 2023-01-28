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

void listForm::on_lineEdit_name_editingFinished()
{
    ui->lineEdit_name->setReadOnly(true);
}

