#ifndef PLAYER_H
#define PLAYER_H

class Player
{
    protected:
        int Xinput;
        int Yinput;
        int xShot;
        int yShot;
    public:
    //constructor 
        Player();
    //setters
        virtual void setXYinput() = 0; //virtual function redefined in human class and computer class
        virtual void setShips() = 0;
        virtual void getXshot();
        virtual void getYshot();

    //getters
        int returnX();
        int returnY();

       
                    
};

#endif 

