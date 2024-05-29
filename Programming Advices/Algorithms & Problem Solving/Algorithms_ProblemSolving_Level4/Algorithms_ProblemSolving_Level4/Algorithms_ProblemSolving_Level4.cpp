
#include <iostream>
#include <string>
#include <string.h>
#include <math.h>
#include <vector>


using namespace std;

struct sDate
{
    short Year;
    short Month;
    short Day;
};

bool isLeapYear(short Year)
{
    return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
}

short NumberOfDaysInAMonth(short Month, short Year)
{
    if (Month < 1 || Month>12)
        return 0;
    int days[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
    return (Month == 2) ? (isLeapYear(Year) ? 29 : 28) :
        days[Month - 1];
}

short NumberOfDaysFromTheBeginingOfTheYear(short Day, short Month,  short Year)
{
    short TotalDays = 0;
    for (int i = 1; i <= Month - 1; i++)
    {
        TotalDays += NumberOfDaysInAMonth(i, Year);
    }
    TotalDays += Day;
    return TotalDays;
}

sDate DateAddDays(short Days, sDate Date)
{
    short RemainingDays = Days + NumberOfDaysFromTheBeginingOfTheYear(Date.Day, Date.Month, Date.Year);
    short MonthDays = 0;
    Date.Month = 1;
    while (true)
    {
        MonthDays = NumberOfDaysInAMonth(Date.Month, Date.Year);
        if (RemainingDays > MonthDays)
        {
            RemainingDays -= MonthDays;
            Date.Month++;
            if (Date.Month > 12)
            {
                Date.Month = 1;
                Date.Year++;
            }
        }
        else
        {
            Date.Day = RemainingDays;
            break;
        }
    }
    return Date;
}
// Compleate form Here
short ReadDay()
{
    short Day;
    cout << "\nPlease enter a Day? ";
    cin >> Day;
    return Day;
}

short ReadMonth()
{
    short Month;
    cout << "\nPlease enter a Month? ";
    cin >> Month;
    return Month;
}

short ReadYear()
{
    short Year;
    cout << "\nPlease enter a year? ";
    cin >> Year;
    return Year;
}

sDate ReadFullDate()
{
    sDate Date;
    Date.Day = ReadDay();
    Date.Month = ReadMonth();
    Date.Year = ReadYear();
    return Date;
}

short ReadDaysToAdd()
{
    short Days;
    cout << "\nHow many days to add? ";
    cin >> Days;
    return Days;
}

bool IsDayLastDayInMonth(sDate Date)
{
    return (Date.Day == NumberOfDaysInAMonth(Date.Month, Date.Year));
}

bool IsMonthLastMonthInYear(sDate Date)
{
    return (Date.Month == 12);
}

void IncreasDateByOneDay(sDate &Date)
{
   Date.Day != NumberOfDaysInAMonth(Date.Month, Date.Year) ? Date.Day++ : (Date.Month == 12) ? (Date.Month = 1, Date.Day = 1, Date.Year++) : (Date.Day = 1, Date.Month++);
}

bool ChickDateOneLessDateTwo(sDate Date1, sDate Date2)
{
    return Date1.Year < Date2.Year ? true : (Date1.Year == Date2.Year) ? (Date1.Month < Date2.Month) ? true : (Date1.Month == Date2.Month) ? Date1.Day < Date2.Day : false : false;

}

bool IsDate1EqulsDate2(sDate Date1, sDate Date2)
{
    return (Date1.Year != Date2.Year) ? false : (Date1.Month != Date2.Month) ? false : (Date1.Day == Date2.Day);
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

short DayOfWeekOrder(sDate Date)
{
    return DayOfWeekOrder(Date.Day, Date.Month, Date.Year);
}

void PrintTodayDate(sDate Date)
{
    string Days[] = { "Sun","Mon","Tus","Wed","Thu","Fri","Sat" };
    cout << "\nToday is " << Days[DayOfWeekOrder(Date)] << " , " << Date.Day << "/" << Date.Month << "/" << Date.Year<<endl;
}

bool IsEndOfWeek(sDate Date)
{
    return DayOfWeekOrder(Date) == 6 ;
}

bool IsItWeekend(sDate Date)
{
    short DayOrder = DayOfWeekOrder(Date);
    return (DayOrder == 6 || DayOrder == 5) ? true : false;
}

bool IsItBusinessDay(sDate Date)
{
    return !IsItWeekend(Date);
}

short DaysUntilEndOfWeek(sDate Date)
{
    short Remainder = 6 - DayOfWeekOrder(Date);
    return Remainder;
}

short DaysUntilEndOfMonth(sDate Date)
{
    short Remainder = NumberOfDaysInAMonth(Date.Month, Date.Year) - Date.Day ;
    return Remainder;
}

short DaysUntilEndOfYear(sDate Date)
{
    short Remainder = NumberOfDaysInAMonth(Date.Month,Date.Year) - Date.Day;
    
    for (int i = Date.Month+1; i <= 12; i++)
    {
        Remainder += NumberOfDaysInAMonth(Date.Month, Date.Year);
    }
    return Remainder;
}

short VacationDays(sDate &DateFrom, sDate DateTo)
{
    short VacationDays = 0;
    while (!IsDate1EqulsDate2(DateFrom, DateTo))
    {
        if (IsItBusinessDay(DateFrom))
        {
            VacationDays++;
        }
        IncreasDateByOneDay(DateFrom);
    }
    return VacationDays;
}

sDate ReturnDateAfterVacation(sDate Date, short VacationDays)
{
    short WeekendDays = 0;

    for (int i = 1; i <= VacationDays; i++)
    {
        if (IsItWeekend(Date))
            WeekendDays++;

        IncreasDateByOneDay(Date);
    }

    for (int i = 0; i < WeekendDays; i++)
    {
        IncreasDateByOneDay(Date);
    }
    return Date;
}

bool IsDate1BeforeDate2(sDate Date1, sDate Date2)
{
    return Date1.Year < Date2.Year ? true : (Date1.Year == Date2.Year) ? (Date1.Month < Date2.Month) ? true : (Date1.Month == Date2.Month) ? Date1.Day < Date2.Day : false : false;

}

bool IsDate1AfterDate2(sDate DateOne, sDate DateTwo)
{
    return DateOne.Year > DateTwo.Year ? true : (DateOne.Year < DateTwo.Year) ? false : (DateOne.Month > DateTwo.Month) ? true : (DateOne.Month < DateTwo.Month) ? false : DateOne.Day > DateTwo.Day;
}

enum enCompareChoices { Before = -1, Equal = 0,After = 1 };

enCompareChoices ReturnCompare(sDate DateOne, sDate DateTwo)
{
    if (IsDate1EqulsDate2(DateOne, DateTwo))
    {
        return enCompareChoices::Equal;
    }
    else if (IsDate1BeforeDate2(DateOne, DateTwo))
    {
        return enCompareChoices::Before;
    }
    else
        return enCompareChoices::After;
}

struct sPeriodsDate
{
    sDate DateFrom,DateTo;
};

sPeriodsDate ReadPeriodDate()
{
    sPeriodsDate PeriodOne;
    PeriodOne.DateFrom = ReadFullDate();
    PeriodOne.DateTo = ReadFullDate();
    return PeriodOne;
}


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

bool IsOverlapPeriods(sPeriodsDate PeriodOne, sPeriodsDate PeriodTwo)
{
    if (
        IsDate1BeforeDate2(PeriodTwo.DateTo, PeriodOne.DateFrom)
        ||
        IsDate1AfterDate2(PeriodTwo.DateFrom, PeriodOne.DateTo)
        )
        return false;
    else
        return true;
}

short CalculatePeriodLengthInDays(sPeriodsDate PeriodOne, bool PlusEndDay = false)
{
    short PeriodInDays = 0;
    while (!ReturnCompare(PeriodOne.DateFrom,PeriodOne.DateTo)==enCompareChoices::Equal)
    {
        PeriodInDays++;
        IncreasDateByOneDay(PeriodOne.DateFrom);
    }
    if (PlusEndDay)
        return (PeriodInDays + 1);
    else
        return PeriodInDays;
}

bool IsDateWithinThePeriod(sPeriodsDate PeriodOne, sDate DateOne)
{
    if (IsDate1BeforeDate2(DateOne, PeriodOne.DateFrom) || IsDate1AfterDate2(DateOne, PeriodOne.DateTo))
        return false;
    else
        return true;
}

short CountOverlapDays(sPeriodsDate PeriodOne, sPeriodsDate PeriodTwo)
{
    short PeriodOneLength = CalculatePeriodLengthInDays(PeriodOne, true);
    short PeriodTwoLength = CalculatePeriodLengthInDays(PeriodTwo, true);
    short CountOverlap = 0;
    
    if (!IsOverlapPeriods(PeriodOne, PeriodTwo))
        return 0;

    if (PeriodOneLength < PeriodTwoLength)
    {
        while (IsDate1BeforeDate2(PeriodOne.DateFrom,PeriodOne.DateTo))
        {
            if(IsDateWithinThePeriod(PeriodTwo,PeriodOne.DateFrom))
            CountOverlap++;

            IncreasDateByOneDay(PeriodOne.DateFrom);
        }
    }
    else
    {
        while (IsDate1BeforeDate2(PeriodTwo.DateFrom, PeriodTwo.DateTo))
        {
            if (IsDateWithinThePeriod(PeriodOne, PeriodTwo.DateFrom))
                CountOverlap++;

            IncreasDateByOneDay(PeriodTwo.DateFrom);
        }
    }
    return CountOverlap;

}

bool IsValidateDate(sDate Date)
{
    return (Date.Day <= 0 || Date.Day > NumberOfDaysInAMonth(Date.Month, Date.Year)) ? false : (Date.Month < 1 || Date.Month>12)?false:true;


}

string ReadDateString()
{
    string Date = "";
    cout << "Enter a Date ? ( dd/mm/yy ) \n";
    getline(cin, Date);
    return Date;
}

vector <string> SplitString(string Sentence, char Dimi)
{
    short Pos = 0;
    string word = "";
    vector <string> sWord;

    while ((Pos = Sentence.find(Dimi)) != std::string::npos)
    {
        word = Sentence.substr(0, Pos);
        Sentence.erase(0, Pos + 1);
        sWord.push_back(word);
    }
    sWord.push_back(Sentence);

    return sWord;
}

sDate ConvertFromStringToDate(string stDate)
{
    sDate Date;
  
    vector <string> svWord = SplitString(stDate, '/');

    Date.Day =stoi(svWord.at(0));
    Date.Month = stoi(svWord.at(1));
    Date.Year = stoi(svWord.at(2));

    return Date;
}

string ConvertFromDateToString(sDate Date)
{
    string Result = "";
    Result = to_string(Date.Day) + '/' + to_string(Date.Month) + '/' + to_string(Date.Year) ; 

    return Result;
}

enum FormatingDATE { DMY = 0, YDM = 1, MDY = 2, M_D_Y = 3, D_M_Y = 4, NORMAL = 5 };

string FormatDate(sDate Date, FormatingDATE Format)
{
    switch (Format-1)
    {
    case DMY: return (to_string(Date.Day) + "/" + to_string(Date.Month) + "/" + to_string(Date.Year));
        break;
    case YDM: return (to_string(Date.Year) + "/" + to_string(Date.Day) + "/" + to_string(Date.Month));
        break;
    case MDY: return (to_string(Date.Month) + "/" + to_string(Date.Day) + "/" + to_string(Date.Year));
        break;
    case M_D_Y: return (to_string(Date.Month) + "-" + to_string(Date.Day) + "-" + to_string(Date.Year));
        break;
    case D_M_Y: return (to_string(Date.Day) + "-" + to_string(Date.Month) + "-" + to_string(Date.Year));
        break;
    case NORMAL: return ("Day = " + to_string(Date.Day) + " ,Month = " + to_string(Date.Month) + " ,Year = " + to_string(Date.Year));
        break;
    default:
        break;
    }

}

short ReadNumberOfFormat()
{
    cout << "List are : " << endl;
    cout << "1- D/M/Y \n";
    cout << "2- Y/D/M \n";
    cout << "3- M/D/Y \n";
    cout << "4- M-D-Y \n";
    cout << "5- D-M-Y \n";
    cout << "6- Normal \n";

    short Number = 0;
    cin >> Number;
    return Number;
}
int main()
{
    string stDate = ReadDateString();
   
    cout << FormatDate(ConvertFromStringToDate(stDate), (FormatingDATE)ReadNumberOfFormat());



    system("pause>0");
    return 0;
}


