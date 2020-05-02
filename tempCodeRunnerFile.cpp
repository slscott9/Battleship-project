#include <iostream>
#include <iomanip>
using namespace std;

const int ROWS = 10;
const int COLS = 10;
const int SIZE = 10;
const int width = 8;
int main()
{   
    char GameBoardArray[ROWS][COLS];
    int headerArray[COLS] {0,1,2,3,4,5,6,7,8,9};
    int sideArray[ROWS] = {0,1,2,3,4,5,6,7,8,9};
    for (int row = 0; row < ROWS; row++)
    {   
        for (int col = 0; col < COLS; col++)
        {
             GameBoardArray[row][col] = '*';
        }
    }
     cout << '\t';

    for (int x = 0; x < SIZE; x++)
    {
        cout << setw(width) << headerArray[x];
    }
    cout << endl << endl;
    

    for (int row = 0; row < ROWS; row++)
    {   
        cout << setw(width) << sideArray[row];

        for (int col = 0; col < COLS; col++)
        {
            cout << setw(width) << GameBoardArray[row][col];
        }
        cout << endl << endl;
    }
}

