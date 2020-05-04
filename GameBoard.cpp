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
        ShipsArray[x].setAll(x);
    }

    for (int row = 0; row < ROWS; row++)
    {
        for (int col = 0; col < COLS; col++)
        {
            GameBoardArray[row][col] = '*';
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
            cout << setw(WIDTH) << GameBoardArray[row][col];
        }
        cout << endl << endl;
    }
}



void GameBoard::setXYpos() //needs to be a part of gameboard
{
    int xPos, yPos;

        for (int ship = 0; ship < MAXNUMSHIPS; ship++)
        {   
            cout << ShipsArray[ship].getShipName() << endl;
            cout << "-------------------" << endl;
            for(int coor = 0; coor < ShipsArray[ship].getShipSize(); coor++)
            {
                cout << "Enter the x position: ";
                cin >> xPos;
                cout << "Enter the y position: ";
                cin >> yPos;
                GameBoardArray[yPos][xPos] = ShipNamesArray[ship];
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
    int ship;

    xCoor = getZeroNine();
    cout << "The random x coordinate is " << xCoor << endl;
    yCoor = getZeroNine();
    cout << "The random y coordinate is " << yCoor << endl;

    ship = getZeroOrOne();
    cout << "Ship, which is a zero or one is " << ship << endl;

    if(ship == 0) //then x coordinate is constant the ship will be vertical
    {
        for(int ship = 0; ship < MAXNUMSHIPS; ship++)
        {   
            if(ShipsArray[ship].getShipSize() + yCoor > 9)
            {
                for(int coor = 0; coor < ShipsArray[ship].getShipSize(); coor++)
                {
                    GameBoardArray[yCoor--][xCoor] = ShipNamesArray[ship];
                }
            }
            else
            {
                for(int coor = 0; coor < ShipsArray[ship].getShipSize(); coor++)
                {
                    GameBoardArray[yCoor++][xCoor] = ShipNamesArray[ship];
                }            
            }
        }
    }
    else if(ship == 1)//the y coordinate is constant the shi will have horizontal placement
    {
        for(int ship = 0; ship < MAXNUMSHIPS; ship++)
        {
            if(ShipsArray[ship].getShipSize() + xCoor > 9)
            {
                for(int coor = 0; coor < ShipsArray[ship].getShipSize(); coor++)
                {
                    GameBoardArray[yCoor][xCoor--] = ShipNamesArray[ship];
                }
            }
            else
            {
                for(int coor = 0; coor < ShipsArray[ship].getShipSize(); coor++)
                {
                    GameBoardArray[yCoor][xCoor++] = ShipNamesArray[ship];
                }            
            }
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