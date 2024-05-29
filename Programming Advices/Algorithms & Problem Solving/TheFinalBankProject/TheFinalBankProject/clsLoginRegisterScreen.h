#pragma once
#include "clsScreen.h"
#include <iomanip>
#include <vector>
#include <fstream>
#include <string.h>
#include "clsString.h"
class clsLoginRegisterScreen :protected clsScreen
{
private:

    static vector <string> _RegisterLoginRecords()
    {

        fstream RegisterFile;
        RegisterFile.open("RegisterTimeFile.txt", ios::in);

        if (RegisterFile.is_open())
        {
            string Line = "";
            vector <string> vRegisterLogin;
            while (getline(RegisterFile,Line))
            {
                vRegisterLogin.push_back(Line);
            }

            return vRegisterLogin;
            
        }
        RegisterFile.close();
    }

    static void _PrintRegisterLogintRecordLine(string RegisterLoginLine)
    {
        vector <string> LoginRegisterDatels = clsString::Split(RegisterLoginLine,"#//#");

        cout << setw(8) << left << "" << "| " << setw(25) << left << LoginRegisterDatels.at(0);
        cout << "| " << setw(12) << left << LoginRegisterDatels.at(1);
        cout << "| " << setw(12) << left << LoginRegisterDatels.at(2);
        cout << "| " << setw(12) << left << LoginRegisterDatels.at(3);
    }
    
   

public:
    

    static void ShowLoginRegister()
    {
        if (!CheckAccessRights(clsUser::enPermissions::pLoginRegister))
        {
            return;// this will exit the function and it will not continue
        }


        vector <string> vRegisterLogin = _RegisterLoginRecords();

        string Title = "\t  Login Register Screen";
        string SubTitle = "\t    (" + to_string(vRegisterLogin.size()) + ") Register(s).";

        _DrawScreenHeader(Title, SubTitle);

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "______________________________________________\n" << endl;

        cout << setw(8) << left << "" << "| " << left << setw(25) << "Date/Time";
        cout << "| " << left << setw(12) << "User Name";
        cout << "| " << left << setw(12) << "Password";
        cout << "| " << left << setw(12) << "Permissions";
        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "______________________________________________\n" << endl;

        if (vRegisterLogin.size() == 0)
            cout << "\t\t\t\tNo Register Login Available In the System!";
        else

            for (string Line : vRegisterLogin)
            {

                _PrintRegisterLogintRecordLine(Line);
                cout << endl;
            }

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "______________________________________________\n" << endl;
    }




};

