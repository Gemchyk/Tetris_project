
#define POLE_WIDTH 10
#define POLE_HEIGHT 20
#define cell 50


#include <iostream>
#include <vector>
#include <raylib.h>
#include <ctime>
#include <cstdlib>
#include <string>
using namespace std;
Color col = BLACK;

int score = 0;

struct pos_t {
    int X = 0;
    int Y = 0;
};

struct figure_t {
    vector<pos_t> blockpos;
    vector<pos_t> rightPeaks;
    vector<pos_t> leftPeaks;
    vector<pos_t> downPeaks;
    pos_t absPos;
    int rotatePoint;
};


enum collide_dir {
    ANY,
    RIGHT,
    LEFT,
    DOWN
};




vector<vector<bool>> field;

vector<pos_t> findRow(figure_t figure, int row) {
    vector<pos_t> ret;

    for (pos_t i : figure.blockpos)
    {
        if (i.Y == row)
            ret.push_back(i);
    }

    return ret;
}

vector<pos_t> findColumn(figure_t figure, int column) {
    vector<pos_t> ret;


    for (pos_t i : figure.blockpos)
    {
        if (i.X == column)
            ret.push_back(i);
    }
    return ret;
}


void findRightPeaks(figure_t& figure) {
    int minY = 0;
    int maxY = 0;
    int minX = 0;

    for (pos_t i : figure.blockpos) {
 
        if (i.X < minX) 
            minX = i.X;
        if (i.Y > maxY) 
            maxY = i.Y;
        if (i.Y < minY) 
            minY = i.Y;

    }

    for (int i = minY; i <= maxY; i++) {
        pos_t peak = { minX, 0 };

        for (pos_t& i : findRow(figure, i))
        {
            if (i.X >= peak.X)
                peak = i;
        }
        figure.rightPeaks.push_back(peak);
    }
}

void findLeftPeaks(figure_t& figure) {
    int minY = 0;
    int maxY = 0;
    int maxX = 0;

    for (pos_t i : figure.blockpos) {

        if (i.X > maxX) 
            maxX = i.X;
        if (i.Y > maxY)
            maxY = i.Y;
        if (i.Y < minY) 
            minY = i.Y;

    }

    for (int i = minY; i <= maxY; i++) {
        pos_t peak = { maxX, 0 };


        for (pos_t& i : findRow(figure, i))
        {
            if (i.X <= peak.X)
                peak = i;
        }

        figure.leftPeaks.push_back(peak);
    }
}



void findDownPeaks(figure_t& figure) {
    vector<pos_t> peaks;
    int maxX = 0;
    int minX = 0;
    int minY = 0;

    for (pos_t i : figure.blockpos) {

        if (i.X > maxX)
            maxX = i.X;
        if (i.X < minX) 
            minX = i.X;
        if (i.Y < minY) 
            minY = i.Y;

    }

    for (int i = minX; i <= maxX; i++) {
        pos_t peak = { 0, minY };

        for (pos_t& i : findColumn(figure, i))
        {
            if (i.Y >= peak.Y) 
                peak = i;
        }
        figure.downPeaks.push_back(peak);
    }

}

bool checkCollision(figure_t figure, collide_dir dir, bool check_my_pos = false) {

    if (dir == ANY && check_my_pos) {
        for (pos_t i : figure.downPeaks)
        {
            if (figure.absPos.Y + i.Y >= POLE_HEIGHT)
                return true;
        }
        for (pos_t i : figure.rightPeaks)
        {
            if (figure.absPos.X + i.X >= POLE_WIDTH)
                return true;
        }
        for (pos_t i : figure.leftPeaks)
        {
            if (figure.absPos.X + i.X < 0)
                return true;
        }
    }

    if (dir == DOWN || dir == ANY) {
        for (pos_t i : figure.downPeaks) {
            if (figure.absPos.Y + i.Y + 1 >= POLE_HEIGHT) return true;
            else if (field[figure.absPos.X + i.X][figure.absPos.Y + i.Y + 1]) return true;
            else if (check_my_pos && field[figure.absPos.X + i.X][figure.absPos.Y + i.Y]) return true;
        }
    }

    else if (dir == RIGHT || dir == ANY) {
        for (pos_t i : figure.rightPeaks) {
            if (figure.absPos.X + i.X + 1 >= POLE_WIDTH) return true;
            else if (field[figure.absPos.X + i.X + 1][figure.absPos.Y + i.Y]) return true;
            else if (check_my_pos && field[figure.absPos.X + i.X][figure.absPos.Y + i.Y]) return true;
        }
    }

    else if (dir == LEFT || dir == ANY) {
        for (pos_t i : figure.leftPeaks) {
            if (figure.absPos.X + i.X == 0) return true;
            else if (field[figure.absPos.X + i.X - 1][figure.absPos.Y + i.Y]) return true;
            else if (check_my_pos && field[figure.absPos.X + i.X][figure.absPos.Y + i.Y]) return true;
        }
    }

    return false;
}

