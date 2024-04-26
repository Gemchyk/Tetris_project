#include "Header.h"


const int cell_size = 50;
int blockX, cube_block = 0;
Box pole[20][10];
Figure coming_figures[10];
//Box figura[4][4];




class figure
{
public:

	Figure init_palka()
	{
		Figure init_figure;
		init_figure.a[0] = { 0, 0 };
		init_figure.a[1] = { 1, 0 };
		init_figure.a[2] = { 2, 0 };
		init_figure.a[3] = { 3, 0 };
		return init_figure;
	}

	void palka(int y, int x)
	{
		//for (int i = 0; i < 4; i++)
		//{
		//	//DrawRectangle((i * cell_size + 2.5) + x, y + 2.5, cell_size - 5, cell_size - 5, BLUE);
		//	if (y > 0) {
		//		
		//		pole[y / cell_size - 1][x / cell_size + i].Status = false;
		//		pole[y / cell_size - 1][x / cell_size + i].col = BLACK;				
		//	}
		//	
		//	pole[y / cell_size][x / cell_size + i].Status = true;
		//	pole[y / cell_size][x / cell_size + i].col = BLUE;

		//	
		//}




		/*for (int i = 0; i < 4; i++)
		{
			for (int el = 0; el < 4; el++)
			{
				figura[3][i].Status = true;
				figura[3][i].col = BLUE;
				if (y > 0)
				{
					pole[y / cell_size - 1][x / cell_size + i].Status = false;
					pole[y / cell_size - 1][x / cell_size + i].col = BLACK;
				}

				pole[y / cell_size][x / cell_size + i].Status = figura[el][i].Status;
				pole[y / cell_size][x / cell_size + i].col = figura[el][i].col;
			}
		}*/
		blockX = 6;
	}


	void cube(int y, int x)
	{
		x += 50;
		//for (int i = 0; i < 2; i++)
		//{
		//	for (int el = 0; el < 2; el++)
		//	{
		//		/*DrawRectangle((el * cell_size + 2.5) + x, i * 50 + y + 2.5, cell_size - 5, cell_size - 5, YELLOW);
		//		DrawRectangle((el * cell_size + 2.5) + x, i * 50 + y + 2.5, cell_size - 5, cell_size - 5, YELLOW);*/
		//		pole[y / cell_size + i][x / cell_size + el].Status = true;
		//		pole[y / cell_size + i][x / cell_size + el].col = YELLOW;

		//		if (y > 0) {
		//			pole[y / cell_size  - 1][x / cell_size + el].Status = false;
		//			pole[y / cell_size - 1][x / cell_size + el].col = BLACK;
		//		}
		//	}
		//	
		//}



		/*for (int i = 0; i < 2; i++)
		{
			for (int el = 0; el < 2; el++)
			{
				if (y > 0)
				{
					pole[y / cell_size - 1][x / cell_size + el].Status = false;
					pole[y / cell_size - 1][x / cell_size + el].col = BLACK;
				}

				figura[i][el].Status = true;
				figura[i][el].col = YELLOW;

				pole[y / cell_size + i][x / cell_size + el].Status = figura[i][el].Status;
				pole[y / cell_size + i][x / cell_size + el].col = figura[i][el].col;
			}
		}*/

		blockX = 7;
		cube_block = 1;
	}
	void Tfigure(int y, int x)
	{
		for (int el = 0; el < 2; el++)
		{
			for (int i = 0; i < 3; i++)
			{
				DrawRectangle((i * cell_size + 2.5) + x, y + 2.5, cell_size - 5, cell_size - 5, PURPLE);
				if (el == 1)
				{
					DrawRectangle((el * cell_size + 2.5) + x, y + 2.5 - el * 50, cell_size - 5, cell_size - 5, PURPLE);
				}
			}
			pole[y / cell_size][x / cell_size].Status = true;
			pole[y / cell_size][x / cell_size].col = PURPLE;
		}
		blockX = 7;
	}

