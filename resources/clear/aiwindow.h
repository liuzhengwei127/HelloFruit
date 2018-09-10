#ifndef AIWINDOW_H
#define AIWINDOW_H

#include "gamewindow.h"
#include "aiscorelogic.h"

class AIwindow : public Gamewindow
{
    Q_OBJECT
public:
    AIscorelogic aislogic;

    AIwindow();

private:
    QVector<int> array_record;
    QVector<int> array_final;
    QVector<bool> array_ifselected;
    int max = 0;
    int counter = 0;
    QTimer *timer;

    void draw();
    void initialize();
    void search(int i,int j,int l);
    void mouseReleaseEvent(QMouseEvent *event);
    void clear();
    int compute(int j,int length);

private slots:
    void settxt_ai(int userscore, int aiscore, int remainingline);
    void aioperate();
    void action();
    void postresult(bool,int,int);
};

#endif // AIWINDOW_H
