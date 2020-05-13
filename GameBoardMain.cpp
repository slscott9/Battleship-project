#include "GameBoard.h"
#include "Player.h"
#include "computer.h"
#include "human.h"
#include "Ships.h"
#include <iostream>
using namespace std;

int main()
{   
    
        Player *ptrHuman = new Human;

        Human hum;
        GameBoard board;

        hum.setShips();

        board.displayBoard();


  
}