#include "savewindow.h"

Savewindow::Savewindow()
{
    resize(540,300);

    QPushButton *close = new QPushButton("确定",this);
    close->setStyleSheet("font:30px 微软雅黑");
    close->setGeometry(170,230,200,50);

    QLabel *notice = new QLabel("存档成功",this);
    notice->setStyleSheet("font:bold 50px 等线");
    notice->resize(this->size().width(),230);
    notice->setAlignment(Qt::AlignCenter);

    connect(close,SIGNAL(clicked(bool)),this,SLOT(close()));
}
