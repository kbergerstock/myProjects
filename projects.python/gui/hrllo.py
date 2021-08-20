from tkinter import *

class GUI():
    def __init__(self):
        self.root = Tk()
        mylabel1 = Label(self.root,text='hello World !')
        mylabel2 = Label(self.root,text='this is a a test!')
        mybutton  = Button(self.root,text='enter name',padx=40,pady=14, command = self.myclick,bg='green')
        
        self.name = Entry(self.root,width=30)
        mylabel1.grid(row=0,column=0)
        mylabel2.grid(row=1,column=0)
        self.name.grid(row=1,column=1)
        mybutton.grid(row=2,column=1)

    
    def myclick(self):
        r = self.name.get()
        mylabel3 = Label(self.root, text =f'Look at me {r}')
        mylabel3.grid(row=3,column=1)

    def run(self):
        self.root.mainloop()

if __name__ == "__main__":
    gui = GUI()
    gui.run()

