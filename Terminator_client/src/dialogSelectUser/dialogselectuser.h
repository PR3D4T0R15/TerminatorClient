#ifndef DIALOGSELECTUSER_H
#define DIALOGSELECTUSER_H

#include <QDialog>

namespace Ui {
class dialogSelectUser;
}

class dialogSelectUser : public QDialog
{
    Q_OBJECT

public:
    explicit dialogSelectUser(QWidget *parent = nullptr);
    ~dialogSelectUser();

private:
    Ui::dialogSelectUser *ui;

private slots:
    void on_buttonBox_accepted();

signals:
    void SendData(QString username);
};

#endif // DIALOGSELECTUSER_H
