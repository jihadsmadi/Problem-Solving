#pragma once
#include "clsRealClient.h"
#include "clsHouse.h"

class clsClient : public clsRealClient
{
private:

	clsHouse _House;


public:

	clsClient()
	{

	}

	clsClient(clsHouse House, string ClientId, string FirstName, string LastName
		, string Phone, string FatherName, string MotherName, string IdNumber, clsDate DateOfBearth)
		:clsRealClient(ClientId, FirstName, LastName, Phone, FatherName, MotherName, IdNumber, DateOfBearth)
	{
		_House = House;
	}



	void SetHouse(clsHouse House)
	{
		_House = House;
	}

	clsHouse GetHouse()
	{
		return _House;
	}
	__declspec(property(get = GetCHouse, put = SetHouse)) clsHouse House;


	static void ReadClient(clsClient &Client)
	{


		cout << "Personal Deatils:\n";
		cout << "-----------------------------\n";

		cout << "Enter First Name \n";
		Client.FirstName = clsInputValidate::ReadString();
		cout << "\n";

		cout << "Enter Last Name \n";
		Client.LastName = clsInputValidate::ReadString();
		cout << "\n";

		cout << "Enter Father Name \n";
		Client.FatherName = clsInputValidate::ReadString();
		cout << "\n";

		cout << "Enter Mother Name \n";
		Client.MotherName = clsInputValidate::ReadString();
		cout << "\n";

		cout << "Enter Phone Number \n";
		Client.Phone = clsInputValidate::ReadString();
		cout << "\n";

		cout << "Enter Id Number \n";
		Client.IdNumber = clsInputValidate::ReadString();
		cout << "\n";

		cout << "-----------------------------\n";
		
		cout << "Enter Date Of Bearth \n";
		cout << "-----------------------------\n\n";

		cout << "Enter Day Of Bearth \n";
		Client.Day = clsInputValidate::ReadShortNumber();
		cout << "\n";

		cout << "Enter Month Of Bearth \n";
		Client.Month = clsInputValidate::ReadShortNumber();
		cout << "\n";

		cout << "Enter Year Of Bearth \n";
		Client.Year = clsInputValidate::ReadShortNumber();
		cout << "\n";

		cout << "-----------------------------\n";


		cout << "Client Deatils:\n";
		cout << "-----------------------------\n";

		

		Client.House = clsHouse::ReadHouseDeatils();

		cout << "-----------------------------\n";


	}

	static clsClient ConvertLineToClientObject(string Line, string Seperator = "#//#")
	{
		vector <string> vWords = clsString::Split(Line, "#//#");
		clsClient Client;

		Client.ClientId = vWords.at(0);
		Client.FirstName = vWords.at(1);
		Client.LastName = vWords.at(2);
		Client.Phone = vWords.at(3);
		Client.FatherName = vWords.at(4);
		Client.MotherName = vWords.at(5);
		Client.IdNumber = vWords.at(6);
		
		vector <string> DateOfBearth = clsString::Split(vWords.at(7), "/");

		Client.Day = stoi(DateOfBearth.at(0));
		Client.Month = stoi(DateOfBearth.at(1));
		Client.Year = stoi(DateOfBearth.at(2));

		Client.SetHouse(clsHouse(vWords.at(8), vWords.at(9), vWords.at(10), vWords.at(11)));


		return Client;

	}

	static vector <clsClient> LoadClientsFromFile()
	{
		vector <clsClient> vClients;
		fstream MyFile;

		MyFile.open("Client.txt", ios::in);

		if (MyFile.is_open())
		{
			string Line = "";
			while (getline(MyFile, Line))
			{
				vClients.push_back(ConvertLineToClientObject(Line));
			}
			MyFile.close();
		}
		MyFile.close();

		return vClients;


	}

	static bool isClientExist(string ClientId)
	{
		vector <clsClient> vClients = LoadClientsFromFile();

		for (clsClient& C : vClients)
		{
			if (C.ClientId == ClientId)
				return true;
		}
		return false;
	}

	static clsClient GetAddNewClientObject(string ClientId)
	{
		return clsClient(clsHouse("","","",""), ClientId, "", "", "", "", "","",clsDate(0,0,0));		
	}
	
	void PrintInfo()
	{

		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;

		cout << setw(8) << left << "" << "| " << left << setw(15) << "Client Id";
		cout << "| " << left << setw(27) << "Client Name";
		cout << "| " << left << setw(10) << "Phone";
		cout << "| " << left << setw(8) << "Mother Name";
		cout << "| " << left << setw(9) << "Id Number";
		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;

		cout << setw(8) << left << "" << "| " << setw(15) << left << this->ClientId;
		cout << "| " << setw(27) << left << this->FullName();
		cout << "| " << setw(10) << left << this->Phone;
		cout << "| " << setw(8) << left << this->MotherName;
		cout << "    | " << setw(9) << left << this->IdNumber;

		cout << "\n";

		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;

		cout << setw(8) << left << "" << "| " << left << setw(15) << "Date Of Bearth";
		cout << "| " << left << setw(12) << "House Number";
		cout << "| " << left << setw(15) << "House Building";
		cout << "| " << left << setw(5) << "Floor";
		cout << "| " << left << setw(22) << "Position";
		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;
		
		cout << setw(8) << left << "" << "| " << setw(15) << left << this->_DateOfBearth.DateToString();
		cout << "| " << setw(12) << left << this->GetHouse().Number;
		cout << "| " << setw(15) << left << this->GetHouse().BuildingNumber;
		cout << "| " << setw(1) << left << this->GetHouse().Tabek;
		cout << "    | " << setw(22) << left << this->GetHouse().Position;
		cout << "\n";
		
	}

	static clsClient Find(string ClientId)
	{
		vector <clsClient> vClients = LoadClientsFromFile();

		for (clsClient& C : vClients)
		{
			if (C.ClientId == ClientId)
				return C;
		}

		return clsClient();
	}

};

