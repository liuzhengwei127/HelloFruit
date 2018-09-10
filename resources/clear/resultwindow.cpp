#include "resultwindow.h"
#include "replaywindow.h"

Resultwindow::Resultwindow(bool ifpass, int scores, int level)
{
    resize(540,300);     // 结果窗口格式设置

    result.setParent(this);
    result.resize(this->size());
    result.setAlignment(Qt::AlignCenter);
    result.setStyleSheet("font:bold 28px 等线");

    replaybutton.setParent(this);
    replaybutton.setGeometry(0,0,200,40);
    replaybutton.setText("观看回放");
    replaybutton.setStyleSheet("font:25px 等线");
    connect(&replaybutton,SIGNAL(clicked(bool)),this,SLOT(replay()));

    returntomain.setParent(this);
    returntomain.setGeometry(0,250,180,50);
    returntomain.setText("返回主界面");
    returntomain.setStyleSheet("font:20px 微软雅黑");

    tryagain.setParent(this);
    tryagain.setGeometry(180,250,180,50);
    tryagain.setText("重新开始");
    tryagain.setStyleSheet("font:20px 微软雅黑");

    nextlevel.setParent(this);
    nextlevel.setGeometry(360,250,180,50);
    nextlevel.setText("下一关");
    nextlevel.setStyleSheet("font:20px 微软雅黑");

    if(ifpass)     //根据传入参数判断结果并给出相应结果界面
    {
        if(level != 2)
        {
            result.setText("恭喜你过关了！\n此关你的得分是："+QString::number(scores));
            tryagain.close();
        }
        else
        {
            result.setText("恭喜你通关了！\n此关你的得分是："+QString::number(scores));
            tryagain.close();
            nextlevel.close();
        }

    }
    else
    {
        result.setText("你倒在了这一关！\n你的得分是："+QString::number(scores));
        nextlevel.close();
    }
}

Resultwindow::Resultwindow(bool ifpass, int userscore, int aiscore, int total)
{
    r = new Rankwindow(ifpass,total);
    resize(540,300);

    result.setParent(this);
    result.resize(this->size());
    result.setAlignment(Qt::AlignCenter);
    result.setStyleSheet("font:bold 28px 等线");

    returntomain.setParent(this);
    returntomain.setGeometry(180,250,180,50);
    returntomain.setText("返回主界面");
    returntomain.setStyleSheet("font:20px 微软雅黑");

    QPushButton *inquirebutton = new QPushButton("查看排名",this);
    connect(inquirebutton,SIGNAL(clicked(bool)),this,SLOT(inquire()));

    if(ifpass)     //根据传入参数判断结果并给出相应结果界面
    {
        result.setText("你击败了电脑！\n"
                       "你的得分是:"+QString::number(userscore)+"\t"
                       "电脑得分是:"+QString::number(aiscore)+"\n"
                       "综合得分是:"+QString::number(total));
        tryagain.close();
    }
    else
    {
        result.setText("你输给了电脑！\n"
                       "你的得分是:"+QString::number(userscore)+"\n"
                       "电脑得分是:"+QString::number(aiscore));
        nextlevel.close();
    }
}

void Resultwindow::replay()
{
    Replaywindow *r = new Replaywindow();
    r->show();
    r->begin();
}

void Resultwindow::inquire()
{
    r->show();
}
