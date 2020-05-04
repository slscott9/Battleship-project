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
        char ShipNames[MAXNUMSHIPS] ={'P','S','D','B','C'};

        Ships Ships[MAXNUMSHIPS]; //contains each ship
       
        char Board[ROWS][COLS];

        int headerArray[COLS] {0,1,2,3,4,5,6,7,8,9}; //x coordinates
        int sideArray[ROWS] = {0,1,2,3,4,5,6,7,8,9}; //y coordinates

    public:
    //constructor
        GameBoard();
    //setter gets user input for ship coor and fills board
        void setXYpos(); 

    //This function displays the game board
        void displayBoard();


        //Validation function for vertical or horizontal
        int ValidateVertHoriz();

    
    //computer set shps 
        void setCompXY();
        void checkIfFilled(int *, int *);
        int getZeroOrOne();//generates 1 for vertical or 0 for hoizontal
        int getZeroNine();//generates random 0 - 9 for x and y coord

};

#endif
