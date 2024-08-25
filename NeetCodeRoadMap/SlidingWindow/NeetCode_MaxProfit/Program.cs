using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace NeetCode_MaxProfit
{
	internal class Program
	{
		static void Main(string[] args)
		{
			var input = new int[]{ 10, 8, 7, 5, 2 };

			Console.WriteLine(MaxProfit(input));
			Console.ReadKey();
		}

		//[10,1,5,6,7,1]
		static public int MaxProfit(int[] prices)
		{
			int buyDay = prices[0];
			

			int maxProfit = 0, currentSum = 0;
			

			for(int i=1;i<prices.Length;i++)
			{
				if (prices[i] < buyDay)
				{
					buyDay = prices[i];
				}
				else
				{
					currentSum = prices[i] - buyDay;
					if(currentSum > maxProfit)
						maxProfit = currentSum;
				}
			}

			return (maxProfit > 0 ? maxProfit : 0);
		}

		public int MaxProfit2(int[] prices)
		{
			int maxProfit = 0;
			int minPrice = prices[0];

			for (int i = 1; i < prices.Length; i++)
			{
				int currPrice = prices[i];
				minPrice = Math.Min(minPrice, currPrice);
				maxProfit = Math.Max(maxProfit, currPrice - minPrice);
			}
			return maxProfit;
		}

	}
}
