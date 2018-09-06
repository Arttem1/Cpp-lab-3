#ifndef _OCEAN_H_
#define _OCEAN_H_

#include "common.h"
#include <list>

class Cell;
class Object;

class Ocean
{
	
private:
	Cell** cells;
	std::list<Object*> stuff;

public:
	Ocean();
	~Ocean();
	void print() const;
	void addObjects(int);
	void addObject(Object* theObject);
	void deleteObject(Object*);
    Cell* getCell(Pair theCoord);
	void run();
};


#endif
