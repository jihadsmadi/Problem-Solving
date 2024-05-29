#pragma once
#include <fstream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsClient.h"
using namespace std;

class clsAddNewClientScreen : protected clsScreen
{
private:

	static string _ConvertClientToLine(clsClient Client, string seperator = "#//#")
	{
		string Line = "";
		Line += Client.ClientId + seperator;
		Line += Client.FirstName + seperator;
		Line += Client.LastName + seperator;
		Line += Client.Phone + seperator;
		Line += Client.FatherName + seperator;
		Line += Client.MotherName + seperator;
		Line += Client.IdNumber + seperator;
		Line += Client._DateOfBearth.DateToString() + seperator;
		Line += Client.GetHouse().Number + seperator;
		Line += Client.GetHouse().BuildingNumber + seperator;
		Line += Client.GetHouse().Tabek + seperator;
		Line += Client.GetHouse().Position;

		return Line;

	}

	static bool _SaveClientToFile(clsClient Client)
	{
		fstream MyFile;
		MyFile.open("Client.txt", ios::out | ios::app);

		if (MyFile.is_open())
		{
			MyFile << _ConvertClientToLine(Client) << endl;
			MyFile.close();
			return true;
		}
		MyFile.close();
		return false;

	}

	static void _AddNewClient()
	{
		_DrawScreenHeader("\t  Add New Client Screen");

		string ClientId = "";

		cout << "\nPlease Enter Client ID: ";
		ClientId = clsInputValidate::ReadString();
		while (clsClient::isClientExist(ClientId))
		{
			cout << "\Client ID Is Already Used, Choose another one: ";
			ClientId = clsInputValidate::ReadString();
		}

		clsClient NewClient = clsClient::GetAddNewClientObject(ClientId);


		

		 clsClient::ReadClient(NewClient);

		char YesOrNo = 'y';
		YesOrNo = clsInputValidate::ReadChar("\nDo you sure you want to add the client .. ?(Y or N) \n");

		if (YesOrNo == 'y' || YesOrNo == 'Y')
		{
			if (_SaveClientToFile(NewClient))
			{
				cout << "Client added sucssfully\n";
				return;
			}
			else
			{
				cout << "Client add faild\n";
				return;
			}
		}
		cout << "Client add faild\n";
		

	}

public:

	static void ShowAddNewClientScreen()
	{
		_AddNewClient();
	}

};

