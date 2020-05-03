#include "Ships.h"
#include <string>
#include <iostream>
using namespace std;

//This constructor sets the ship name and size
//It also fills the ship hit vector to false
Ships::Ships(int nameInput, int sizeInput, bool isCompSetting, bool isPlayerSetting)
{   
    cout << "In constructor" << endl;
    ShipName = ShipNamesArray[nameInput];
    cout << "after shipname var" << endl;
    ShipSize = sizeInput;
    cout << "After shipsize var " << endl;
    computerSet = isCompSetting;
    cout << "After computer set var " << endl;
    playerSet = isPlayerSetting;
    cout << "After player set var " << endl;
    


    for (int x = 0; x < sizeInput; x++)
    {   
        cout << "In for loop to set shihitVect " << endl;
        ShipHitsArray[x] = false;
        cout << "After shihitsVect = false" << endl;
    }
    cout << "After for loop " << endl;
}

//setters
void Ships::setXYpos()
{
    /*if(computerSet == true)
    {
        for(int x = 0; x < ShipSize; x++)
        {
            
        }
    }*/
    cout << "In xy position set function";
    if(playerSet)
    {
        for (int x = 0; x < ShipSize; x++)
        {   
            cout << "Enter the " << ShipSize << " x and y positions for your " << ShipName << endl;
            cout << " x position " << x+1 << ": ";
            cin >> XPosVect[x];
            cout << "y position " << x+1 << ": ";
            cin >> YposVect[x];
        }
    }
}


//getters
bool Ships::getIsSunk()
{
    return IsSunk;
}

int Ships::getHitCount()
{
    return HitCount;
}

int Ships::getShipSize()
{
    return ShipSize;
}

int Ships::getXpos(int index)
{
    return XPosVect[index];
}

int Ships::getYpos(int index)
{
    return YposVect[index];
}