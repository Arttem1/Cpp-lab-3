#include "common.h"
#include "Ocean.h"
#include <ctime>
#include <cstdlib>
#include <iostream>

using namespace std;

int main()
{
	srand(time(nullptr));
	Ocean *atlantic = new Ocean;
    atlantic->addObjects(30);
	atlantic->run();
	std::cout << "End" << std::endl;
	return 0;
}
