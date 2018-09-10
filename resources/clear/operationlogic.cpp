#include "operationlogic.h"
#include <QDebug>
#include <QTimer>
#include <QThread>

Operationlogic::Operationlogic()
{    
    reset(); //重置判断数据
    replay_operation.setFileName("replay_operation.txt");
    replay_operation.open(QIODevice::ReadWrite);

    boom.setMedia(QUrl::fromLocalFile("../resources/boom.mp3"));
    boom.setVolume(80);
    for (int i=0;i<4;i++)
    {
        selected[i].setMedia(QUrl::fromLocalFile("../resources/selected.mp3"));
        selected[i].setVolume(60);
    }
}

/* 重置判断数据 */
void Operationlogic::reset()
{
    ifpress = false;
    formerfr = NULL;
    frtype = -1;
    length = 0;
}

void Operationlogic::setfrtype(int type)
{
    frtype = type;
}

Basicfruit *&Operationlogic::getfr(int i, int j)
{
    return fr[i+j*column];
}

Basicfruit *&Operationlogic::getfr(int seq)
{
    return fr[seq];
}

bool Operationlogic::ifpvalid(Basicfruit *fr)    //判断当前水果是否是有效操作内的相同类型水果
{
    if (fr->gettype() == frtype && fr != formerfr && fr->gettype() != 4)
    {
        if (formerfr == NULL)
            return true;
        else
        {
            if(square(fr->pos(),formerfr->pos())<=16200)
                return true;
            else
                return false;
        }
    }
    else
        return false;
}

int Operationlogic::square(QPoint a, QPoint b)
{
    return (a.x()-b.x())*(a.x()-b.x())+(a.y()-b.y())*(a.y()-b.y());
}

void Operationlogic::mousemove(QPoint p)
{
    if (ifpress && !animation)     //如果鼠标处于点击状态则进入鼠标移动的事件处理
    {
        int seqnum = getseqnum(p);    //获得当前鼠标所在点水果的行列数和

        if(seqnum>=0 && ifpvalid(fr[seqnum]))   //判断是否是有效水果
        {
            if ((formerfr == NULL) || ((fr[seqnum]) != formerfr->formerfr))
            {
                if (!fr[seqnum]->getifselected())
                {
                    add(seqnum);   //如果有效则长度加1
                    selected[(musiccounter++)%4].play();
                }
            }
            else
            {
                subtract(seqnum);   //如果是上一个水果则判定为是取消操作，长度减1
                selected[(musiccounter++)%4].play();
            }
        }
    }
}

void Operationlogic::mouserelease()  //处理鼠标松开的事件
{
    if (!replay)
        replay_operation.write((QString::number(-1)+"\n").toLatin1());


    if (length >= 8)               //一条线超过八个时的奖励机制
        for (int i=0;i<column;i++)
            if (fr[i+formerfr->getj()*column] && !fr[i+formerfr->getj()*column]->getifselected() && fr[i+formerfr->getj()*column]->gettype() != 4)
            {
            fr[i+formerfr->getj()*column]->setifselected(true);
            length++;
            }

    if (length >=3)
    {
        for (int i=0;i<column;i++)
            for (int j=0;j<row;j++)
                if (fr[i+j*column] && fr[i+j*column]->getifselected() && fr[i+j*column]->gettype() != 4)
                    fr[i+j*column]->changeto(2);

        QTimer::singleShot(60,this,SLOT(animation_begin()));
        emit successful_operation(length);
    }
    else
        cancle();  //消除之前在水果上设置的数据

    reset();    //数据重置
}

void Operationlogic::mousepress(int type)
{
    if (!replay && !operationforbid)
    {
        frtype = type;
        ifpress = true;
    }

}

void Operationlogic::animation_end()
{
    animation = false;
}

void Operationlogic::skill_repaint()
{
    if(!replay)
        replay_operation.write((QString::number(-2)+"\n").toLatin1());

    int columnclearnum[12] = {0};

    for (int i=0;i<column;i++)
    {
        columnclearnum[i] = row;
        for (int j=0;j<row;j++)
        {
            if (fr[i+j*column])
            {
                fr[i+j*column]->setifselected(true);
                fr[i+j*column]->changeto(1);
                length++;
            }
        }
    }

    QParallelAnimationGroup* anig = new QParallelAnimationGroup(this);  //如果总选中水果数大于3则设置动画

    connect(anig,SIGNAL(finished()),this,SLOT(animation_end()));
    addanimationgruop(anig,columnclearnum);
    anig->start();    //动画开始
    animation = true;

    reset();
}

void Operationlogic::skill_incscore()
{
    if(!replay)
        replay_operation.write((QString::number(-3)+"\n").toLatin1());
}

