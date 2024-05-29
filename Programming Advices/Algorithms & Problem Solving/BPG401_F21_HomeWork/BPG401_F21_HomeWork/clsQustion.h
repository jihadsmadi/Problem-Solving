#pragma once
#include <iostream>
#include "clsInputValidate.h"
#include "clsUtil.h"
using namespace std;


class clsQustion
{
private:

	int _NumberOfQustion;
	
	



	enum GameChoises { Even = 1, Odd = 2, Primary = 3 };

	struct RoundResult
	{
		string Qustion = "";
		int UserAnsowr = 0;
		int CorrectAnsowr = 0;
		GameChoises Type;
	};

	int _UserResult(GameChoises Type)
	{
		int Result = 0;
		switch (Type)
		{
		case clsQustion::Even:
		
			cout << "How Many Times Even Number Repeat in This Qusition ...? \n";
			Result = clsInputValidate::ReadShortNumber();
			return Result;
		
			break;
		case clsQustion::Odd:

			cout << "How Many Times Odd Number Repeat in This Qusition ...? \n";
			Result = clsInputValidate::ReadShortNumber();
			return Result;
			break;
		case clsQustion::Primary:

			cout << "How Many Times Primary Number Repeat in This Qusition ...? \n";
			Result = clsInputValidate::ReadShortNumber();
			return Result;
			break;
		default:
			break;
		}
	}

	bool _isNumber(int Number, GameChoises Type)
	{
		switch (Type)
		{
		case clsQustion::Even:
			return Number % 2 == 0;
		case clsQustion::Odd:
			return Number % 2 != 0;
		case clsQustion::Primary:
			return clsUtil::isPrimaryNumber(Number);

		default:
			break;
		}
	}

	int _CorrectResult(string Qustion, GameChoises Type)
	{
		int Result = 0;
		for (int i = 0; i < Qustion.length(); i++)
		{
			if ((char)Qustion[i] >= 49 && (char)Qustion[i] <= 57)
			{
				if (_isNumber((int)Qustion[i], Type))
				{
					Result++;
				}
			}
		}
		return Result;
	}

	void _ReadNumberOfQustion()
	{
		cout << "Please Enter A Number Of Maxium Qustions ....? ";
		_NumberOfQustion = clsInputValidate::ReadShortNumber();
	}

	int _ReadNumberOfTextGenerate()
	{
		int NumberTextGenerate =0;
		cout << "Enter How Many Latters Do You Want Between (3,100) ....?";
		NumberTextGenerate = clsInputValidate::ReadShortNumberBetween(3, 100);
		return NumberTextGenerate;
	}

	string _GenerateQustion(int NumberOfLettars)
	{
		clsUtil::Srand();
		string qustion ="";

		for (int i = 0; i < NumberOfLettars; i++)
		{

			qustion += clsUtil::GetRandomCharacter(clsUtil::MixCharacter);

		}
		
		return qustion;
	}

	void _PlayRound(vector <RoundResult> &GameResults)
	{
		cout << "Enter Number Of Latters You Want to genarate ...?  \n";
		int NumberOfTextLettars = clsInputValidate::ReadIntNumber();
		
		clsUtil::Srand();
		RoundResult Round;

		Round.Qustion = _GenerateQustion(NumberOfTextLettars);
		Round.Type = (GameChoises)clsUtil::RandomNumber(1, 3);

		cout << Round.Qustion << endl;

		Round.UserAnsowr = _UserResult(Round.Type);
		Round.CorrectAnsowr = _CorrectResult(Round.Qustion, Round.Type);

		GameResults.push_back(Round);

	}

	void _PrintScrren()
	{
		cout << "\t\t\t\t----------------------\n";
		cout << "\t\t\t\tFunctions You Can Do  \n";
		cout << "\t\t\t\t----------------------\n\n";
		cout << "\t\t\t\tGet Wrong Ansowrs .1   \n";
		cout << "\t\t\t\tGet Right Ansowrs .2   \n";
		cout << "\t\t\t\tGet All Qustions  .3   \n";
		cout << "\t\t\t\t----------------------\n";


	}

	int _WrongAnswor(vector <RoundResult> GameResul)
	{
		int WrongAnsowr=0;

		for (RoundResult& R : GameResul)
		{
			if (R.CorrectAnsowr != R.UserAnsowr)
			{
				WrongAnsowr++;
			}
		}
		return WrongAnsowr;
	}

	void _ShowWrongAnswors(int WrongAnswor)
	{
		cout << "\n\t\t\t\tRowng Answors is : " << WrongAnswor ;
	}

	
	int _RightAnswors(vector <RoundResult> GameResul)
	{
		int RightAnswors=0;

		for (RoundResult & R : GameResul)
		{
			if (R.CorrectAnsowr == R.UserAnsowr)
			{
				RightAnswors++;
			}
		}

		return RightAnswors;
	}

	void _ShowRightAnswors(int RightAnsowr)
	{
		cout << "\n\t\t\t\Right Answors is : " << RightAnsowr;
	}

	void _ResultsScreen(vector <RoundResult> GameResul)
	{
		_PrintScrren();

		short Option = clsInputValidate::ReadShortNumberBetween(1,3,"Enter A Number Between 1 To 3 .....!");

		switch (Option)
		{
		case(1):
			_ShowWrongAnswors(_WrongAnswor(GameResul));
			break;
		case(2):
			_ShowRightAnswors(_RightAnswors(GameResul));
			break;
		case(3):
			cout << "Nothing Unit Now ";
			break;
		
		}
		
	}

public:

	
	 void PlayTheGame()
 	 {
		 char PlayAgain = 'y';
		 vector <RoundResult> GameResult;

		 while (PlayAgain == 'y' || PlayAgain == 'Y')
		 {
			 _ReadNumberOfQustion();

			 for (int i = 0; i < _NumberOfQustion; i++)
			 {
				 _PlayRound(GameResult);
			 }

			 cout << "Do You Want To Play Again ...? (Y or N)  \n";
			 cin >> PlayAgain;

		 }

		 system("cls");
		
		 _ResultsScreen(GameResult);

	 }



};

