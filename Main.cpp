#include "Header.h"

const int rec_wid = 50;
const int rec_hei = 50;
int blockX, cube_block = 0;


class figure
{
public:
	void palka(int y, int x)
	{
		for (int i = 0; i < 4; i++)
		{
			DrawRectangle((i * 50 + 2.5) + x, y + 2.5, rec_wid - 5, rec_hei - 5, BLUE);
		}
		blockX = 6;
	}
	void cube(int y, int x)
	{
		x += 50;
		for (int i = 0; i < 2; i++)
		{
			for (int el = 0; el < 2; el++)
			{
				DrawRectangle((el * 50 + 2.5) + x, i * 50 + y + 2.5, rec_wid - 5, rec_hei - 5, YELLOW);
				DrawRectangle((el * 50 + 2.5) + x, i * 50 + y + 2.5, rec_wid - 5, rec_hei - 5, YELLOW);
			}
			
		}
		blockX = 7;
		cube_block = 1;
	}
	void Tfigure(int y, int x)
	{
		for (int el = 0; el < 2; el++)
		{
			for (int i = 0; i < 3; i++)
			{
				DrawRectangle((i * 50 + 2.5) + x, y + 2.5, rec_wid - 5, rec_hei - 5, BLUE);
				if (el == 1)
				{
					DrawRectangle((el * 50 + 2.5) + x,y + 2.5 - el*50, rec_wid - 5, rec_hei - 5, BLUE);
				}
			}
		}
		blockX = 7;
	}
	void Jfigure(int y, int x) {
		for (int i = 0; i < 3; i++) {
			DrawRectangle((i * 50 + 2.5) + x,y + 2.5, rec_wid - 5, rec_hei - 5, BLUE);
			if (i == 0) {
				DrawRectangle((i * 50 + 2.5) + x, y + 2.5 - 50, rec_wid - 5, rec_hei - 5, BLUE);
			}
		}
		blockX = 7;
	}
	void Lfigure(int y, int x) {
		for (int i = 0; i < 3; i++) {
			DrawRectangle((i * 50 + 2.5) + x, y + 2.5, rec_wid - 5, rec_hei - 5, BLUE);
			if (i == 2) {
				DrawRectangle((i * 50 + 2.5) + x, y + 2.5 - 50, rec_wid - 5, rec_hei - 5, BLUE);
			}
		}
		blockX = 7;
	}
	void Sfigure(int y, int x) {
		for (int i = 0; i < 4; i++) {
			if (i < 2) {
				DrawRectangle((i * 50 + 2.5) + x, y + 2.5, rec_wid - 5, rec_hei - 5, BLUE);
			}
			else {
				DrawRectangle(((i - 1)* 50 + 2.5) + x, y + 2.5 - 50, rec_wid - 5, rec_hei - 5, BLUE);
			}
		}
		blockX = 7;
	}
	void SRfigure(int y, int x) {
		for (int i = 0; i < 4; i++) {
			if (i < 2) {
				DrawRectangle((i * 50 + 2.5) + x, y + 2.5 - 50, rec_wid - 5, rec_hei - 5, BLUE);
			}
			else  {
				DrawRectangle(((i - 1) * 50 + 2.5) + x, y + 2.5, rec_wid - 5, rec_hei - 5, BLUE);
			}
		}
		blockX = 7;
	}
};

int main()
{
	
	InitWindow(600, 1000, "Game");


	figure figura;
	double start = GetTime();
	int d_y = 0;
	int x = 150;


	while (!WindowShouldClose())
	{
		BeginDrawing();

		/*----------------------POLE----------------------*/
		ClearBackground(BLACK);
		for (float i = 0; i < 20; i++)
		{
			for (float el = 0; el < 10; el++)
			{
				DrawRectangle(el * rec_wid, i * rec_hei, rec_wid, rec_hei, RAYWHITE);
				DrawRectangle(el * rec_wid + 2.5, i * rec_hei + 2.5, rec_wid - 5, rec_hei - 5, BLACK);
			}
		}
		/*----------------------POLE----------------------*/


		

		if (GetTime() - start >= 0.5)
		{

			start = GetTime();

			if (d_y == rec_hei * (19 - cube_block)) {
				d_y == rec_hei * (19 - cube_block);
			}
			else {
				d_y += 50;
			}


		}

		figura.SRfigure(d_y, x);


		if (x > rec_wid * blockX) {
			x = rec_wid * blockX;
		}
		if (x < 0) {
			x = 0 - cube_block * 50;
		}

		if (d_y != rec_hei * (19 - cube_block)) {
			if (IsKeyPressed(KEY_RIGHT)) {
				x += 50;
			}
			if (IsKeyPressed(KEY_LEFT)) {
				x -= 50;
			}
		}

		
		

		/*---------------------RANDOM----------------------*/


		
		


		/*---------------------RANDOM----------------------*/



		EndDrawing();
	}
}


