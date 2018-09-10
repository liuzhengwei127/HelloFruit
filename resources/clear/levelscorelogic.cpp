#include "levelscorelogic.h"

Levelscorelogic::Levelscorelogic()
{
}

void Levelscorelogic::setstandard(int targets, int remaininglines,int s)
{
    target = targets;
    remainingline = remaininglines;
    score = s;
    emit settxt(s,target,remainingline);
}

void Levelscorelogic::setscore(int scores)
{
    score = scores;
}

int Levelscorelogic::getscore()
{
    return score;
}

int Levelscorelogic::getremainingline()
{
    return remainingline;
}

int Levelscorelogic::gettarget()
{
    return target;
}

int Levelscorelogic::computescore(int length)
{
    int addscore = 0;      //根据特定算法得出当前一次操作的得分

    while (length > 5)
    {
        addscore += 5*base;
        base += 100;
        length -= 5;
    }

    addscore += length*base;
    base = 100;

    return addscore;
}

void Levelscorelogic::update(int length)
{
    score += computescore(length);    //更新当前数据（分数）
    remainingline--;
    emit settxt(score,target,remainingline);

    if(!remainingline || score>=target)
    {
        if(score>=target)
            emit end(true,score);
        else
            emit end(false,score);
    }
}

void Levelscorelogic::skill_incscore()
{
    base = 200;
}

