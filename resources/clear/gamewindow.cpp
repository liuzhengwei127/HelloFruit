#include "Gamewindow.h"

void Gamewindow::mouseMoveEvent(QMouseEvent *event)
{
    if (!replay && !ologic.operationforbid)
        ologic.mousemove(event->pos());
}

void Gamewindow::mouseReleaseEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton && !replay && !ologic.operationforbid)
        ologic.mouserelease();
}

Gamewindow::Gamewindow()
{    
    setMouseTracking(true);
    qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));
    connect(&ologic,SIGNAL(generate(int,int)),this,SLOT(generate(int,int)));
    replay_map.setFileName("replay_map.txt");
    replay_map.open(QIODevice::ReadWrite);
}

void Gamewindow::generate(int i, int j)
{
    generatefruit(i,j,qrand()%typenumber);
}

void Gamewindow::returntomain()
{
    emit signal_returntomain(this);
}

void Gamewindow::paintfruit()
{
    for (int i=0;i<column;i++)
        for (int j=0;j<row;j++)
            generatefruit(i,j,qrand()%typenumber);
}

void Gamewindow::generatefruit(int i, int j,int type)
{
    if(!replay)
        replay_map.write((QString::number(type)+"\n").toLatin1());

    ologic.getfr(i,j) = new Basicfruit(type,i,j);   //通过随机数绘制水果阵

    int x = (this->size().width()-90*column)/2;
    int y = (this->size().height()-90*row)/2;
    ologic.getfr(i,j)->setGeometry(i*90+x,
                                   j*90+y,
                                   Basicfruit::size.width(),
                                   Basicfruit::size.height());

    ologic.getfr(i,j)->setParent(this);    //鼠标点击事件的传递
    connect(ologic.getfr(i,j),
            SIGNAL(mousepress(int)),
            &ologic,
            SLOT(mousepress(int)));
}

void Gamewindow::setfr(int c, int r, int n)
{
    column = c;
    row = r;
    typenumber = n;
    ologic.setcr(c,r);
    if(!replay)
    {
        replay_map.write((QString::number(c)+"\n").toLatin1());
        replay_map.write((QString::number(r)+"\n").toLatin1());
        replay_map.write((QString::number(n)+"\n").toLatin1());
    }

}

void Gamewindow::paintscore()
{
    scoretxt.setGeometry(400,20,600,50);    //分数显示格式设置
    scoretxt.setAlignment(Qt::AlignLeft);
    scoretxt.setParent(this);

    remaininglinestxt.setGeometry(0,20,400,50);
    remaininglinestxt.setAlignment(Qt::AlignLeft);
    remaininglinestxt.setParent(this);
}
