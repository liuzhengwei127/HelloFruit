#ifndef WINDOW_H
#define WINDOW_H

#include <QPushButton>
#include <QLabel>
#include <QGridLayout>
#include <QMediaPlaylist>
#include <QMediaPlayer>
#include <QLineEdit>

class Window : public QWidget
{
    Q_OBJECT
protected:
    /* 构造函数 */
    explicit Window(QWidget *parent = nullptr);

private:
    /* 设置背景图片 */
    void setbackground();
};

#endif // WINDOW_H
