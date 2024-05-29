#pragma once
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsBankClient.h"
#include "clsTransactionScreen.h"



class clsTransferScreen : protected clsScreen
{

private:

	static string _ReadAccountNumber()
	{
		cout << "Please Enter An Account Number To Transfer From: ";
		string AccountNumber = clsInputValidate::ReadString();

		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "\nThis Account Number " << AccountNumber << " Is Not Exist,Try To Enter Another Account Nubmre? ";
			AccountNumber = clsInputValidate::ReadString();
		}
		return AccountNumber;

	}

	static void PrintTransferDeatils(clsBankClient Client)
	{
		cout << "Client One:\n";
		cout << "----------------------\n";
		cout << "Full Name:   " << Client.FullName() << "\n";
		cout << "Acc. Number: " << Client.AccountNumber() << "\n";
		cout << "Balance:     " << Client.AccountBalance << "\n";
		cout << "----------------------" << endl;
	}

	static double ReadAmount(clsBankClient Client)
	{
		double Amount = 0.0;
		cout << "Enter Transfer Amount? ";
		Amount = clsInputValidate::ReadDoublNumber();

		while (Amount > Client.AccountBalance)
		{
			cout << "Amount Exceeds The Avalible Balance! Enter Another Amount Please?";
			Amount = clsInputValidate::ReadDoublNumber();
		}

		return Amount;
	}

public:

	static void ShowTransferScreen()
	{

		clsScreen::_DrawScreenHeader("\tTransfer Screen");


		clsBankClient ClientFrom = clsBankClient::Find(_ReadAccountNumber());
		PrintTransferDeatils(ClientFrom);

		clsBankClient ClientTo = clsBankClient::Find(_ReadAccountNumber());
		PrintTransferDeatils(ClientTo);

		
		
		double Amount = ReadAmount(ClientFrom);

		char AreYouSure = 'y';
		AreYouSure = clsInputValidate::ReadChar("Are You Sure Do You Want To Perform This Operation? (Y/N)");
		

		if (AreYouSure == 'Y' || AreYouSure == 'y')
		{
			if (ClientFrom.Transfer(Amount, ClientTo,CurrentUser.UserName))
			{
				cout << "Transfer Done Successfully\n";
				

				PrintTransferDeatils(ClientFrom);
				PrintTransferDeatils(ClientTo);
			}
			
		}
		else
		{
			cout << "Transfer Faild";
			return;
		}
		


	}



};

