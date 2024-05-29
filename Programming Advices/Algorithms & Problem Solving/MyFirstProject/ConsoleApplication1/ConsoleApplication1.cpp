#include <iostream>
#include <string.h>
#include <random>
#include <string>

using namespace std;

int RandomNumber(int From, int To)
{
    //Function to generate a random number
    int randNum = rand() % (To - From + 1) + From;
    return randNum;
}

void ReturnRandomMatrix(int Matrix[3][3])
{

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            Matrix[i][j] = RandomNumber(1, 100);
        }
    }
}

void PrintMatrix(int Matrix[3][3])
{
    cout << "\nMatrix Elements: \n";
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << Matrix[i][j] << "\t\t";
        }
        cout << endl;
    }
}

int main()
{
    //Seeds the random number generator in C++, called only onc
    srand((unsigned)time(NULL));
    
    int TestArray[3][3];
    ReturnRandomMatrix(TestArray);
    PrintMatrix(TestArray);

}


