#ifndef HUMAN_H
#define HUMAN_H
#include "Player.h"
#include "GameBoard.h"

class Human : public Player, GameBoard
{
    public:
        Human();
    //setters
        void setXYinput();
        void setShips();//virtual redefined

};

#endif