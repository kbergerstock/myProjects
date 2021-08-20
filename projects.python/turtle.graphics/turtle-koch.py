
#krb 1/17/20123 turtle exercise

import turtle
import math

def draw(t,length,n):
	if n == 0:
		return
	angle = 50.0
	t.fd(length * n)
	t.lt(angle)
	draw(t,length,n-1)
	t.rt(2*angle)
	draw(t,length,n-1)
	t.lt(angle)
	t.bk(length * n)

def  koch(t,x):
	if(x < 3):
		t.fd(x)
		return
	koch(t,x/3)
	t.lt(60)
	koch(t,x/3)
	t.rt(120)
	koch(t,x/3)
	t.lt(60)
	koch(t,x/3)

def kochSnowFlake(t,x):
	t.rt(60)
	for i in range(3):
		koch(t,x)
		t.rt(120)
	
wn =   turtle.Screen()
tess = turtle.Turtle()
tess.hideturtle()

tess.speed(10)
tess.pu()
tess.lt(90)
tess.dot(4,"blue")
tess.fd(100)
tess.rt(90)
tess.pd()
kochSnowFlake(tess,300)

wn.exitonclick()
