using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CircularQueue
{
	public class MyCircularQueue
	{
		private int[] myQueue;
		private int capacity = 0;
		private int size = 0;

		private int head = 0;
		private int tail = -1;
		public MyCircularQueue(int k)
		{
			capacity = k;
			myQueue= new int[capacity];
		}

		public bool EnQueue(int value)
		{ 
			if(IsFull()) return false;

			if (tail == capacity - 1)
				tail = 0;
			else
				tail++;

			myQueue[tail] = value;
			size++;
			return true;
		}

		public bool DeQueue()
		{
			if(IsEmpty()) return false;

			
			if (head == capacity - 1)
				head = 0;
			else
			head++;

			size--;
			return true;
		}

		public int Front()
		{
			if (IsEmpty()) return -1;
			return myQueue[head];
		}

		public int Rear()
		{
			if(IsEmpty() ) return -1;
			return myQueue[tail];
		}

		public bool IsEmpty()
		{
			return size == 0;
		}

		public bool IsFull()
		{
			return size == capacity;
		}
	}

	/**
	 * Your MyCircularQueue object will be instantiated and called as such:
	 * MyCircularQueue obj = new MyCircularQueue(k);
	 * bool param_1 = obj.EnQueue(value);
	 * bool param_2 = obj.DeQueue();
	 * int param_3 = obj.Front();
	 * int param_4 = obj.Rear();
	 * bool param_5 = obj.IsEmpty();
	 * bool param_6 = obj.IsFull();
	 */
}
