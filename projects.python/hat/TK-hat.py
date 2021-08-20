#krb TK-HAT()

from tkinter import *
import math
import datetime
import time


def calcCX(width):
    return width / 2

def calcCY(hgt):
    return int(((float(hgt)/2.0) * 9.0) / 10.0)

class mCanvas(Canvas):

    def plot(self,sx,sy,color):
        self.create_line(sx,sy,sx+1,sy,fill=color)

    def drawHat(self,color):
        #preload constants
        XP = 300.0
        YP = 110.0
        ZP = 90.0
        XR = 1.5 * math.pi
        YR = 1.0
        xf = XR/XP
        yf = YP/YR
        zf = XP/ZP
        xp2 = XP*XP
        cx = calcCX(800)
        cy = calcCY(600)
        zi = -ZP
        while zi < ZP:
            zt = zf * zi
            xl = 0.5 +  math.sqrt(xp2 - (zt * zt))
            xi = -xl
            while xi < xl:
                xt = math.sqrt( xi*xi + zt*zt) * xf
                yy = math.sin( math.sin(xt) + 0.4 * math.sin( 3.0 * xt) ) * yf
                sx = int(cx+xi+zi)
                sy = int(cy+zi-yy)
                self.plot(sx,sy,color)
                xi += 2.0                                       # inc xi to advance loop
            zi += 1.0                                           # inc zi to advance loop

class mApp():
    def __init__(self):
        self.color = "BLUE"
        self.root = Tk()
        self.w = mCanvas(self.root,width=800,height=600,bg="BLACK")
        self.sb = Label(self.root,text="running",width=100)
        self.w.pack(side="top")   
        self.sb.pack(side="bottom")

    def run(self):
        ts=time.time()
        self.w.drawHat(self.color)
        te=time.time()
        et = "elapsed time :%g" % ((te-ts)*1000.0)
        self.sb["text"]=et
        mainloop()


def main():
    app = mApp()
    app.run()

if __name__ == '__main__':
    main()





