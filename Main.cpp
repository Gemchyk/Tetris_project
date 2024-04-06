#include "Header.h"

const int rec_wid = 50;
const int rec_hei = 50;

class figure
{
public:
	void palka(int y, int x)
	{
		for (int i = 0; i < 4; i++)
		{
			DrawRectangle((i * 50 + 2.5) + x, y + 2.5, rec_wid - 5, rec_hei - 5, BLUE);
		}
	}
	void cube(int y, int x)
	{
		for (int i = 0; i < 2; i++)
		{
			for (int el = 0; el < 2; el++)
			{
				DrawRectangle((el * 50 + 2.5) + x, i * 50 + y + 2.5, rec_wid - 5, rec_hei - 5, YELLOW);
				DrawRectangle((el * 50 + 2.5) + x, i * 50 + y + 2.5, rec_wid - 5, rec_hei - 5, YELLOW);
			}

		}
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
	}
};

int main()
{
	
	InitWindow(600, 1000, "Game");


	figure figura;
	double start = GetTime();
	int d_y = 0;
	int x = 0	;


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

			if (d_y == rec_hei * 19) {
				d_y == rec_hei * 19;
			}
			else {
				d_y += 50;
			}

		}

		figura.palka(d_y, x);


		if (x > rec_wid * 6) {
			x = rec_wid * 6;
		}
		if (x <= 0) {
			x = 0;
		}



		if (IsKeyPressed(KEY_RIGHT)) {
			x += 50;
		}
		if (IsKeyPressed(KEY_LEFT)) {
			x -= 50;
		}


		EndDrawing();
	}
}


