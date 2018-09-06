#ifndef _COMMON_H_
#define _COMMON_H_

#include <vector>
#include <cstdio>

typedef size_t coord_t;

struct Pair
{
	//Pair(coord_t theX, coord_t theY)
	//: x(theX), y(theY) 
	//{
	//}
	coord_t x; // 0..M-1
	coord_t y; // 0..N-1
};

const size_t N = 20;
const size_t M = 50;

class Helper {
public:
	static std::vector<Pair> GetRelatedCells(Pair theCenter)
	{
		std::vector<Pair> aCoords;

        int i = theCenter.y, j = theCenter.x;
        for (int y = i - 1; y <= i + 1; y++) {
            for (int x = j - 1; x <= j + 1; x++) {
                if (y >= 0 && y < static_cast<int> (N) && x >= 0 && x < static_cast<int> (M)) {
                    aCoords.push_back(Pair{ static_cast<size_t> (x), static_cast<size_t> (y) });
				}
			}
		}

		return aCoords;
	}
};



#endif
