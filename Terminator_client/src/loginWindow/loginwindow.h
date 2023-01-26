#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QMainWindow>

namespace Ui {
class loginWindow;
}

class loginWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit loginWindow(QWidget *parent = nullptr);
    ~loginWindow();

private:
    Ui::loginWindow *ui;
	
private slots:
    void on_pushButton_login_clicked();
    void on_pushButton_new_clicked();
	
signals:
    void LoginSucces(QString username, QString password);
};

#endif // LOGINWINDOW_H
