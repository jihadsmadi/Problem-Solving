#pragma once
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsMainScreen.h"
#include "clsUser.h"
#include "Global.h"

class clsLoginScreen : protected clsScreen
{
private:

	static void _Login()
	{
		string Username, Password;

		bool LoginFalild = false;

		do
		{
			if (LoginFalild) {

				cout << "Invalide Username/Password  try again ! \n";
			}

			cout << "Enter Username: ";
			Username = clsInputValidate::ReadString();

			cout << "\nEnter Password: ";
			Password = clsInputValidate::ReadString();

			CurrentUser = clsUser::Find(Username, Password);

			LoginFalild = CurrentUser.IsEmpty();

		} while (LoginFalild);


		clsMainScreen::ShowMainMenue();

	}

public:


	static void ShowLoginScreen()
	{
		system("cls");
		_DrawScreenHeader("\t     Login Screen");
		_Login();
		

	}
};

