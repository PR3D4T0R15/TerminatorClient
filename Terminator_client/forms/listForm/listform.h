#ifndef LISTFORM_H
#define LISTFORM_H

#include <QWidget>

namespace Ui {
class listForm;
}

class listForm : public QWidget
{
    Q_OBJECT

public:
    explicit listForm(QWidget *parent = nullptr);
    ~listForm();

    void SetText(QString text);
    QString GetText();
    void DisableEdit();

private:
    Ui::listForm *ui;

private slots:
    void on_lineEdit_name_editingFinished();
    void on_pushButton_delete_clicked();

signals:
    void ButtonClickedList(QString text);
    void ListCreated(QString listName);
};

#endif // LISTFORM_H
