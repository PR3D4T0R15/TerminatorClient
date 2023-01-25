#include "newuser.h"
#include "ui_newuser.h"
#include "network.h"
#include <QMessageBox>

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

void newUser::on_buttonBox_accepted()
{
    QString username = ui->lineEdit_login->text();
    QString password1 = ui->lineEdit_pass1->text();
    QString password2 = ui->lineEdit_pass2->text();

    if (password1 != password2)
    {
        QMessageBox::critical(this, "BŁĄD", "Hasła się nie zgadzają");
        return;
    }

    if (username == "")
    {
        QMessageBox::critical(this, "BŁĄD", "Puste pole nazwy użytkownika");
        return;
    }

    networkAPI net;
    bool status = net.CreateUser("Admin", "AdmiN", username, password1);

    if (!status)
    {
        QMessageBox::critical(this, "BŁĄD", "Coś poszło nie tak");
        return;
    }
    else
    {
        this->hide();
    }
}


void newUser::on_lineEdit_login_textEdited(const QString& arg1)
{
    if (ui->lineEdit_login->text() != "" && ui->lineEdit_pass1->text() == ui->lineEdit_pass2->text())
    {
        ui->label_info->setText("Utwórz nowego użytkownika");
        ui->buttonBox->show();
    }
    else
    {
        ui->label_info->setText("<p style=\"color:red\">Pole login jest puste</p>");
        ui->buttonBox->hide();
    }
}


void newUser::on_lineEdit_pass1_textEdited(const QString& arg1)
{
    if (ui->lineEdit_pass1->text() == ui->lineEdit_pass2->text() && ui->lineEdit_login->text() != "")
    {
        ui->label_info->setText("Utwórz nowego użytkownika");
        ui->buttonBox->show();
    }
    else
    {
        ui->label_info->setText("<p style=\"color:red\">Hasła są różne</p>");
        ui->buttonBox->hide();
    }
}


void newUser::on_lineEdit_pass2_textEdited(const QString& arg1)
{
    if (ui->lineEdit_pass2->text() == ui->lineEdit_pass1->text() && ui->lineEdit_login->text() != "")
    {
        ui->label_info->setText("Utwórz nowego użytkownika");
        ui->buttonBox->show();
    }
    else
    {
        ui->label_info->setText("<p style=\"color:red\">Hasła są różne</p>");
        ui->buttonBox->hide();
    }
}

