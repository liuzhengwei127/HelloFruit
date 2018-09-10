#ifndef RANKWINDOW_H
#define RANKWINDOW_H

#include "window.h"
#include <QtSql>

class Rankwindow : public Window
{
    Q_OBJECT
public:
    Rankwindow(bool ifp,int tot);

private:
    int total;
    int grade[5];
    QString name[5];
    QLabel ranktxt;
    QSqlDatabase db;
    bool ifpass;

    void showrank();

private slots:
    void upload(QString username);
    void getusername();
};

#endif // RANKWINDOW_H
