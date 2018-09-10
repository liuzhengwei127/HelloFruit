#ifndef BASICFRUIT_H
#define BASICFRUIT_H

#include <QLabel>
#include <QSize>
#include <QMouseEvent>

class Basicfruit : public QLabel
{
    Q_OBJECT
public:
    /* 规定水果的尺寸 */
    static QSize size;
    /* 在选定队列中，记录此水果前一个被选定的水果 */
    Basicfruit* formerfr;


    /* 构造函数 */
    Basicfruit(int random,int i,int j);
    /* 将水果的状态切换为指定的状态（换图片） */
    void changeto(int state);
    /* 设置水果的选定状态 */
    void setifselected(bool b);
    /* 获得水果的类型 */
    int gettype();
    /* 获得水果是否被选中 */
    bool getifselected();
    int geti();
    int getj();
    void seti(int i);
    void setj(int j);
    void settype(int t);
    QPoint getpos();
    /* 用于截获消息并标记 为其他事件操作提供基础 */
    void mousePressEvent(QMouseEvent *event);


private:
    /* 保存样式表需要用到的图片文件路径 */
    static QString ss[5][4];
    /* 记录此水果是否被选中 */
    bool ifselected;
    /* 记录水果的类型 */
    int type;
    int fri;
    int frj;


signals:
    /* 发送鼠标点击的信号给逻辑层处理 */
    void mousepress(int type);
};

#endif // BASICFRUIT_H
