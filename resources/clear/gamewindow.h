#ifndef Gamewindow_H
#define Gamewindow_H

#include <QString>
#include <QTime>
#include <QTimer>
#include <QFile>
#include <QDebug>
#include "basicfruit.h"
#include "operationlogic.h"
#include "levelscorelogic.h"
#include "resultwindow.h"
#include "savewindow.h"

class Gamewindow : public Window
{
    Q_OBJECT
public:
    /* 重载鼠标移动响应事件 */
    void mouseMoveEvent(QMouseEvent *event);
    /* 重载鼠标松开响应事件 */
    void mouseReleaseEvent(QMouseEvent *event);

protected:
    /* 操作逻辑对象 */
    Operationlogic ologic;    
    /* 记录水果列数 */
    int column;    
    /* 记录水果行数 */
    int row;    
    /* 记录水果种类数 */
    int typenumber;
    /* 记录地图难度等级 */
    int level;
    bool replay = false;
    /* 显示分数 */
    QLabel scoretxt;
    /* 显示剩余划线数 */
    QLabel remaininglinestxt;
    QFile replay_map;

    /* 构造函数 */
    Gamewindow();
    /* 绘制水果阵 */
    void paintfruit();
    /* 设置行数与列数 */
    void setfr(int c,int r,int typenumber);
    /* 根据指定的行列数生成新的水果 */
    virtual void generatefruit(int i,int j,int type);
    /* 界面绘制 */
    void paintscore();

signals:
    /* 向主界面发送回到主界面信号 */
    void signal_returntomain(Gamewindow *d);

private slots:
    /* 调用生成新水果的函数 */
    void generate(int i,int j);
    /* 回到主界面 */
    void returntomain();
};

#endif // Gamewindow_H
