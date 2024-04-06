#include "Header.h"

const int rec_wid = 50;
const int rec_hei = 50;

class figure
{
public:
	void palka(int y)
	{
		for (int i = 0; i < 4; i++)
		{
			DrawRectangle(i * 50 + 2.5, y + 2.5, rec_wid - 5, rec_hei - 5, BLUE);
		}
	}
	
};

int main()
{
	
	InitWindow(600, 1000, "Game");


	figure a;
	double start = GetTime();
	int d_y = 0;


	while (!WindowShouldClose())
	{
		BeginDrawing();
		ClearBackground(BLACK);
		for (float i = 0; i < 20; i++)
		{
			for (float el = 0; el < 10; el++)
			{
				DrawRectangle(el * rec_wid, i * rec_hei, rec_wid, rec_hei, RAYWHITE);
				DrawRectangle(el * rec_wid + 2.5, i * rec_hei + 2.5, rec_wid - 5, rec_hei - 5, BLACK);
			}
		}
		if (GetTime() - start >= 0.5)
		{
			start = GetTime();
			d_y += 50;
		}
		a.palka(d_y);


		EndDrawing();
	}
	

}
void  randF() {
	std::cout << "iweuihriujehwriojqijdeooqkpwddlkp";
}