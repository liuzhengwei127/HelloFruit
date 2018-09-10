#include "aiscorelogic.h"

AIscorelogic::AIscorelogic()
{    
}

int AIscorelogic::computescore(int length)
{
    int addscore = 0;      //根据特定算法得出当前一次操作的得分
    int base = 100;

    while (length > 5)
    {
        addscore += 5*base;
        base += 100;
        length -= 5;
    }

    addscore += length*base;

    return addscore;
}

void AIscorelogic::setremainingline(int remain)
{
    remainingline = remain;
}

void AIscorelogic::update(int length)
{
    if (userturn)
    {
        userscore += computescore(length);
    }
    else
        aiscore += computescore(length);

    remainingline--;
    userturn = !userturn;

    emit settxt_ai(userscore,aiscore,remainingline);

    if(!remainingline)
    {
        if(userscore>=aiscore)
            emit end(true,userscore,aiscore);
        else
            emit end(false,userscore,aiscore);
    }
}
