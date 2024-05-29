#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

string ClientsFile = "Clients.txt";

void Login();
void ShowATMMainMenueScreen();
void ShowQuickWithDrawScreen();

struct  sClient
{
	string AccountNumber = "";
	string PinCode = "";
	string Name = "";
	string PhoneNumber = "";
	double Balance = 0.0;
};

sClient GlobalClient;

enum enATMMenue{eQuickWithdraw = 1,eNormalWithdraw = 2, eDeposit = 3,eCheckBalance = 4, eLogout = 5};

short ReadATMChoice()
{
	short Choice = 0;

	cout << "Choose what do you want to do ( 1-5 ) ?? ";
	cin >> Choice;

	return Choice;
}
short ReadWithdraw()
{
	cout << "Choose what to withdraw you want fro ( 1 - 8 ) ?? ";

	short Choice = 0;
	cin >> Choice;

	return Choice;
}

void GoBackToATM_MainMenue()
{
	cout << "\nPress any key to go back to ATM Menue .......";
	system("pause>0");
	ShowATMMainMenueScreen();
}

vector <string> SplitString(string Sentence, string Sepelator = "#//#")
{
	int pos = 0;
	vector <string> vString;
	string Word = "";

	while ((pos = Sentence.find(Sepelator)) != std::string::npos)
	{
		Word = Sentence.substr(0, pos);
		vString.push_back(Word);
		Sentence.erase(0, pos + Sepelator.length());
	}

	if (Sentence != "")
		vString.push_back(Sentence);

	return vString;
}

sClient ConvertLineToRecord(string Sentence, string Sepelator = "#//#")
{
	sClient Client; 
	vector <string> vString = SplitString(Sentence);

	Client.AccountNumber = vString.at(0);
	Client.PinCode = vString.at(1);
	Client.Name = vString.at(2);
	Client.PhoneNumber = vString.at(3);
	Client.Balance = stod(vString.at(4));

	return Client;
}

string ConvertRecordToLine(sClient Client)
{
	string Line = "";

	Line += Client.AccountNumber + "#//#" + Client.PinCode + "#//#" + Client.Name + "#//#" + Client.PhoneNumber + "#//#" + to_string(Client.Balance) ;
	
	return Line;
}

vector <sClient> LoadClintsLineFromFile(string ClientFile)
{
	fstream MyFile;
	vector <sClient> vClients;
	MyFile.open(ClientFile, ios::in);
	
	if (MyFile.is_open())
	{
		string word = "";
		while (getline(MyFile,word))
		{
			vClients.push_back(ConvertLineToRecord(word));
		}
		MyFile.close();
    }

	return vClients;
}

bool IsClientExist(string AccountNumber, string PinCode, string FileName,sClient &Client)
{
	vector <sClient> vClient = LoadClintsLineFromFile(ClientsFile);

	for (sClient &C : vClient)
	{
		if (AccountNumber == C.AccountNumber && PinCode == C.PinCode)
		{
			Client = C;
			return true;
		}
	}
	return false;
}

bool SaveClientsToFile(vector <sClient> vClients, string FileName)
{
	fstream MyFile;
	MyFile.open(FileName, ios::out);

	if (MyFile.is_open())
	{
		for (sClient C : vClients)
		{
			MyFile << ConvertRecordToLine(C)<<endl;
		}
		MyFile.close();
		return true;
	}
	else
	{
		return false;
	}

}

bool UpdatBalance()
{
	vector <sClient> vClient = LoadClintsLineFromFile(ClientsFile);

	for (sClient &C : vClient)
	{
		if (C.AccountNumber == GlobalClient.AccountNumber)
		{
			C.Balance = GlobalClient.Balance;
			break;
		}
	}
	if (SaveClientsToFile(vClient, ClientsFile))
	{
		cout << "\nTransaction is done successfully ...";
		return true;
	}
	
	return false;

}

void QuickWithDraw()
{
	double QuickCost[] = { 20,50,100,200,400,600,800,1000 };

	short Choice = ReadWithdraw();
	if (Choice == 9)
	{
		ShowATMMainMenueScreen();
	}

	if (GlobalClient.Balance < QuickCost[Choice - 1])
	{
		cout << "Your Balance is " << GlobalClient.Balance << " Less than " << QuickCost[Choice - 1] << endl;
		ShowQuickWithDrawScreen();
	}
	else
	{
		char YesOrNo = 'y';
		cout << "\nAre you sure to withdraw " << QuickCost[Choice - 1] << " ? ( Y/N ) ";
		cin >> YesOrNo;

		if (YesOrNo == 'y' || YesOrNo == 'Y')
		{
			GlobalClient.Balance -= QuickCost[Choice - 1];
			if (UpdatBalance())
			{
				cout << "\nYour New Balance is : " << GlobalClient.Balance;
			}
			ShowATMMainMenueScreen();
		}
		else
		{
			ShowATMMainMenueScreen();
		}
	}
	
}

