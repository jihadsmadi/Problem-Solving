using System;
using System.Collections.Generic;

namespace NeetCode_Duplicate_Integer
{
	internal class Program
	{
		static void Main(string[] args)
		{
			Console.WriteLine(hasDuplicate(new int[] { 1,2,3,3}));
			Console.ReadKey();
		}

		
		static public bool hasDuplicate(int[] nums)
		{
			HashSet<int> values = new HashSet<int>();

			for (int i = 0; i < nums.Length; i++)
			{
				if (values.Contains(nums[i]))
				{
					return true;
				}
				else
				{
					values.Add(nums[i]);
				}
			}

			return false;
		}
	}
	
}
