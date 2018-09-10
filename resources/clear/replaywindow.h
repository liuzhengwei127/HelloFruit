#ifndef REPLAYWINDOW_H
#define REPLAYWINDOW_H

#include "levelwindow.h"

class Replaywindow : public Levelwindow
{
    Q_OBJECT
public:
    Replaywindow();

    void begin();

private:
    int counter_map;
    int counter_operation;
    int timeinterval;
    QTimer *timer;
    QVector<int> array_map;
    QVector<int> array_operation;

    void generatefruit(int i, int j, int type);
    void skillclose();
    void draw();

private slots:
    void mousemove();
    void mouserelease();
    void timerstart();
    void postresult(bool ifpass, int scores);
    void nextaction();
    void skillrepaint();
    void skillincscore();
};

#endif // REPLAYWINDOW_H