	void Jfigure(int y, int x) {
		for (int i = 0; i < 3; i++) {
			DrawRectangle((i * 50 + 2.5) + x, y + 2.5, cell_size - 5, cell_size - 5, DARKBLUE);
			if (i == 0) {
				DrawRectangle((i * 50 + 2.5) + x, y + 2.5 - 50, cell_size - 5, cell_size - 5, DARKBLUE);
			}
		}
		pole[y / 50][x / 50].Status = true;
		pole[y / 50][x / 50].col = DARKBLUE;
		blockX = 7;
	}
	void Lfigure(int y, int x) {
		for (int i = 0; i < 3; i++) {
			DrawRectangle((i * 50 + 2.5) + x, y + 2.5, cell_size - 5, cell_size - 5, ORANGE);
			if (i == 2) {
				DrawRectangle((i * 50 + 2.5) + x, y + 2.5 - 50, cell_size - 5, cell_size - 5, ORANGE);
			}

		}
		pole[y / 50][x / 50].Status = true;
		pole[y / 50][x / 50].col = ORANGE;
		blockX = 7;
	}
	void Sfigure(int y, int x) {
		for (int i = 0; i < 4; i++) {
			if (i < 2) {
				DrawRectangle((i * 50 + 2.5) + x, y + 2.5, cell_size - 5, cell_size - 5, GREEN);
			}
			else {
				DrawRectangle(((i - 1) * 50 + 2.5) + x, y + 2.5 - 50, cell_size - 5, cell_size - 5, GREEN);
			}
		}
		pole[y / 50][x / 50].Status = true;
		pole[y / 50][x / 50].col = GREEN;
		blockX = 7;
	}
	void SRfigure(int y, int x) {
		for (int i = 0; i < 4; i++) {
			if (i < 2) {
				DrawRectangle((i * 50 + 2.5) + x, y + 2.5 - 50, cell_size - 5, cell_size - 5, RED);
			}
			else {
				DrawRectangle(((i - 1) * 50 + 2.5) + x, y + 2.5, cell_size - 5, cell_size - 5, RED);
			}
		}
		pole[y / 50][x / 50].Status = true;
		pole[y / 50][x / 50].col = RED;
		blockX = 7;
	}
	/*-----------------------------RANDOM-----------------------------------*/



	void Ran_Fig(int x, int d_y, int d_x)
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


	figure object;
	double start = GetTime();
	int d_y = 0;
	int x = 150;
	srand(time(0));
	int num_of_fig = ran_num();
	for (int i = 0; i < 20; i++)
	{
		for (int el = 0; el < 10; el++)
		{
			pole[i][el].Status = false;
			pole[i][el].col = BLACK;
		}
	}

	


	while (!WindowShouldClose())
	{
		BeginDrawing();

		/*----------------------POLE----------------------*/
		ClearBackground(BLACK);



		for (int i = 0; i < 20; i++)
		{
			for (int el = 0; el < 10; el++)
			{
				DrawRectangle(el * cell_size, i * cell_size, cell_size, cell_size, RAYWHITE);
				DrawRectangle(el * cell_size + 2.5, i * cell_size + 2.5, cell_size - 5, cell_size - 5, pole[i][el].col);
				//object.Ran_Fig(num_of_fig, d_y, x);
				//object.palka(d_y, x);

			}
		}


		/*----------------------POLE----------------------*/



				if (d_y == cell_size * (19 - cube_block)) {
					d_y = 0;
					//figura.Ran_Fig(num_of_fig, d_y, x);
					figura.cube(d_y, x);
					num_of_fig = rand() % 7 + 1;
				}
				if (pole[(d_y / cell_size) + 1 + cube_block][x / cell_size].Status == true) 
				{
					d_y = 0;
					num_of_fig = rand() % 7 + 1;
				}
				else {
					d_y += 50;
				}
			}



































		//if (GetTime() - start >= 0.2)
		//{
		//	start = GetTime();

		//	if (d_y == cell_size * (19 - cube_block)) {
		//		d_y = 0;
		//		//figura.Ran_Fig(num_of_fig, d_y, x);
		//		//object.cube(d_y, x);
		//		num_of_fig = rand() % 7 + 1;
		//	}
		//	if (pole[(d_y / cell_size) + 1 + cube_block][x / cell_size].Status == true)    Êîìåíò ùîá íå áóëî êîíôë³êò³â
		//	{
		//		d_y = 0;
		//		num_of_fig = rand() % 7 + 1;
		//	}
		//	else {
		//		d_y += cell_size;
		//	}
		//}



		if (x > cell_size * blockX) {
			x = cell_size * blockX;
		}
		if (x < 0) {
			x = 0 - cube_block * 50;
		}

		if (d_y != cell_size * (19 - cube_block)) {

			if (IsKeyPressed(KEY_LEFT)) {
				x -= 50;
				for (int i = 0; i < 4; i++)
				{
					for (int el = 0; el < 4; el++)
					{
						/*pole[(d_y / 50)][x / 50].col = figura[el][i].col;
						pole[(d_y / 50)][x / 50].Status = figura[el][i].Status;*/

					}
				}

				//pole[(d_y / 50)][(x + 200) / 50].Status = false;  // Ne ïðàöþº
				//pole[(d_y / 50)][(x + 200) / 50].col = BLACK;
			}
			if (IsKeyPressed(KEY_RIGHT)) {
				x += 50;
				for (int i = 0; i < 4; i++)
				{
					for (int el = 0; el < 4; el++)
					{
						/*	pole[(d_y / 50)][x / 50].col = figura[el][i].col;
							pole[(d_y / 50)][x / 50].Status = figura[el][i].Status;*/
					}
				if (IsKeyPressed(KEY_RIGHT)) {
					x += 50;
					pole[d_y / 50 ][(x + 50) / 50].Status = false;  // ïðàöþº
					pole[d_y / 50][(x + 50) / 50].col = BLACK;

				}
				//pole[d_y / 50 ][(x - 50) / 50].Status = false;  // ïðàöþº
				//pole[d_y / 50][(x - 50) / 50].col = BLACK;
			}

		}

		EndDrawing();
	}
}


