#include "post.h"

int Post::count = 0;
Post::Post() {count++;}
Post::~Post(){count--;}

void Post::setInfo(QString t, QString d, QDate indate, int r, QString categ)
{
    title = t;
    description = d;
    date = indate;
    rating = r;
    category = categ;

}
