#include "Predator.h"
#include "Cell.h"

#include <cstdlib>
#include <iostream>
#include <algorithm>

//#define LOG_TO_STANDARD_STREAM_ENABLED

unsigned int Predator::count = 0;
char         Predator::name = PREDATOR_N;

unsigned int Predator::getCount()
{
    return count;
}

Predator::Predator(Cell * c)
: Prey(c)
{
	count++;
    golodTime = 5;
	liveTime = 10;
	reproductionTime = 3;
}

Predator::~Predator()
{
	count--;
}

bool Predator::TryLive()
{
	bool aRes = Prey::TryLive();

	if (aRes && golodTime-- == -1) {
		cell->killMe();
		return false;
	}
    return aRes;
}

bool Predator::TryEat()
{
	auto aPairs = Helper::GetRelatedCells(cell->getPair());
	Ocean* anOcean = cell->getOcean();
	Cell* aCell = nullptr;
	std::vector<Cell*> aCellsWithPrey;

	for (auto aPair : aPairs) {
		aCell = anOcean->getCell(aPair);
		if (aCell->getObject() && aCell->getObject()->getName() == PREY_N) {
			aCellsWithPrey.push_back(aCell);
		}
	}

	auto aCellsWithPreySize = aCellsWithPrey.size();

	if (aCellsWithPreySize == 0) {
		return false;
	}

	auto aRandNumber = rand() % aCellsWithPreySize;
	
	auto aCellWithPrey = aCellsWithPrey[aRandNumber];
	aCellWithPrey->killMe();

    golodTime += 3;
	return true;
}

void Predator::live()
{
	bool aRes = TryLive();
	if (aRes) {
		Coral::live();
		if (!myStepDone) {
			myStepDone = TryEat();
		}
		if (!myStepDone) {
			move();
			myStepDone = true;
		}
	}
}

char Predator::getName()
{
	return name;
}

Object* Predator::generateObject(Cell* theCell)
{
	Object* theTarget = new Predator(theCell);
	theTarget->getCell()->setObject(theTarget);
	return theTarget;
}
