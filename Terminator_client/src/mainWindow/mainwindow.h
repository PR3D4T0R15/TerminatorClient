#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QJsonDocument>

namespace Ui {
class mainWindow;
}

class mainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit mainWindow(QWidget *parent = nullptr);
    ~mainWindow();

private:
    Ui::mainWindow *ui;
    QString logedLogin;
    QString logedPass;
    QJsonDocument listNames;
    QJsonDocument currentList;

    void LoadJSON();


signals:

public slots:
    void ShowWindow(QString username, QString Password);
};

#endif // MAINWINDOW_H
