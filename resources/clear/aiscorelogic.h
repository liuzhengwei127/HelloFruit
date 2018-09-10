#ifndef AISCORELOGIC_H
#define AISCORELOGIC_H

#include <QObject>

class AIscorelogic : public QObject
{
    Q_OBJECT
public:
    bool userturn = true;

    AIscorelogic();
    void setremainingline(int remain);

private:
    int aiscore = 0;
    int userscore = 0;
    int remainingline;    

    int computescore(int length);


signals:
    void settxt_ai(int userscore, int aiscore, int remainingline);
    void aiturn();
    void end(bool,int,int);

public slots:
    void update(int length);
};

#endif // AISCORELOGIC_H
