#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>


using namespace std;
const string ClientsFileName = "Clients.txt";

struct sClient
{
	string AccountNumber = "";
	string PinCode = "";
	string Name = "";
	string Phone = "";
	double AccountBalance = 0.0;
	bool MarkForDelete = false;
	bool MarkForUpdate = false;
};

sClient ReadUpdateClient(string AccountNumber)
{
	sClient Client;
	Client.AccountNumber = AccountNumber;

	cout << "Enter PinCode? ";
	getline(cin >> ws, Client.PinCode);
	cout << "Enter Name? ";
	getline(cin, Client.Name);
	cout << "Enter Phone? ";
	getline(cin, Client.Phone);
	cout << "Enter AccountBalance? ";
	cin >> Client.AccountBalance;
	return Client;
}

string ReadAccountNumber()
{
	string AccountNumber = "";
	cout << "Enter Account Number For Looking? ";
	getline(cin, AccountNumber);
	return AccountNumber;
}

string UpperAllString(string Sentence)
{
	for (int i = 0; i < Sentence.length(); i++)
	{
		if (islower(Sentence[i]))
			Sentence[i] = toupper(Sentence[i]);
	}
	return Sentence;
}

void PrintClientCard(sClient Client)
{
	cout << "Clinet Data: \n";
	cout << "Account Number: " << Client.AccountNumber << endl
		<< "Pin Code:       " << Client.PinCode << endl
		<< "Name:           " << Client.Name << endl	
		<<  "Phone Number:   " << Client.Phone << endl
		<<  "Balance:        " << Client.AccountBalance << endl;

}

vector <string> SplitString(string S1, string Delim)
{
	vector<string> vString;
	short pos = 0;
	string sWord; // define a string variable 
	// use find() function to get the position of the delimiters 
	while ((pos = S1.find(Delim)) != std::string::npos)
	{
		sWord = S1.substr(0, pos); // store the word 
		if (sWord != "")
		{
			vString.push_back(sWord);
		}
		S1.erase(0, pos + Delim.length());
	}
	if (S1 != "")
	{
		vString.push_back(S1); // it adds last word of the string.
	}
	return vString;
}

sClient ConvertLinetoRecord(string Line, string Seperator = "#//#")
{
	sClient Client;
	vector<string> vClientData;
	vClientData = SplitString(Line, Seperator);
	Client.AccountNumber = vClientData[0];
	Client.PinCode = vClientData[1];
	Client.Name = vClientData[2];
	Client.Phone = vClientData[3];
	Client.AccountBalance = stod(vClientData[4]);//cast string to double

	return Client;
}

string ConvertRecordToLine(sClient Record, string Seperator = "#//#")
{
	string Line = "";
	Line = Record.AccountNumber + Seperator + Record.PinCode + Seperator +
		Record.Name + Seperator + Record.Phone + Seperator +
		to_string(Record.AccountBalance);

	return Line;
}

vector <sClient> LoadCleintsDataFromFile(string FileName)
{
	vector <sClient> vClients;
	fstream MyFile;
	MyFile.open(FileName, ios::in);//read Mode
	if (MyFile.is_open())
	{
		string Line;
		sClient Client;
		while (getline(MyFile, Line))
		{
			Client = ConvertLinetoRecord(Line);
			vClients.push_back(Client);
		}
		MyFile.close();
	}
	return vClients;
}

void LoadClientToFile(string FileName, string ClientLine)
{
	fstream MyFile;
	MyFile.open(FileName, ios::out | ios::app);

	if (MyFile.is_open())
	{
		MyFile << ClientLine << endl;
		MyFile.close();
	}
}

void LoadClientToNewFile(string FileName, string ClientLine)
{
	fstream MyFile;
	MyFile.open(FileName, ios::out );

	if (MyFile.is_open())
	{
		MyFile << ClientLine << endl;
		MyFile.close();
	}
}

void PrintClientRecord(sClient Client)
{
	cout << "| " << setw(15) << left << Client.AccountNumber;
	cout << "| " << setw(10) << left << Client.PinCode;
	cout << "| " << setw(40) << left << Client.Name;
	cout << "| " << setw(12) << left << Client.Phone;
	cout << "| " << setw(12) << left << Client.AccountBalance;
}

