#pragma once
#include "clsScreen.h"
#include "clsDate.h"
#include "clsString.h"
#include <string>
#include <iomanip>
#include <vector>

class clsTransferLogScreen : protected clsScreen
{
private:

	static vector <string> _vTransferLogs()
	{
		vector <string> vTransferLog;
		fstream TransferLog;
		  
		TransferLog.open("TransferLog.txt", ios::in);

		if (TransferLog.is_open())
		{
			string Line = "";
			while (getline(TransferLog,Line))
			{
				vTransferLog.push_back(Line);
			}
			TransferLog.close();
			return vTransferLog;
		}
		
	}

	static void _PrintTransferLogRecord(string Record)
	{
		vector <string> TransferDate = clsString::Split(Record,"#//#");

        cout << setw(8) << left << "" << "| " << setw(20) << left << TransferDate.at(0);
        cout << "| " << setw(4) << left << TransferDate.at(1);
        cout << "| " << setw(4) << left << TransferDate.at(2);
        cout << "| " << setw(13) << left << TransferDate.at(3);
        cout << "| " << setw(16) << left << TransferDate.at(4);
        cout << "| " << setw(16) << left << TransferDate.at(5);
        cout << "| " << setw(7) << left << TransferDate.at(6);

	}
   

public:

    static void ShowTransferLogScreen()
    {
        vector <string> vTransferLogs = _vTransferLogs();

        string Title = "\t  Transfer Log Screen";
        string SubTitle = "\t    (" + to_string(vTransferLogs.size()) + ") Operat(s).";

        _DrawScreenHeader(Title, SubTitle);

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "______________________________________________\n" << endl;

        cout << setw(8) << left << "" << "| " << left << setw(20) << "Date Time";
        cout << "| " << left << setw(4) <<  "ACN1";
        cout << "| " << left << setw(4) <<  "ACN2";
        cout << "| " << left << setw(13) << "Amount";
        cout << "| " << left << setw(16) << "Account1 Balance";
        cout << "| " << left << setw(16) << "Account2 Balance";
        cout << "| " << left << setw(7) << "User";
        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "______________________________________________\n" << endl;

        if (vTransferLogs.size() == 0)
            cout << "\t\t\t\tNo Users Available In the System!";
        else

            for (string Log : vTransferLogs)
            {

                _PrintTransferLogRecord(Log);
                cout << endl;
            }

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "______________________________________________\n" << endl;
    }

};

