#include <cmath>
#include <iostream>

const char FULL_CHAR = '*';
const char EMPTY_CHAR = ' ';
const int BOARD_SIZE = 50;
const int MID_COORD = (int) BOARD_SIZE / 2;

char circle[BOARD_SIZE][BOARD_SIZE];

void printCircle() 
{
    for (int x = 0; x < BOARD_SIZE; x++) {

        char line[BOARD_SIZE + 1];

        for (int y = 0; y < BOARD_SIZE; y++) line[y] = circle[x][y] ? circle[x][y] : EMPTY_CHAR;
        
        line[BOARD_SIZE] = '\0';

        puts(line);

    }
}

void point(int x, int y) 
{
    circle[x + MID_COORD][y + MID_COORD] = FULL_CHAR;
}

void drawCircle(int r, int n) 
{
    for(int angle = 0; angle < 360; angle += (int)(360 / n)) {
      int x = r * cos(angle); 
      int y = r * sin(angle);
      
      point(x, y);
    }
}

int main(int argc, char *argv[]) 
{
    const int RADIUS = std::stoi(argv[1]);
    const int VERTICE_COUNT = argv[1] ? std::stoi(argv[2]) : 360;

    drawCircle(RADIUS, VERTICE_COUNT);
    printCircle();
}