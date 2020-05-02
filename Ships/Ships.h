#ifndef SHIPS_H
#define SHIPS_H
#include <string>
#include <vector>
#define SIZE 5

class Ships
{
    private:
    //vars for ship characteristics
        std::string ShipName;
        int ShipSize;
        bool IsSunk = false;
        bool computerSet;
        bool playerSet;
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


};

#endif