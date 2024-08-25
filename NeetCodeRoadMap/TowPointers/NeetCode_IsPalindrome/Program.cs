using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace NeetCode_IsPalindrome
{
	internal class Program
	{
		//Input: s = "Was it a car or a cat I saw?"

		static void Main(string[] args)
		{
			Console.WriteLine(IsPalindrome("1Was it a car or a cat I saw1?"));
			Console.ReadKey();
		}
		static public bool IsPalindrome(string s)
		{
			
			var s2 = GetAlphanumerical(s);
			int first = 0, last = s2.Length - 1;

			while (first <= last)
			{
				if (s2[first] != s2[last])
					return false;

				first++; last--;
			}
			return true;
		}

		static public string GetAlphanumerical(string s)
		{
			StringBuilder result = new StringBuilder();
			s = s.ToLower();

			for(int i=0;i<s.Length;i++)
			{
				if (isAlphanumric(s[i]))
				{
					result.Append(s[i]);
				}
			}

			return result.ToString();
		}

		static public bool isAlphanumric(char c)
		{
			return ( (int)c>= 97 && (int)c <= 122 || (int)c >= 48 && (int)c <= 57  );
		}
	}
}
