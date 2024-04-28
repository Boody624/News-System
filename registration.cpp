#include "registration.h"
#include "ui_registration.h"
#include "data.h"
#include "adminview.h"

registration::registration(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::registration)
{
    ui->setupUi(this);
    ui->username_error->hide();
    ui->check_error->hide();
}

registration::~registration()
{
    delete ui;
}

void registration::on_pushButton_clicked()

{
    ui->username_error->hide();
    ui->check_error->hide();
    auto i = usernames.find(ui->username_lineedit->text());
    if (!ui->admin_button->isChecked()&&!ui->user_button->isChecked()){
        ui->check_error->show();
        return;
    }
    if(i==usernames.end()){
        usernames.insert({ui->username_lineedit->text(), std::pair<QString, bool>(ui->password_lineedit->text(), ui->admin_button->isChecked())});
        if (ui->admin_button->isChecked()){
            adminView *V = new adminView(this);
            V->isAdmin = true;
            this->hide();
            V->show();
        }
        else{
            //Go to user
        }
    }
    else{
        ui->username_error->show();
        return;
    }

}




