

#include <iostream>
#include <ctime>
#include <raylib.h>
#include <vector>
#define cell_size 50




int blockX = 7;
int y_stop;


struct figure_t {
	std::vector<pos_t> blockpos;
	std::vector<pos_t> rightPeaks;
	std::vector<pos_t> leftPeaks;
	std::vector<pos_t> downPeaks;
	pos_t absPos;
	int rotatePoint;
};

struct Box
{
	bool Status = false;
	Color col = BLACK;
};
struct pos_t {
	int X = 0;
	int Y = 0;
};
struct Figure
{
	pos_t a[4];
	pos_t pos;
};

std::vector<std::vector<Box>> figura(4, std::vector<Box>(4));

void InitPalka()
{
	for (int i = 0; i < 4; i++)
	{
		for (int el = 0; el < 4; el++)
		{
			figura[3][i].Status = true;
			figura[3][i].col = BLUE;
		}
	}
	blockX = 6;
	y_stop = 3;
}

void InitCube() {
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			figura[i][j].Status = true;
			figura[i][j].col = YELLOW;
		}
	}
	y_stop = 1;
	blockX = 8;
}

void InitT() {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			figura[1][i].Status = true;
			figura[1][i].col = BLUE;
			if (i == 1) {
				figura[0][i].Status = true;
				figura[0][i].col = BLUE;
			}
		}
	}
	y_stop = 2;
}

void InitJ() {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			figura[1][i].Status = true;
			figura[1][i].col = DARKBLUE;
			if (i == 0) {
				figura[0][i].Status = true;
				figura[0][i].col = DARKBLUE;
			}
		}
	}
	y_stop = 1;
	blockX = 6;
}

void InitL() {
	for (int i = 0; i < 3; i++) 
	{
		for (int j = 0; j < 3; j++) 
		{
			figura[i][1].Status = true;
			figura[i][1].col = ORANGE;

			figura[0][2].Status = true;
			figura[0][2].col = ORANGE;
		}
	}
	y_stop = 2;
}

void InitS() {
	for (int i = 0; i < 4; i++) 
	{
		for (int j = 0; j < 4; j++) 
		{
			if (i < 2) {
				figura[1][i].Status = true;
				figura[1][i].col = GREEN;
			}
			else {
				figura[0][i - 1].Status = true;
				figura[0][i - 1].col = GREEN;
			}
		}
	}
	blockX = 6;
	y_stop = 1;
}

void InitSR() {
	for (int i = 0; i < 4; i++) 
	{
		for (int j = 0; j < 4; j++) 
		{
			if (i < 2) {
				figura[0][i].Status = true;
				figura[0][i].col = RED;
			}
			else {
				figura[1][i - 1].Status = true;
				figura[1][i - 1].col = RED;
			}
		}
	}
	blockX = 6;
	y_stop = 1;
}
/*---------------------RANDOM----------------------*/






/*---------------------RANDOM----------------------*/






