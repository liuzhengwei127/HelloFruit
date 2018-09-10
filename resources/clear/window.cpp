#include "window.h"

Window::Window(QWidget *parent) : QWidget(parent)
{
    resize(1000,800);          //基本格式设置
    setbackground();
    setWindowTitle("你好，水果");
}

void Window::setbackground()     //背景设置
{
    QPalette palette = this->palette();
    palette.setBrush(QPalette::Window,
            QBrush(QPixmap("../resources/background.jpg").scaled(
                this->size(),
                Qt::IgnoreAspectRatio,
                Qt::SmoothTransformation)));
    this->setPalette(palette);
}
