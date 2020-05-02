#include "GameBoard.h"
#include "Ships.h"
#include <iostream>
#include <vector>
using namespace std;

int main()
{   

    cout << "Hello";
    Ships carrier(4, 5, false, true);
     //Battleship(3, 4, false, true), Destroyer(2, 3, false, true),
    //Sub(1, 2, false, true), patrol(0, 1, false, true);
    
    carrier.setXYpos();

    /*carrier.setXYpos();
    Battleship.setXYpos();
    Destroyer.setXYpos();
    Sub.setXYpos();
    patrol.setXYpos();*/

    //GameBoard board(carrier, Battleship, Destroyer, Sub, patrol);

    //board.displayBoard();

}