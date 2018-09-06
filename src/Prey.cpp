#include "Prey.h"
#include "Cell.h"

#include <cstdlib>
#include <iostream>
#include <algorithm>

//#define LOG_TO_STANDARD_STREAM_ENABLED

unsigned int Prey::count = 0;
char         Prey::name = PREY_N;

unsigned int Prey::getCount()
{
	return count;
}

Prey::Prey(Cell * c)
: Coral(c)
{
	count++;
    liveTime = 15;
	reproductionTime = 3;
}
Prey::~Prey()
{
	count--;
}

void Prey::move()
{
	auto aPairs = Helper::GetRelatedCells(cell->getPair());
    auto aPairsNumber = aPairs.size();
	bool aRes = AllIsBusy(aPairs);
	Ocean* anOcean = cell->getOcean();
	Cell* aCell;
	while (!aRes) {
        auto aRandomNumber = rand() % aPairsNumber;
#ifdef LOG_TO_STANDARD_STREAM_ENABLED
        std::cout << "Generated number: " << aRandomNumber << std::endl;
#endif
        auto aPair = aPairs[aRandomNumber];
		aCell = anOcean->getCell(aPair);
		if (aCell->isEmpty()) {
			cell->setObject(nullptr);
			cell = aCell;
			cell->setObject(this);
			break;
		}
	}
}


bool Prey::AllIsBusy(std::vector<Pair> thePairs)
{
	bool aRes = false;
	auto anOcean = cell->getOcean();

	auto aCheckFunc = [anOcean](Pair thePair) {
		auto aCell = anOcean->getCell(thePair);
		return !aCell->isEmpty();
	};

	aRes = std::all_of(thePairs.begin(), thePairs.end(), aCheckFunc);
	return aRes;
}

void Prey::live()
{
	bool aRes = TryLive();
	if (aRes) {
		Coral::live();
		if (!myStepDone) {
			move();
			myStepDone = true;
		}
	}
}

bool Prey::TryLive()
{
	liveTime--;
	if (liveTime == 0) {
		cell->killMe();
		return false;
	}
	return true;
}

char Prey::getName()
{
	return name;
}

Object* Prey::generateObject(Cell* theCell)
{
    Object* theTarget = new Prey(theCell);
	theTarget->getCell()->setObject(theTarget);
    if (!theTarget) {
        std::cout << "stop";
    }
    return theTarget;
}

bool Prey::reproduction()
{
	if (reproductionTime == 0) {
		auto aPairs = Helper::GetRelatedCells(cell->getPair());
		bool aRes = AllIsBusy(aPairs);
		if (aRes) {
			return false;
		}

		auto aPairsNumber = aPairs.size();

		while (!aRes) {
			auto aRandomNumber = rand() % aPairsNumber;
#ifdef LOG_TO_STANDARD_STREAM_ENABLED
			std::cout << "Generated number: " << aRandomNumber << std::endl;
#endif
			auto aPair = aPairs[aRandomNumber];
			aRes = TryReproduction(aPair);
		}
		reproductionTime = 3;
		return true;
	}
	else {
		reproductionTime--;
		return false;
	}
}
