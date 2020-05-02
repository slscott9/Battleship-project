#ifndef GAMEBOARD_H
#define GAMEBOARD_H
#define ROWS 10
#define COLS 10
#define SIZE 10
#define WIDTH 8
#include <iomanip>

class GameBoard
{
    private:
        char GameBoardArray[ROWS][COLS];
        int headerArray[COLS] {0,1,2,3,4,5,6,7,8,9};
        int sideArray[ROWS] = {0,1,2,3,4,5,6,7,8,9};
    public:
        GameBoard();
        void displayBoard();
        

};

#endif
