#ifndef Mainwindow_H
#define Mainwindow_H

#include <QApplication>
#include "easy.h"
#include "difficult.h"
#include "hell.h"
#include "aiwindow.h"

class Mainwindow : public Window
{
    Q_OBJECT
public:
    /* 构造函数 */
    Mainwindow();

private:
    /* 绘制界面 */
    void draw();
    /* 设置信号与槽 */
    void link(Gamewindow *w);

private slots:
    /* 处理开始游戏事件 */
    void gamebegin();
    /* 处理重新开始事件 */
    void gamerestart(Gamewindow *d);
    /* 处理返回主界面事件 */
    void closegamew(Gamewindow *d);
    /* 处理进入下一关事件 */
    void nextlevel(Gamewindow *d,int level);
    void continuegame();
    void playmusic();
    void aigamebegin();
};

#endif // Mainwindow_H
