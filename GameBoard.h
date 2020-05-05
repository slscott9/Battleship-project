#ifndef GAMEBOARD_H
#define GAMEBOARD_H
#include <iomanip>
#include "Ships.h"
#include "Player.h"
#define ROWS 10
#define COLS 10
#define TENSIZE 10
#define WIDTH 8
class GameBoard
{
    private:
        char ShipAbrev[MAXNUMSHIPS] ={'P','S','D','B','C'};
        std::string ShipNames[MAXNUMSHIPS] = {"Patrol Boat","Submarine","Destroyer","Battleship","Carrier"};
        int ShipSizes[MAXNUMSHIPS] = {2,3,3,4,5};

        Ship Ships[MAXNUMSHIPS]; //contains each ship
        Player player;
        Player Computer;

        char Board[ROWS][COLS]; //actual game board
        int headerArray[COLS] {0,1,2,3,4,5,6,7,8,9}; //Displays x coordinates
        int sideArray[ROWS] = {0,1,2,3,4,5,6,7,8,9}; //Displays y coordinates

    public:
    //constructor
        GameBoard();
    
    //setters
        void setP1ships();
        void setCompShips();

    //functions set a ships coordinates

    //function check if the computer is off the board or if spot is filled
        bool offBoard(int, int);
        bool isXYfilled(int xpos, int ypos);


    //getters
     

    //This function displays the game board
        void displayBoard();



    




        

};

#endif
