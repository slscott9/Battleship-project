#include "GameBoard.h"
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
using namespace std;

//constructor fills the gameboard with astericks
GameBoard::GameBoard()
{   
    srand((unsigned) time(0));

    for (int x = 0; x < MAXNUMSHIPS; x++)
    {
        Ships[x].setAll(x);
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



void GameBoard::setXYpos() //needs to be a part of gameboard
{
    int xPos, yPos;

        for (int ship = 0; ship < MAXNUMSHIPS; ship++)
        {   
            cout << Ships[ship].getShipName() << endl;
            cout << "-------------------" << endl;
            for(int coor = 0; coor < Ships[ship].getShipSize(); coor++)
            {
                cout << "Enter the x position: ";
                cin >> xPos;
                cout << "Enter the y position: ";
                cin >> yPos;
                Board[yPos][xPos] = ShipNames[ship];
            }
            displayBoard();
        }
}




int GameBoard::ValidateVertHoriz()
{   
    int Choice;
    cout << "Enter 1 for vertical placement or 2 for horizontal placement: ";
    while(!(cin >> Choice)||Choice != 1 && Choice != 2)
    {
        cout << "Error choice must be 1 or 2 enter again: ";
        cin.clear();
        cin.ignore();
        
    }
    return Choice;
}

void GameBoard::setCompXY()
{   

    int xCoor, yCoor;
    int *ptrXcoor = &xCoor;
    int *ptrYcoor = &yCoor;

    bool isVertical;

    xCoor = getZeroNine();
    cout << "The random x coordinate is " << xCoor << endl;
    yCoor = getZeroNine();
    cout << "The random y coordinate is " << yCoor << endl;

    isVertical = getZeroOrOne();
    cout << "Ship, which is a zero or one is " << isVertical << endl;

    if(isVertical) //then x coordinate is constant the ship will be vertical
    {
        for(int ship = 0; ship < MAXNUMSHIPS; ship++)
        {   
            if(Ships[ship].getShipSize() + yCoor > 9)
            {
                for(int coor = 0; coor < Ships[ship].getShipSize(); coor++)
                {
                    Board[yCoor--][xCoor] = ShipNames[ship];
                }
            }
            else // Y coordinate is constant the ship will be horizontal
            {
                for(int coor = 0; coor < Ships[ship].getShipSize(); coor++)
                {
                    Board[yCoor++][xCoor] = ShipNames[ship];
                }            
            }
           checkIfFilled(ptrXcoor, ptrYcoor);
        }
    }
    else //the y coordinate is constant the shi will have horizontal placement
    {
        for(int ship = 0; ship < MAXNUMSHIPS; ship++)
        {
            if(Ships[ship].getShipSize() + xCoor > 9)
            {
                for(int coor = 0; coor < Ships[ship].getShipSize(); coor++)
                {
                    Board[yCoor][xCoor--] = ShipNames[ship];
                }
            }
            else
            {
                for(int coor = 0; coor < Ships[ship].getShipSize(); coor++)
                {
                    Board[yCoor][xCoor++] = ShipNames[ship];
                }            
            }
            checkIfFilled(ptrXcoor, ptrYcoor);
            
        }    
    }
}


int GameBoard::getZeroOrOne()
{
    //either 0 or 1
    //srand(time(NULL));
    int rand0or1 =  rand() % 2;

    return rand0or1;
}

int GameBoard::getZeroNine()
{   
    //srand((unsigned) time(0));

    //srand(time(NULL));
    //int randomNumber = rand() % 10;
    int randomNumber = (rand() % 10) + 0;

    return randomNumber;
    
}

void GameBoard::checkIfFilled(int *ptrXcoor, int *ptrYcoor)
{
    *ptrXcoor = getZeroNine();
    *ptrYcoor = getZeroNine();
    while(Board[*ptrYcoor][*ptrXcoor] != '*')
    {
        *ptrXcoor = getZeroNine();
        *ptrYcoor = getZeroNine();
    }
}