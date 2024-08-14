using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace NeetCode_Is_Anagram
{
	internal class Program
	{
		static void Main(string[] args)
		{
			Console.WriteLine(IsAnagram("jar","jam"));

			Console.ReadKey();
		}
		//Solution before neet code
		static public bool IsAnagram(string s, string t)
		{
			if (s.Length != t.Length) return false;


			Dictionary<char,int> sDic= new Dictionary<char,int>();
			Dictionary<char,int> tDic= new Dictionary<char,int>();

			

			for(int i=0;i<s.Length;i++)
			{
				if (sDic.Keys.Contains(s[i]))
				{
					sDic[s[i]]++;
				}
				else
				{
					sDic.Add(s[i], 1);
				}


				if (tDic.Keys.Contains(t[i]))
				{
					tDic[t[i]]++;
				}
				else
				{
					tDic.Add(t[i], 1);
				}

				
			}

			foreach(char c in sDic.Keys)
			{
				if (!tDic.ContainsKey(c))
					return false;
				else if (sDic[c] != tDic[c])
					return false;
			}
				
			return true;
		}
	}
}
