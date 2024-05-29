#pragma once

#include "clsClient.h"
#include "clsScreen.h"
#include "clsString.h"
#include <vector>
#include <iostream>

class clsFindClient : protected clsScreen
{

private:






public:

	static void ShowFindClientScreen()
	{
		_DrawScreenHeader("Find Client");

		cout << "Enter Client Id For Search ...? \n";
		string ClientId = clsInputValidate::ReadString();

		char YesOrNo = 'y';

		while (YesOrNo == 'y' || YesOrNo == 'Y')
		{
			if (clsClient::isClientExist(ClientId))
			{
				 clsClient::Find(ClientId).PrintInfo();
				 break;
			}
			else
			{
				cout << "Client With " << ClientId << " Is Not Exist ...! ";
				
			}

			cout << "\nDo You Want To Search Again ...? (Y or N) ";
			YesOrNo = clsInputValidate::ReadChar("");

		}


	}


};

