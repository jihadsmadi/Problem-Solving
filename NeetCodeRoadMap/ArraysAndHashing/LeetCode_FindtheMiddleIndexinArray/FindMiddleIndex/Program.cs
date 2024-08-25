using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace FindMiddleIndex
{
	internal class Program
	{
		static void Main(string[] args)
		{
			Console.ReadKey();
		}
		static public int FindMiddleIndex(int[] nums)
		{
			int total = 0;
			foreach (int i in nums) total += i;

			int left = 0, right = total;
			for(int j=0;j<nums.Length;j++)
			{
				right -= nums[j];
				if (right == left) return j;
				left += nums[j];
			}
			return -1;
		}
	}
}
