#include "Ocean.h"
#include "Stone.h"
#include "Coral.h"
#include "Cell.h"
#include "Prey.h"
#include "Predator.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>

Ocean::Ocean()
{
	cells = new Cell*[N];
	for (size_t i = 0; i < N; i++)
	{
		cells[i] = new Cell[M];
		for (size_t j = 0; j < M; j++)
			cells[i][j].init(Pair{ j, i }, this); // ?
	}
}

Ocean::~Ocean()
{
	for (size_t i = 0; i < N; i++)
		delete[] cells[i];
	delete[] cells;
	for (auto iter = stuff.begin(); iter != stuff.end(); ++iter)
		delete *iter;
}

void Ocean::print() const
{
	for (size_t i = 0; i < N; i++)
	{
		for (size_t j = 0; j < M; j++)
			std::cout << 
			(cells[i][j].getObject() ? 
			 cells[i][j].getObject()->getName() : '.');

		std::cout << std::endl;
	}
}
void Ocean::addObjects(int count)
{
	while (count > 0)
	{
		size_t x = rand() % M;
		size_t y = rand() % N;
		if (cells[y][x].getObject())
			continue;
		else
		{
			if (count % 4 == 0)
			{
				Object *born = new Stone(&cells[y][x]);
				cells[y][x].setObject(born);
				stuff.push_back(born);
				count--;
			}
			else if (count % 4 == 1)
			{
				Object *born = new Coral(&cells[y][x]);
				cells[y][x].setObject(born);
				stuff.push_back(born);
				count--;

			}
			else if (count % 4 == 2)
			{
				Object *born = new Prey(&cells[y][x]);
				cells[y][x].setObject(born);
				stuff.push_back(born);
				count--;

			}
			else
			{
				Object *born = new Predator(&cells[y][x]);
				cells[y][x].setObject(born);
				stuff.push_back(born);
				count--;

			}
		}

	}
}

void Ocean::deleteObject(Object* theObject)
{
	auto anIt = std::find(stuff.begin(), stuff.end(), theObject);
	if (anIt != stuff.end()) {
        //stuff.erase (anIt);
		(*anIt) = nullptr;
	}
}

void Ocean::run()
{
	while (1)
	{
		auto anAllDied = true;
        for (auto anIt = stuff.begin(); anIt != stuff.end(); ++anIt)
        {
            Object* obj = (*anIt);
            if (obj) {
                anAllDied = false;
                obj->live();
            }
        }
//		for (auto obj : stuff)
//		{

//		}

		if (anAllDied) {
			std::cout << "All died" << std::endl;
			break;
		}

		clock_t now = clock();
		while (clock() < now + CLOCKS_PER_SEC);
		system("cls");
		print();
	}
}

Cell* Ocean::getCell(Pair theCoord)
{
    return &cells[theCoord.y][theCoord.x];
}

void Ocean::addObject(Object* theObject)
{
    if (!theObject) {
        std::cout << "bumps";
    }
	stuff.push_back(theObject);
}
