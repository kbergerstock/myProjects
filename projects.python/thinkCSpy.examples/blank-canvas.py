from tkinter import *


root = Tk()

w = Canvas(root,width=800,height=400)
l = Label(root,text="test",width=100)
w.pack(side="top")
l.pack(side="bottom",fill="both")

mainloop()

