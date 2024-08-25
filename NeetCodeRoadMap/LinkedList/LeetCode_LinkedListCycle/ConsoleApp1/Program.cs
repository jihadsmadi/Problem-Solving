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
			
		}

		public class ListNode
		{
			public int val;
			public ListNode next;
			public ListNode(int x)
			{
				val = x;
				next = null;
			}
		}
		static public bool HasCycle(ListNode head)
		{
			if(head == null) return false;
			ListNode Slow = head, Fast = head.next;

			while(Slow!= null && Fast != null && Fast.next != null)
			{
				if (Fast == Slow) return true;

				Slow = Slow.next;
				Fast = Fast.next.next;
			}
			return false;
		}

	}
}
