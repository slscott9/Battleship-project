#include "GameBoard.h"
#include <iostream>
#include <iomanip>

using namespace std;

//constructor fills the gameboard with astericks
GameBoard::GameBoard()
{   
    for (int x = 0; x < MAXNUMSHIPS; x++) //sets each ship instance variables 
    {
        Ships[x].setAll(ShipNames[x], ShipAbrev[x], ShipSizes[x]);
    }
    for (int row = 0; row < ROWS; row++)
    {
        for (int col = 0; col < COLS; col++)
        {
            Board[row][col] = '*';
        }
    }
}

void GameBoard::displayBoard()
{   
    cout << '\t'; //tabs header number over

    for (int x = 0; x < TENSIZE; x++)
    {
        cout << setw(WIDTH) << headerArray[x]; //prints header numbers 0 - 9
    }
    cout << endl << endl;

//prints side numbers then game board
    for (int row = 0; row < ROWS; row++)
    {   
        cout << setw(WIDTH) << sideArray[row];

        for (int col = 0; col < COLS; col++)
        {
            cout << setw(WIDTH) << Board[row][col];
        }
        cout << endl << endl;
    }
}

//function to fill the board with ship positions
void GameBoard::fillBoard()
{
    for(int ship = 0; ship < MAXNUMSHIPS; ship++)
    {
        for(int coor = 0; coor < Ships[ship].getShipSize();coor++)
        {
            int x = Ships[ship].getShipXCoor(coor);
            int y = Ships[ship].getShipYCoor(coor);
            Board[y][x] = Ships[ship].getShipAbrev();
        }
    }
}
//function to set all of player one's ships coordinates
void GameBoard::setP1ships()
{
    for (int ship = 0; ship < MAXNUMSHIPS; ship++)
    {   
        cout << Ships[ship].getShipName() << endl;
        cout << "-------------------" << endl;
        for(int coorIndex = 0; coorIndex < Ships[ship].getShipSize(); coorIndex++)
        {
            player.setXYinput();
            Ships[ship].setCoor(player.returnX(), player.returnY(), coorIndex);

            int x = Ships[ship].getShipXCoor(coorIndex);
            int y = Ships[ship].getShipYCoor(coorIndex);

            Board[y][x] = Ships[ship].getShipAbrev();
            displayBoard();  
        }
    }
}



void GameBoard::setCompShips()
{
    for (int ship = 0; ship < MAXNUMSHIPS; ship++)
    {   
        Computer.setCompXY();
        for(int coorIndex = 0; coorIndex < Ships[ship].getShipSize(); coorIndex++)
        {   
            int x = Computer.returnX();
            int y = Computer.returnY();
            if(offBoard(ship, Computer.returnX()))
            {   
                Ships[ship].setCoor(y, x--, coorIndex);
            }
            else if(offBoard(ship, Computer.returnY()))
            {
                Ships[ship].setCoor(y--, x, coorIndex);
            } 
        }
    }
}
//function uses Ships class setCoor function to set a ship and a single coordinate
//use this in a loop in gameboard





bool GameBoard::offBoard(int index, int coor)
{
    if(Ships[index].getShipSize() + coor > 9)
    {
        return true;
    }
    return false;
}


bool GameBoard::isXYfilled(int xPos, int yPos)
{
    if(Board[yPos][xPos] != '*')
    {
        return true;
    }
    return false;
    
}












