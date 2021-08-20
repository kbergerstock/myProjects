
def  pbk(str):
	k = -1
	for i in range(len(str)):
		print(str[k])
		k = k - 1
		
def rotate(s,d):
	s1 = ''
	for c in s.lower():
		o = (ord(c) + d) 
		if o > ord('z'):
			o = o - ord('z')
			o = ord('a') + o - 1
		elif o < ord('a'):
			o = ord('a') - o
			o = ord('z') - o + 1
		s1 = s1 + chr(o)
	return s1
	
		
pbk('keith')
	
print(rotate("cheer",26+7))
print (rotate("melon",-10))
