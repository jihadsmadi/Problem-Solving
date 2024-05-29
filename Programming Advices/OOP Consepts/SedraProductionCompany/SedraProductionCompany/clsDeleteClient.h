#pragma once
#include <fstream>
#include "clsClient.h"
#include "clsScreen.h"
#include "clsInputValidate.h"

class clsDeleteClient : protected clsScreen
{
private:

	 static bool _SaveClientsToFile(vector <clsClient> vClients)
	{
		fstream MyFile;
		MyFile.open("Client.txt", ios::out );

		for (clsClient& C : vClients)
		{
			if (C.MarkForDelete == false)
			{
				MyFile << _ConvertClientToLine(C) << endl;
			}
		
		}
		MyFile.close();
		return true;
	}

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

public:

	static void ShowDeleteClientScreen()
	{
		_DrawScreenHeader("Delete Client");

		cout << "\nEnter Client Id For Delete: \n";

		string ClientId = "";
		ClientId = clsInputValidate::ReadString();

		while (!clsClient::isClientExist(ClientId))
		{
			cout << "Client Id Is Not Exist Enter Another Id ......!\n";
			ClientId = clsInputValidate::ReadString();
		}

		vector <clsClient> vClients = clsClient::LoadClientsFromFile();

		


		for (clsClient& C : vClients)
		{
			if (C.ClientId == ClientId)
			{
				C.MarkForDelete = true;
				break;
			}
		}

		clsClient Client = clsClient::Find(ClientId);

		Client.PrintInfo();

		char YesOrNO = 'Y';
	
		YesOrNO = clsInputValidate::ReadChar("Are you sure you want to delete this client ... ? (Y or N) \n");

			if (YesOrNO == 'Y' || YesOrNO == 'y')
			{
				_SaveClientsToFile(vClients);
			}

			cout << Client.FullName() << " Deleted Succesfully  \n";

	}


};

