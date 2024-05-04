#ifndef ADMINVIEW_H
#define ADMINVIEW_H
#include <QLabel>
#include <QDialog>
#include <QDebug>
class Post;

namespace Ui {
class adminView;
}

class adminView : public QDialog
{
    Q_OBJECT

public:
    explicit adminView(QWidget *parent = nullptr);
    ~adminView();
    bool isAdmin = false;
private:
    Ui::adminView *ui;

public slots:
    void addPost(Post *p);
    void on_pushButton_clicked();
    //void updatePost(QString title, QString description);
private slots:
    void on_title_search_button_clicked();
};

#endif // ADMINVIEW_H
