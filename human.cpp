#include "human.h"
#include <iostream>
using namespace std;

Human::Human() : Player()
{
    
}

void Human::setXYinput()
{
    cout << "Enter the x coordinate: ";
    cin >> Xinput;
    cout << "Enter the y coordinate: ";
    cin >> Yinput;
    
}

void Human::setShips() //redefined virtual function from gameboard base class
{
    for (int ship = 0; ship < MAXNUMSHIPS; ship++)
    {   
        cout << Ships[ship].getShipName() << endl;
        cout << "-------------------" << endl;
        for(int coorIndex = 0; coorIndex < Ships[ship].getShipSize(); coorIndex++)
        {
            setXYinput();
            Ships[ship].setCoor(returnX(), returnY(), coorIndex);

            int x = Ships[ship].getShipXCoor(coorIndex);
            int y = Ships[ship].getShipYCoor(coorIndex);

            Board[y][x] = Ships[ship].getShipAbrev();
            displayBoard();  
        }
    }
}