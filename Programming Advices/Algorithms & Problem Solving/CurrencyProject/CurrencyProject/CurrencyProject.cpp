#include <iostream>
#include "clsCurrency.h"
#include "ShowCurrensyScreen.h"


template <typename T> T Max(T FirstNum, T SecondNum)
{
    return FirstNum > SecondNum ? FirstNum : SecondNum;
}

int main()

{
    cout << Max(1.3, 2.3);

    return 0;
}

