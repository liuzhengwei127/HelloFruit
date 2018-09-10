#ifndef LEVELWINDOW_H
#define LEVELWINDOW_H

#include "gamewindow.h"

class Levelwindow : public Gamewindow
{
    Q_OBJECT
public:    
    /* 分数逻辑对象 */
    Levelscorelogic levelslogic;

protected:
    bool skill1 = true;
    QPushButton *skill_repaintbutton;
    QPushButton *skill_incscorebutton;

    Levelwindow();
    Levelwindow(QFile *file);
    /* 通过设置目标分数和规定划线数来控制难度 */
    void setstandard(int targets, int remaininglines,int score = 0);
    /* 界面绘制 */
    void draw();
    void paintskill();


signals:
    /* 发送再来一次信号 */
    void signal_tryagain(Gamewindow *d);
    /* 发送进入下一关信号 */
    void signal_nextlevel(Gamewindow *d,int level);
    void skillused();

private slots:
    /* 刷新分数文本 */
    void settxt(int score,int target,int remainingline);
    /* 调出结果提示界面 */
    virtual void postresult(bool ifpass,int scores);
    /* 再来一次 */
    void tryagain();
    /* 下一关 */
    void nextlevel();
    void save();
    void skillclose();
};

#endif // LEVELWINDOW_H
