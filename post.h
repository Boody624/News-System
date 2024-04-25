#ifndef POST_H
#define POST_H
#include <QString>
#include<QDate>

class Post
{
public:
    static int count;
    QString title;
    QString description;
    QDate date;
    int rating;
    QString category;
    Post();
    ~Post();
    void setInfo(QString t, QString d, QDate indate, int r, QString categ);

};


#endif // POST_H
