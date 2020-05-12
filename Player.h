#ifndef PLAYER_H
#define PLAYER_H
#include "GameBoard.h"

class Player : public GameBoard
{
    protected:
        int Xinput;
        int Yinput;
    public:
    //constructor 
        Player();
    //setters
        virtual void setXYinput()= 0; //virtual function redefined in human class and computer class

    //getters
        int returnX();
        int returnY();

       
                    
};

#endif 

