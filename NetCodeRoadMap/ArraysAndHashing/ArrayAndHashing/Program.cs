using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Linq;
using System.Reflection.Emit;
using System.Runtime.Remoting.Metadata.W3cXsd2001;
using System.Security.AccessControl;
using System.Text;
using System.Threading.Tasks;


namespace ArrayAndHashing
{
	class clsArrays
	{
		public static bool ContainsDuplicate(int[] nums)
		{
			for (int i = 0; i < nums.Length; i++)
			{
				for (int j = i + 1; j < nums.Length; j++)
				{
					if (nums[i] == nums[j])
						return true;

				}
			}
			return false;

		}

		public static bool IsAnagram(string s, string t)
		{
			if(s.Length != t.Length)
				return false;

			SortedDictionary<char,int> sLettars= new SortedDictionary<char,int>();
			SortedDictionary<char,int> tLetters= new SortedDictionary<char,int>();

			for(int i=0;i<s.Length;i++)
			{
				if (sLettars.Keys.Contains(s[i]))
				{
					sLettars[s[i]]++;
				}else 
				{
					sLettars.Add(s[i], 1);
				}

				if (tLetters.Keys.Contains(t[i]))
				{
					tLetters[t[i]]++;
				}
				else
				{
					tLetters.Add(t[i], 1);
				}

			}

			
			for(int i=0;i<sLettars.Count;i++)
			{

				if (tLetters.ElementAt(i).Key != sLettars.ElementAt(i).Key)
					return false;
				if(tLetters.ElementAt(i).Value != sLettars.ElementAt(i).Value)
					return false;
			}

			return true;


		}

		public static int[] TwoSum(int[] nums, int target)
		{
			//int[] indices = new int[2];

			//for(int i=0;i<nums.Length-1;i++)
			//{


			//	for(int j=i+1;j<nums.Length;j++) 
			//	{
			//		if (nums[i] + nums[j] == target)
			//		{
			//			indices[0] = i; 
			//			indices[1] = j; 
			//			return indices;
			//		}
			//	}
			//}

			//return null;

			Dictionary<int, int> prevMap = new Dictionary<int, int> ();
			int[] indices = new int[2];
			int deff;
			

			for(int i=0;i<nums.Length;i++)
			{
				deff = target- nums[i];

				if(prevMap.Keys.Contains(deff) )
				{
					indices[0] = prevMap[deff];
					indices[1] = i;
					return indices;

				}else if (!prevMap.Keys.Contains(nums[i]))
				{
					prevMap.Add(nums[i], i);
				}

				
			}

			return null;

		}

		public static int[] TopKFrequent(int[] nums, int k)
		{

			Dictionary<int, int> hashElementsFrequent = new Dictionary<int, int>();

			for (int i = 0; i < nums.Length; i++)
			{
				if (hashElementsFrequent.Keys.Contains(nums[i]))
				{
					hashElementsFrequent[nums[i]] += 1;
				}
				else
				{
					hashElementsFrequent.Add(nums[i], 1);
				}
			}

			var sortedDict = hashElementsFrequent;

			if (hashElementsFrequent.Count != 1)
			 sortedDict = hashElementsFrequent.OrderByDescending(pair => pair.Value).ToDictionary(pair => pair.Key, pair => pair.Value);

			int[] results = new int[k];

			for (int i = 0; i < k; i++)
			{
				results[i] = sortedDict.Keys.ElementAt(i);
			}

			return results; 

		}

		public static int[] ProductExceptSelf(int[] nums)
		{
			int[] Results = new int [nums.Length];

			int prefx = 1, postfx = 1;

			for(int i =0;i<nums.Length;i++)
			{
				Results[i] = prefx;
				prefx  *= nums[i];
			}

			for(int j=nums.Length-1;j>=0;j--)
			{
				Results[j] *= postfx;
				postfx *= nums[j];
			}

			return Results;

		}

		public static int LongestConsecutive(int[] nums)
		{
			if(nums.Length== 0) return 0;

			HashSet<int> listNums = nums.ToHashSet();
			int Longest = 0;
			



			foreach(int i in nums) 
			{
				if (!listNums.Contains(i-1))
				{

					int length = 1;
					int j = i;
					
					while (true)
					{
						if(listNums.Contains(j + 1))
						{
							j++;
							length++;
							if (Longest < length)
							{
								Longest = length;
							}
						}
						else
						{
							break;
						}
						
					}


				}
				
			}

			return Longest;

		}

