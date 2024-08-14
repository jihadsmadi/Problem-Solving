using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp1
{
	internal class Program
	{
		static void Main(string[] args)
		{
			string date1 = "2020-01-15", date2 = "2019-12-31";
			Console.WriteLine(DaysBetweenDates(date1, date2));
			Console.ReadKey();	
		}
		static public int DaysBetweenDates(string date1, string date2)
		{
			return Math.Abs((DateTime.Parse(date1) - DateTime.Parse(date2)).Days );
		}								   
	}
}
