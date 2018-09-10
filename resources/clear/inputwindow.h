#ifndef INPUTWINDOW_H
#define INPUTWINDOW_H

#include "window.h"

class Inputwindow : public Window
{
    Q_OBJECT
public:
    Inputwindow();

private:
    QLineEdit input_username;
    QLabel information;

signals:
    void name(QString username);

private slots:
    void post_name();
};

#endif // INPUTWINDOW_H
