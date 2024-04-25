#ifndef ADMINVIEW_H
#define ADMINVIEW_H

#include <QDialog>
#include "post.h"

namespace Ui {
class adminView;
}

class adminView : public QDialog
{
    Q_OBJECT

public:
    explicit adminView(QWidget *parent = nullptr);
    ~adminView();

private:
    Ui::adminView *ui;

public slots:
    void addPost(Post *p);
    void on_pushButton_clicked();

};

#endif // ADMINVIEW_H
