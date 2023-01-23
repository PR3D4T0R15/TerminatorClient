#ifndef GETUSERNICKNAME_H
#define GETUSERNICKNAME_H

#include <QMainWindow>

namespace Ui {
class getUserNickname;
}

class getUserNickname : public QMainWindow
{
    Q_OBJECT

public:
    explicit getUserNickname(QWidget *parent = nullptr);
    ~getUserNickname();

private:
    Ui::getUserNickname *ui;

private slots:
    void on_pushButton_clicked();

signals:
    void SendData(QString username, QString form);
};

#endif // GETUSERNICKNAME_H
