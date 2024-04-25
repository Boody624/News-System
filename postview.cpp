#include "postview.h"
#include "ui_postview.h"
#include "adminview.h"
#include "post.h"


PostView::PostView(Post *inP,QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::PostView)
{
    p = inP;
    ui->setupUi(this);

}

PostView::~PostView()
{
    delete ui;
}

void PostView::on_pushButton_clicked()
{
    QString title = ui->lineEdit->text();
    QString Description = ui->textEdit->toPlainText();
    int rating = ui->comboBox->currentText().toInt();
    QString Category = ui->comboBox_2->currentText();
    QDate Date = ui->dateEdit->date();
    p->setInfo(title,Description,Date,rating,Category);
    emit postPublished(p);
    this->hide();

}



