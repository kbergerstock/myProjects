# usqrt.py


import time
def usqrt(n):
    xl = 0
    x = n // 2
    while x != xl:
        xl = x
        x  = (x + (n // x)) // 2
        
        if(x+1 == xl):
            break
    return x

if __name__ == "__main__":
    n = 1010000
    for i in range(1000):
        x = usqrt(i+n)
        print( n+i,"\t",x)