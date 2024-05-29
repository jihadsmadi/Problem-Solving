using System;
using System.Collections.Generic;
using System.Collections.Specialized;
using System.Linq;
using System.Text;
using System.Threading.Tasks;


namespace AlgorithmsAndDataStructuer
{
     class clsTraining
    {
        public struct Data
        {

            public string day;
            public string month;
            public string year;
        }

        public Data ReadDateFromUser()
        {

            Data BirthData;
            Console.WriteLine("Please enter your Day when you burn? ");
            BirthData.day = Console.ReadLine()!;
            Console.WriteLine("\nPlease enter your Month when you burn? ");
            BirthData.month = Console.ReadLine()!;
            Console.WriteLine("]nPlease enter your Year when you burn? ");
            BirthData.year = Console.ReadLine()!;

            return BirthData;
        }

        public int CalculateAgeAtDaysFromBirthDate(Data date)
        {

            int Age = 0;
            Age = int.Parse(date.day);
            Age += CalculateHowDaysInMonth(date);
            Age += CalculateHowDaysInYear(date);

            return Age;

            
        }

        public Data CalculateAgeAtYearsAndMonthesAndDays(int AgeAtDays)
        {
            Data AgeData;
            AgeData.year = (AgeAtDays/365).ToString();
            AgeData.month = ((AgeAtDays % 365) / 30).ToString();
            AgeData.day = ((AgeAtDays- (AgeAtDays % 365) / 30)).ToString();

            return AgeData;
        }
        public int CalculateHowDaysInMonth(Data date)
        {
            string[] Months = { "31", "28", "31", "30", "31","30","31","30","31","30","31","30" };
            return int.Parse(Months[int.Parse(date.month)]);
        }

        public int CalculateHowDaysInYear(Data date)
        {
            return int.Parse(date.year);
        }

        public void  printAge(Data Age)
        {
            Console.WriteLine();
            Console.WriteLine("Your Age in days is: ");
        }
    }
}
