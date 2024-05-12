#include "Header.h"



int ran_num();


int cube_block = 0;
Box pole[20][10];

int num_of_fig = ran_num();
double start = GetTime();
int d_y = 0;
int x = 3;
//Figure coming_figures[10];

std::vector<std::vector<Box>> rotate(std::vector<std::vector<Box>> test)
{
	std::vector<std::vector<Box>> tmp(4, std::vector<Box>(4));

	for (int i = 0; i < 4; i++)
	{
		for (int el = 0; el < 4; el++)
		{
			tmp[i][el] = test[el][i];
		}
	}
	return tmp;
}


class figure
{
public:

	

	void palka(int y, int x)
	{
		
		for (int i = 0; i < 4; i++)
		{
			for (int el = 0; el < 4; el++)
			{
				if (y > 0)
				{
					pole[y - 1][x + i].Status = false;
					pole[y - 1][x + i].col = BLACK;
				}

				pole[y + el][x + i].Status = figura[el][i].Status;
				pole[y + el][x + i].col = figura[el][i].col;
			}
		}
		

	}


	void cube(int y, int x)
	{
	


		for (int i = 0; i < 2; i++)
		{
			for (int el = 0; el < 2; el++)
			{
				if (y > 0)
				{
					pole[y - 1][x + el].Status = false;
					pole[y - 1][x + el].col = BLACK;
				}


				pole[y + i][x + el].Status = figura[i][el].Status;
				pole[y + i][x + el].col = figura[i][el].col;
			}
		}

		cube_block = 1;
	}
	void Tfigure(int y, int x)
	{
		

		for (int i = 0; i < 3; i++)
		{
			for (int el = 0; el < 3; el++)
			{

				pole[y + el + 1][x + i].Status = figura[el][i].Status;
				pole[y + el + 1][x + i].col = figura[el][i].col;

				if (y > 0)
				{
					pole[y - 1][x + i].Status = false;
					pole[y - 1][x + i].col = BLACK;
					
					pole[y][x + i].Status = false;
					pole[y][x + i].col = BLACK;
				}
			}
		}	

		
		

	}

	void Jfigure(int y, int x) {
		for (int i = 0; i < 3; i++) {
			for (int el = 0; el < 3; el++) {
				
				
				pole[y + el][x + i + 1].Status = figura[el][i].Status;
				pole[y + el][x + i + 1].col = figura[el][i].col;

				if (y > 0)
				{
					pole[y - 1][x + 1].Status = false;
					pole[y - 1][x + 1].col = BLACK;

					pole[y][x].Status = false;
					pole[y][x].col = BLACK;
				}
			}
		}
		blockX = 7;
	}
	void Lfigure(int y, int x) {
		for (int i = 0; i < 3; i++) {
			for (int el = 0; el < 2; el++)
			{
				if (y > 0)
				{
					pole[y - 1][x + el].Status = false;
					pole[y - 1][x + el].col = BLACK;
				}
				

				pole[y + i][x + el].Status = figura[i][el].Status;
				pole[y + i][x + el].col = figura[i][el].col;
			}

		}
		pole[y][x].Status = true;
		pole[y][x].col = ORANGE;


	
	}
	void Sfigure(int y, int x)
	{
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				pole[y + j][x + i + 1].Status = figura[j][i].Status;
				pole[y + j][x + i + 1].col = figura[j][i].col;

				if (y > 0) {
					pole[y - 1][x + j].Status = false;
					pole[y - 1][x + j].col = BLACK;
				}
			}
		}
		

	}
	void SRfigure(int y, int x) 
	{
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				pole[y + j][x + i + 1].Status = figura[j][i].Status;
				pole[y + j][x + i + 1].col = figura[j][i].col;

				if (y > 0) {
					pole[y - 1][x + j].Status = false;
					pole[y - 1][x + j].col = BLACK;
				}
			}
		}
	}
	/*-----------------------------RANDOM-----------------------------------*/



	void Ran_Fig(int x, int d_y, int d_x)
	{
		switch (x)
		{
		case 1:
			InitPalka();
			palka(d_y, d_x);
			break;
		case 2:
			InitT();
			Tfigure(d_y, d_x);
			break;
		case 3:
			InitCube();
			cube(d_y, d_x);
			break;
		case 4:
			InitJ();
			Jfigure(d_y, d_x);
			break;
		case 5:
			InitL();
			Lfigure(d_y, d_x);
			break;
		case 6:
			InitS();
			Sfigure(d_y, d_x);
			break;
		case 7:
			InitSR();
			SRfigure(d_y, d_x);
			break;
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
	srand(time(0));


	for (int i = 0; i < 20; i++)
	{
		for (int el = 0; el < 10; el++)
		{
			pole[i][el].Status = false;
			pole[i][el].col = BLACK;
		}
	}


	InitPalka();

	while (!WindowShouldClose())
	{
		BeginDrawing();

		/*----------------------POLE----------------------*/
		ClearBackground(BLACK);

		object.palka(d_y, x);

		for (int i = 0; i < 20; i++)
		{
			for (int el = 0; el < 10; el++)
			{
				DrawRectangle(el * cell_size, i * cell_size, cell_size, cell_size, RAYWHITE);
				DrawRectangle(el * cell_size + 2.5, i * cell_size + 2.5, cell_size - 5, cell_size - 5, pole[i][el].col);
				//object.Ran_Fig(num_of_fig, d_y, x);


			}
		}


		/*----------------------POLE----------------------*/




		if (GetTime() - start >= 0.2)
		{
			start = GetTime();

			if (d_y == 19 - y_stop) {
				d_y = 0;
				//object.cube(d_y, x);
				num_of_fig = rand() % 7 + 1;
			}
			if (pole[(d_y) + 1 +cube_block][x].Status == true)
			{
				d_y = 0;
				num_of_fig = rand() % 7 + 1;
			}
			else {
				d_y += 1;
			}
		}


		if (x > blockX) {
			x = blockX;
		}
		if (x < 0) {
			x = -cube_block;
		}

		if (d_y != 19 - y_stop) {

			if (IsKeyPressed(KEY_LEFT)) {
				for (int i = 0; i < 4; i++)
				{
					for (int el = 0; el < 4; el++)
					{
						if (figura[el][i].Status)
						{
							pole[(d_y) + el][x + i].col = BLACK;
							pole[(d_y) + el][x + i].Status = false;
						}
					}
				}

				x -= 1;
				for (int i = 0; i < 4; i++)
				{
					for (int el = 0; el < 4; el++)
					{
						pole[d_y][x].col = figura[el][i].col;
						pole[d_y][x].Status = figura[el][i].Status;

					}
				}


			}
			if (IsKeyPressed(KEY_RIGHT)) {
				 
				for (int i = 0; i < 4; i++)
				{
					for (int el = 0; el < 4; el++)
					{
						if (figura[el][i].Status)
						{
							pole[d_y + el][x + i].col = BLACK;
							pole[d_y + el][x + i].Status = false;
						}
					}
				}

				x += 1;
				for (int i = 0; i < 4; i++)
				{
					for (int el = 0; el < 4; el++)
					{
						pole[d_y][x].col = figura[el][i].col;
						pole[d_y][x].Status = figura[el][i].Status;

					}


				}


			}
			if (IsKeyPressed(KEY_UP))
			{
				figura = rotate(figura);
			}

		}

		EndDrawing();
	}
}


