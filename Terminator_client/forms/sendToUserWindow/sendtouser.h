#ifndef SENDTOUSER_H
#define SENDTOUSER_H

#include <QDialog>

namespace Ui {
class sendToUser;
}

class sendToUser : public QDialog
{
    Q_OBJECT

public:
    explicit sendToUser(QWidget *parent = nullptr);
    ~sendToUser();
    void SetData(QString user, QString pass);

signals:
    void SendData(QString destUser, QString listName);

private slots:
    void on_buttonBox_accepted();
    void on_buttonBox_rejected();

private:
    Ui::sendToUser *ui;
    QString username;
    QString password;
};

#endif // SENDTOUSER_H
