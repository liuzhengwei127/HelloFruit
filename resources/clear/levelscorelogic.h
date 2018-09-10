#ifndef LEVELSCORELOGIC_H
#define LEVELSCORELOGIC_H

#include <QObject>

class Levelscorelogic : public QObject
{
    Q_OBJECT
public:
    Levelscorelogic();

    /* 设置目标分数，要求划线数 */
    void setstandard(int targets, int remaininglines,int s = 0);
    void setscore(int scores);
    int getscore();
    int getremainingline();
    int gettarget();

private:
    /* 记录分数 */
    int score = 0;
    /* 记录目标分数 */
    int target;
    /* 记录剩余划线数 */
    int remainingline;
    int base = 100;

    /* 计算此次得分 */
    int computescore(int length);


signals:
    /* 发送结束信号 */
    void end(bool ifpass,int scores);
    /* 发送刷新分数信号 */
    void settxt(int score,int target,int remainingline);

public slots:
    /* 处理更新文本事件 */
    void update(int length);
    void skill_incscore();
};

#endif // LEVELSCORELOGIC_H
