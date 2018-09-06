#include "Stone.h"
#include "Cell.h"

unsigned int Stone::count = 0;
char         Stone::name  = STONE_N;

unsigned int Stone::getCount()
{
	return count;
}

Stone::Stone(Cell * c) 
: Object(c)
{	
	count++;
	liveTime = 50;
}
Stone::~Stone()
{
	count--;
}
void Stone::live()
{
	liveTime--;
	if (liveTime == 0)
		cell->killMe();
}

char Stone::getName()
{
	return name;
}