#ifndef LOGINFORM_H
#define LOGINFORM_H
#include <QString>
#include <QDialog>
#include <QString>

namespace Ui {
class loginForm;
}

class loginForm : public QDialog
{
    Q_OBJECT

public:
    explicit loginForm(QWidget *parent = nullptr);
    ~loginForm();
    QString username;
    QString password;

private slots:
    void on_pushButton_clicked();

private:
    Ui::loginForm *ui;
};

#endif // LOGINFORM_H
