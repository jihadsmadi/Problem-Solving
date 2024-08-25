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
			Console.WriteLine(IsPowerOfTwo(64));
			Console.ReadKey();
		}
		static public bool IsPowerOfTwo(int n)
		{
			return n >0 && (n & n-1) == 0;
		}
	}
}
