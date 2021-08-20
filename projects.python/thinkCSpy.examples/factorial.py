#krb factorial

known = {0:0, 1:1}

def kFibonacci(n):
	if n in known:
		return known[n]
	res = kFibonacci(n-1) + kFibonacci(n-2)
	known[n] = res
	return res

def fibonacci(n):
	### recurisive fibonacci ####
	if n == 0:
		return 0
	elif n == 1:
		return 1
	else:
		return fibonacci(n-1) + fibonacci(n-2)

def iFibonacci(n):
        ### fast fibonacci based on iteritive loop ####
        f0 = 0
        f1 = 1
        if n == 0:
                return f0
        elif n == 1:
                return f1
        elif n == 2:
                return f0 + f1
        else:
                for i in range (n-2):
                        t = f0 + f1
                        f0 = f1
                        f1 = t
                return f0 + f1



def nFactorial(n):
	if n == 0:
		return 1
	else:
		return n * nFactorial(n-1)

def	iFactorial(n):
	f = 1
	for i  in range(n+1):
		if(i>0):
			f = f * i
	return f

def factorial(n):
	if not isinstance(n,int):
		print ('factorial is only defined for integers.')
		return None
	elif n < 0:
		print ('factorial is only defined for positive integers.')
		return None
	else:
		return nFactorial(n)

def ack(m,n):
	if m == 0:
		return n+1
	if m > 0 and n == 0:
		return ack(m-1,1)
	else:
		return ack(m-1,ack(m,n-1))



# main if used
def main():
	print (factorial(5.0))
	print (factorial(-5))

	for i in range(50):
			print (i,factorial(i),":",iFactorial(i))

	for i in range(50):
		print(i,iFibonacci(i))

	for i in range(51):
		print(i,kFibonacci(i))

	print (ack(3,4))

if __name__ == '__main__':
    main()

