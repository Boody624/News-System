#include "loginwindow.h"
#include "ui_loginwindow.h"
#include "data.h"
#include "registration.h"
#include "adminview.h"
using namespace std;
loginWindow::loginWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::loginWindow)
{
    ui->setupUi(this);
    ui->username_error->hide();
    ui->password_error->hide();
}

loginWindow::~loginWindow()
{
    delete ui;
}

void loginWindow::on_login_button_clicked()

{
    ui->username_error->hide();
    ui->password_error->hide();
    auto i=usernames.find(ui->username_lineedit->text());
    if (i==usernames.end()){
        ui->username_error->show();
        return;
    }
    if(get<0>(i->second)== ui->password_lineedit->text()){
        if (get<1>(i->second)==true){
            //Go to admin
            adminView *V = new adminView(this);
            this->hide();
            qDebug()<<"admin";
            V->show();


        }
        else{
            //Go to user
        }
    }
    else{
        ui->username_error->show();
    }

}


void loginWindow::on_signup_button_clicked()
{
    hide();
    registration* reg = new registration(this);
    reg->show();

}

