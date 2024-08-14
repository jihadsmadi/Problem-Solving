using System;


namespace NeetCode_BinarySearch
{
	internal class Program
	{
		static void Main(string[] args)
		{
			int[] inputs = { -1, 0, 1,2, 4,5, 6,7 ,8,25,33 };

			Console.WriteLine(Search(inputs,25));
			Console.ReadKey();
		}
		static public int Search(int[] nums, int target)
		{
			int low = 0,high = nums.Length -1;
			while (low <= high)
			{
				int mid = low + (high - low) / 2;
				if (nums[mid] < target)
				{
					low = mid + 1;
				}else if (nums[mid] > target)
				{
					high = mid - 1;
				}
				else
				{
					return mid;
				}
			}

			return -1;
		}
	}
}
