#pragma once
#include "clsScreen.h"
#include <iomanip>
class ShowCurrensyScreen : public clsScreen
{

private:
    enum enCurrency {ListCurrency = 1, FindCurrency = 2,UpdateRate = 3, CurrencyCalculater = 4, Exit = 5};

    static short _ReadMainMenueOption()
    {
        short Option = 0;
        
        do
        {

            cin >> Option;

        } while (Option < 1 || Option > 5);

        return Option;
    }


    static  void _GoBackToCurrencyScreen()
    {
        cout << setw(37) << left << "" << "\n\tPress any key to go back to Main Menue...\n";

        system("pause>0");
        ShowCurrensyMenue();
    }

    static void _ShowListCurrencyScreen()
    {
        system("cls");
        cout << "\nList Currency will be here ...!";
        
    }

    static void _ShowFindCurrency()
    {
        system("cls");
        cout << "\nFind Currency will be here ...!";
    }

    static void _ShowUpdateRate()
    {
        system("cls");
        cout << "\nUpdate Rate will be here ...!";
    }

    static void _ShowCaluclateCurrency()
    {
        system("cls");
        cout << "\nCalculate Currency will be here ...!";
    }

    static void _PerfromMainMenueOption(enCurrency CurrencyOption)
    {
        switch (CurrencyOption)
        {
        case ShowCurrensyScreen::ListCurrency:
            _ShowListCurrencyScreen();
            _GoBackToCurrencyScreen();
            break;
        case ShowCurrensyScreen::FindCurrency:
            _ShowFindCurrency();
            _GoBackToCurrencyScreen();
            break;
        case ShowCurrensyScreen::UpdateRate:
            _ShowUpdateRate();
            _GoBackToCurrencyScreen();
            break;
        case ShowCurrensyScreen::CurrencyCalculater:
            _ShowCaluclateCurrency();
            _GoBackToCurrencyScreen();
            break;
        case ShowCurrensyScreen::Exit:
            _GoBackToCurrencyScreen();
            break;
        default:
            break;
        }
    }
public:


     static void ShowCurrensyMenue()
    {

        system("cls");
        _DrawScreenHeader("\t\tCurrensy Screen");

        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\t\tCurrensy Screen\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] List Currencies.\n";
        cout << setw(37) << left << "" << "\t[2] Find Currensy.\n";
        cout << setw(37) << left << "" << "\t[3] Update Rate.\n";
        cout << setw(37) << left << "" << "\t[4]Currency Calculater.\n";
        cout << setw(37) << left << "" << "\t[5] Exit.\n";
        cout << setw(37) << left << "" << "===========================================\n";

        _PerfromMainMenueOption((enCurrency)_ReadMainMenueOption());
    }






};

