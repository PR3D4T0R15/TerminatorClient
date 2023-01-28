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

    void AddToTasks(QString text, bool status);
    void AddToList(QString text);

private slots:
    void on_pushButton_addTask_clicked();
    void on_pushButton_addLists_clicked();

signals:

public slots:
    void ShowWindow(QString username, QString Password);
    void DeleteList(QString text);
    void DeleteTask(QString text);
};

#endif // MAINWINDOW_H
