using System;
using System.Collections.Generic;
using System.Linq;


namespace NeetCode_ContainsDuplicateII
{
	internal class Program
	{
		static void Main(string[] args)
		{
			int[] inputs = {1,0,1,1};
			Console.WriteLine(ContainsNearbyDuplicate(inputs,1));
			Console.ReadKey();
		}
		static public bool ContainsNearbyDuplicate(int[] nums, int k)
		{
			Dictionary<int, int> keyValuePairs= new Dictionary<int,  int>();
			for(int i=0;i<nums.Length;i++)
			{
				if (!keyValuePairs.ContainsKey(nums[i]))
				{

					keyValuePairs.Add(nums[i], i);
				}
				else
				{
					if (Math.Abs(keyValuePairs[nums[i]] - i) <= k)
					{
						return true;
					}
					//0 1 2 3 4 5 6 -> the index is incresing,
					//so we replace the last value cause it dosen't important any more

					keyValuePairs[nums[i]] = i;
				}
			}
			return false;
		}

		
	}
}
