#ifndef HELL_H
#define HELL_H

#include "levelwindow.h"

class Hell : public Levelwindow
{
public:
    /* 构造函数 */
    Hell();
    Hell(QFile *file);

private:
    void paintfruit();
};

#endif // HELL_H
