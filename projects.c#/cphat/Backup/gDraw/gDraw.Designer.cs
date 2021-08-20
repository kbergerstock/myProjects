namespace gDraw
{
    partial class gDraw
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
            this.addPoint = new System.Windows.Forms.Button();
            this.addHollowCircle = new System.Windows.Forms.Button();
            this.addFilledCircle = new System.Windows.Forms.Button();
            this.addHollwRectangle = new System.Windows.Forms.Button();
            this.addFilledRectangle = new System.Windows.Forms.Button();
            this.inputDemo = new System.Windows.Forms.GroupBox();
            this.label3 = new System.Windows.Forms.Label();
            this.radius = new System.Windows.Forms.TextBox();
            this.centerY = new System.Windows.Forms.TextBox();
            this.label2 = new System.Windows.Forms.Label();
            this.label1 = new System.Windows.Forms.Label();
            this.centerX = new System.Windows.Forms.TextBox();
            this.addFilledCircleAt = new System.Windows.Forms.Button();
            this.changeToHotPink = new System.Windows.Forms.Button();
            this.eraseAll = new System.Windows.Forms.Button();
            this.drawing = new System.Windows.Forms.PictureBox();
            this.inputDemo.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.drawing)).BeginInit();
            this.SuspendLayout();
            // 
            // addPoint
            // 
            this.addPoint.Location = new System.Drawing.Point(399, 25);
            this.addPoint.Name = "addPoint";
            this.addPoint.Size = new System.Drawing.Size(133, 24);
            this.addPoint.TabIndex = 0;
            this.addPoint.Text = "add Point";
            this.addPoint.UseVisualStyleBackColor = true;
            this.addPoint.Click += new System.EventHandler(this.event_addPoint);
            // 
            // addHollowCircle
            // 
            this.addHollowCircle.Location = new System.Drawing.Point(399, 65);
            this.addHollowCircle.Name = "addHollowCircle";
            this.addHollowCircle.Size = new System.Drawing.Size(133, 23);
            this.addHollowCircle.TabIndex = 1;
            this.addHollowCircle.Text = "Add Hollow Circle";
            this.addHollowCircle.UseVisualStyleBackColor = true;
            this.addHollowCircle.Click += new System.EventHandler(this.event_addHollowCircle);
            // 
            // addFilledCircle
            // 
            this.addFilledCircle.Location = new System.Drawing.Point(399, 150);
            this.addFilledCircle.Name = "addFilledCircle";
            this.addFilledCircle.Size = new System.Drawing.Size(133, 23);
            this.addFilledCircle.TabIndex = 2;
            this.addFilledCircle.Text = "add Filled Circle";
            this.addFilledCircle.UseVisualStyleBackColor = true;
            this.addFilledCircle.Click += new System.EventHandler(this.event_addFilledCircle);
            // 
            // addHollwRectangle
            // 
            this.addHollwRectangle.Location = new System.Drawing.Point(399, 105);
            this.addHollwRectangle.Name = "addHollwRectangle";
            this.addHollwRectangle.Size = new System.Drawing.Size(133, 23);
            this.addHollwRectangle.TabIndex = 3;
            this.addHollwRectangle.Text = "add Hollow Rectangle";
            this.addHollwRectangle.UseVisualStyleBackColor = true;
            this.addHollwRectangle.Click += new System.EventHandler(this.event_addHollowRectangle);
            // 
            // addFilledRectangle
            // 
            this.addFilledRectangle.Location = new System.Drawing.Point(399, 193);
            this.addFilledRectangle.Name = "addFilledRectangle";
            this.addFilledRectangle.Size = new System.Drawing.Size(133, 23);
            this.addFilledRectangle.TabIndex = 4;
            this.addFilledRectangle.Text = "Add Filled rectangle";
            this.addFilledRectangle.UseVisualStyleBackColor = true;
            this.addFilledRectangle.Click += new System.EventHandler(this.event_addFilledRectangle);
            // 
            // inputDemo
            // 
            this.inputDemo.Controls.Add(this.label3);
            this.inputDemo.Controls.Add(this.radius);
            this.inputDemo.Controls.Add(this.centerY);
            this.inputDemo.Controls.Add(this.label2);
            this.inputDemo.Controls.Add(this.label1);
            this.inputDemo.Controls.Add(this.centerX);
            this.inputDemo.Controls.Add(this.addFilledCircleAt);
            this.inputDemo.Location = new System.Drawing.Point(399, 234);
            this.inputDemo.Name = "inputDemo";
            this.inputDemo.Size = new System.Drawing.Size(133, 131);
            this.inputDemo.TabIndex = 5;
            this.inputDemo.TabStop = false;
            this.inputDemo.Text = "input demo";
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(28, 77);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(35, 13);
            this.label3.TabIndex = 11;
            this.label3.Text = "radius";
            // 
            // radius
            // 
            this.radius.Location = new System.Drawing.Point(92, 71);
            this.radius.Name = "radius";
            this.radius.Size = new System.Drawing.Size(35, 20);
            this.radius.TabIndex = 10;
            this.radius.Text = "25";
            // 
            // centerY
            // 
            this.centerY.Location = new System.Drawing.Point(92, 45);
            this.centerY.Name = "centerY";
            this.centerY.Size = new System.Drawing.Size(35, 20);
            this.centerY.TabIndex = 9;
            this.centerY.Text = "150";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(25, 48);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(45, 13);
            this.label2.TabIndex = 9;
            this.label2.Text = "center y";
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(25, 22);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(45, 13);
            this.label1.TabIndex = 8;
            this.label1.Text = "center x";
            // 
            // centerX
            // 
            this.centerX.Location = new System.Drawing.Point(92, 19);
            this.centerX.Name = "centerX";
            this.centerX.Size = new System.Drawing.Size(35, 20);
            this.centerX.TabIndex = 8;
            this.centerX.Text = "100";
            // 
            // addFilledCircleAt
            // 
            this.addFilledCircleAt.Location = new System.Drawing.Point(6, 102);
            this.addFilledCircleAt.Name = "addFilledCircleAt";
            this.addFilledCircleAt.Size = new System.Drawing.Size(121, 23);
            this.addFilledCircleAt.TabIndex = 6;
            this.addFilledCircleAt.Text = "add Filled Circle at";
            this.addFilledCircleAt.UseVisualStyleBackColor = true;
            this.addFilledCircleAt.Click += new System.EventHandler(this.event_addFilledCircleAt);
            // 
            // changeToHotPink
            // 
            this.changeToHotPink.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(255)))), ((int)(((byte)(192)))), ((int)(((byte)(192)))));
            this.changeToHotPink.Location = new System.Drawing.Point(399, 409);
            this.changeToHotPink.Name = "changeToHotPink";
            this.changeToHotPink.Size = new System.Drawing.Size(133, 23);
            this.changeToHotPink.TabIndex = 6;
            this.changeToHotPink.Text = "change Fills to Hot Pink";
            this.changeToHotPink.UseVisualStyleBackColor = false;
            this.changeToHotPink.Click += new System.EventHandler(this.event_changeFills);
            // 
            // eraseAll
            // 
            this.eraseAll.Location = new System.Drawing.Point(399, 458);
            this.eraseAll.Name = "eraseAll";
            this.eraseAll.Size = new System.Drawing.Size(133, 23);
            this.eraseAll.TabIndex = 7;
            this.eraseAll.Text = "erase all";
            this.eraseAll.UseCompatibleTextRendering = true;
            this.eraseAll.UseVisualStyleBackColor = true;
            this.eraseAll.Click += new System.EventHandler(this.event_eraseAll);
            // 
            // drawing
            // 
            this.drawing.BackColor = System.Drawing.Color.White;
            this.drawing.Location = new System.Drawing.Point(13, 13);
            this.drawing.Name = "drawing";
            this.drawing.Size = new System.Drawing.Size(380, 468);
            this.drawing.TabIndex = 8;
            this.drawing.TabStop = false;
            // 
            // gDraw
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(558, 512);
            this.Controls.Add(this.drawing);
            this.Controls.Add(this.eraseAll);
            this.Controls.Add(this.changeToHotPink);
            this.Controls.Add(this.inputDemo);
            this.Controls.Add(this.addFilledRectangle);
            this.Controls.Add(this.addHollwRectangle);
            this.Controls.Add(this.addFilledCircle);
            this.Controls.Add(this.addHollowCircle);
            this.Controls.Add(this.addPoint);
            this.Name = "gDraw";
            this.Text = "gDraw";
            this.inputDemo.ResumeLayout(false);
            this.inputDemo.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.drawing)).EndInit();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.Button addPoint;
        private System.Windows.Forms.Button addHollowCircle;
        private System.Windows.Forms.Button addFilledCircle;
        private System.Windows.Forms.Button addHollwRectangle;
        private System.Windows.Forms.Button addFilledRectangle;
        private System.Windows.Forms.GroupBox inputDemo;
        private System.Windows.Forms.Button addFilledCircleAt;
        private System.Windows.Forms.Button changeToHotPink;
        private System.Windows.Forms.Button eraseAll;
        private System.Windows.Forms.TextBox centerX;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.TextBox radius;
        private System.Windows.Forms.TextBox centerY;
        private System.Windows.Forms.PictureBox drawing;
    }
}

