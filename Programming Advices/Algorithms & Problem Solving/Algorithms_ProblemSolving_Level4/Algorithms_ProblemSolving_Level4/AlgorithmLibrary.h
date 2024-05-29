#include <iostream>
#include <string>
#include <datetimeapi.h>

using namespace std;

string NumberToText(int Number)
{
    if (Number == 0)
    {
        return "";
    }
    if (Number >= 1 && Number <= 19)
    {
        string arr[] = { "",
       "One","Two","Three","Four","Five","Six","Seven",
        "Eight","Nine","Ten","Eleven","Twelve","Thirteen","Fourteen",
        "Fifteen","Sixteen","Seventeen","Eighteen","Nineteen" };
        return arr[Number] + " ";
    }
    if (Number >= 20 && Number <= 99)
    {
        string arr[] = {
       "","","Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty"
       ,"Ninety" };

        return arr[Number / 10] + " " + NumberToText(Number % 10);
    }
    if (Number >= 100 && Number <= 199)
    {
        return "One Hundred " + NumberToText(Number % 100);
    }
    if (Number >= 200 && Number <= 999)
    {
        return NumberToText(Number / 100) + "Hundreds " +
            NumberToText(Number % 100);
    }
    if (Number >= 1000 && Number <= 1999)
    {
        return "One Thousand " + NumberToText(Number % 1000);
    }
    if (Number >= 2000 && Number <= 999999)
    {
        return NumberToText(Number / 1000) + "Thousands " +
            NumberToText(Number % 1000);
    }
    if (Number >= 1000000 && Number <= 1999999)
    {
        return "One Million " + NumberToText(Number % 1000000);
    }
    if (Number >= 2000000 && Number <= 999999999)
    {
        return NumberToText(Number / 1000000) + "Millions " +
            NumberToText(Number % 1000000);
    }
    if (Number >= 1000000000 && Number <= 1999999999)
    {
        return "One Billion " + NumberToText(Number %
            1000000000);
    }
    else
    {
        return NumberToText(Number / 1000000000) + "Billions " +
            NumberToText(Number % 1000000000);
    }
}

int ReadNumber()
{
    int Number;
    cout << "\nEnter a Number? ";
    cin >> Number;
    return Number;
}

