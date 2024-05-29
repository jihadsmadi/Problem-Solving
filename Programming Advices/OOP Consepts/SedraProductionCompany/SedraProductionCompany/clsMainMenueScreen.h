#pragma once
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsShowClientsList.h"
#include "clsAddNewClientScreen.h"
#include "clsUpdateClientScreen.h"
#include "clsDeleteClient.h"
#include "clsFindClient.h"

class clsMainMenueScreen : protected clsScreen
{

private:

	static void _GoBackToMainMenue()
	{
		cout << setw(37) << left << "" << "\n\tPress any key to go back to Main Menue...\n";

		system("pause>0");
		ShowMainMenue();
	}



public:

	enum enMainScreenItems { enShowClinetsList = 1, enAddNewClient = 2,
		enDeleteClient = 3,enFindClient = 4,enUpdateClient=5, enExit = 6 };

	static void PerformMainMenueOption(enMainScreenItems Option)
	{
		switch (Option)
		{
		case (clsMainMenueScreen::enShowClinetsList):
			system("cls");
			clsShowClientsList::ShowClientsList();
			_GoBackToMainMenue();
			break;
		case clsMainMenueScreen::enAddNewClient:
			system("cls");
			clsAddNewClientScreen::ShowAddNewClientScreen();
			_GoBackToMainMenue();
			break;
		case clsMainMenueScreen::enDeleteClient:
			system("cls");
			clsDeleteClient::ShowDeleteClientScreen();
			_GoBackToMainMenue();
		case clsMainMenueScreen::enFindClient:
			system("cls");
			clsFindClient::ShowFindClientScreen();
			_GoBackToMainMenue();
		case clsMainMenueScreen::enUpdateClient:
			system("cls");
			clsUpdateClientScreen::ShowUpdateClientScreen();
			_GoBackToMainMenue();
		case clsMainMenueScreen::enExit:

			break;
		
		}
	}

	static void ShowMainMenue()
	{
		system("cls");
		_DrawScreenHeader("     Main Menue");
		
		cout << "\t\t\t\t\t______________________________________\n";
		cout << "\n\t\t\t\t\t[1] Show Clients List.";
		cout << "\n\t\t\t\t\t[2] Add New Client.   ";
		cout << "\n\t\t\t\t\t[3] Delete Client.   ";
		cout << "\n\t\t\t\t\t[4] Find Client.   ";
		cout << "\n\t\t\t\t\t[5] Update Client.   ";
		cout << "\n\t\t\t\t\t[6] Exit.             ";
		cout << "\n\n";
		cout << "\t\t\t\t\t______________________________________";
		cout << "\n\n\t\t\t\t\tChose Option From 1 to 6 ..? ";

		PerformMainMenueOption(enMainScreenItems(clsInputValidate::ReadShortNumberBetween(1, 6)));
		

	}

	


};

