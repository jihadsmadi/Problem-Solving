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
			int[] nums1 = { 1, 2, 2, 1 }, nums2 = { 2, 2 };
			int []result = Intersection(nums1, nums2);

			Console.Write("[");
			foreach(int i in result)
			{
				Console.Write(i + ",");
			}
			Console.Write("]");
			Console.ReadKey();
		}
		static public int[] Intersection(int[] nums1, int[] nums2)
		{
			HashSet<int> set = new HashSet<int>(nums1);
			List<int> list = new List<int>();

			for(int i =0;i<nums2.Length;i++)
			{
				if (set.Contains(nums2[i]))
				{
					list.Add(nums2[i]);
					set.Remove(nums2[i]);
				}
					
			}

			return list.ToArray();
		}
	}
}
