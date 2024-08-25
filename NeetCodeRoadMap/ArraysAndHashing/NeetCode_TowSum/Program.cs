using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace NeetCode_TowSum
{
	internal class Program
	{
		static void Main(string[] args)
		{
			int[] result = TwoSum(new int[] { 1, 4, 5, 3 }, 7);
			for (int i = 0;i < result.Length; i++)
			{
				Console.Write(result[i]);
			}
			Console.ReadKey();
		}

		static public int[] TwoSum(int[] nums, int target)
		{
			Dictionary<int,int> keyValuePairs= new Dictionary<int,int>();
			
			
			int x;
			for(int i=0;i<nums.Length;i++)
			{
				x = target - nums[i];
				if(keyValuePairs.ContainsKey(x))
				{
					return new int[] { keyValuePairs[x],i };
				}
				else
				{
					if (!keyValuePairs.ContainsKey(nums[i]))
					{
						keyValuePairs.Add(nums[i], i);
					}
				}
			}

			return null;
		}
	}
}
