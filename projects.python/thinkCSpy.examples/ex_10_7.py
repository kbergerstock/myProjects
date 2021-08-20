#read word file and construct list
#krb


import datetime
import time
import os

def append(t,w):
	t.append(w)
	
def  read_words(file,fn,t):
	#reads file and performs function on word
	f = open(file)
	for line in f:
		word = line.strip()
		fn(t,word)
	f.close()

#---------------------------------------------------------------------	
	
def bisect(word_list,word):
	#example 10.8
		li = 0
		hi = len(word_list)
		while True:
			mi = (li + hi ) // 2	
			if word_list[mi] == word:
				return mi
			elif  li == mi or mi == hi:
				return None
			elif word < word_list[mi]:
				hi = mi 
			else:
				li = mi
				
def search(word_list,word):
	#example 10.7
	if word in word_list:	
		return  word_list.index(word)
	else:
		return None
	
	
def dict_find(wd,word):
	# example 11.1
	if word in wd:
		return wd[word]
	else:
		return  None	

#---------------------------------------------------------------------
	
def output(word_list,fn,word):
	idx = 0
	ts = time.perf_counter()
	for i in range (100):
		idx = fn(word_list,word)
	te = time.perf_counter()
	et = (te-ts) * 1e6 / 100

	print( ' {0:12} {1:12} {2:} '.format(word,idx,et) )


def main():
	#append method
	wl = []
	wd = dict()
	ts=time.clock()
	path = os.getcwd() + '\\words.txt'
	read_words(path,append,wl)
	
	pos = 0
	for w in wl:
		wd[w] = pos
		pos += 1

	te=time.clock()	
	print('load time:',(te-ts)*1000)
	
	
	fl = ['treadmill','abeam','keith','intuit','aa','zymurgy']
	for word in fl:
		output(wl,bisect,word)
		output(wl,search,word)
		output(wd,dict_find,word)
		
if __name__ == '__main__':
    main()
		