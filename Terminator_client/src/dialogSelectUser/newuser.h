#ifndef NEWUSER_H
#define NEWUSER_H

#include <QDialog>

namespace Ui {
class newUser;
}

class newUser : public QDialog
{
    Q_OBJECT

public:
    explicit newUser(QWidget *parent = nullptr);
    ~newUser();

private:
    Ui::newUser *ui;
};

#endif // NEWUSER_H
