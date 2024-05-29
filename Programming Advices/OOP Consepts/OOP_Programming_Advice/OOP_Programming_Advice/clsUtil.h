#pragma once

#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <random>
#include "clsDate.h"

using namespace std;


class clsUtil
{

public:

	enum eCharacterType { SmallLetters = 1, CapitalLetters = 2, Numbers = 3, Pouncatouchan = 4, MixCharacter = 5 };
	
	// Randoms
	static void Srand()
	{
		srand((unsigned)time(NULL));
	}

	static int RandomNumber(int From, int To)
	{
		//Function to generate a random number
		int randNum = rand() % (To - From + 1) + From;
		return randNum;
	}
	
	static char GetRandomCharacter(eCharacterType CharacterType)
	{
	
		switch (CharacterType)
		{
		case(SmallLetters):
			return (char)RandomNumber(97, 122);
		case(CapitalLetters):
			return (char)RandomNumber(65, 90);
		case(Numbers):
			return (char)RandomNumber(48, 57);
		case(Pouncatouchan):
			return (char)RandomNumber(33, 47);
		case(MixCharacter):
			return GetRandomCharacter((clsUtil::eCharacterType)RandomNumber(1, 4));
		}
	}

	static string GenerateWord(eCharacterType CharacterType,int LengthOfWord)
	{
		string Word = "";
		for (int i = 0; i < LengthOfWord; i++)
		{
			Word += GetRandomCharacter(CharacterType);
		}
		return Word;
	}

	// Keys
	static string GenerateKey(clsUtil::eCharacterType KeyType)
	{
		string Key = "";


		Key = GenerateWord(KeyType, 4) + "-";
		Key = Key + GenerateWord(KeyType, 4) + "-";
		Key = Key + GenerateWord(KeyType, 4) + "-";
		Key = Key + GenerateWord(KeyType, 4);


		return Key;
	}

	static void GenerateKeys(clsUtil::eCharacterType KeyType, int NumberOfKeys)
	{
		for (int i = 0; i < NumberOfKeys; i++)
		{
			cout << "Key [" << i+1 << "] : ";
			cout << GenerateKey(KeyType) << endl;
		}
	}

	// Fill Array
	static void FillArrayWithRandomNumbers(int arr[100], int arrLength, int From, int To)
	{
		for (int i = 0; i < arrLength; i++)
			arr[i] = RandomNumber(From, To);
	}

	static void FillArrayWithRandomWords(string arr[100], int arrLength, eCharacterType CharType, short Wordlength)
	{
		for (int i = 0; i < arrLength; i++)
			arr[i] = GenerateWord(CharType, Wordlength);

	}

	static void FillArrayWithRandomKeys(string arr[100], int arrLength, eCharacterType CharType)
	{
		for (int i = 0; i < arrLength; i++)
			arr[i] = GenerateKey(CharType);
	}

	// Swap
	static void Swap(int& x, int& y)
	{
		int Temp = 0;

		Temp = x;
		x = y;
		y = Temp;
	}

	static void Swap(double & x, double & y)
	{
		double Temp = 0;

		Temp = x;
		x = y;
		y = Temp;
	}

	static void Swap(string & x, string & y)
	{
		string Temp = "";

		Temp = x;
		x = y;
		y = Temp;
	}

	static void Swap(clsDate& x, clsDate& y)
	{
		clsDate::SwapDates(x, y);
	}

	static void Swap(char& x, char& y)
	{
		char Temp = 0;

		Temp = x;
		x = y;
		y = Temp;
	}

	static void Swap(bool& x, bool& y)
	{
		bool Temp = 0;

		Temp = x;
		x = y;
		y = Temp;
	}

	/*static void FillArrayWithRandomNumber(int Arr, int LengthOfArray, int From, int To)
	{
		int* pArr;
		pArr = new int[LengthOfArray];

		clsUtil::Srand();
		for (int i = 0; i < LengthOfArray; i++)
		{
			*(pArr+i) = RandomNumber(From, To);
		}

		Arr = *pArr;
		delete [] pArr;
	}*/

	// Tab
	static string Tabs(int Length)
	{
		string Tabs = "";
		for (int i = 0; i < Length; i++)
		{
			Tabs += "\t";
		}
		return Tabs;
	}

	// Encryption & Decryption

	static string  EncryptText(string Text, short EncryptionKey)
	{

		for (int i = 0; i <= Text.length(); i++)
		{

			Text[i] = char((int)Text[i] + EncryptionKey);

		}

		return Text;

	}

	static string  DecryptText(string Text, short EncryptionKey)
	{

		for (int i = 0; i <= Text.length(); i++)
		{

			Text[i] = char((int)Text[i] - EncryptionKey);

		}
		return Text;

	}

	//Shuffle Array
	static  void ShuffleArray(int arr[100], int arrLength)
	{

		for (int i = 0; i < arrLength; i++)
		{
			Swap(arr[RandomNumber(1, arrLength) - 1], arr[RandomNumber(1, arrLength) - 1]);
		}

	}

	//Number To Text
	static string NumberToText(int Number)
	{

		if (Number == 0)
		{
			return "";
		}

		if (Number >= 1 && Number <= 19)
		{
			string arr[] = { "", "One","Two","Three","Four","Five","Six","Seven",
		"Eight","Nine","Ten","Eleven","Twelve","Thirteen","Fourteen",
		  "Fifteen","Sixteen","Seventeen","Eighteen","Nineteen" };

			return  arr[Number] + " ";

		}

		if (Number >= 20 && Number <= 99)
		{
			string arr[] = { "","","Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninety" };
			return  arr[Number / 10] + " " + NumberToText(Number % 10);
		}

		if (Number >= 100 && Number <= 199)
		{
			return  "One Hundred " + NumberToText(Number % 100);
		}

		if (Number >= 200 && Number <= 999)
		{
			return   NumberToText(Number / 100) + "Hundreds " + NumberToText(Number % 100);
		}

		if (Number >= 1000 && Number <= 1999)
		{
			return  "One Thousand " + NumberToText(Number % 1000);
		}

		if (Number >= 2000 && Number <= 999999)
		{
			return   NumberToText(Number / 1000) + "Thousands " + NumberToText(Number % 1000);
		}

		if (Number >= 1000000 && Number <= 1999999)
		{
			return  "One Million " + NumberToText(Number % 1000000);
		}

		if (Number >= 2000000 && Number <= 999999999)
		{
			return   NumberToText(Number / 1000000) + "Millions " + NumberToText(Number % 1000000);
		}

		if (Number >= 1000000000 && Number <= 1999999999)
		{
			return  "One Billion " + NumberToText(Number % 1000000000);
		}
		else
		{
			return   NumberToText(Number / 1000000000) + "Billions " + NumberToText(Number % 1000000000);
		}


	}
};