bool LeapYear(int Year)
{
    return  (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
}

short NumberOfDaysInYear(int Year)
{
    return LeapYear(Year) ? 366 : 365;
}

short NumberOfDaysInMonth(int Year, short Month)
{

    short MonthDaysLeapYear[] = { 31,29,31,30,31,30,31,30,31,30,31,30 };

    return Month == 2 ? (LeapYear(Year) ? 29 : 28) : MonthDaysLeapYear[Month - 1];
}

short NumberOfHoursInYear(int Year)
{
    return NumberOfDaysInYear(Year) * 24;
}

int NumberOfMinutsInYear(int Year)
{
    return NumberOfHoursInYear(Year) * 60;
}

int NumberOfSecondsInYear(int Year)
{
    return NumberOfMinutsInYear(Year) * 60;
}

short DayOfWeekOrder(short Day, short Month, short Year)
{
    short a, y, m;
    a = (14 - Month) / 12;
    y = Year - a;
    m = Month + (12 * a) - 2;
    // Gregorian:
    //0:sun, 1:Mon, 2:Tue...etc
    return (Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
}

void PrintMonthCalendar(short Month, short Year)
{
    int NumberOfDays;
    // Index of the day from 0 to 6
    int current = DayOfWeekOrder(1, Month, Year);
    NumberOfDays = NumberOfDaysInAMonth(Month, Year);
    // Print the current month name
    printf("\n _______________%s_______________\n\n",
        MonthShortName(Month).c_str());
    // Print the columns
    printf(" Sun Mon Tue Wed Thu Fri Sat\n");
    // Print appropriate spaces
    int i;
    for (i = 0; i < current; i++)
        printf(" ");
    for (int j = 1; j <= NumberOfDays; j++)
    {
        printf("%5d", j);
        if (++i == 7)
        {
            i = 0;
            printf("\n");
        }
    }
    printf("\n _________________________________\n");
}

void PirntMonthsInYearCalendar(short Year)
{
    for (short i = 1; i <= 12; i++)
    {
        PrintMonthCalendar(i, Year);
        cout << "---------------------------\n";
    }
}

bool ChickDateOneLessDateTwo(sDate Date1, sDate Date2)
{
    return Date1.Year < Date2.Year ? true : (Date1.Year == Date2.Year) ? (Date1.Month < Date2.Month) ? true : (Date1.Month == Date2.Month) ? Date1.Day < Date2.Day : false : false;

}

bool IsDate1EqulsDate2(sDate Date1, sDate Date2)
{
    return (Date1.Year != Date2.Year) ? false : (Date1.Month != Date2.Month) ? false : (Date1.Day == Date2.Day);
}

void IncreasDateByOneDay(sDate& Date)
{
    Date.Day != NumberOfDaysInAMonth(Date.Month, Date.Year) ? Date.Day++ : (Date.Month == 12) ? (Date.Month = 1, Date.Day = 1, Date.Year++) : (Date.Day = 1, Date.Month++);
}

short DefranssBetweenDateOneAndDateTow(sDate Date1, sDate Date2, bool IncludeTheLastDay = false)
{
    short DaysDefferanc;
    IncludeTheLastDay == false ? DaysDefferanc = 0 : DaysDefferanc = 1;

    if (ChickDateOneLessDateTwo(Date1, Date2))
    {
        while (!IsDate1EqulsDate2(Date1, Date2))
        {
            IncreasDateByOneDay(Date1);
            DaysDefferanc++;
        }
        return DaysDefferanc;
    }
    else
        return (-1 * DefranssBetweenDateOneAndDateTow(Date2, Date1));


}

bool IsMonthLastMonthInYear(sDate Date)
{
    return (Date.Month == 12);
}

sDate GetSystemDate()
{
    sDate Date;
    time_t t = time(0);
    tm* now = localtime(&t);
    Date.Year = now->tm_year + 1900;
    Date.Month = now->tm_mon + 1;
    Date.Day = now->tm_mday;
    return Date;
}

void IncreasDateBy_X_Days(sDate& Date, short Days)
{

    for (int i = 0; i < Days; i++)
    {
        IncreasDateByOneDay(Date);
    }

}

void IncreasDateByOneWeek(sDate& Date)
{

    if ((NumberOfDaysInAMonth(Date.Month, Date.Year) - Date.Day) >= 7)
    {
        Date.Day += 7;
    }
    else
    {
        IsMonthLastMonthInYear(Date) ? (Date.Month = 1, Date.Year++, Date.Day = 7 - (NumberOfDaysInAMonth(Date.Month, Date.Year) - Date.Day)) : (Date.Month++, Date.Day = 7 - (NumberOfDaysInAMonth(Date.Month, Date.Year) - Date.Day));

    }
}

void IncreasDateBy_X_Week(sDate& Date, short NumberOfWeeks)
{
    for (int i = 0; i < NumberOfWeeks; i++)
    {
        IncreasDateByOneWeek(Date);
    }

}

void IncreasDateByOneMonth(sDate& Date)
{
    if (IsMonthLastMonthInYear(Date))
    {
        Date.Month = 1;
        Date.Year++;
    }
    else
    {
        Date.Month++;
    }

    if (Date.Day > NumberOfDaysInAMonth(Date.Month, Date.Year))
    {
        Date.Day = NumberOfDaysInAMonth(Date.Month, Date.Year);
    }
}

void IncreasDateBy_X_Month(sDate& Date, short NumberOfMonths)
{
    for (int i = 0; i < NumberOfMonths; i++)
    {
        IncreasDateByOneMonth(Date);
    }
}

void IncreasDateByOneYear(sDate& Date)
{
    Date.Year++;
}

void IncreasDateBy_X_Year(sDate& Date, short NumberOfYears)
{
    for (int i = 0; i < NumberOfYears; i++)
    {
        IncreasDateByOneYear(Date);
    }
}

void IncreasDateBy_X_YearFaster(sDate& Date, short NumberOfYears)
{
    Date.Year += NumberOfYears;
}

void IncreasDateByOneDecades(sDate& Date)
{
    IncreasDateBy_X_YearFaster(Date, 10);
}

void IncreasDateBy_X_Decades(sDate& Date, short NumberOfDecades)
{
    for (int i = 0; i < NumberOfDecades; i++)
    {
        IncreasDateByOneDecades(Date);
    }
}

void IncreasDateBy_X_DecadesFaster(sDate& Date, short NumberOfDecades)
{
    Date.Year += NumberOfDecades * 10;
}

void IncreasDateByOneCentury(sDate& Date)
{
    Date.Year += 100;
}

void IncreasDateByOneMillennum(sDate& Date)
{
    Date.Year += 1000;
}
// Decrease Dates


void DecreaseDateByOneDay(sDate& Date)
{
    if (Date.Day == 1)
    {
        if (Date.Month == 1)
        {
            Date.Year--;
            Date.Month = 12;
            Date.Day = NumberOfDaysInAMonth(Date.Month, Date.Year);
        }
        else
        {
            Date.Month--;
            Date.Day = NumberOfDaysInAMonth(Date.Month, Date.Year);
        }
    }
    else
    {
        Date.Day--;
    }
}

void DecreaseDateBy_X_Days(sDate& Date, short NumberOfDays)
{
    for (int i = 0; i < NumberOfDays; i++)
    {
        DecreaseDateByOneDay(Date);
    }
}

void DecreaseDateByOneWeek(sDate& Date)
{
    DecreaseDateBy_X_Days(Date, 7);
}

void DecreaseDateBy_X_Week(sDate& Date, short NumberOfWeeks)
{
    for (int i = 0; i < NumberOfWeeks; i++)
    {
        DecreaseDateByOneWeek(Date);
    }
}

void DecreaseDateByOneMonth(sDate& Date)
{
    if (Date.Month == 1)
    {
        if (Date.Day == NumberOfDaysInAMonth(Date.Month, Date.Year))
        {
            Date.Year--;
            Date.Month = 12;
            Date.Day = NumberOfDaysInAMonth(Date.Month, Date.Year);
        }
        else
        {
            Date.Year--;
            Date.Month = 12;
        }
    }
    else
    {
        if (Date.Day == NumberOfDaysInAMonth(Date.Month, Date.Year))
        {
            Date.Month--;
            Date.Day = NumberOfDaysInAMonth(Date.Month, Date.Year);
        }
        else
        {
            Date.Month--;
        }

    }
}

void DecreaseDateBy_X_Month(sDate& Date, short NumberOfMonth)
{
    for (int i = 0; i < NumberOfMonth; i++)
    {
        DecreaseDateByOneMonth(Date);
    }
}

void DecreaseDateByOneYear(sDate& Date)
{
    Date.Year--;
}

void DecreaseDateBy_X_Years(sDate& Date, short NumberOfYears)
{
    for (int i = 0; i < NumberOfYears; i++)
    {
        DecreaseDateByOneYear(Date);
    }
}

void DecreaseDateBy_X_YearsFaster(sDate& Date, short NumberOfYears)
{
    Date.Year -= NumberOfYears;
}

void DecreaseDateByDecades(sDate& Date)
{
    DecreaseDateBy_X_YearsFaster(Date, 10);
}

void DecreaseDateBy_X_Decades(sDate& Date, short NumberOfDecades)
{
    for (int i = 0; i < NumberOfDecades; i++)
    {
        DecreaseDateByDecades(Date);
    }
}

void DecreaseDateBy_X_DecadesFaster(sDate& Date, short NumberOfDecades)
{
    Date.Year -= NumberOfDecades * 10;
}

void DecreaseDateByOneCetury(sDate& Date)
{
    Date.Year -= 100;
}

void DecreaseDateByOneMillennum(sDate& Date)
{
    Date.Year -= 1000;
}

