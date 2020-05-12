#ifndef HUMAN_H
#define HUMAN_H
#include "Player.h"

class Human : public Player
{
    public:
        Human();
    //setters
        void setXYinput();
        void setHumanShips();//virtual redefined

};

#endif