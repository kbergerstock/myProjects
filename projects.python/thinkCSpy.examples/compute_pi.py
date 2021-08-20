#krb factorial
import math
		
def	iFactorial(n):
	''' computs factorial using iteration - no parameter checking'''
	f = 1
	for i  in range(n+1):
		if(i>0):
			f = f * i
	return f	
		


def compute_term(k):
	''' computes summation term of ramanujan's infinte series'''
	nm = float(iFactorial(4*k)) * (1103.0 + 26390.0 * k)
	dn = (float(iFactorial(k)) ** 4) * (396.0 **(4 * k))
	return nm/dn
	
def compute_pi():
	k = 0
	s = 0.0
	t = compute_term(k)
	while t > 1e-15:
		s = s + t
		k = k + 1
		t = compute_term(k)
	pi = ((2.0 * math.sqrt(2.0))/9801.0) * s
	return 1/pi
		
print("pi = " , compute_pi(),math.pi)
	
