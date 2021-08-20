import clr
clr.AddReference('System.Drawing')
clr.AddReference('System.Windows.Forms')

from System.Drawing import *
from System.Windows.Forms import *

class MyForm(Form):
    def __init__(self):
        # Create child controls and initialize form
        self.Text = "hw version 0.0.3.0"
        self.Width =  800
        self.Height = 640
        self.textbox1 = Label()
        self.textbox1.Text = "hello World"
        self.textbox1.Top = 50
        self.textbox1.Left = 25
        self.Controls.Add(self.textbox1)
        self.button = Button()
        self.button.Text = "OFF"
        self.button.Click+= self.onClickB1
        self.button.Top = 100
        self.button.Left = 25
        self.Controls.Add(self.button)
        self.button2 = Button()
        self.button2.Text = "Not Ready"
        self.button2.Click+= self.onClickB2
        self.button2.Top = 150
        self.button2.Left = 25
        self.Controls.Add(self.button2)
     
    def onClickB1(self,source,event):
        if self.button.Text == "ON":
            self.button.Text = "OFF"
        else:
            self.button.Text = "ON"

    def onClickB2(self,source,event):
        if self.button2.Text == "Ready":
            self.button2.Text = "Not Ready"
        else:
            self.button2.Text = "Ready"

Application.EnableVisualStyles()
Application.SetCompatibleTextRenderingDefault(False)

form = MyForm()
Application.Run(form)
