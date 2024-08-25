namespace Course19Training
{
	partial class Form1
	{
		/// <summary>
		/// Required designer variable.
		/// </summary>
		private System.ComponentModel.IContainer components = null;

		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		/// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
		protected override void Dispose(bool disposing)
		{
			if (disposing && (components != null))
			{
				components.Dispose();
			}
			base.Dispose(disposing);
		}

		#region Windows Form Designer generated code

		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		private void InitializeComponent()
		{
			this.uctDemo1 = new Course19Training.uctDemo();
			this.SuspendLayout();
			// 
			// uctDemo1
			// 
			this.uctDemo1.Location = new System.Drawing.Point(50, 27);
			this.uctDemo1.Name = "uctDemo1";
			this.uctDemo1.Size = new System.Drawing.Size(254, 282);
			this.uctDemo1.TabIndex = 0;
			this.uctDemo1.OnCalculationComplete += new System.Action<int>(this.uctDemo1_OnCalculationComplete);
			// 
			// Form1
			// 
			this.AutoScaleDimensions = new System.Drawing.SizeF(9F, 19F);
			this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
			this.ClientSize = new System.Drawing.Size(800, 450);
			this.Controls.Add(this.uctDemo1);
			this.Name = "Form1";
			this.Text = "Form1";
			this.ResumeLayout(false);

		}

		#endregion

		private uctDemo uctDemo1;
	}
}

