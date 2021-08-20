#python square root via newtons method
import math

def sqrt_guess(a,x):
	return (x + a/x) /2.0
	
	
def sqrt(a):
	''' find the sqrt of a number using newton's method'''
	x0 = a
	x1  = a / 2.0
	i = 0
	while abs( x1 - x0  ) > 1e-9:
		print("itereration",i,x0)
		x0 = x1
		x1 = sqrt_guess(a,x0)
		i = i +1
	return x1		

			
			
			
print(sqrt(4))
print(sqrt(100))
print(sqrt(999))
print(sqrt(5))
