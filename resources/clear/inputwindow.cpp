#include "inputwindow.h"

Inputwindow::Inputwindow()
{
    resize(400,200);

    input_username.setParent(this);
    input_username.setGeometry(100,70,200,30);
    connect(&input_username,SIGNAL(returnPressed()),this,SLOT(post_name()));
    connect(&input_username,SIGNAL(returnPressed()),this,SLOT(deleteLater()));

    information.setParent(this);
    information.setGeometry(0,0,400,80);
    information.setStyleSheet("font:20px 等线");
    information.setText("请输入您用于上传成绩的用户名\n"
                        "按回车确定");
    information.setAlignment(Qt::AlignCenter);
}

void Inputwindow::post_name()
{
     emit name(input_username.text());
}
