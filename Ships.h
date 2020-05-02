#ifndef SHIPS_H
#define SHIPS_H
#include <string>
#include <vector>

class Ships
{
    private:
    //vars for ship characteristics
        std::string ShipName = "";
        int ShipSize = 0;
        bool IsSunk = false;
        bool computerSet = false;
        bool playerSet = false;
        std::vector<std::string>ShipNamesVect = {"Patrol Boat","Submarine","Destroyer","Battleship","Carrier"};
    //var for number of hits on ship
        int HitCount = 0;
    //parallel arrays for x and y positions and if that position is a hit
        std::vector<bool> ShipHitsVect;
        std::vector<int> XPosVect;
        std::vector<int> YposVect;

    public:
        Ships( int, int, bool, bool);
    //setters
        void setXYpos();
        
        void setHits(int);
        void setHitCount(int);
        void setIsSunk();
    //getters
        bool getIsSunk();
        int getHitCount();
        int getShipSize();
        int getXpos(int);
        int getYpos(int);


};

#endif