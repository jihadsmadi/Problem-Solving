using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;

namespace NeetCode_Stack_MinimumStack
{
	internal class Program
	{
		static void Main(string[] args)
		{
			MinStack minStack = new MinStack();
			minStack.Push(1);
			minStack.Push(2);
			minStack.Push(0);
			Console.WriteLine(minStack.GetMin()); // return 0
			minStack.Pop();
			Console.WriteLine(minStack.Top());     // return 2
			Console.WriteLine(minStack.GetMin());  // return 1


			Console.ReadKey();
		}
	}

	public class MinStack
	{
		private LinkedList<int> _stack;

		public MinStack()
		{
			_stack = new LinkedList<int>();
		}

		public void Push(int val)
		{
			_stack.AddLast(val);
		}

		public void Pop()
		{
			if(_stack.Count > 0 )
			{
				_stack.RemoveLast();
			}
		}

		public int Top()
		{
			return _stack.Last.Value;
		}

		public int GetMin()
		{
			int min = _stack.First.Value;

			for(int i=1;i< _stack.Count;i++)
			{
				if (_stack.ElementAt(i) < min)
				{
					min = _stack.ElementAt(i);
				}
			}

			return min;
		}

		

	
	}
}
