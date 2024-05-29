using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Course19Training
{
	public partial class Form2 : Form
	{
		public Form2()
		{
			InitializeComponent();
		}

		public delegate void DataBackEventHandler(object sender, int personID);

		public event DataBackEventHandler DataBack;
		private void button1_Click(object sender, EventArgs e)
		{
			
		}
	}
}
