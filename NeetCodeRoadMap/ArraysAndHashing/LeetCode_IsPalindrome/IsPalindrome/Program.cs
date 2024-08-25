using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;

namespace IsPalindrome
{
	internal class Program
	{
		static void Main(string[] args)
		{

			string s = "`l;`` 1o1 ??;l`";
			Console.WriteLine(IsPalindrome(s));
			Console.ReadKey();
		}
		/*
			Input: s = "A man, a plan, a canal: Panama"
			Output: true
			Explanation: "amanaplanacanalpanama" is a palindrome.
		 */
		static public bool IsPalindrome(string s)
		{
			if(string.IsNullOrWhiteSpace(s)) return true;
			int first =0,last = s.Length-1;
		

			while(first <= last)
			{
				if (!char.IsLetterOrDigit(s[first]) || string.IsNullOrWhiteSpace(s[first].ToString()))
				{
					first++;
					continue;
				}else if (!char.IsLetterOrDigit(s[last]) || string.IsNullOrWhiteSpace(s[last].ToString()))
				{
					last--;
					continue;
				}

				if (Char.ToUpper(s[first])!= Char.ToUpper(s[last]))
				{
					return false;
				}

				first++;
				last--;
			}
			return true;
		}
	}
}
