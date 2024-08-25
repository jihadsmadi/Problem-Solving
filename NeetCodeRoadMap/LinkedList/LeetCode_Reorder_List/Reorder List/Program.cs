using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Reorder_List
{
	internal class Program
	{
		static void Main(string[] args)
		{
			//head = [1, 2, 3, 4]
			ListNode head= new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4,new ListNode(5)))));
		

			ReorderList(head);

			while(head != null)
			{
				Console.Write(head.val + " -> ");
				head = head.next;
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


		static public void ReorderList(ListNode head)
		{
			if (head == null || head.next == null) return;

			// Step 1: Find the middle of the linked list
			ListNode slow = head, fast = head;
			while (fast != null && fast.next != null)
			{
				slow = slow.next;
				fast = fast.next.next;
			}

			// Step 2: Reverse the second half of the list
			ListNode prev = null, curr = slow;
			while (curr != null)
			{
				ListNode nextTemp = curr.next;
				curr.next = prev;
				prev = curr;
				curr = nextTemp;
			}

			// Step 3: Merge the two halves
			ListNode first = head;
			ListNode second = prev; // This is the head of the reversed second half

			while (second != null)
			{
				ListNode temp1 = first.next;
				ListNode temp2 = second.next;

				first.next = second; // Link first part to second part
				second.next = temp1; // Link second part back to the first part

				first = temp1; // Move to next node in the first part
				second = temp2; // Move to next node in the second part
			}
			if (first != null )
				first.next = null;
		}




	}
}
