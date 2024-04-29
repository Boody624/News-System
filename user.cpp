#include "user.h"
#include "ui_user.h"

user::user(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::user)
{
    ui->setupUi(this);
}

user::~user()
{
    delete ui;
}

void user::on_pushButton_clicked()
{
    if (ui->title->isChecked())
    {
        // search code with the titles of other news
    }
    else if (ui->date->isChecked())
    {
      // search code with the dates of other news
    }
    else if (ui->keyword->isChecked())
    {
        // search code with the keyword of other news
    }
}


void user::on_pushButton_2_clicked()
{
    // does something to the rating
    ui->rate->currentIndex();
}


void user::on_pushButton_3_clicked()
{
    //does something to the news
    ui->filter->currentText();
}

