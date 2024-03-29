#ifndef TASKFORM_H
#define TASKFORM_H

#include <QWidget>

namespace Ui {
class taskForm;
}

class taskForm : public QWidget
{
    Q_OBJECT

public:
    explicit taskForm(QWidget *parent = nullptr);
    ~taskForm();

    void SetText(QString text);
    QString GetText();
    void SetCheck(bool status);
    int GetCheck();
    void DisableEdit();
    

private:
    Ui::taskForm *ui;

private slots:
    void on_lineEdit_name_editingFinished();

    void on_pushButton_delete_clicked();

    void on_checkBox_isdone_stateChanged(int arg1);

signals:
    void ButtonClickedTask(QString text);
    void TaskChanged();
};

#endif // TASKFORM_H
