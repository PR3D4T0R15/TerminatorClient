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

private slots:
    void on_pushButton_login_clicked();
    void on_pushButton_nowy_clicked();

private:
    Ui::loginWindow *ui;
};

#endif // LOGINWINDOW_H
