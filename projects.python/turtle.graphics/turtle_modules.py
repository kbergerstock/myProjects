
#krb 1/17/20123 turtle exercise

import turtle
import math

def deg2rad(d):
    rad = (d * math.pi) / 180.0
    return rad

def calcPolyRadius(ln,sides):
    return ln / ( 2 * math.sin( math.pi / sides) )

def calcPolyHgt(ln,sides):
    r = calcPolyRadius(ln,sides)
    a = ln / 2.0
    b2 = r * r - a * a
    return math.sqrt(b2)

def drawPolyLine(tTurtle,n,length,angle):
    """	draw line segments for n sides with the given length and angle """
    for i in range(n):
        tTurtle.forward(length)
        tTurtle.right(angle)

def drawPoly(tTurtle,n,length):
    angle = 360.0 / n
    drawPolyLine(tTurtle,n,length,angle)

def drawSquare(tTurtle,length):
	drawPoly(tTurtle,4,length)

def drawArc(tTurtle,r,angle):
   """ draws a arc of radius r through given angle """
   arc_length = 2 * math.pi * r * angle / 360
   n = int(arc_length / 3) + 1
   step_length = arc_length / n
   step_angle = float(angle) / n
   drawPolyLine(tTurtle,n,step_length,step_angle)

def drawCircle(tTurtle, r):
	""" draws a circle of radius r """
	drawArc(tTurtle,r,360)

def drawFlower(tTurtle,r,n):
    angle = 2.0 *(360.0 / float(n))
    for i in range(n):
        drawArc(tTurtle,r,angle)
        tTurtle.rt((angle))

def drawPetal(tTurtle,r,angle):
    for i in range(2):
        drawArc(tTurtle,r,angle)
        tTurtle.right(180-angle)

def drawPolyFlower(tTurtle,r,arc_angle,n):
    angle = 360 / n
    for i in range(n):
        drawPetal(tTurtle,r,arc_angle)
        tTurtle.right(angle)
    
