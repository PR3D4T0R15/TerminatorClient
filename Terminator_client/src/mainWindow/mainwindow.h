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
    void AddToList(QString name);
    void AddtoTasks(QString name, int status);

private slots:
    void on_pushButton_addLists_clicked();
    void on_pushButton_sendLists_clicked();
    void on_pushButton_addTask_clicked();
    void OnClickedLists();
    void OnClickedTasks();
    void DialogReturnValues(QString username, QString form);

signals:

public slots:
    void ShowWindow(QString username, QString Password);
};

#endif // MAINWINDOW_H
