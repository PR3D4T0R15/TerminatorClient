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
    void SetCheck(bool status);

private:
    Ui::taskForm *ui;

private slots:
    void on_lineEdit_name_editingFinished();
};

#endif // TASKFORM_H
