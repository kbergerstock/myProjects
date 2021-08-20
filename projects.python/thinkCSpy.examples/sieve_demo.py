#! python3

def eSieve1(n):
	n = int(n)
	P = []
	d = [True] * (n+1)
	for p in range(2, n+1):
		if  d[p] :
			P.append(p)
			for m in range(p * p , n + 1, p):
				d[m] = False	
	return P


def main():
    P1 = eSieve1(10021)
    print(P1)

if __name__ == '__main__':
    main()

