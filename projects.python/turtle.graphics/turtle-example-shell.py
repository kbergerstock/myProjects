
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

def drawSectorTriangle(tTurtle,ln,sides):
    angle = 360.0 / sides
    a1 = angle / 2.0
    a2 = 180 - angle
    r = calcPolyRadius(ln,sides)

wn =   turtle.Screen()
alex = turtle.Turtle()
tess = turtle.Turtle()

wn.bgcolor("lightgreen")
tess.color("blue")
tess.pensize(3)

##r = calcPolyHgt(73,7)
##
##tess.penup()
##tess.left(90)
##tess.fd(r)
##tess.left(90)
##tess.fd(73/2)
##tess.left(180)
##tess.pendown()
##
##drawPoly(tess,7,73)
##
##alex.speed(6)
##
##for j in range(10):
##    alex.right(36)
##    drawSquare(alex,50)
##
##r1 = calcPolyRadius(73,7)
##
##tess.color("red")
##tess.pensize(1)
##tess.speed(10)
##tess.penup()
##tess.fd(73/2)
##tess.lt(90)
##tess.fd(r1-r)
##tess.rt(90)
##tess.pendown()
##
##drawCircle(tess,r1)
##
##tess.penup()
##tess.fd(150)
##tess.pendown()

##tess.color("blue")
##tess.pensize(1)
##tess.speed(10)
##drawPolyFlower(tess,75,60,7)


wn.exitonclick()
