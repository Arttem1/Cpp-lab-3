#include "Coral.h"
#include "Ocean.h"
#include "Cell.h"

#include <iostream>

unsigned int Coral::count = 0;
char         Coral::name = CORAL_N;

unsigned int Coral::getCount()
{
	return count;
}

Coral::Coral(Cell * c) :Object(c)
{
	count++;
    reproductionTime = 5;
}
Coral::~Coral()
{
	count--;
}

Object* Coral::generateObject(Cell* theCell)
{
    Object* theTarget = new Coral(theCell);
    theTarget->getCell()->setObject(theTarget);
    return theTarget;
}

bool Coral::TryReproduction(Pair thePair)
{
	Ocean* anOcean = cell->getOcean();
	Cell* aCell = anOcean->getCell(thePair);
    if (aCell->isEmpty()) {
        Object* aNewObject = generateObject (aCell);
		anOcean->addObject(aNewObject);
		return true;
	}
	return false;
}

bool Coral::reproduction()
{
	if (reproductionTime == 0) {
		auto aPairs = Helper::GetRelatedCells(cell->getPair());
		for (auto aPair : aPairs) {
			TryReproduction(aPair);
		}

        reproductionTime = 5;
		return true;
	}
	else {
		reproductionTime--;
		return false;
	}
}

void Coral::live()
{
	myStepDone = reproduction();
}

char Coral::getName()
{
	return name;
}