void ShowQuickWithDrawScreen()
{
	system("cls");
	cout << "-----------------------------------\n";
	cout << "        Quick Withdraw             \n";
	cout << "-----------------------------------\n\n";

	cout << "[1] 20 $       [2] 50  $  \n";
	cout << "[3] 100$       [4] 200 $  \n";
	cout << "[5] 400$       [6] 600 $  \n";
	cout << "[7] 800$       [8] 1000$  \n";
	cout << "[9] Exit\n";

	QuickWithDraw();
}

void NormalWithdraw()
{
	double Amount = 0;

	do
	{
		cout << "Enter an amount multiple of 5 ? \n";
		cin >> Amount;

		

	} while ((int)Amount % 5 != 0 );

	if ( Amount > GlobalClient.Balance)
	{
		cout << "Your balance is less than " << Amount << " !!!\n";
		GoBackToATM_MainMenue();
	}

	char YesOrNo = 'y';
	cout << "Are you sure you want to do this transaction ? ( Y - N ) \n";
	cin >> YesOrNo;

	if (YesOrNo == 'y' || YesOrNo == 'Y')
	{
		GlobalClient.Balance -= Amount;
		if (UpdatBalance())
			cout << "\nYour New Balance is " << GlobalClient.Balance;
		ShowATMMainMenueScreen();
	}
	else
	{
		ShowATMMainMenueScreen();
	}

}

void ShowNormalWithDrawScreen() 
{
	system("cls");
	cout << "--------------------------------------\n";
	cout << "           Normal Withdraw            \n";
	cout << "--------------------------------------\n";

	NormalWithdraw();
}

void Deposit()
{
	short AmoutnToDeposit = 0;
	 
	do
	{
		cout << "Enter a positive Deposit amount ? ";
		cin >> AmoutnToDeposit;

	} while (AmoutnToDeposit <= 0);

	char YesOrNo = 'y';

	cout << "\nAre you sure you want to deposit ( Y - N ) \n";
	cin >> YesOrNo;

	if (YesOrNo == 'y' || YesOrNo == 'Y')
	{
		GlobalClient.Balance += AmoutnToDeposit;
		if (UpdatBalance())
			cout << "\nYour New Balance is " << GlobalClient.Balance;
		
	}
	GoBackToATM_MainMenue();
}

void ShowDepositScreen()
{
	system("cls");
	cout << "------------------------------------\n";
	cout << "          Deposit Screen            \n";
	cout << "------------------------------------\n";

	Deposit();
}

void CheckBalance(string AccoutnNumber)
{
	vector <sClient> vClients = LoadClintsLineFromFile(ClientsFile);
	double Balance=0;

	for (sClient C : vClients)
	{
		if (C.AccountNumber == AccoutnNumber)
		{
			Balance = C.Balance;
			break;
		}
			
	}


	cout << endl;
	cout << "\tYour Balance is : " << Balance;
	GoBackToATM_MainMenue();
}

void ShowCheckBalanceScreen()
{
	cout << "-----------------------------------\n";
	cout << "      Check Balance Screen         \n";
	cout << "-----------------------------------\n";

	CheckBalance(GlobalClient.AccountNumber);
}

void PerformATM(enATMMenue Choice)
{
	switch (Choice)
	{
	case eQuickWithdraw:
		system("cls");
		ShowQuickWithDrawScreen();
		break;
	case eNormalWithdraw:
		system("cls");
		ShowNormalWithDrawScreen();
		break;
	case eDeposit:
		system("cls");
		ShowDepositScreen();
		break;
	case eCheckBalance:
		system("cls");
		ShowCheckBalanceScreen();
		break;
	case eLogout:
		system("cls");
		Login();
		break;
	}
}

void ShowATMMainMenueScreen()
{
	system("cls");
	cout << "--------------------------------------\n";
	cout << "\tATM Main Menue Screen\n";
	cout << "--------------------------------------\n\n";

	cout << "[1] Quick Withdraw \n";
	cout << "[2] Normal Withdraw \n";
	cout << "[3] Deposit \n";
	cout << "[4] Check Balance \n";
	cout << "[5] Logout \n";

	PerformATM((enATMMenue)ReadATMChoice());
}

void Login()
{
	string AccountNubmer;
	string PinCode;
	
	do
	{
		cout << "\n--------------------------------------------\n";
		cout << "\t\tLogin Screen\n";
		cout << "--------------------------------------------\n";

		cout << "Enter Account Number? ";
		getline(cin >> ws, AccountNubmer);

		cout << "\nEnter Pin Code? ";
		getline(cin >> ws, PinCode);

		if (IsClientExist(AccountNubmer, PinCode, ClientsFile, GlobalClient))
		{
			ShowATMMainMenueScreen();
		}
		else
		{
			cout << "\nInvalid Account Number / Passowrd !";
		}

	} while (true);
}

int main()
{
	Login();
}


