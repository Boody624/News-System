#include "adminview.h"
#include "ui_adminview.h"
#include "postview.h"
#include "editpost.h"
#include "post.h"

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
    QWidget *postWidget = new QWidget(ui->scrollAreaWidgetContents);
    QVBoxLayout *postLayout = new QVBoxLayout(postWidget);

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

    if (isAdmin) {
        QPushButton *deleteButton = new QPushButton("Delete");
        QPushButton *editButton = new QPushButton("Edit");

        postLayout->addWidget(deleteButton);
        postLayout->addWidget(editButton);

        connect(deleteButton, &QPushButton::clicked, [=]() {
            ui->verticalLayout->removeWidget(postWidget);
            delete postWidget;
            delete p;
        });

        connect(editButton, &QPushButton::clicked, [=]() {
            EditPostDialog dialog(this);
            dialog.titleEdit->setText(p->title);
            dialog.descriptionEdit->setText(p->description);
            dialog.dateEdit->setDate(p->date); // Set date using QDate
            dialog.ratingComboBox->setCurrentText(QString::number(p->rating) + " Stars"); // Set selected rating in combo box
            dialog.categoryComboBox->setCurrentText(p->category); // Set selected category in combo box

            if (dialog.exec() == QDialog::Accepted) {
                // Update the post information if the dialog was accepted
                p->title = dialog.titleEdit->text();
                p->description = dialog.descriptionEdit->toPlainText();
                p->date = dialog.dateEdit->date(); // Retrieve date from QDateEdit
                QString selectedRating = dialog.ratingComboBox->currentText();
                p->rating = selectedRating.split(" ")[0].toInt(); // Retrieve rating from combo box
                p->category = dialog.categoryComboBox->currentText(); // Retrieve category from combo box

                // Update UI with edited post information
                title->setText(p->title);
                description->setText(p->description);
                date->setText(p->date.toString());
                rating->setText("Rating: "+QString::number(p->rating)+ " Stars");
                category->setText(p->category);
            }
        });
    }

    ui->verticalLayout->addWidget(postWidget);
}
