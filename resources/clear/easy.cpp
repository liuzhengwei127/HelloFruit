#include "easy.h"
#include <QTextStream>
#include <QDebug>

/* 地图初始化 */
Easy::Easy()
{
    draw();
    level = 0;
    setfr(5,5,3);
    setstandard(12000,7);    
    paintfruit();

}

Easy::Easy(QFile *file) : Levelwindow(file)
{
}
