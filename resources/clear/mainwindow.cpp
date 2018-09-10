#include "mainwindow.h"
#include <QFile>
#include <QDebug>

Mainwindow::Mainwindow()
{
    draw();//绘制主界面    

    QMediaPlaylist *playlist = new QMediaPlaylist();
    playlist->setPlaybackMode(QMediaPlaylist::Loop);
    playlist->addMedia(QUrl::fromLocalFile("../resources/bgm1.mp3"));
    playlist->addMedia(QUrl::fromLocalFile("../resources/bgm2.mp3"));
    playlist->addMedia(QUrl::fromLocalFile("../resources/bgm3.mp3"));
    playlist->setCurrentIndex(1);

    QMediaPlayer *player = new QMediaPlayer;
    player->setPlaylist(playlist);
    player->setVolume(30);
    player->play();

//    connect(player,SIGNAL(stateChanged(QMediaPlayer::State)),this,SLOT(playmusic()));
}


void Mainwindow::draw()  //主界面格式设置
{
    QGridLayout* layout= new QGridLayout(this);
    QPushButton* beginbutton = new QPushButton("闯关模式");
    QPushButton* endbutton = new QPushButton("退出游戏");
    QPushButton* continuebutton = new QPushButton("读取存档");
    QPushButton* aibutton = new QPushButton("对战模式");
    QLabel* clear = new QLabel("你好，水果");

    beginbutton->setStyleSheet("font:30px 微软雅黑");
    continuebutton->setStyleSheet("font:30px 微软雅黑");
    endbutton->setStyleSheet("font:30px 微软雅黑");
    aibutton->setStyleSheet("font:30px 微软雅黑");
    clear->setStyleSheet("font:bold 80px 微软雅黑");

    connect(endbutton,SIGNAL(clicked()),this,SLOT(close()));
    connect(beginbutton,SIGNAL(clicked()),this,SLOT(gamebegin()));
    connect(continuebutton,SIGNAL(clicked(bool)),this,SLOT(continuegame()));
    connect(aibutton,SIGNAL(clicked(bool)),this,SLOT(aigamebegin()));

    layout->addWidget(clear,0,1);
    layout->addWidget(beginbutton,1,1);
    layout->addWidget(continuebutton,2,1);
    layout->addWidget(aibutton,3,1);
    layout->addWidget(endbutton,4,1);
    layout->setColumnStretch(0,1);
    layout->setColumnStretch(2,1);
    layout->setRowStretch(0,2);
    layout->setRowStretch(2,1);
    layout->setRowStretch(4,2);
}

void Mainwindow::link(Gamewindow *w)   //连通各种信号
{
    connect(w,SIGNAL(signal_returntomain(Gamewindow*)),this,SLOT(closegamew(Gamewindow*)));
    connect(w,SIGNAL(signal_tryagain(Gamewindow*)),this,SLOT(gamerestart(Gamewindow*)));
    connect(w,SIGNAL(signal_nextlevel(Gamewindow*,int)),this,SLOT(nextlevel(Gamewindow*,int)));
    w->show();
}

void Mainwindow::gamebegin()
{
    Easy *e = new Easy();
    this->hide();
    link(e);
}

void Mainwindow::gamerestart(Gamewindow *w)
{
    w->deleteLater();
    Easy *e = new Easy();
    link(e);
}

void Mainwindow::closegamew(Gamewindow *d)
{
    d->deleteLater();
    this->show();
}

void Mainwindow::nextlevel(Gamewindow *w, int level)
{
    w->deleteLater();
    switch (level) {    //根据上一次的难度 调出下一难度的关卡地图
    case 0:
    {
        Difficult *d = new Difficult();
        link(d);
        break;
    }
    case 1:
    {
        Hell *h = new Hell();
        link(h);
        break;
    }
    }
}

void Mainwindow::continuegame()
{
    QFile file("save.txt");

    if(file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        switch(file.read(1).toInt())
        {
        case 0:
        {
            this->hide();
            Easy *e = new Easy(&file);
            link(e);
            break;
        }
        case 1:
        {
            this->hide();
            Difficult *d = new Difficult(&file);
            link(d);
            break;
        }
        case 2:
        {
            this->hide();
            Hell *h = new Hell(&file);
            link(h);
            break;
        }
        }
    }

    file.close();
}

void Mainwindow::playmusic()
{
//    player->play();
}

void Mainwindow::aigamebegin()
{
    AIwindow *a = new AIwindow();
    this->hide();
    connect(a,SIGNAL(signal_returntomain(Gamewindow*)),this,SLOT(closegamew(Gamewindow*)));
    a->show();
}

int main(int argc, char** argv)
{
    QApplication app(argc,argv);

    Mainwindow w;
    w.show();

    return app.exec();
}
