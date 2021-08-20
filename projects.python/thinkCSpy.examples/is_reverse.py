#is reverse.py

def is_reverse(s1,s2):
	if len(s1) != len(s2) :
		return False
	j = -1
	for i in range(len(s1)):
		if s1[i] != s2[j]:
			return False
		j  -= 1
	return True
	
	
	
print(is_reverse('stop','pots'))