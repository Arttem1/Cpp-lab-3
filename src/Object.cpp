#include "Object.h"
#include "Cell.h"
#include <cstdlib>

unsigned int Object::count = 0;
char		 Object::name = '.';

unsigned int Object::getCount()
{
	return count;
}


Object::Object(Cell * c) :cell(c)
{
	//cell->setObject(this);
	//cell = c;
	//name = rand() % ('Z' - 'A' + 1) + 'A';
	count++;
}
Object::~Object()
{
	count--;
}

void Object::setCell(Cell* c)
{
	cell = c;
}

char Object::getName()
{
	return name;
}