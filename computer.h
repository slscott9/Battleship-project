#ifndef COMPUTER_H
#define COMPUTER_H
#include "Player.h"
#include "GameBoard.h"


class Computer : public Player, GameBoard
{
    protected:
        bool isVertical;
    public:
    //constructors
        Computer();
        
        void setXYinput();//redefined virtual function
        void setShips(); //redefined virutal function

        int getZeroNine();//generates random 0 - 9 for x and y coord
        bool setVertical();//generates 1 for vertical or 0 for hoizontal

        bool getIsVert(); //returns isVertical variable


};

#endif