void initPole(int width, int height) {
   
    field.resize(width);

    for (auto& i : field) {
        i.resize(height);
    }
}

void drawPole() {
    for (int i = 0; i < field.size(); i++) {
        vector<bool> column = field[i];

        for (int j = 0; j < column.size(); j++) {
            DrawRectangle(i * cell, j * cell, cell, cell, WHITE);
            DrawRectangle(i * cell + 5, j * cell + 5, 45, 45, (column[j]) ? col : BLACK);
        }
    }
    
    DrawText("Score:", 550, 100, 40, WHITE);
    DrawText(TextFormat("   %0i", score), 550, 150, 40, WHITE);
}




bool checkFullRow(int row) {
    for (int i = 0; i < POLE_WIDTH; i++)
    {
        if (!field[i][row]) return false;
    }
    score += 500;

    return true;
}

void clearFullRow(int row) {
    for (int i = 0; i < POLE_WIDTH; i++) 
        field[i][row] = false;
}

void moveRows(int start) {
    for (int i = start - 1; i >= 0; i--) {
        for (int j = 0; j < POLE_WIDTH; j++)
            field[j][i + 1] = field[j][i];
    }
}

void clearFullRows() {
    for (int i = 0; i < POLE_HEIGHT; i++) {
        if (checkFullRow(i)) {
            clearFullRow(i);
            moveRows(i);
        }
    }
}

void insertToPole(figure_t figure) {
    for (pos_t i : figure.blockpos)
        field[i.X + figure.absPos.X][i.Y + figure.absPos.Y] = true;
}

void removeFromPole(figure_t figure) {
    for (pos_t i : figure.blockpos)
        field[i.X + figure.absPos.X][i.Y + figure.absPos.Y] = false;

}

void moveFigureX(figure_t& figure, bool invert = false) {
    if (!invert && checkCollision(figure, RIGHT))
        return;
    else if (invert && checkCollision(figure, LEFT)) 
        return;

    removeFromPole(figure);
    if (!invert)
        figure.absPos.X++;
    else
        figure.absPos.X--;
    insertToPole(figure);
}

void moveFigureY(figure_t& figure) {
    if (checkCollision(figure, DOWN)) 
        return;

    removeFromPole(figure);
    figure.absPos.Y++;
    insertToPole(figure);
}

void jumpToFloor(figure_t& figure) {
    while (!checkCollision(figure, DOWN))
    {
        moveFigureY(figure);
    }
}

void normalizeFigure(figure_t& figure) {
    int minX = 0;
    int minY = 0;

    for (pos_t i : figure.blockpos) {
        if (i.X > minX) 
            minX = i.X;

        if (i.Y > minY) 
            minY = i.Y;
    }

    for (pos_t i : figure.blockpos) {
        if (i.X < minX) 
            minX = i.X;

        if (i.Y < minY) 
            minY = i.Y;
    }

    for (pos_t& i : figure.blockpos) {
        i.X -= minX;
        i.Y -= minY;
    }
}

void rotateFigure(figure_t& figure) {
    removeFromPole(figure);

    figure_t newFigure;
    newFigure.absPos = figure.absPos;
    newFigure.rotatePoint = figure.rotatePoint;

    for (int i = 0; i < figure.blockpos.size(); i++) {
        pos_t pos = figure.blockpos[i];
        pos_t rotatePointPos = figure.blockpos[figure.rotatePoint];

        pos_t newpos;
        newpos.X = rotatePointPos.Y - pos.Y;
        newpos.Y = pos.X - rotatePointPos.X;

        newFigure.blockpos.push_back(newpos);
    }

    normalizeFigure(newFigure);

    findRightPeaks(newFigure);
    findLeftPeaks(newFigure);
    findDownPeaks(newFigure);

    if (!checkCollision(newFigure, ANY, true)) 
        figure = newFigure;

    insertToPole(figure);
}

figure_t create_palka(pos_t pos) {
    figure_t figure;
    figure.absPos = pos;
    figure.rotatePoint = 1;
    figure.blockpos = { {0, 0}, {0, 1}, {0, 2}, {0, 3} };
    

    normalizeFigure(figure);

    findRightPeaks(figure);
    findLeftPeaks(figure);
    findDownPeaks(figure);

    col = BLUE;
    return figure;
}

figure_t create_palka(int X, int Y) 
{
    return create_palka({ X, Y }); 
}

