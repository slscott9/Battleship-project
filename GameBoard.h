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
        
        bool XoffPositve, XoffNeg, YoffPositive, YoffNeg;

        char Board[ROWS][COLS]; //actual game board
        int headerArray[COLS] {0,1,2,3,4,5,6,7,8,9}; //Displays x coordinates
        int sideArray[ROWS] = {0,1,2,3,4,5,6,7,8,9}; //Displays y coordinates

    public:
    //constructor
        GameBoard();
    
    //setters
        void setP1ships();
        void setCompShips();

    //This function displays the game board
        void displayBoard();

    //These function will be for on board validation checking
        bool getGoodLocation(int, int, int, bool);
        bool IsXoffBoardPos(int, int);
        bool IsYoffBoardPos(int, int);
        bool IsYoffBoardNeg(int, int);
        bool IsXoffBoardNeg(int, int);

    //these functions will check if there is a ship on the coordinate
        bool checkIfSHip(bool, bool, int, int, int);
        bool checkCoor(int, int, int);


    




        

};

#endif
