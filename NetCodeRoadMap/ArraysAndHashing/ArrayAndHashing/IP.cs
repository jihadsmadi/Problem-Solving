using System;
using System.Runtime.Remoting.Proxies;
using System.Xml.Schema;

namespace ArrayAndHashing
{
	public class IP
	{
		//192.268.343.211
		public int[] segments { get; set; }

		public int this[int x]
		{
			get { return segments[x]; }
			set { this.segments[x] = value; }
		}
		public IP(int[] segments)
		{
			this.segments = segments;
		}

		public IP(string Address)
		{
			var s = Address.Split('.');
			int[] seg = new int[s.Length];

			for(int i=0;i<s.Length;i++)
			{
				seg[i] = Convert.ToInt32(s[i]);
			}

			this.segments = seg;
		}
		
		public void PrintAddress()
		{
			string address = string.Join(".", this.segments);
			Console.WriteLine(address);
		}

	}
}
