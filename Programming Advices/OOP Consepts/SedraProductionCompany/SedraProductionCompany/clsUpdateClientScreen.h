#pragma once
#include "clsClient.h"
#include "clsScreen.h"
#include "clsString.h"
#include "clsInputValidate.h"

class clsUpdateClientScreen : protected clsScreen
{
private:


	static void _UpdateClient(clsClient Client)
	{
		enum enChosesOfInformation
		{
			enFirstName = 1,enLastName = 2,enFaterName =3 ,enMotherName = 4,enPhoneNumber = 5,
			enDateOfBearth = 6,enIdNumber = 7,enHouseDeatils = 8,enAll = 9,
		};

		system("cls");
		_DrawScreenHeader("Update Client",Client.FirstName + " "+ Client.LastName + " ("+Client.ClientId+")");


		cout << "\t\t\t\t\t______________________________________\n";
		cout << "\n\t\t\t\t\t[1] First Name.      " << "\t" << "[2] Last Name.     ";
		cout << "\n\t\t\t\t\t[3] Father Name.     " << "\t" << "[4] Mother Name.   ";
		cout << "\n\t\t\t\t\t[5] Phone Number.    " << "\t" << "[6] DateOfBearth.  ";
		cout << "\n\t\t\t\t\t[7] Id Number.       " << "\t" << "[8] House Deatils. ";
		cout << "\n\t\t\t\t\t[9] All Data.";

		
		cout << "\n\t\t\t\t\t______________________________________";
		cout << "\n\n\t\t\t\t\tChose Option From 1 to 9 ..? ";

		enChosesOfInformation Chose = (enChosesOfInformation)clsInputValidate::ReadShortNumberBetween(1, 9);

		switch (Chose)
		{
		case enFirstName:
			cout << "\nEnter new First Name ...? ";
			Client.FirstName = clsInputValidate::ReadString();
			break;
		case enLastName:
			cout << "\nEnter new Last Name ...? ";
			Client.LastName = clsInputValidate::ReadString();
			break;
		case enFaterName:
			cout << "\nEnter new Fater Name ...? ";
			Client.FatherName = clsInputValidate::ReadString();
			break;
		case enMotherName:
			cout << "\nEnter new Mother Name ...? ";
			Client.MotherName = clsInputValidate::ReadString();
			break;
		case enPhoneNumber:
			cout << "\nEnter new Phone Number ...? ";
			Client.Phone = clsInputValidate::ReadString();
			break;
		case enDateOfBearth:
			cout << "Enter Date Of Bearth \n";
			cout << "-----------------------------\n";

			cout << "Enter Day Of Bearth \n";
			Client.Day = clsInputValidate::ReadShortNumber();
			cout << "\n";

			cout << "Enter Month Of Bearth \n";
			Client.Month = clsInputValidate::ReadShortNumber();
			cout << "\n";

			cout << "Enter Year Of Bearth \n";
			Client.Year = clsInputValidate::ReadShortNumber();
			cout << "\n";

			break;
		case enIdNumber:
			cout << "\nEnter new Id Number ...?";
			Client.IdNumber = clsInputValidate::ReadString();
			break;
		case enHouseDeatils:
	
			Client.GetHouse().ReadHouseDeatils();
			break;
		
		case enAll:
			clsClient::ReadClient(Client);
			break;
	
		}


	
	}

public:

	static void ShowUpdateClientScreen()
	{

		_DrawScreenHeader("Update Client");

		
		string ClientId;  

		char YesOrNo = 'y';

		while (YesOrNo == 'y' || YesOrNo == 'Y')
		{
			cout << "\nEnter Client Id For Update ...? \n";
			ClientId = clsInputValidate::ReadString();

			if (clsClient::isClientExist(ClientId))
			{
				_UpdateClient(clsClient::Find(ClientId));

				cout << "Client Update Saccesfully   ... ";
			}
			else
			{
				cout << "Client With " << ClientId << " Is Not Exist ...! ";

			}

			cout << "\n\nDo You Want To Do Again ...? (Y or N) ";
			YesOrNo = clsInputValidate::ReadChar("");

		}

	}

};

