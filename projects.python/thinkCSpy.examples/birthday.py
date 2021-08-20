#birthday.py

import random

def has_duplicates(t):
    k=t[:]
    k.sort()
    for i in range((len(k)-1)):
        if k[i] == k[i+1]:
            return 1
    return 0
    
def generate():
    t = []
    for i in range(23):
        t.append(random.randint(1,365))
    return t
     
def main():
    total = 0
    pos = 0
    for i in range(1000):
        t = generate()
        total += 1
        pos += has_duplicates(t)
    print(pos,total,100.0*float(pos)/float(total))
 
if __name__ == '__main__':
    main()