void Operationlogic::animation_begin()
{
    int columnclearnum[12] = {0};   //此变量用于后面动画的设计

    for (int i=0;i<column;i++)     //记录每列消去的水果数
        for (int j=row-1;j>=0;j--)
        {
            if (fr[i+j*column])
            {
                if (fr[i+j*column]->getifselected())
                    columnclearnum[i]++;
                if (fr[i+j*column]->gettype() == 4)
                {
                    columnclearnum[i] = 0;
                }
            }
        }

    QParallelAnimationGroup* anig = new QParallelAnimationGroup(this);  //如果总选中水果数大于3则设置动画
    connect(anig,SIGNAL(finished()),this,SLOT(animation_end()));

    addanimationgruop(anig,columnclearnum);
    anig->start();    //动画开始
    boom.play();
    animation = true;
}

int Operationlogic::getseqnum(QPoint p)
{
    for (int i = 0; i < column; i++)
        for (int j = 0; j < row; j++)
            if(fr[i+j*column] && fr[i+j*column]->geometry().contains(p))
                return (i+j*column);

    return -1;
}

void Operationlogic::add(int seqnum)
{
    if(!replay)
        replay_operation.write((QString::number(seqnum)+"\n").toLatin1());
    fr[seqnum]->setifselected(true);
    fr[seqnum]->changeto(1);
    length++;
    if (length >= 8)
    {
        if (length >= 9)
            for (int i=0;i<column;i++)
            {
                int seq = i+formerfr->getj()*column;
                if (fr[seq] && !fr[seq]->getifselected())
                    fr[seq]->changeto(0);
            }

        for (int i=0;i<column;i++)
        {
            int seq = i+(seqnum/column)*column;
            if (fr[seq] && !fr[seq]->getifselected()  && fr[seq]->gettype() != 4)
                fr[seq]->changeto(3);
        }
    }

    fr[seqnum]->formerfr = formerfr;
    formerfr = fr[seqnum];
}

void Operationlogic::subtract(int seqnum)
{
    if(!replay)
        replay_operation.write((QString::number(seqnum)+"\n").toLatin1());
    length--;
    formerfr->setifselected(false);
    formerfr->changeto(0);
    if (length >= 7)
    {
        for (int i=0;i<column;i++)
        {
            int seq = i+formerfr->getj()*column;
            if (fr[seq] && !fr[seq]->getifselected())
                fr[seq]->changeto(0);
        }
        if (length >= 8)
            for (int i=0;i<column;i++)
            {
                int seq = i+(seqnum/column)*column;
                if (fr[seq] && !fr[seq]->getifselected() && fr[seq]->gettype() != 4)
                    fr[seq]->changeto(3);
            }
    }
    formerfr->formerfr = NULL;
    formerfr = fr[seqnum];
}

void Operationlogic::cancle()
{
    for (int i=0;i<column;i++)
        for (int j=0;j<row;j++)
        {
            if(fr[i+j*column] && fr[i+j*column]->getifselected())
            {
                fr[i+j*column]->setifselected(false);
                fr[i+j*column]->formerfr = NULL;
                fr[i+j*column]->changeto(0);
            }
        }
}

void Operationlogic::setcr(int i, int j)
{
    column = i;
    row = j;
}

void Operationlogic::setreplay()
{
    replay = true;
}

void Operationlogic::setifpress(bool p)
{
    ifpress = p;
}

void Operationlogic::addanimationgruop(QAnimationGroup *anig, int *columnclearnum)
{
    for (int i=0; i<column; i++)     //设置已存在水果的动画
    {
        int length = 0;
        for (int j=row - 1; j>=0; j--)
        {
            if (fr[i+j*column])
            {
                if(fr[i+j*column]->getifselected() && fr[i+j*column]->gettype() != 4)
                {
                    length++;
                    fr[i+j*column]->setifselected(false);
                    fr[i+j*column]->close();
                }
                else
                {
                    if (fr[i+j*column]->gettype() == 4)
                    {
                        length = 0;
                    }

                    if(length)
                    {
                        QPropertyAnimation* ani = new QPropertyAnimation(fr[i+j*column],"geometry");
                        QPoint p;
                        p.setX(fr[i+j*column]->pos().x());
                        p.setY(fr[i+j*column]->pos().y() + 90*length);
                        ani->setDuration(300*length);
                        ani->setStartValue(QRect(fr[i+j*column]->pos(),Basicfruit::size));
                        ani->setEndValue(QRect(p,Basicfruit::size));
                        anig->addAnimation(ani);
                        fr[i+(j+length)*column] = fr[i+j*column];
                        fr[i+(j+length)*column]->setj(j+length);
                        fr[i+j*column] = NULL;
                    }
                }
            }
        }
    }

    for (int i=0;i<column;i++)   //设置新生成水果的动画
    {
        for (int j=0;j<columnclearnum[i];j++)
        {
            if (!fr[i+j*column] || fr[i+j*column]->gettype() != 4)
            {
                emit generate(i,j);
                QPropertyAnimation* ani = new QPropertyAnimation(fr[i+j*column],"geometry");
                QPoint p;
                p.setX(fr[i+j*column]->pos().x());
                p.setY(0);
                fr[i+j*column]->show();
                ani->setDuration(300*j+800);
                ani->setStartValue(QRect(p,Basicfruit::size));
                ani->setEndValue(QRect(fr[i+j*column]->pos(),Basicfruit::size));
                anig->addAnimation(ani);
            }
        }
    }
}
