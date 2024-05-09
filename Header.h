

#include <iostream>
#include <ctime>
#include <raylib.h>
#include <vector>
#define cell_size 50





struct Box
{
	bool Status = false;
	Color col = BLACK;
};
struct points
{
	int x_pos;
	int y_pos;
};
struct Figure
{
	points a[4];
	points pos;
};

std::vector<std::vector<Box>> figura(4, std::vector<Box>(4));

void InitPalka()
{
	for (int i = 0; i < 4; i++)
	{
		for (int el = 0; el < 4; el++)
		{
			figura[0][i].Status = true;
			figura[0][i].col = BLUE;
		}
	}
}

/*---------------------RANDOM----------------------*/






/*---------------------RANDOM----------------------*/