figure_t create_J(pos_t pos) {
    figure_t figure;
    figure.absPos = pos;
    figure.rotatePoint = 1;
    figure.blockpos = { {0, 0}, {0, 1}, {0, 2}, {-1, 2} };
    ;

    normalizeFigure(figure);

    findRightPeaks(figure);
    findLeftPeaks(figure);
    findDownPeaks(figure);

    col = ORANGE;
    return figure;
}



figure_t create_J(int X, int Y)
{ 
    return create_J({ X, Y }); 
}

figure_t create_L(pos_t pos) {
    figure_t figure;
    figure.absPos = pos;
    figure.rotatePoint = 1;
    figure.blockpos = { {0, 0}, {0, 1}, {0, 2}, {1, 2} };
    

    normalizeFigure(figure);

    findRightPeaks(figure);
    findLeftPeaks(figure);
    findDownPeaks(figure);

    col = DARKBLUE;
    return figure;
}

figure_t create_L(int X, int Y)
{ 
    return create_L({ X, Y }); 
}

figure_t create_cube(pos_t pos) {
    figure_t figure;
    figure.absPos = pos;
    figure.rotatePoint = 0;
    figure.blockpos = { {0, 0}, {1, 0}, {0, 1}, {1, 1} };
    

    normalizeFigure(figure);

    findRightPeaks(figure);
    findLeftPeaks(figure);
    findDownPeaks(figure);

    col = YELLOW;

    return figure;
}

figure_t create_cube(int X, int Y)
{
    return create_cube({ X, Y }); 
}


figure_t create_S(pos_t pos) {
    figure_t figure;
    figure.absPos = pos;
    figure.rotatePoint = 2;
    figure.blockpos = { {0, 0}, {1, 0}, {-1, 1}, {0, 1} };
    


    normalizeFigure(figure);

    findRightPeaks(figure);
    findLeftPeaks(figure);
    findDownPeaks(figure);

    col = RED;

    return figure;
}

figure_t create_S(int X, int Y) 
{ 
    return create_S({ X, Y });
}

figure_t create_Z(pos_t pos) {
    figure_t figure;
    figure.absPos = pos;
    figure.rotatePoint = 2;
    figure.blockpos = { {0, 0}, {1, 0}, {1, 1}, {2, 1} };
    


    normalizeFigure(figure);

    findRightPeaks(figure);
    findLeftPeaks(figure);
    findDownPeaks(figure);

    col = RED;

    return figure;
}

figure_t create_Z(int X, int Y)
{ 
    return create_Z({ X, Y }); 
}

figure_t create_T(pos_t pos) {
    figure_t figure;
    figure.absPos = pos;
    figure.rotatePoint = 1;
    figure.blockpos = { {0, 0}, {1, 0}, {2, 0}, {1, 1} };
    



    normalizeFigure(figure);

    findRightPeaks(figure);
    findLeftPeaks(figure);
    findDownPeaks(figure);

    col = PURPLE;
    return figure;
}

figure_t create_T(int X, int Y)
{ 
    return create_T({ X, Y });
}

figure_t randomFigure() {

    int rand_numb = rand() % 7;

    switch (rand_numb) {
        case 0:
            return create_palka(3, 0);
            break;
        case 1:
            return create_J(4, 0);
            break;
        case 2:
            return create_L(4, 0);
            break;
        case 3:
            return create_cube(4, 0);
            break;
        case 4:
            return create_S(4, 0);
            break;
        case 5:
            return create_Z(4, 0);
            break;
        default:
            return create_T(4, 0);
            break;
    }
   
    
}

int main() {
    InitWindow(800, 1000, "Tetris");
    SetTargetFPS(60);

    initPole(POLE_WIDTH, POLE_HEIGHT);

    figure_t currentFigure = randomFigure();
    insertToPole(currentFigure);


    double start = GetTime();

    

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(BLACK);

        if (GetTime() - start >= 1) {
            if (checkCollision(currentFigure, DOWN)) {
                clearFullRows();
                currentFigure = randomFigure();

                insertToPole(currentFigure);

            }

            start = GetTime();
            moveFigureY(currentFigure);
        }

        else if (IsKeyDown(KEY_DOWN)) 
            moveFigureY(currentFigure);



        if (IsKeyPressed(KEY_RIGHT))
            moveFigureX(currentFigure); 

        if (IsKeyPressed(KEY_LEFT)) 
            moveFigureX(currentFigure, true);

        if (IsKeyPressed(KEY_UP)) 
            rotateFigure(currentFigure);

        if (IsKeyPressed(KEY_SPACE)) 
        {
            jumpToFloor(currentFigure);

            clearFullRows();
            currentFigure = randomFigure();

            insertToPole(currentFigure);
        }

        drawPole();


        EndDrawing();
    }
}