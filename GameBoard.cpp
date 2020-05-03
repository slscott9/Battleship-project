#include "GameBoard.h"
#include <iostream>
using namespace std;

//constructor fills the gameboard with astericks
GameBoard::GameBoard()
{   
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

    /*for(int ship = 0; ship < 10; ship++)
    {
        for(int coor = 0; coor < P1ShipsVect[ship].getShipSize(); coor++)
        {
            P1GameBoardArray[P1ShipsVect[ship].getXpos(coor)][P1ShipsVect[ship].getYpos(coor)] = 'x';
            //CompGameBoardArray[CompShipsVect[ship].getXpos(coor)][CompShipsVect[ship].getYpos(coor)] = 'o';
        }
    }*/


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


/*int Ships::getXpos(int index)
{
    return XPosArray[index];
}

int Ships::getYpos(int index)
{
    return YposArray[index];
}*/


