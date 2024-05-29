

#include <iostream>
#include "clsHarmashTrayning.h"


using namespace std;

int ReadInt()
{
    cout << "Enter a Number You Want ...? ";
    int Number;
    do
    {
        cin >> Number;
    } while (Number <=0);
    
    return Number;
}

int main()
{

   cout << clsHarmashTrayning::ReplaceAll("Jihad Smadi Hello world","Hello","Bayy");

    return 0;
}

