#ifndef LOGIN_H
#define LOGIN_H

#include <QMainWindow>
#include <QFileInfo>
#include <QDebug>
#include <QString>
//#include <database/database.h>
//#include <brain/brain.h>
#include "persons_database.h"

namespace Ui {
class Login;
}

class Login : public QMainWindow
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = nullptr);
    ~Login();

private slots:
    //void on_pushButton_login_clicked();

    void on_pushButton_signup_clicked();




    //void on_pushButton_signup_clicked();

    //void on_PB_back_clicked();

    //void on_pb_getinfo_clicked();

    void on_PB_login_clicked();

    //void on_PB_test_clicked();

    void on_PB_back_to_login_clicked();

    void on_PB_register_clicked();

    void on_pushButton_clicked();

private:
    Ui::Login *ui;


};

#endif // LOGIN_H
