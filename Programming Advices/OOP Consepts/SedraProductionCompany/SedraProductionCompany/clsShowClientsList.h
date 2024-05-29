#pragma once
#include <vector>
#include <fstream>
#include <iomanip>
#include "clsClient.h"
#include "clsString.h"
#include "clsScreen.h"


using namespace std;

class clsShowClientsList : protected clsScreen
{

private:

	

	

	static void _PrintClientRecordLine(clsClient Client)
	{

		cout << setw(8) << left << "" << "| " << setw(15) << left << Client.ClientId;
		cout << "| " << setw(27) << left << Client.FullName();
		cout << "| " << setw(10) << left << Client.Phone;
		cout << "| " << setw(8) << left << Client.GetHouse().Number;
		cout << "    | " << setw(9) << left << Client.GetHouse().BuildingNumber;

	}

public:


	static void ShowClientsList()
	{
		vector <clsClient> vClients = clsClient::LoadClientsFromFile();
		
		
		string Title = "Client List Screen";
		string SubTitle = "\t    (" + to_string(vClients.size()) + ") Client(s).";

		_DrawScreenHeader(Title, SubTitle);


		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;

		cout << setw(8) << left << "" << "| " << left << setw(15) << "Client Id";
		cout << "| " << left << setw(27) << "Client Name";
		cout << "| " << left << setw(10) << "Phone";
		cout << "| " << left << setw(8) << "Hosue Number";
		cout << "| " << left << setw(9) << "Building Number";
		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;

		if (vClients.size() == 0)
			cout << "\t\t\t\tNo Clients Available In the System!";
		else

			for (clsClient &Client : vClients)
			{

				_PrintClientRecordLine(Client);
				cout << endl;
			}

		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;

	}
	

};

