#include "Header.h"

const int rec_wid = 50;
const int rec_hei = 50;
int blockX, cube_block = 0;
Box pole[20][10];



class figure
{
public:
	void palka(int y, int x)
	{
		for (int i = 0; i < 4; i++)
		{
			DrawRectangle((i * 50 + 2.5) + x, y + 2.5, rec_wid - 5, rec_hei - 5, BLUE);
		}
		pole[y / 50][x / 50].Status = true;
		pole[y / 50][x / 50].col = BLUE;
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
		pole[y / 50][x / 50].Status = true;
		pole[y / 50][x / 50].col = YELLOW;
		blockX = 7;
		cube_block = 1;
	}
	void Tfigure(int y, int x)
	{
		for (int el = 0; el < 2; el++)
		{
			for (int i = 0; i < 3; i++)
			{
				DrawRectangle((i * 50 + 2.5) + x, y + 2.5, rec_wid - 5, rec_hei - 5, PURPLE);
				if (el == 1)
				{
					DrawRectangle((el * 50 + 2.5) + x,y + 2.5 - el*50, rec_wid - 5, rec_hei - 5, PURPLE);
				}
			}
			pole[y / 50][x / 50].Status = true;
			pole[y / 50][x / 50].col = PURPLE;
		}
		blockX = 7;
	}
	void Jfigure(int y, int x) {
		for (int i = 0; i < 3; i++) {
			DrawRectangle((i * 50 + 2.5) + x,y + 2.5, rec_wid - 5, rec_hei - 5, DARKBLUE);
			if (i == 0) {
				DrawRectangle((i * 50 + 2.5) + x, y + 2.5 - 50, rec_wid - 5, rec_hei - 5, DARKBLUE);
			}
		}
		pole[y / 50][x / 50].Status = true;
		pole[y / 50][x / 50].col = DARKBLUE;
		blockX = 7;
	}
	void Lfigure(int y, int x) {
		for (int i = 0; i < 3; i++) {
			DrawRectangle((i * 50 + 2.5) + x, y + 2.5, rec_wid - 5, rec_hei - 5, ORANGE);
			if (i == 2) {
				DrawRectangle((i * 50 + 2.5) + x, y + 2.5 - 50, rec_wid - 5, rec_hei - 5, ORANGE);
			}
			
		}
		pole[y / 50][x / 50].Status = true;
		pole[y / 50][x / 50].col = ORANGE;
		blockX = 7;
	}
	void Sfigure(int y, int x) {
		for (int i = 0; i < 4; i++) {
			if (i < 2) {
				DrawRectangle((i * 50 + 2.5) + x, y + 2.5, rec_wid - 5, rec_hei - 5, GREEN);
			}
			else {
				DrawRectangle(((i - 1)* 50 + 2.5) + x, y + 2.5 - 50, rec_wid - 5, rec_hei - 5, GREEN);
			}
		}
		pole[y / 50][x / 50].Status = true;
		pole[y / 50][x / 50].col = GREEN;
		blockX = 7;
	}
	void SRfigure(int y, int x) {
		for (int i = 0; i < 4; i++) {
			if (i < 2) {
				DrawRectangle((i * 50 + 2.5) + x, y + 2.5 - 50, rec_wid - 5, rec_hei - 5, RED);
			}
			else  {
				DrawRectangle(((i - 1) * 50 + 2.5) + x, y + 2.5, rec_wid - 5, rec_hei - 5, RED);
			}
		}
		pole[y / 50][x / 50].Status = true;
		pole[y / 50][x / 50].col = RED;
		blockX = 7;
	}
	/*-----------------------------RANDOM-----------------------------------*/

	

	void Ran_Fig(int x,  int d_y, int d_x)
	{
		if (x == 1)
		{
			palka(d_y, d_x);
		}
		if (x == 2)
		{
			Tfigure(d_y, d_x);
		}
		if (x == 3)
		{
			cube(d_y, d_x);
		}
		if (x == 4)
		{
			Jfigure(d_y, d_x);
		}
		if (x == 5)
		{
			Lfigure(d_y, d_x);
		}
		if (x == 6)
		{
			Sfigure(d_y, d_x);
		}
		if (x == 7)
		{
			SRfigure(d_y, d_x);
		}
	}

};
int ran_num()
{
	return rand() % 7 + 1;
}

int main()
{
	
	InitWindow(600, 1000, "Game");


	figure figura;
	double start = GetTime();
	int d_y = 0;
	int x = 150;
	srand(time(0));
	int num_of_fig = ran_num();


	while (!WindowShouldClose())
	{
		BeginDrawing();

		/*----------------------POLE----------------------*/
		ClearBackground(BLACK);

		

		for (int i = 0; i < 20; i++)
		{
			for (int el = 0; el < 10; el++)
			{
				pole[i][el].Status = false;
				pole[i][el].col = BLACK;
				DrawRectangle(el * rec_wid, i * rec_hei, rec_wid, rec_hei, RAYWHITE);
				DrawRectangle(el * rec_wid + 2.5, i * rec_hei + 2.5, rec_wid - 5, rec_hei - 5, BLACK);
			}
		}

		
		/*----------------------POLE----------------------*/


		

		

		
			figura.Ran_Fig(num_of_fig, d_y, x);
		


		
			if (GetTime() - start >= 0.5)
			{
				start = GetTime();

				if (d_y == rec_hei * (19 - cube_block)) {
					d_y = 0;
					num_of_fig = rand() % 7 + 1;
				}
				if (pole[(d_y / 50) + 1][x / 50].Status == true)
				{
					d_y = 0;
					num_of_fig = rand() % 7 + 1;
				}
				else {
					d_y += 50;
				}
			}



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
		
			
		
		

		



		EndDrawing();
	}
}


