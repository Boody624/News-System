#include "user.h"
#include "ui_user.h"
#include <QDialog>
#include "postview.h"
#include "editrating.h"
int user::count = 0;
user::user(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::user)
{
    ui->setupUi(this);
    ui->verticalLayout = new QVBoxLayout(ui->scrollAreaWidgetContents);
    ui->scrollArea->setWidget(ui->scrollAreaWidgetContents);
    count++;
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
    postWidget = new QWidget(ui->scrollAreaWidgetContents);
    postLayout = new QVBoxLayout(postWidget);
    vector.push_back(postWidget);
    Post *NEWP = new Post();
    PostView *p = new PostView(NEWP, this);
    connect(p, &PostView::postPublished, this, &user::viewPost);
    p->show();
    vec.push_back(NEWP);
}


void user::on_pushButton_3_clicked()
{
    int lol = 0;
    for (int count = 0; count < vector.size(); count++) {
        // adding all postwidgets again
     ui->verticalLayout->addWidget(vector.at(count));
     vector.at(count)->show();
    }
    for (auto i = vec.begin(); i != vec.end(); )
    {
        Post* p = *i;
        QString hamo = p->getcateg();
        if (hamo != ui->filter->currentText() && ui->filter->currentText()!= "None") {
            qDebug() << "Hiding post with category: " << hamo;

            // Remove the postWidget from the layout
            ui->verticalLayout->removeWidget(vector.at(lol));

            // Hide the postWidget
            vector.at(lol)->hide();

            ++i;
        } else {

            ++i;
        }
        lol++;
    }
}


void user::viewPost(Post *p) {
        //postWidget = new QWidget(ui->scrollAreaWidgetContents);
        //postLayout = new QVBoxLayout(postWidget);

        QLabel *title = new QLabel(p->title);
        QLabel *description = new QLabel(p->description);
        QLabel *date = new QLabel(p->date.toString());
        QLabel *rating = new QLabel("Rating: "+QString::number(p->rating)+ " Stars");
        QLabel *category = new QLabel(p->category);

        description->setWordWrap(true);
        postLayout->addWidget(title);
        postLayout->addWidget(description);
        postLayout->addWidget(rating);
        postLayout->addWidget(category);
        postLayout->addWidget(date);
            QPushButton *Addrating = new QPushButton("Rate");

            postLayout->addWidget(Addrating);



            connect(Addrating, &QPushButton::clicked, [=]() {
                editrating dialog(this);
                dialog.ratingComboBox->setCurrentText(QString::number(p->rating) + " Stars"); // Set selected rating in combo box

                if (dialog.exec() == QDialog::Accepted) {
                    // Update the post information if the dialog was accepted
                    QString selectedRating = dialog.ratingComboBox->currentText();
                    p->rating = selectedRating.split(" ")[0].toInt(); // Retrieve rating from combo box

                    // Update UI with edited post information
                    rating->setText("Rating: "+QString::number(p->rating)+ " Stars");
                }
            });
        ui->verticalLayout->addWidget(postWidget);
    }



