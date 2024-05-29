#pragma once

#include <iostream>
#include <string.h>
#include <string>

using namespace std;


namespace MyInputsLib
{

	int ReadNumberInTheRange(int From, int To, string Messege)
	{
		int Number = 0;
		do
		{
			cout << Messege;
			cin >> Number;
		} while (Number < From || Number > To);

		return Number;
	}

	float ReadFloatNumberInTheRange(int From, int To, string Messege)
	{
		float FNumber = 0;
		do
		{
			cout << Messege;
			cin >> FNumber;
		} while (FNumber < From || FNumber > To);

		return FNumber;

	}

	int ReadValidNumber(string messege)
	{
		int number = 0;

		cout << messege << endl;
		cin >> number;

		while (cin.fail())
		{
			cin.clear();
			cin.ignore(std::numeric_limits < std::streamsize > ::max(), '\n');
			

			cout << "Invalid Input , Enter valid Number ? \n";
			cin >> number;
		}
		return number;
	}

	void ReturnMultiplicationArray(int ResultArray[11][11])
	{

		for (int i = 0; i <= 10; i++)
		{

			for (int j = 0; j <= 10; j++)
			{
				ResultArray[i][j] = i * j;
			}
		}

	}

	void Swap(int* Number1, int* Number2)
	{
		int temp;

		temp = *Number1;
		*Number1 = *Number2;
		*Number2 = temp;

	}

	void PrintTime()
	{
		time_t t = time(0);
		char* dt = ctime(&t);
		cout << dt << endl;

		tm* gmtm = gmtime(&t);
		dt = asctime(gmtm);
		cout << dt << endl;
	}
}


