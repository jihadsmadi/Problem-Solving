#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class clsHarmashTrayning
{

private:



public:

	//Sheap One 
	static void PrintShape1_1(int Lines)
	{

		for (int i = 1; i <= Lines; i++)
		{
			for (int j = i; j > 0; j--)
			{
				cout << "*";
			}
			cout << "\n";
		}
	}

	static void PrintShape1_2(int Lines)
	{

		for (int i = 1; i <= Lines; i++)
		{
			for (int j = 1; j <= Lines - i; j++)
			{
				cout << " ";
			}
			
			for (int c = 0; c<i; c++)
			{
				cout << "*";
			}
			cout << "\n";
		}
	}

	static void PrintShape1_3(int Lines)
	{

		for (int i = Lines; i >0 ; i--)
		{
			for (int j = i; j > 0; j--)
			{
				cout << "*";
			}
			cout << "\n";
		}
	}

	static void PrintShape1_4(int Lines)
	{
		for (int i = Lines; i > 0; i--)
		{
			for (int j = Lines - i; j > 0; j--)
			{
				cout << " ";
			}

			for (int c = i; c > 0; c--)
			{
				cout << "*";
			}
			cout << "\n";
		}
	}

	static void PrintShape1_5(int Lines,int Rows)
	{
		for (int i = 1; i <= Lines; i++)
		{
			for (int j = Lines - i; j > 0; j--)
			{
				cout << " ";
			}

			for (int c = 1; c <= Rows; c++)
			{
				cout << "*";
			}
			cout << "\n";
		}
	}


	//Sheap Tow

	static void PrintSheap2_1(int Colomns, int Lines)
	{

		for (int i = Lines; i > 0; i--)
		{
			for (int j = Lines - i;j>0; j--)
			{
				cout << " ";
			}
			for (int c = Colomns; c > 0; c--)
			{
				cout << "*";
			}
			cout << "\n";
		}

	}

	static void PrintSheap2_2(int Lines)
	{
		int space = Lines - 1;
		int Stars = 1;
		for (int i = Lines; i > 0; i--)
		{
			for ( int j = space;j > 0; j--)
			{
				cout << " ";
			}
			space--;

			for (int c = Stars; c > 0 ; c--)
			{
				cout << "*";
			}
			Stars += 2;

			cout << "\n";
		}

	}

	static void PrintSheap2_3(int Lines)
	{
		int space = 0;
		int Stars;

		if (Lines % 2 == 0)
		{
			Stars = Lines * 2;
		}
		else
		{
			Stars = Lines * 2 - 1;
		}

		 
		for (int i = Lines; i > 0; i--)
		{
			for (int j = 0; j <space; j++)
			{
				cout << " ";
			}
			space++;

			for (int c = Stars; c > 0; c--)
			{
				cout << "*";
			}
			Stars -= 2;

			cout << "\n";
		}

	}

	static int pow(int Asas, int Es)
	{
		int result = 1;
		for (int i = Es; i > 0; i--)
		{
			result *= Asas ;
		}
		return result;
	}
	//Numbers And Text
	static int printExambel1_1(int Number)
	{
		int result = 0;

		while (Number!=0)
		{
			result += Number % 10;
			Number /= 10;
		}
		return result;
	}

	static int PrintExambel1_2(int Number)
	{
		int reverseNumber = 0;
		int remainder = 0;
		while (Number != 0)
		{
			remainder = Number % 10;
			reverseNumber = reverseNumber * 10 + remainder;

			Number /= 10;
		}
		return reverseNumber;
	}
	
	static bool Exambel1_3(int Number)
	{
		int reverseNumber = PrintExambel1_2(Number);

		return Number == reverseNumber;
	}

	static int CountOccurrences(string mainString, string cuttingString)
	{
		int result = 0;

		for (int i = 0; i < mainString.length(); i++)
		{

			if (mainString.substr(i, cuttingString.length()) == cuttingString)
			{
				result++;
			}

		}
		return result;
	}

	static string reverseString(string text)
	{
		string NewString = text;

		for (int i = 0; i < text.length(); i++)
		{
			NewString[i] = text[(text.length() - (i + 1))];
		}
		return NewString;
	}

	static string RemoveAll(string maintext, string forDelete)
	{
		string text = maintext;
		for (int i = 0; i < text.length(); i++)
		{
			if (text.substr(i, forDelete.length()) == forDelete)
			{
				text.erase(i, forDelete.length());
			}
		}
		return text;
	}

	static string ReplaceAll(string mainText, string TextForSearch, string TextForReplace)
	{
		string Result = mainText;
		for (int i = 0; i < mainText.length(); i++)
		{
			if (mainText.substr(i, TextForSearch.length()) == TextForSearch)
			{
				Result.replace(i, TextForSearch.length(), TextForReplace);
			}
		}
		return Result;
	}



};

