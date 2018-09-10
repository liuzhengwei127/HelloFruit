#ifndef DIFFICULT_H
#define DIFFICULT_H

#include "levelwindow.h"

class Difficult : public Levelwindow
{
    Q_OBJECT
public:
    /* 构造函数 */
    Difficult();
    Difficult(QFile *file);
};

#endif // DIFFICULT_H
