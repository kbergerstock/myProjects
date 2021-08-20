namespace cphat
{
    partial class cp_hat
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
            this.plot = new System.Windows.Forms.PictureBox();
            this.time2draw = new System.Windows.Forms.TextBox();
            ((System.ComponentModel.ISupportInitialize)(this.plot)).BeginInit();
            this.SuspendLayout();
            // 
            // plot
            // 
            this.plot.BackColor = System.Drawing.Color.Black;
            this.plot.Location = new System.Drawing.Point(-9, -2);
            this.plot.Name = "plot";
            this.plot.Size = new System.Drawing.Size(769, 461);
            this.plot.TabIndex = 0;
            this.plot.TabStop = false;
            this.plot.Paint += new System.Windows.Forms.PaintEventHandler(this.event_plot_draw);
            // 
            // time2draw
            // 
            this.time2draw.Location = new System.Drawing.Point(589, 437);
            this.time2draw.Name = "time2draw";
            this.time2draw.Size = new System.Drawing.Size(171, 20);
            this.time2draw.TabIndex = 1;
            // 
            // cp_hat
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(759, 457);
            this.Controls.Add(this.time2draw);
            this.Controls.Add(this.plot);
            this.Name = "cp_hat";
            this.Text = "c# hat";
            ((System.ComponentModel.ISupportInitialize)(this.plot)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.PictureBox plot;
        private System.Windows.Forms.TextBox time2draw;

    }
}

