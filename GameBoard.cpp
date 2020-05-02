#include "GameBoard.h"
#include <iostream>
using namespace std;

//constructor fills the gameboard with astericks
GameBoard::GameBoard(/*Ships &Ccarrier, Ships &CBattleShip, Ships &Cdestroyer, Ships &Csub, Ships &Cpatrol,*/Ships &Pcarrier, Ships &PbattleShip, Ships &Pdestroyer, Ships &Psub, Ships &Ppatrol)
{   
    P1ShipsVect = {Pcarrier, PbattleShip, Pdestroyer, Psub, Ppatrol};
    //CompShipsVect = {Ccarrier, CBattleShip, Cdestroyer, Csub, Cpatrol};

    for (int row = 0; row < ROWS; row++)
    {
        for (int col = 0; col < COLS; col++)
        {
            P1GameBoardArray[row][col] = '*';
            //CompGameBoardArray[row][col] = '*';
        }
    }

    for(int ship = 0; ship < 10; ship++)
    {
        for(int coor = 0; coor < P1ShipsVect[ship].getShipSize(); coor++)
        {
            P1GameBoardArray[P1ShipsVect[ship].getXpos(coor)][P1ShipsVect[ship].getYpos(coor)] = 'x';
            //CompGameBoardArray[CompShipsVect[ship].getXpos(coor)][CompShipsVect[ship].getYpos(coor)] = 'o';
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
            cout << setw(WIDTH) << P1GameBoardArray[row][col];
        }
        cout << endl << endl;
    }
}