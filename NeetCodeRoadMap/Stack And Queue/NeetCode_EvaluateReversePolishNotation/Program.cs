using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace NeetCode_EvaluateReversePolishNotation
{
	internal class Program
	{
		static void Main(string[] args)
		{
			string[] input = { "1", "2", "+", "3", "*", "4", "-" };
			Console.WriteLine(EvalRPN(input));

			Console.ReadKey();
		}
		static public int EvalRPN(string[] tokens)
		{
			string operators = "+-*/";
			Stack<int> stack = new Stack<int>();
			string op = "";
			int a=-1,b=-1;

			for(int i=0;i<tokens.Length;i++)
			{
				string c = tokens[i];
				if (!operators.Contains(c))
				{
					stack.Push(int.Parse(c));
				}
				else
				{
					op = c;

					b = stack.Pop();
					a = stack.Pop();

					stack.Push(doOperat(a, b, op));
				}
			}
			return stack.Peek();
		}
		static public int doOperat(int num1,int num2,string op) 
		{
			switch (op)
			{
				case "+":
					return num1 + num2; 
				case "-":
					return num1 - num2;
				case "*":
					return num1 * num2;
				case "/":
					return num1 / num2;
					default: return num1;
			}
		}
		 
	}
}
