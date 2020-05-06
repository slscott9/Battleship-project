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
    bool isShip, isVertical, isNegative;
    int xCoor, yCoor,shipSize;


   for(int ship = 0; ship < MAXNUMSHIPS; ship++)
   {       
       cout << "Before do while " << endl;
       do
       {    
           cout << "IN do while" << endl;
            Computer.setVertical();
            isVertical = Computer.getIsVert(); //if false then horizontal
            
            cout << "Isvertical " << isVertical << endl;

            xCoor = Computer.returnX();
            yCoor = Computer.returnY();
            shipSize = Ships[ship].getShipSize();

            isNegative = getGoodLocation(xCoor, yCoor, shipSize, isVertical);
            isShip = checkIfSHip(isVertical,isNegative, xCoor, yCoor, ship);       
        } while (isShip);

        cout << "x is " << xCoor << " Y is " << yCoor << endl;
        if(isVertical)
        {   
            int dir = 1;
            if(isNegative ) dir=-1;
            for(int y = yCoor; y < Ships[ship].getShipSize(); y+=dir)
            {
                Board[y][xCoor] = Ships[ship].getShipAbrev();
            }
        }
        else
        {
            int dir = 1;
            if(isNegative ) dir=-1;
            for(int x = xCoor; x < Ships[ship].getShipSize(); x+=dir)
            {
                Board[yCoor][x] = Ships[ship].getShipAbrev();
            }
        }
       
   }
}

bool GameBoard::getGoodLocation(int xcoor, int ycoor, int shipSize, bool isVertical)
{   
    int x = xcoor;
    int y = ycoor;
    bool isNegative = true; //if false we go positive

    if(isVertical) // we are going up or down
    {
        if(IsYoffBoardNeg(y, shipSize))
        {
            isNegative = false;
        }
        else if(IsYoffBoardPos(y, shipSize))
        {
            isNegative = true;
        }
    }
    else // we are going side to side
    {
        if(IsXoffBoardNeg(x, shipSize))
        {
            isNegative = false;
        }
        else if(IsXoffBoardPos(x, shipSize))
        {
            isNegative = true;
        }
    }
    return isNegative;
    //at this point we have determined which directon to put the ship
    
}

bool GameBoard::checkIfSHip(bool isVert, bool isNegative, int x , int y, int shipIndex)
{   
    if(isVert)
    {
        if(isNegative)
        {
            for(int x = 0; x < Ships[shipIndex].getShipSize(); x++)
            {
                if(checkCoor(x,y--,Ships[shipIndex].getShipSize()))
                {
                    return true;
                }
            }
        }
        else if(isNegative == false)
        {
            for(int x = 0; x < Ships[shipIndex].getShipSize(); x++)
            {
                if(checkCoor(x,y++,Ships[shipIndex].getShipSize()))
                {
                    return true;
                }
            }
        }
        else
        {
            return true;
        }
    }

    if(isVert == false)
    {
        if(isNegative)
        {
            for(int x = 0; x < Ships[shipIndex].getShipSize(); x++)
            {
                if(checkCoor(x--,y,Ships[shipIndex].getShipSize()))
                {
                    return true;
                }
            }
        }
        else if(isNegative == false)
        {
            for(int x = 0; x < Ships[shipIndex].getShipSize(); x++)
            {
                if(checkCoor(x++,y,Ships[shipIndex].getShipSize()))
                {
                    return true;
                }
            }
        }
        else
        {
            return true;
        }
    }

    return false;
}

bool GameBoard::checkCoor(int x, int y, int shipSize)
{
    
    if(Board[y][x] != '*')
    {
        return true;
    }
    return false;
}


bool GameBoard::IsXoffBoardPos(int x, int shipSize)
{
    if(shipSize + x-1 > 9)
    {
        return true;
    }
}

bool GameBoard::IsYoffBoardPos(int y, int shipSize)
{
    if(shipSize + y - 1 > 9)
    {
        return true;
    }
}

bool GameBoard::IsXoffBoardNeg(int x , int shipSize)
{
    if(x+1 - shipSize < 0)
    {
        return true;
    }
}

bool GameBoard::IsYoffBoardNeg(int y, int shipSize)
{
    if(y+1 - shipSize < 0)
    {
        return true;
    }
}   











