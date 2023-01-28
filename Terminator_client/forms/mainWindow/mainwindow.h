#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QJsonArray>

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
    QJsonArray listNames;
    QJsonArray currentList;

    void AddToTasks(QString text, bool status);
    void AddToList(QString text);
    void LoadLists();
    //void CreateList(QString listName);
    //void LoadTasks();
    //void CreateTask();

private slots:
    void on_pushButton_addTask_clicked();
    void on_pushButton_addLists_clicked();
    void on_pushButton_sendLists_clicked();

signals:

public slots:
    void ShowWindow(QString username, QString Password);
    void DeleteList(QString text);
    void DeleteTask(QString text);
    void RecevieDataDestUSer(QString destUser, QString listName);
};

#endif // MAINWINDOW_H
