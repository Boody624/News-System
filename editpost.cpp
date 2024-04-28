#include "editpost.h"

EditPostDialog::EditPostDialog(QWidget *parent)
    : QDialog(parent)
{
    QVBoxLayout *layout = new QVBoxLayout();

    titleEdit = new QLineEdit();
    descriptionEdit = new QTextEdit();

    dateEdit = new QDateEdit(); // Change to QDateEdit
    dateEdit->setDate(QDate::currentDate()); // Set current date
    dateEdit->setCalendarPopup(true); // Enable calendar popup
    ratingComboBox = new QComboBox(); // Change to QComboBox
    ratingComboBox->addItem("1 Star");
    ratingComboBox->addItem("2 Stars");
    ratingComboBox->addItem("3 Stars");
    ratingComboBox->addItem("4 Stars");
    ratingComboBox->addItem("5 Stars");

    categoryComboBox = new QComboBox(); // Change to QComboBox
    categoryComboBox->addItem("Politics");
    categoryComboBox->addItem("Business");
    categoryComboBox->addItem("Technology");
    categoryComboBox->addItem("Health");
    categoryComboBox->addItem("Science");
    categoryComboBox->addItem("Entertainment");
    categoryComboBox->addItem("Sports");

    layout->addWidget(new QLabel("Title:"));
    layout->addWidget(titleEdit);
    layout->addWidget(new QLabel("Description:"));
    layout->addWidget(descriptionEdit);
    layout->addWidget(new QLabel("Date:"));
    layout->addWidget(dateEdit);
    layout->addWidget(new QLabel("Rating:"));
    layout->addWidget(ratingComboBox);
    layout->addWidget(new QLabel("Category:"));
    layout->addWidget(categoryComboBox);

    QPushButton *saveButton = new QPushButton("Save");

    connect(saveButton, &QPushButton::clicked, this, &EditPostDialog::savePost);

    layout->addWidget(saveButton);

    setLayout(layout);
}

void EditPostDialog::savePost()
{
    QString title = titleEdit->text();
    QString description = descriptionEdit->toPlainText();
    QDate date = dateEdit->date(); // Retrieve date from QDateEdit
    QString rating = ratingComboBox->currentText(); // Retrieve selected text from QComboBox
    QString category = categoryComboBox->currentText(); // Retrieve selected text from QComboBox

    emit postEdited(title, description, date, rating, category);

    accept();
}
