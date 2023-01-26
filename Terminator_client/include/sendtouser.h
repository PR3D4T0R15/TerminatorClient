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

signals:
    void SendData();

private:
    Ui::sendToUser *ui;
};

#endif // SENDTOUSER_H
