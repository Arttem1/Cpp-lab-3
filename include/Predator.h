#ifndef _PREDATOR_H_
#define _PREDATOR_H_

#include "Prey.h"

class Cell;

class Predator : public Prey
{
    static char name;
    static unsigned int count;
public:
    Predator(Cell* theCell = nullptr);
    ~Predator();
    virtual void live();
    virtual char getName();
    static unsigned int getCount();
protected:
    virtual Object* generateObject(Cell* theCell);
    virtual bool TryLive();
    virtual bool TryEat();

protected:
    int golodTime;
};

#endif //_PREDATOR_H_
