#pragma once

#include <string>
#include <string.h>
#include <iostream>
#include <vector>

using namespace std;

class EasyLevel
{
public:

	static int centuryFromYear(int year)
	{
		return year % 10 == 0 ? (year / 100) : ((year / 100) + 1);
	}
	
	static string reverseString(string str)
	{
		string reversed = "";

		for (int i = str.length() - 1; i >= 0; i--)
		{
			reversed += str[i];
		}
		return reversed;
	}

	/*static int quarter_of(int month) {
		
		return ceil(float(month) / 3.0);
	}*/

	static vector<int> invert (vector<int> values)
	{
		vector<int> invert;
		for (int& x : values)
		{
			invert.push_back(x * -1);
		}
			return invert;
	}

	static string to_alternating_case( string& str)
	{
		string result = "";
		for (int i = 0; i < str.length(); i++)
		{
			if (int(str[i]) <= 90 && int(str[i]) >= 65)
			{
				result += char(int(str[i]) + 32);
			}
			else
			{
				result += char(int(str[i]) - 32);
			}
		}


		return result;
	}

	static char SwapToCorrectChar(char x)
	{
		switch (x)
		{
		case('0'):
			return 'O';
		case('1'):
			return 'I';
		case('5'): 
			return 'S';
		default:
			return x;
			break;
		}
	}

	static string correct(string str)
	{
		string result = "";

		for (int i = 0; i < str.length(); i++)
		{
			result += SwapToCorrectChar(str[i]);
		}
		return result;
	}

	static std::string HowWin(const std::string p1, const std::string p2)
	{
		if (p1 == "scissors")
		{
			if (p2 == "paper")
				return p1;
			else if (p2 == "rock")
				return p2;
			else return "Draw";
		}
		else if (p1 == "rock")
		{
			if (p2 == "paper")
				return p2;
			else if (p2 == "rock")
				return "Draw";
			else return p1;
		}
		else
		{
			if (p2 == "paper")
				return "Draw";
			else if (p2 == "rock")
				return p2;
			else return p1;
		}
	}


	static std::string abbrevName(std::string name)
	{
		string result = "";

		for (int i = 0; i < name.length(); i++)
		{
			if (i == 0)
				result += toupper(name[i]) ;
			if (name[i] == ' ')
				result += '.'+toupper(name[i + 1]);
		}
		return result;
	}

	std::string makeUpperCase(const std::string& input_str)
	{
		std::string result = "";
		for (int i = 0; i < input_str.length(); i++)
		{
			result += toupper(input_str[i]);
		}
		return result;
	}

	static string sum_str(const std::string& a, const std::string& b) {
		return to_string(stoi(a) + stoi(b));
	}

	static string vaporcode(const string& str) {
		//your code here

		string OriginalWord = str;
		string result = "";

		for (int i = 0; i < OriginalWord.length() ; i++)
		{
			if (OriginalWord[i] != ' ')
			{
				result += toupper(char(OriginalWord[i]))+ "  ";
			}
		}

		return result;

	}

};

