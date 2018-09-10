#include "basicfruit.h"

QSize Basicfruit::size = QSize(70,70);
QString Basicfruit::ss[5][4]=
{
    {"border-image:url(../resources/waterme.png);",
     "border-image:url(../resources/waterme_s.png);",
     "border-image:url(../resources/boom.png);",
     "border-image:url(../resources/waterme.png);background:#AAAAAA;"},
    {"border-image:url(../resources/orange.png);",
     "border-image:url(../resources/orange_s.png);",
     "border-image:url(../resources/boom.png);",
     "border-image:url(../resources/orange.png);background:#AAAAAA;"},
    {"border-image:url(../resources/strawberry.png);",
     "border-image:url(../resources/strawberry_s.png);",
     "border-image:url(../resources/boom.png);",
     "border-image:url(../resources/strawberry.png);background:#AAAAAA;"},
    {"border-image:url(../resources/grape.png);",
     "border-image:url(../resources/grape_s.png);",
     "border-image:url(../resources/boom.png);",
     "border-image:url(../resources/grape.png);background:#AAAAAA;"},
    {"border-image:url(../resources/barrier.png);",
     "border-image:url(../resources/barrier.png);",
     "border-image:url(../resources/boom.png);",
     "border-image:url(../resources/barrier.png);background:#AAAAAA;"}
};                                                //设置水果的图片路径字符串

Basicfruit::Basicfruit(int random,int i,int j)
{
    ifselected = false;
    type = random;
    this->setFixedSize(size);
    formerfr = NULL;
    this->changeto(0);
    fri = i;
    frj = j;
}

void Basicfruit::changeto(int state)
{
    this->setStyleSheet(ss[type][state]);
}

void Basicfruit::setifselected(bool b)
{
    ifselected = b;
}

int Basicfruit::gettype()
{
    return type;
}

bool Basicfruit::getifselected()
{
    return ifselected;
}

int Basicfruit::geti()
{
    return fri;
}

int Basicfruit::getj()
{
    return frj;
}

void Basicfruit::seti(int i)
{
    fri = i;
}

void Basicfruit::setj(int j)
{
    frj = j;
}

void Basicfruit::settype(int t)
{
    type = t;
}

QPoint Basicfruit::getpos()
{
    return this->pos();
}

void Basicfruit::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
        emit mousepress(this->type); // 事件处理 用于截获消息并标记 为其他事件操作提供基础
}
