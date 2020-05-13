#include "computer.h"
#include <iostream>
using namespace std;


//constructor
Computer::Computer() : Player()
{
    setVertical(); // sets Computers isVertical member
    setXYinput();
}


//function to get randomly generated computer numbers and set them to x and y coordinates
void Computer::setXYinput()
{   
    Xinput = getZeroNine();

    Yinput = getZeroNine();
}

//function for the computer player

bool Computer::getIsVert()
{
    return isVertical;
}

int Computer::getZeroNine()
{   
    //srand((unsigned) time(0));

    //srand(time(NULL));
    //int randomNumber = rand() % 10;
    int randomNumber = (rand() % 10) + 0;

    return randomNumber;
    
}


bool Computer::setVertical()
{
    //either 0 or 1
    //srand(time(NULL));
    int rand0or1 =  rand() % 2;

    if(rand0or1 == 1)
    {
        isVertical = true;
    }
    else
    {
        isVertical = false;
    }
    
}


void Computer::setShips()
{   
    enum xDir {RIGHT = 1, XNOCHANGE = 0, LEFT = -1};
    enum yDir {DOWN = 1, YNOCHANGE = 0, UP = -1};

    xDir Xdirection = RIGHT;
    yDir Ydirection = DOWN;

    int shipsSetup = 0;

    for(int ship = 0; ship < MAXNUMSHIPS; ship++)
    {   
        bool good = true;
        do
        {   
            good = true;

            setXYinput(); //x and y randomly chosen
            setVertical(); //verticle is chosen 0 for horizontal 1 for vertical

            if(getIsVert())
            {   
                 Xdirection = XNOCHANGE;
                if((returnY() + Ships[ship].getShipSize()-1) > 9)
                {   
                     Ydirection = UP;
                }
                else
                {
                    Ydirection = DOWN;
                }
                
            }
            else
            {   
                 Ydirection = YNOCHANGE;
                if((returnX() + Ships[ship].getShipSize() - 1) > 9)
                {   
                     Xdirection = LEFT;
                }
                else
                {
                    Xdirection = RIGHT;
                }
                
            }//end if vertical

            int x = returnX();
            int y = returnY();

            for(int coor = 0; coor < Ships[ship].getShipSize(); coor++)
            {   
                if(boardIsShipsHit(x,y,shipsSetup))
                {
                    good = false;
                    cout << "         In nested for loop if statement for is a hit" << endl;
                    break;
                }
                else
                {   
                     y+=Ydirection;
                     x+=Xdirection;
                }
                
            }//end nested for
            
            if(good)
            {   
                x = returnX();
                y = returnY();
                for(int coor = 0; coor < Ships[ship].getShipSize(); coor++)
                {
                    Ships[ship].setCoor(x,y,coor);
                    Board[y][x] = Ships[ship].getShipAbrev();
                   
                    y+=Ydirection;
                    x+=Xdirection;
                }
            }
            //cin.get();

        } while (!good);

        shipsSetup++;

        
    }//end first for

}//end of function
