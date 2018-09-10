#ifndef RESULTWINDOW_H
#define RESULTWINDOW_H

#include "window.h"
#include "rankwindow.h"

class Resultwindow : public Window
{
    Q_OBJECT
public:
    /* 返回主界面按钮 */
    QPushButton returntomain;
    /* 重新开始按钮 */
    QPushButton tryagain;
    /* 下一关按钮 */
    QPushButton nextlevel;
    QPushButton replaybutton;


    /* 构造函数 */
    Resultwindow(bool ifpass,int scores,int level);
    Resultwindow(bool ifpass,int userscore,int aiscore,int total);

private:
    /* 显示结果信息 */
    QLabel result;
    int total;
    Rankwindow *r;

signals:
    /* 发送返回主界面信号 */
    void signal_returntomain();
    /* 发送重新开始信号 */
    void signal_tryagain();

public slots:
    void replay();
    void inquire();
};

#endif // RESULTWINDOW_H
