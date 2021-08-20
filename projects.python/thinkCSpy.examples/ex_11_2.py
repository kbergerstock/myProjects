# python template
# k. r. bergerstock
# 11_2, 11_3, 11_4,11_5

#imports
import random

def histogram(s):
    d = dict()
    for c in s:
        d[c] = 1 + d.get(c,0)
    return d
    
def invert_dict(d):
	inv = dict()
	for key in d:
		val = d.key()
		if( inv.stdefault(val,key) ):
			inv[val].append(key)
	return inv
	
def reverse_lookup(d,v):
	for k in d:
		if d[k] == v:
			return k
	raise ValueError('value does not appear in the dictionary')
		
	
def print_hist(d):
	dl = []
	dl = sorted(d.keys() )
	for c in dl:
		print(c,d[c])
        
# main if used     
def main():
	b = histogram('brontosaurus')
	print(b)
	print(b.keys() )
	print_hist(b)

	print(reverse_lookup(b,2))
	print(reverse_lookup(b,3))

if __name__ == '__main__':
    main()