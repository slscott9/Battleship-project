#ifndef SHIPS_H
#define SHIPS_H
#include <string>
#include <vector>
#define MAXNUMSHIPS 5

class Ships
{
    private:
    //vars for ship characteristics
        std::string ShipNamesArray[MAXNUMSHIPS] = {"Patrol Boat","Submarine","Destroyer","Battleship","Carrier"};
        int ShipSizes[MAXNUMSHIPS] = {2,3,3,4,5};
        bool ShipHitsArray[MAXNUMSHIPS];
        
        std::string ShipName;
        int ShipSize;
        bool IsSunk;
        int HitCount;
        

    public:
    //constructor
        Ships();
        Ships(int);

    //setters
        void setAll(int);

        void setHitCount(int); //keep in ships

        void setHits(int);//keep in ships

        
        void setIsSunk(); //keep in ships
    //getters
        std::string getShipName();

        int getShipSize(); //keep

        bool getIsSunk(); //keep

        int getHitCount(); //keep
   


        
    


};

#endif