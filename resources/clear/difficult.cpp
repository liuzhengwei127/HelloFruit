#include "difficult.h"

/* 地图初始化 */
Difficult::Difficult()
{
    draw();
    level = 1;
    setfr(6,6,4);
    setstandard(15000,7);
    paintfruit();
}

Difficult::Difficult(QFile *file) : Levelwindow(file)
{
}
