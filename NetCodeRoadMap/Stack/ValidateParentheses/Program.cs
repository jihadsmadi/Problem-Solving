using System;
using System.Collections.Generic;
using System.Linq;

namespace ValidateParentheses
{
	internal class Program
	{
		static void Main(string[] args)
		{
			Console.WriteLine(IsValid("(){}}{"));
			Console.ReadKey();
		}

		//input: ([{}]) --> Valid
		//input: ([{])} --> Invalid
		static public bool IsValid(string s)
		{
			var openBrackets = "([{";


			Stack<char> stack = new Stack<char>();
			for(int i=0;i<s.Length;i++)
			{
				if (openBrackets.Contains<char>(s[i])) // s[i] is open
				{
					stack.Push(s[i]);
				}
				else
				{
					if (i == 0)
						return false;

					bool isIntegrate = false;

					switch(s[i])
					{
						case ')':
							isIntegrate = stack.Pop() == '(' ? true : false;
							break;
						case '}':
							isIntegrate = stack.Pop() == '{' ? true : false;
							break;
						case ']':
							isIntegrate = stack.Pop() == '[' ? true : false;
							break;
					}

					if(isIntegrate == false)
					{
						return false;
					}
				}
			}

			if (stack.Count == 0)
				return true;
			else
				return false;
			

			
		}
	}
}
