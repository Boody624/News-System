#include "adminview.h"
#include "ui_adminview.h"
#include "postview.h"
#include <QLabel>
adminView::adminView(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::adminView)
{
    ui->setupUi(this);
    ui->verticalLayout = new QVBoxLayout(ui->scrollAreaWidgetContents);
    ui->scrollArea->setWidget(ui->scrollAreaWidgetContents);



}

adminView::~adminView()
{
    delete ui;
}

void adminView::on_pushButton_clicked()
{
    Post *NEWP = new Post();
    PostView *p = new PostView(NEWP, this);
    connect(p, &PostView::postPublished, this, &adminView::addPost);
    p->show();

}
void adminView::addPost(Post *p) {

    QWidget *post = new QWidget(ui->scrollAreaWidgetContents);
    QVBoxLayout *postLayout = new QVBoxLayout(post);

    QLabel *title = new QLabel(p->title);
    QLabel *description = new QLabel(p->description);
    QLabel *date = new QLabel(p->date.toString());
    QLabel *rating = new QLabel("Rating: "+QString::number(p->rating)+ " Stars");
    QLabel *categ = new QLabel(p->category);


    description->setWordWrap(true);

    postLayout->addWidget(title);
    postLayout->addWidget(description);
    postLayout->addWidget(rating);
    postLayout->addWidget(categ);
    postLayout->addWidget(date);




    ui->verticalLayout->addWidget(post);
}

