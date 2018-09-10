#ifndef OPERATIONLOGIC_H
#define OPERATIONLOGIC_H

#include "basicfruit.h"
#include <QParallelAnimationGroup>
#include <QPropertyAnimation>
#include <QMouseEvent>
#include <QMediaPlayer>

class Operationlogic : public QObject
{
    Q_OBJECT
public:
    QFile replay_operation;
    /* 用于禁止用户在动画执行时操作 */
    bool operationforbid = false;


    /* 构造函数 */
    Operationlogic();
    /* 设置此条线的水果类型 */
    void setfrtype(int type);
    /* 设置行数列数 */
    void setcr(int i,int j);
    void setreplay();
    void setifpress(bool p);
    /* 处理鼠标移动事件 */
    void mousemove(QPoint p);
    /* 处理鼠标释放事件 */
    void mouserelease();
    /* 获得指定行列数的水果指针 */
    Basicfruit *&getfr(int i,int j);
    Basicfruit *&getfr(int seq);

private:
    /* 记录此条线当前最后选定的水果 */
    Basicfruit* formerfr;
    /* 存储所有水果的指针，便于操作 */
    Basicfruit* fr[64] = {NULL};
    /* 此条线的水果类型 */
    int frtype;
    /* 记录此条线当前选中的水果 */
    int length;
    /* 列数 */
    int column;
    /* 行数 */
    int row;
    int musiccounter = 0;
    /* 用于记录鼠标处于按下状态 */
    bool ifpress;
    bool replay = false;
    bool animation = false;
    QMediaPlayer boom;
    QMediaPlayer selected[4];

    /* 判断逻辑的数据重置 */
    void reset();
    /* 判断点是否有效 */
    bool ifpvalid(Basicfruit *fr);
    /* 计算平方和 */
    int square(QPoint a,QPoint b);
    /* 获得点在图上对应水果的行列数和 */
    int getseqnum(QPoint p);
    /* 此条线长度加一 */
    void add(int seqnum);
    /* 此条线长度减一 */
    void subtract(int seqnum);
    /* 设置动画 */
    void addanimationgruop(QAnimationGroup *anig, int *columnclearnum);
    /* 操作无效 上一次记录取消 */
    void cancle();


public slots:
    /* 处理鼠标点击事件 */
    void mousepress(int type);
    /* 处理动画结束事件 */
    void animation_end();
    void skill_repaint();
    void skill_incscore();
    void animation_begin();

signals:
    /* 发送成功消除一条线的信息 */
    void successful_operation(int length);
    /* 产生新的水果 */
    void generate(int i,int j);

};

#endif // OPERATIONLOGIC_H
