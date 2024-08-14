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
			Console.ReadKey();
		}
		static public bool ArrayStringsAreEqual(string[] word1, string[] word2)
		{
			StringBuilder sentence1 = new StringBuilder(), sentence2 = new StringBuilder();
			for(int i =0;i<word1.Length;i++)
			{
				sentence1.Append( word1[i]);
			}

			for (int j = 0; j < word2.Length; j++)
			{
				sentence2.Append(word2[j]);
			}
			return sentence1.ToString() == sentence2.ToString();
		}
	}
}
