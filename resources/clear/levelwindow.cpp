#include "levelwindow.h"

Levelwindow::Levelwindow()
{
    connect(&ologic,SIGNAL(successful_operation(int)),&levelslogic,SLOT(update(int)));
    connect(&levelslogic,SIGNAL(end(bool,int)),this,SLOT(postresult(bool,int)));
    connect(&levelslogic,SIGNAL(settxt(int,int,int)),this,SLOT(settxt(int,int,int)));
}

Levelwindow::Levelwindow(QFile *file)
{
    connect(&ologic,SIGNAL(successful_operation(int)),&levelslogic,SLOT(update(int)));
    connect(&levelslogic,SIGNAL(end(bool,int)),this,SLOT(postresult(bool,int)));
    connect(&levelslogic,SIGNAL(settxt(int,int,int)),this,SLOT(settxt(int,int,int)));
    draw();

    QVector<int> array;
    QTextStream s(file);

    while(!s.atEnd())
    {
        int buf;
        s>>buf;
        array.append(buf);
    }

    level = array[0];
    levelslogic.setscore(array[1]);
    setfr(array[2],array[3],array[4]);
    setstandard(array[5],array[6],array[1]);

    if (!array[7])
    {
        skill_repaintbutton->close();
        skill_incscorebutton->close();
    }
    for (int i=0;i<column;i++)
        for (int j=0;j<row;j++)
            generatefruit(i,j,array[i+j*row+8]);
}

void Levelwindow::save()
{
    QFile file("save.txt");

    if(file.open(QIODevice::WriteOnly))
    {
        file.write((QString::number(level)+"\n").toLatin1());
        file.write((QString::number(level)+"\n").toLatin1());
        file.write((QString::number(levelslogic.getscore())+"\n").toLatin1());
        file.write((QString::number(column)+"\n").toLatin1());
        file.write((QString::number(row)+"\n").toLatin1());
        file.write((QString::number(typenumber)+"\n").toLatin1());
        file.write((QString::number(levelslogic.gettarget())+"\n").toLatin1());
        file.write((QString::number(levelslogic.getremainingline())+"\n").toLatin1());
        file.write((QString::number(skill1)+"\n").toLatin1());
        for (int j=0;j<row;j++)
            for (int i=0;i<column;i++)
                file.write((QString::number(ologic.getfr(i,j)->gettype())+"\n").toLatin1());
    }

    file.close();

    Savewindow *s = new Savewindow();
    s->show();
}

void Levelwindow::skillclose()
{
    skill_repaintbutton->deleteLater();
    skill_incscorebutton->deleteLater();
}

void Levelwindow::tryagain()
{
    emit signal_tryagain(this);
}

void Levelwindow::nextlevel()
{
    emit signal_nextlevel(this,level);
}

void Levelwindow::setstandard(int targets, int remaininglines, int score)
{
    levelslogic.setstandard(targets, remaininglines,score);
    if(!replay)
    {
        replay_map.write((QString::number(targets)+"\n").toLatin1());
        replay_map.write((QString::number(remaininglines)+"\n").toLatin1());
        replay_map.write((QString::number(score)+"\n").toLatin1());
    }
}

void Levelwindow::draw()
{
    paintscore();
    paintskill();

    QPushButton *savebutton = new QPushButton("存档",this);
    savebutton->setGeometry(700,710,250,40);
    savebutton->setStyleSheet("font:25px 微软雅黑");
    connect(savebutton,SIGNAL(clicked(bool)),this,SLOT(save()));

    QPushButton *returnbutton = new QPushButton("返回主界面",this);
    returnbutton->setGeometry(700,750,250,40);
    returnbutton->setStyleSheet("font:25px 微软雅黑");
    connect(returnbutton,SIGNAL(clicked(bool)),this,SLOT(returntomain()));

    connect(skill_repaintbutton,SIGNAL(clicked(bool)),&ologic,SLOT(skill_repaint()));
    connect(skill_repaintbutton,SIGNAL(clicked(bool)),this,SLOT(skillclose()));
    connect(skill_incscorebutton,SIGNAL(clicked(bool)),&levelslogic,SLOT(skill_incscore()));
    connect(skill_incscorebutton,SIGNAL(clicked(bool)),this,SLOT(skillclose()));
    connect(skill_incscorebutton,SIGNAL(clicked(bool)),&ologic,SLOT(skill_incscore()));
}

void Levelwindow::paintskill()
{
    QLabel *skill = new QLabel("技能",this);
    skill->setGeometry(0,250,150,50);
    skill->setStyleSheet("font:bold 35px 微软雅黑");
    skill->setAlignment(Qt::AlignCenter);

    skill_repaintbutton = new QPushButton("重新出图",this);
    skill_repaintbutton->setGeometry(0,300,150,50);
    skill_repaintbutton->setStyleSheet("font:20px 微软雅黑");

    skill_incscorebutton = new QPushButton("分数提升",this);
    skill_incscorebutton->setGeometry(0,380,150,50);
    skill_incscorebutton->setStyleSheet("font:20px 微软雅黑");

    connect(this,SIGNAL(skillused()),skill_incscorebutton,SLOT(close()));
    connect(this,SIGNAL(skillused()),skill_repaintbutton,SLOT(close()));
}

void Levelwindow::settxt(int score, int target, int remainingline)  //刷新分数
{
    scoretxt.setText("现在的分数："+QString::number(score)+"\t目标分数："+QString::number(target));
    scoretxt.setStyleSheet("font:bold 28px 等线");
    remaininglinestxt.setText("\t剩余划线数："+QString::number(remainingline));
    remaininglinestxt.setStyleSheet("font:bold 28px 等线");
}

void Levelwindow::postresult(bool ifpass,int scores)
{
    ologic.replay_operation.close();
    replay_map.close();

    Resultwindow *resultw = new Resultwindow(ifpass,scores,level);
    /* 调出结果界面 并对所有按钮设置信号 */
    connect(&(resultw->returntomain),SIGNAL(clicked(bool)),this,SLOT(returntomain()));
    connect(&(resultw->returntomain),SIGNAL(clicked(bool)),resultw,SLOT(close()));
    connect(&(resultw->tryagain),SIGNAL(clicked(bool)),this,SLOT(tryagain()));
    connect(&(resultw->tryagain),SIGNAL(clicked(bool)),resultw,SLOT(close()));
    connect(&(resultw->nextlevel),SIGNAL(clicked(bool)),this,SLOT(nextlevel()));
    connect(&(resultw->nextlevel),SIGNAL(clicked(bool)),resultw,SLOT(close()));
    resultw->show();
    close();
}
