#include "Ships.h"
#include <string>
#include <iostream>
using namespace std;

Ships::Ships()
{
    ShipName = "";
    ShipSize = 0;
    IsSunk = false;
    HitCount = 0;
}
//This constructor sets the ship name and size
//It also fills the ship hit vector to false
Ships::Ships(int index)
{   
   setAll(index);
}

//setters
void Ships::setAll(int index)
{
    ShipName = ShipNamesArray[index];
    ShipSize = ShipSizes[index];
    ShipHitsArray[index] = false;
    
}

void Ships::setHitCount(int hit)
{
    HitCount = hit;
}

void Ships::setHits(int hit)
{

}

void Ships::setIsSunk()
{

}


//getters

string Ships::getShipName()
{
    return ShipName;
}

int Ships::getShipSize()
{
    return ShipSize;
}

bool Ships::getIsSunk()
{
    return IsSunk;
}

int Ships::getHitCount()
{
    return HitCount;
}





