#include <cstdlib>
#include <ctime>
#include <iostream>
#include "Player.h"
using namespace std;

Player::Player()
{
    srand((unsigned) time(0));
    Xinput = 0;
    Yinput = 0;
}

int Player ::returnY()
{
    return Yinput;
}

int Player::returnX()
{
    return Xinput;
}


