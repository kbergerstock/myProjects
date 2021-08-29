// converted to win 10 64.bit mode 2021
using System;
using System.Windows.Forms;

namespace cphat
{
    static class Program
    {
        /// <summary>
        /// The main entry point for the application.
        /// </summary>
        [STAThread]
        static void Main()
        {
            Application.EnableVisualStyles();
            Application.SetCompatibleTextRenderingDefault(false);
            Application.Run(new Hat());
        }
    }
}