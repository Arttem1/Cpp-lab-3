#ifndef _CORAL_H_
#define _CORAL_H_

#include "Object.h"
#include "common.h"

class Cell;

class Coral : public Object
{

	static char name;
	static unsigned int count;

public:
	Coral(Cell * = nullptr);
	~Coral();
	void live();
	static unsigned int getCount();
	virtual char getName();

protected:
	bool TryReproduction(Pair thePair);
	virtual bool reproduction();
    virtual Object* generateObject(Cell* theCell);

protected:
	int reproductionTime;
	bool myStepDone;
};

#endif
