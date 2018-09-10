#include "hell.h"

Hell::Hell()
{
    draw();
    level = 2;
    setfr(7,7,4);
    setstandard(30000,9);    
    paintfruit();
}

Hell::Hell(QFile *file) : Levelwindow(file)
{
}

void Hell::paintfruit()
{
    int ibarrier = qrand()%typenumber;
    int jbarrier = qrand()%typenumber;

    for (int i=0;i<column;i++)
        for (int j=0;j<row;j++)
        {
            if (i == ibarrier && j == jbarrier)
                generatefruit(i,j,4);
            else
                generatefruit(i,j,qrand()%typenumber);
        }
}