void PrintAllClientsData(vector <sClient> vClients)
{
	cout << "\n\t\t\t\t\tClient List (" << vClients.size() << ") Client(s).";
	cout <<
		"\n_______________________________________________________";
	cout << "_________________________________________\n" << endl;
	cout << "| " << left << setw(15) << "Accout Number";
	cout << "| " << left << setw(10) << "Pin Code";
	cout << "| " << left << setw(40) << "Client Name";
	cout << "| " << left << setw(12) << "Phone";
	cout << "| " << left << setw(12) << "Balance";
	cout <<
		"\n_______________________________________________________";
	cout << "_________________________________________\n" << endl;
	for (sClient Client : vClients)
	{
		PrintClientRecord(Client);
		cout << endl;
	}
	cout <<
		"\n_______________________________________________________";
	cout << "_________________________________________\n" << endl;
}

bool FindClientByAccountNumber(string AccountNumber ,vector <sClient> Vclients, sClient &Client)
{
	
	for (sClient C : Vclients)
	{
		if (C.AccountNumber == UpperAllString(AccountNumber))
		{
			Client = C;
			return true;
		}
	}
	return false;
}

bool MarkClientForDeleteByAccountNumber(string AccountNumber, vector <sClient> & Vclients)
{
	for (sClient& C : Vclients)
	{
		if (C.AccountNumber == AccountNumber)
		{
			C.MarkForDelete = true;
			return true;
		}
	}
	return false;
}

bool MarkClientForUpdateByAccountNumber(string AccountNumber, vector <sClient>& Vclients)
{
	for (sClient& C : Vclients)
	{
		if (C.AccountNumber == AccountNumber)
		{
			C.MarkForUpdate = true;
			return true;
		}
	}
	return false;
}

vector <sClient> SaveClientsDataToFile(string filename,vector <sClient> Vclients)
{
	fstream MyFile;
	MyFile.open(filename, ios::out);

	if (MyFile.is_open())
	{
		string DataLine;
		for (sClient C : Vclients)
		{
			if (C.MarkForDelete == false)
			{
				DataLine = ConvertRecordToLine(C);
				MyFile << DataLine << endl;
			}
		}
		MyFile.close();
	}
	return Vclients;
}

vector <sClient> UpdateClientsDataToFile(string filename, vector <sClient> Vclients,sClient UpdateClient)
{
	fstream MyFile;
	MyFile.open(filename, ios::out|ios::app);

	if (MyFile.is_open())
	{
		string DataLine;
		for (sClient C : Vclients)
		{
			if (C.MarkForUpdate == true)
			{
				DataLine = ConvertRecordToLine(UpdateClient);
				MyFile << DataLine << endl;
			}
		}
		MyFile.close();
	}
	return Vclients;
}

bool DeleteClientByAccountNumber(string AccountNumber, vector <sClient>& Vclients)
{
	char YesOrNo = 'Y';
	sClient Client;
	if (FindClientByAccountNumber(AccountNumber, Vclients,Client))
	{
		PrintClientCard(Client);
		cout << "Do you want to delete " << AccountNumber << " Client (Y / N)\n";
		cin >> YesOrNo;

		if (toupper(YesOrNo) == 'Y')
		{
			MarkClientForDeleteByAccountNumber(AccountNumber, Vclients);
			SaveClientsDataToFile(ClientsFileName, Vclients);

			Vclients = LoadCleintsDataFromFile(ClientsFileName);
			cout << "\n\nClient Deleted Successfully.";
			return true;
		}
	}
	else
	{
		return false;
	}
	


}

bool UpdateClientInformation(string AccountNumber, vector <sClient>& Vclients)
{
	char YesOrNo = 'N';
	sClient Client;
	if (FindClientByAccountNumber(AccountNumber, Vclients, Client))
	{
		PrintClientCard(Client);
		cout << "Do you wanna update client (Y / N) ? ";
		cin >> YesOrNo;

		if (toupper(YesOrNo) == 'Y')
		{
			MarkClientForUpdateByAccountNumber(AccountNumber, Vclients);
			Client = ReadUpdateClient(AccountNumber);
			Vclients = UpdateClientsDataToFile(ClientsFileName, Vclients, Client);
			cout << "the client update succesfully";
			return true;
		}
	}
	else
	{
		return false;
	}
}

int main()
{
	vector <sClient> vClients = LoadCleintsDataFromFile(ClientsFileName);

	string AccountNumber = ReadAccountNumber();
	UpdateClientInformation(AccountNumber, vClients);

	system("pause>0");

	return 0;
}


