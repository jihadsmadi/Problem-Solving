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
	public partial class uctDemo : UserControl
	{
		public uctDemo()
		{
			InitializeComponent();
		}

		public event Action<int> OnCalculationComplete;

		protected virtual void CalculationComplete(int value)
		{
			Action<int> Handler = OnCalculationComplete;

			if(Handler != null)
			{
				Handler(value);
			}
		}
		private void button1_Click(object sender, EventArgs e)
		{
			int result = (Convert.ToInt32(textBox1.Text) + Convert.ToInt32(textBox2.Text));
			label1.Text = result.ToString();

			if(OnCalculationComplete != null)
			{
				CalculationComplete(result);
			}
		}
	}
}