		public static bool IsIsomorphic(string s, string t)
		{
			if(s.Length != t.Length ) return false;


			Dictionary<char,char> dict1 = new Dictionary<char,char>();
			Dictionary<char,char> dict2 = new Dictionary<char,char>();

			for(int i=0;i<s.Length;i++)
			{
				if (!dict1.Keys.Contains(s[i]))
				{
					dict1.Add(s[i], t[i]);
				}
				else
				{
					if (dict1[s[i]] != t[i])
					{
						return false;
					}
				}

				if (!dict2.Keys.Contains(t[i]))
				{
					dict2.Add(t[i], s[i]);
				}
				else
				{
					if (dict2[t[i]] != s[i])
					{
						return false;
					}
				}
			}

			return true;

		}

		public class NumArray
		{
			public int[] Nums;
			public NumArray(int[] nums)
			{
				this.Nums = nums;
			}

			public int SumRange(int left, int right)
			{
				int Sum = 0;

				while (left <= right)
				{
					Sum += Nums[left];
					left++;
				}

				return Sum;

			}
		}

		public class MyHashMap
		{
			
		}

		public static int SumFrom1_n(int n)
		{
			return ( n * (n + 1)) / 2;
		}

		public static IList<int> FindDisappearedNumbers(int[] nums)
		{
			Dictionary<int,bool> dict = new Dictionary<int,bool>();

			for(int i=1;i<=nums.Length;i++)
			{
				dict.Add(i, false);
			}

			foreach (int n in nums)
			{ 
				if(dict.Keys.Contains(n))
				{
					dict.Remove(n);
				}
			}

			return dict.Keys.ToArray();

		}

		public static bool WordPattern(string pattern, string s)
		{
			Dictionary<char,string> keyValuePairs= new Dictionary<char,string>();
			string [] sList = s.Split(' ');

			if (pattern.Length != sList.Length)
				return false;

			for(int i=0;i<pattern.Length;i++) 
			{
				if (!keyValuePairs.Keys.Contains(pattern[i]) )
				{
					if (keyValuePairs.Values.Contains(sList[i]))
						return false;

					keyValuePairs.Add(pattern[i], sList[i]);
				}
				
				else
				{
					if (sList[i] != keyValuePairs[pattern[i]])
					{
						return false;
					}
				}
			
			}


			return true;

		}

		public class ParkingSystem
		{
			Dictionary<int,int> keyValuePairs1= new Dictionary<int,int>();
			public ParkingSystem(int big, int medium, int small)
			{
				keyValuePairs1.Add(3, small);
				keyValuePairs1.Add(2, medium);
				keyValuePairs1.Add(1, big);
			}

		
			public bool AddCar(int carType)
			{
				if (keyValuePairs1[carType] > 0 ) 
				{
					keyValuePairs1[carType]--;
					return true;
				}
				else
				{
					return false;
				}
			}
		}

		public static int StrStr(string haystack, string needle)
		{
			

			for(int i =0;i<haystack.Length;i++)
			{
				if (haystack[i] == needle[0])
				{
					if (i >= haystack.Length - needle.Length + 1)
						return -1;

					if( haystack.Substring(i,(needle.Length)) == needle)
					{
						return i;
					}
				}
			}

			return -1;
		}

		public static string ConvertToAnagramSorted(string str)
		{
			SortedDictionary<char, int> strGroubAnagram = new SortedDictionary<char, int>();


			for (int i = 0; i < str.Length; i++)
			{
				if (strGroubAnagram.Keys.Contains(str[i]))
				{
					strGroubAnagram[str[i]]++;
				}
				else
				{
					strGroubAnagram.Add(str[i], 1);
				}

			}

			string res = "";

			for(int i=0;i<strGroubAnagram.Keys.Count;i++)
			{
				for(int j = 0; j < strGroubAnagram.Values.ElementAt(i);j++)
				{
					res += strGroubAnagram.Keys.ElementAt(i);
				}
			}

			return res;
		}

		public static IList<IList<string>> GroupAnagrams(string[] strs)
		{
			Dictionary<List<string>, string> strGroupAnagrams = new Dictionary<List<string>, string>();

			for (int i =0;i< strs.Length;i++)
			{
				string anagramWord = ConvertToAnagramSorted(strs[i]);
				if (strGroupAnagrams.Values.Contains(anagramWord))
				{
					strGroupAnagrams.Keys.ElementAt(i).Append(strs[i]);
				}
				else
				{
					strGroupAnagrams.Add(new List<string>() { strs[i] }, anagramWord);
				}

			}

			List<List<string>> res = new List<List<string>>();

			for(int i=0;i<strGroupAnagrams.Keys.Count;i++)
			{
				res.Add(strGroupAnagrams.Keys.ElementAt(i));
			}

			return res.ToArray();

		}

	}
	internal class Program
	{

		static void Main(string[] args)

		{
			string ipAddress = "192.168.1.1";

			IP i = new IP(ipAddress);

			Console.WriteLine(i[0]);

			Console.ReadKey();

		}
	}
}
