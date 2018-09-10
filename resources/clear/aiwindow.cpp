#include "aiwindow.h"
#include <QDebug>

AIwindow::AIwindow()
{
    connect(&ologic,SIGNAL(successful_operation(int)),&aislogic,SLOT(update(int)));
    connect(&aislogic,SIGNAL(end(bool,int,int)),this,SLOT(postresult(bool,int,int)));
    connect(&aislogic,SIGNAL(settxt_ai(int,int,int)),this,SLOT(settxt_ai(int,int,int)));
    connect(&aislogic,SIGNAL(aiturn()),this,SLOT(aioperate()));

    draw();
    setfr(6,6,4);
    paintfruit();
    settxt_ai(0,0,6);
    array_final.resize(column*row+1);
    array_record.resize(column*row+1);
    array_ifselected.resize(column*row+1);
    for (int i=0;i<column*row+1;i++)
        array_ifselected[i] = false;
}

void AIwindow::draw()
{
    paintscore();

    QPushButton *returnbutton = new QPushButton("返回主界面",this);
    returnbutton->setGeometry(700,750,250,40);
    returnbutton->setStyleSheet("font:25px 微软雅黑");
    connect(returnbutton,SIGNAL(clicked(bool)),this,SLOT(returntomain()));
}

void AIwindow::search(int i, int j, int l) //找最合适的消除路径
{
    array_record[l] = i+j*column;
    array_ifselected[i+j*column] = true;
    int length = compute(j,l+1);
    if (max < length)
    {
        max = length;
        for (int t=0;t<l+1;t++)
            array_final[t] = array_record[t];
    }

    int type = ologic.getfr(array_record[0])->gettype();

    if (i>0 && ologic.getfr(i-1+j*column)->gettype() == type && !array_ifselected[i-1+j*column])
        search(i-1,j,l+1);
    if (i+1<column && ologic.getfr(i+1+j*column)->gettype() == type && !array_ifselected[i+1+j*column])
        search(i+1,j,l+1);
    if (j>0  && ologic.getfr(i+(j-1)*column)->gettype() == type && !array_ifselected[i+(j-1)*column])
        search(i,j-1,l+1);
    if (j+1<row  && ologic.getfr(i+(j+1)*column)->gettype() == type && !array_ifselected[i+(j+1)*column])
        search(i,j+1,l+1);
    if (i>0 && j>0  && ologic.getfr(i-1+(j-1)*column)->gettype() == type && !array_ifselected[i-1+(j-1)*column])
        search(i-1,j-1,l+1);
    if (i>0 && j+1<row  && ologic.getfr(i-1+(j+1)*column)->gettype() == type && !array_ifselected[i-1+(j+1)*column])
        search(i-1,j+1,l+1);
    if (i+1<column && j>0  && ologic.getfr(i+1+(j-1)*column)->gettype() == type && !array_ifselected[i+1+(j-1)*column])
        search(i+1,j-1,l+1);
    if (i+1<column && j+1<row  && ologic.getfr(i+1+(j+1)*column)->gettype() == type && !array_ifselected[i+1+(j+1)*column])
        search(i+1,j+1,l+1);

    array_ifselected[i+j*column] = false;
}

void AIwindow::mouseReleaseEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton && !replay && !ologic.operationforbid)
        ologic.mouserelease();

    if (!aislogic.userturn && !ologic.operationforbid)
    {
        ologic.operationforbid = true;
        QTimer::singleShot(4000,this,SLOT(aioperate()));
    }
}

void AIwindow::clear()
{
    max = 0;
    counter = 0;
    for (int i=0;i<column*row+1;i++)
    {
        array_ifselected[i] = false;
        array_final[i] = 0;
        array_record[i] = 0;
    }
}

int AIwindow::compute(int j, int length)
{
    if (length >= 8)
        for (int i=0;i<column;i++)
            if (!array_ifselected[i+j*column])
                length++;

    return length;
}

void AIwindow::settxt_ai(int userscore, int aiscore, int remainingline)
{
    aislogic.setremainingline(remainingline);
    scoretxt.setText("你的分数："+QString::number(userscore)+"\t电脑分数："+QString::number(aiscore));
    scoretxt.setStyleSheet("font:bold 28px 等线");
    remaininglinestxt.setText("\t剩余划线数："+QString::number(remainingline));
    remaininglinestxt.setStyleSheet("font:bold 28px 等线");
}

void AIwindow::aioperate()    //电脑AI操作
{
    for (int i=0;i<column;i++)
        for (int j=0;j<row;j++)
            search(i,j,0);

    array_final[max] = -1;

    timer = new QTimer(this);
    timer->setInterval(300);
    connect(timer,SIGNAL(timeout()),this,SLOT(action()));
    timer->start();
}

void AIwindow::action()
{
    if (array_final[counter] >= 0)
    {
        Basicfruit *fr = ologic.getfr(array_final[counter]);
        counter++;
        ologic.setfrtype(fr->gettype());
        ologic.setifpress(true);
        ologic.mousemove(fr->getpos());
    }
    else
    {
        timer->stop();
        ologic.mouserelease();
        ologic.operationforbid = false;
        clear();
    }
}

void AIwindow::postresult(bool ifpass, int userscore, int aiscore)
{
    ologic.replay_operation.close();
    replay_map.close();

    Resultwindow *resultw = new Resultwindow(ifpass,userscore,aiscore,2*userscore-aiscore);
    /* 调出结果界面 并对所有按钮设置信号 */
    connect(&(resultw->returntomain),SIGNAL(clicked(bool)),this,SLOT(returntomain()));
    connect(&(resultw->returntomain),SIGNAL(clicked(bool)),resultw,SLOT(close()));
    resultw->show();
    close();
}
