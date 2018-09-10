#ifndef EASY_H
#define EASY_H

#include "levelwindow.h"

class Easy : public Levelwindow
{
    Q_OBJECT
public:
    /* 构造函数 */
    Easy();
    Easy(QFile *file);
};

#endif // EASY_H
