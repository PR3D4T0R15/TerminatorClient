#ifndef NEWUSER_H
#define NEWUSER_H

#include <QDialog>

namespace Ui {
class newUser;
}

class newUser : public QDialog
{
    Q_OBJECT

public:
    explicit newUser(QWidget *parent = nullptr);
    ~newUser();

private slots:
    void on_buttonBox_accepted();
    void on_lineEdit_login_textEdited(const QString& arg1);
    void on_lineEdit_pass1_textEdited(const QString& arg1);
    void on_lineEdit_pass2_textEdited(const QString& arg1);

private:
    Ui::newUser *ui;
};

#endif // NEWUSER_H
