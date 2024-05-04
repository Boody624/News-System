#ifndef USER_H
#define USER_H
#include <QLabel>
#include <QDebug>
#include <QDialog>
#include <QVector>
#include "post.h"

namespace Ui {
class user;
}

class user : public QDialog
{
    Q_OBJECT

public:
    explicit user(QWidget *parent = nullptr);
    ~user();
    void viewPost(Post* p);
    QVector <Post*> vec;
    QVector<QWidget* > vector;
    QVBoxLayout *postLayout;
    QWidget *postWidget;
    static int count;

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::user *ui;
};

#endif // USER_H
