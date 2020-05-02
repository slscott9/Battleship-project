#ifndef GAMEBOARD_H
#define GAMEBOARD_H
#define ROWS 10
#define COLS 10
#define TENSIZE 10
#define WIDTH 8
#define SIZE 5
#include <iomanip>
#include "Ships.h"
#include "vector"

class GameBoard
{
    private:
        std::vector<Ships>P1ShipsVect;
        std::vector<Ships>CompShipsVect;
        char P1GameBoardArray[ROWS][COLS];
        char CompGameBoardArray[ROWS][COLS];
        int headerArray[COLS] {0,1,2,3,4,5,6,7,8,9}; //x coordinates
        int sideArray[ROWS] = {0,1,2,3,4,5,6,7,8,9}; //y coordinates
    public:
    //constructor
        GameBoard(Ships &, Ships&, Ships&, Ships&, Ships&);
                  //Ships&, Ships&, Ships&, Ships&, Ships&);fills the game board with * when instance of gameboard is created

    //This function displays the game board
        void displayBoard();

    //Fill Board With Ships
        void FillBoard();

    
        

};

#endif
