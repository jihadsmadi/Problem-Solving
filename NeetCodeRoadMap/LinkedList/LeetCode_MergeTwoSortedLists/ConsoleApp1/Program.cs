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
			// list1 = [1,2,4], list2 = [1,3,4]
			ListNode list1 = new ListNode(1,new ListNode(2,new ListNode(4)));
			ListNode list2 = new ListNode(1,new ListNode(3,new ListNode(4)));

			ListNode list3 = MergeTwoLists(list1,list2);
			while(list3!= null)
			{
				Console.Write(list3.val + " -> ");
				list3 = list3.next;
			}
			Console.ReadKey();
		}


		public class ListNode
		{
			public int val;
			public ListNode next;
			public ListNode(int val = 0, ListNode next = null)
			{
				this.val = val;
				this.next = next;
			}
		}


		static public ListNode MergeTwoLists(ListNode list1, ListNode list2)
		{
			ListNode result = new ListNode();
			ListNode tail = result;
			while (list1 != null && list2 != null)
			{
				if(list1.val < list2.val)
				{
					tail.next = list1;
					list1 = list1.next;
				}
				else
				{
					tail.next = list2;
					list2 = list2.next;
				}
				tail = tail.next;
			}

			if(list1 == null)
			{
				tail.next = list2;
			}
			else if(list2 == null)
			{
				tail.next = list1;
			}

			return result.next;
		}

	}
}
