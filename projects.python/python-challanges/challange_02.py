ecs = "g fmnc wms bgblr rpylqjyrc gr zw fylb. rfyrq ufyr amknsrcpq ypc dmp. bmgle gr gl zw fylb gq glcddgagclr ylb rfyr'q ufw rfgq rcvr gq qm jmle. sqgle qrpgle.kyicrpylq() gq pcamkkclbcb. lmu ynnjw ml rfc spj. "


def rotate(s,d):
	s1 = ''
	print(s)
	for c in s:
		if c > 'z' or c < 'a':
				s1 = s1 + c
		else:
			o = (ord(c) + d) 
			if o > ord('z'):
				o = o - ord('z')
				o = ord('a') + o - 1
			elif o < ord('a'):
				o = ord('a') - o
				o = ord('z') - o + 1
			s1 = s1 + chr(o)
	return s1
	
		
	
def main():
	print(rotate("koe",2))
	print(rotate("mqg",-2))
	print( rotate(ecs,-24))
	print(rotate("map",-24))
	
if __name__ == '__main__':
    main()	
	
	
#	http://www.pythonchallenge.com/pc/def/ocr.html

