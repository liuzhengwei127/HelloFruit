#include "replaywindow.h"
#include <QDebug>
#include <QTextStream>

Replaywindow::Replaywindow()
{
    replay = true;

    counter_map = 6;
    counter_operation = 0;
    ologic.setreplay();
    ologic.setifpress(true);
    timeinterval = 250;
    QTextStream s_map(&replay_map);
    QTextStream s_operation(&ologic.replay_operation);

    while(!s_map.atEnd())
    {
        int buf;
        s_map>>buf;
        array_map.append(buf);
    }

    while(!s_operation.atEnd())
    {
        int buf;
        s_operation>>buf;
        array_operation.append(buf);
    }

    setfr(array_map[0],array_map[1],array_map[2]);
    setstandard(array_map[3],array_map[4],array_map[5]);

    paintfruit();
    draw();
}

void Replaywindow::begin()
{
    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(nextaction()));
    timer->start(timeinterval);
}

void Replaywindow::generatefruit(int i, int j, int type)
{
    type = array_map[counter_map++];
    Gamewindow::generatefruit(i,j,type);
}

void Replaywindow::draw()
{
    paintscore();
    paintskill();

    QPushButton* closebutton = new QPushButton("关闭",this);
    closebutton->setGeometry(700,750,250,40);
    closebutton->setStyleSheet("font:25px 微软雅黑");

    connect(closebutton,SIGNAL(clicked(bool)),this,SLOT(deleteLater()));
}

void Replaywindow::mousemove()  //触发鼠标移动事件
{    
    Basicfruit *fr = ologic.getfr(array_operation[counter_operation]);
    counter_operation++;
    ologic.setfrtype(fr->gettype());
    ologic.setifpress(true);
    ologic.mousemove(fr->getpos());
}

void Replaywindow::mouserelease()   //触发鼠标松开事件
{
    counter_operation++;
    ologic.mouserelease();
    QTimer::singleShot(timeinterval*10,this,SLOT(timerstart()));
}

void Replaywindow::timerstart()
{
    timer->start(timeinterval);
}

void Replaywindow::postresult(bool, int)
{
    ologic.replay_operation.close();
    replay_map.close();
    deleteLater();
}

void Replaywindow::nextaction()
{
    if (array_operation[counter_operation] >= 0)
        mousemove();
    else
    {
        switch(array_operation[counter_operation])
        {
        case -1:
            timer->stop();
            QTimer::singleShot(timeinterval,this,SLOT(mouserelease()));
            break;
        case -2:
            timer->stop();
            QTimer::singleShot(timeinterval,this,SLOT(skillrepaint()));
            break;
        case -3:
            timer->stop();
            QTimer::singleShot(timeinterval,this,SLOT(skillincscore()));
            break;
        }
    }
}

void Replaywindow::skillrepaint()  //触发技能事件
{
    counter_operation++;
    ologic.skill_repaint();
    emit skillused();
    QTimer::singleShot(timeinterval*10,this,SLOT(timerstart()));
}

void Replaywindow::skillincscore()
{
    counter_operation++;
    levelslogic.skill_incscore();
    emit skillused();
    QTimer::singleShot(timeinterval*10,this,SLOT(timerstart()));
}
