using System;
using System.Diagnostics;
using System.Drawing;
using System.Windows.Forms;


namespace cphat
{
    public partial class Hat : Form
    {
        // defined constants
        const double pi = 3.14159265358979323846;
        const double XP = 300;
        const double YP = 110;
        const double ZP = 90;
        const double XR = (1.5 * pi);
        const double YR = 1.0;

        public Hat()
        {
            InitializeComponent();
            // force plot update
            plot.Invalidate();
        }

        // fix add plot routines here
        private void DrawPoint(Graphics g, Pen pen, float x, float y)
        {
            g.DrawRectangle(pen, x, y, (float)0.1, (float)0.1);
        }
        private int CalcCY(int hgt)
        {
            return (((hgt / 2) * 9) / 10);
        }
        private int CalcCX(int width)
        {
            return (int)(width / 2.0);
        }

        public void DrawHat(Graphics g)
        {
            // Create a new pen.
            Pen pen = new Pen(Brushes.Blue);

            // function variables
            int zi, xi, xl, yy;
            double zt, xt;
            double xf = XR / XP;
            double yf = YP / YR;
            double zf = XP / ZP;
            double xp2 = XP * XP;

            double dxi;
            int sx, sy;
            int cx = CalcCX(plot.Size.Width);
            int cy = CalcCY(plot.Size.Height);

            for (zi = (int)-ZP; zi < (int)ZP; zi++)
            {
                zt = zf * (double)(zi);
                xl = (int)(0.5 + Math.Sqrt(xp2 - (zt * zt)));

                for (xi = -xl; xi <= xl; xi += 2)
                {
                    dxi = (double)(xi);
                    xt = Math.Sqrt(dxi * dxi + zt * zt) * xf;
                    yy = (int)(Math.Sin(Math.Sin(xt) + 0.4 * Math.Sin(3.0 * xt)) * yf);
                    sx = (cx + xi + zi);
                    sy = (cy + zi - yy);
                    DrawPoint(g, pen, sx, sy);
                }
            }
        }

        private void Event_plot_draw(object sender, PaintEventArgs e)
        {
            Stopwatch pt = new Stopwatch();
            pt.Start();
            DrawHat(e.Graphics);
            pt.Stop();
            String v = "time:" + pt.ElapsedMilliseconds;
            time2draw.Text = v;
        }

    }
}