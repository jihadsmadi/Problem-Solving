#pragma once
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsMainScreen.h"
#include "clsString.h"
#include "clsUser.h"
#include "Global.h"

class clsLoginScreen : protected clsScreen
{
private:

	static bool _Login()
	{
		string Username, Password;

		bool LoginFalild = false;
		short LoginLockedCounter = 0;

		do
		{
			if (LoginFalild) {

				cout << "Invalide Username/Password  try again ! \n";
				LoginLockedCounter++;
				cout << "You have " << (3 - LoginLockedCounter) << " Traials to login\n";
			}

			if (LoginLockedCounter == 3)
			{
				cout << "\nYou are locked after 3 faild traials";
				return false;
			}

			cout << "Enter Username: ";
			Username = clsInputValidate::ReadString();

			cout << "\nEnter Password: ";
			Password = clsInputValidate::ReadString();

			CurrentUser = clsUser::Find(clsString::LowerAllString(Username), Password);

			LoginFalild = CurrentUser.IsEmpty();

		} while (LoginFalild);

		CurrentUser.RegisterTime();
		clsMainScreen::ShowMainMenue();
		
		
	}

public:


	static bool ShowLoginScreen()
	{
		system("cls");
		_DrawScreenHeader("\t     Login Screen");
		return _Login();


	}
};

