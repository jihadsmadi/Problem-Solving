using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CircularQueue
{
	internal class Program
	{
		static void Main(string[] args)
		{
			/*["MyCircularQueue","enQueue","Rear","Rear","deQueue","enQueue","Rear","deQueue","Front","deQueue","deQueue","deQueue"]
				[[6],[6],[],[],[],[5],[],[],[],[],[],[]]
			Output:
			[null,true,6,6,true,true,5,true,0,false,false,false]
			Expected:
			[null,true,6,6,true,true,5,true,-1,false,false,false]*/

			MyCircularQueue queue = new MyCircularQueue(6);
			Console.WriteLine(queue.EnQueue(6));
			Console.WriteLine(queue.Rear());
			Console.WriteLine(queue.Rear());
			Console.WriteLine(queue.DeQueue());
			Console.WriteLine(queue.EnQueue(5));
			Console.WriteLine(queue.Rear());
			Console.WriteLine(queue.DeQueue());
			Console.WriteLine(queue.Front());
			Console.WriteLine(queue.DeQueue());
			Console.WriteLine(queue.DeQueue());
			Console.WriteLine(queue.DeQueue());

			Console.ReadKey();
		}
	}
}
