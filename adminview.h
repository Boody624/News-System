#ifndef ADMINVIEW_H
#define ADMINVIEW_H
#include <QLabel>
#include <QDialog>
#include <QDebug>
#include <vector>
#include <QFile>
#include <QTextStream>
#include<vector>
#include "post.h"
using namespace std;
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
    QFile posts;
    vector<Post*> PostsVector;
    void loadPosts(); // loads all posts at the beginning (when the constructor is called)
    void UploadPosts(); // Uploads all poss at the end (when destructor is called)

private:
    Ui::adminView *ui;

public slots:
    void addPost(Post *p);
    void on_pushButton_clicked();
    //void updatePost(QString title, QString description);
private slots:
    void on_pushButton_2_clicked();
};

#endif // ADMINVIEW_H
