#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;


int main()
{   
    //srand((unsigned) time(0));

    
    //either 0 or 1
    srand(time(NULL));
    for (int x = 0; x < 10; x++)
    {
        int rand0or1 =  rand() % 2;
        cout << rand0or1 << endl;
    }
    

    //random number between 0 and 9
    
    int randomNumber;
    for(int x = 0; x < 10;x++)
    {
        randomNumber = (rand() % 10) + 0;
        cout << randomNumber;
    }


}

