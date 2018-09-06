#ifndef _PREY_H_
#define _PREY_H_

#include "Coral.h"

class Cell;

class Prey : public Coral
{
	static char name;
	static unsigned int count;

public:
	Prey(Cell* theCell = nullptr);
	~Prey();
	void live();
	virtual char getName();
	static unsigned int getCount();

protected:
    virtual Object* generateObject(Cell* theCell);
	bool AllIsBusy(std::vector<Pair> thePairs);
	void move();
    virtual bool reproduction();
	virtual bool TryLive();

protected:
	int liveTime;
};

#endif //_PREY_H_
