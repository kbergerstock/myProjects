
# function modular_pow(base, exponent, modulus)
#	 c := 1
# 	for e_prime = 1 to exponent 
# 		c := (c * base) mod modulus
#	return c

	
def mod_pow(base,exponent,modulus):
	c = 1
	for e in range(exponent):
		c = (c * base) % modulus
	return c

def mPow(b, e, m):
	r  = 1
	while e > 0:
		if e % 2 == 1:
			r = (r * b) % m
		e  = e >> 1
		b = (b * b ) % m
	return r


#	ecluides seive (mine)
def eSieve(n):
	d = list(range(0,n))
	P = [1,2]
	p = 2
	while p < n:
		m = p * p
		while m < n:
			d[m] = 0
			m += p
		m = p+1
		while m < n and d[m] == 0:
			m += 1
		if m < n:
			p = d[m]
			P.append(p)
		else:
			break
	return P		

#	ecluides seive (mine)
def eSieve1(n):
	n = int(n)
	P = [1]
	d = [True] * (n+1)	
	for p in range(2, n+1):
		if  d[p] :
			P.append(p)
			for m in range(p * p , n + 1, p):	
				d[m] = False
	return P		

	
# recurisive greatest common denomator from wikpedia algorithm implementation		
def egcd(a, b):
		if a == 0:
			return (b, 0, 1)
		else:
			g, y, x = egcd( b % a , a)
			return ( g, x - (b // a) * y, y)

# recurisive modular inverse from wikpedia algorithm implementation			
def modinv(a,m):
	g,x,y = egcd(a,m)
	if g != 1:
		return None	# modular inverse does not exist
	else:
		return x % m
				

# make rse keys from a list of primes and an entry point
def make_keys(P,k):
	p = P[k]
	q = P[k+1]
	n = p * q 
	t = (p-1)*(q-1)
	i = 10
	m = None
	while m == None:
		e = P[i]
		m = modinv(e,t)	
		i += 1
		
	return  e, m, t
		

def encrypt(s):
	b = bytearray(s, 'utf8')

	l=[]
	for i in range( 0, len(b)-4, 4):
		l.append( (b[i] << 24)+(b[i+1]<<16)+(b[i+2]<<8)+b[i+3] )
	return l
	
def decrypt(l):
	l=list(l)
	s =bytearray()
	
	for dw in l:
		s += ((dw>>24) & 255)
		s += ((dw>>16) & 255))
		s += ((dw>>8) & 255))
		s += (dw & 255))
		
	return s
	
	
def main():
	
	s1 = "this is a test, this is not a good test, but never the less this is a test keith R. Bergerstock..."
	print(s1)
	
	l  = encrypt(s1)
	print(l)
	
	b = decrypt(l)
	print(b)

	P1 = eSieve(10000)

	print ( make_keys( P1,101) )

	S1 = eSieve(1000)
	S2 = eSieve1(1000)

	
if __name__ == '__main__':
    main()
