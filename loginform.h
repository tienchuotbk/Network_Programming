#ifndef LOGINFORM_H
#define LOGINFORM_H

#include <QDialog>

namespace Ui {
class loginForm;
}

class loginForm : public QDialog
{
    Q_OBJECT

public:
    explicit loginForm(QWidget *parent = nullptr);
    ~loginForm();

private:
    Ui::loginForm *ui;
};

#endif // LOGINFORM_H
