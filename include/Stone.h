#ifndef _STONE_H_
#define _STONE_H_

#include "Object.h"

class Cell;

class Stone : public Object
{
	int liveTime;
	static char name;
	static unsigned int count;
public:
	Stone(Cell* theCell = nullptr);
	~Stone();
	void live();
	virtual char getName();
	static unsigned int getCount();
};

#endif