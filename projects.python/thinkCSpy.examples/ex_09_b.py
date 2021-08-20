#exercises for chapeter 9
#read_words, wordlen, no_e

def  wordln(w):
	return len(w) > 20

def no_e(w):
	for c in w:
		if c == 'e' or c == 'E':
			return False
	return True


def  read_words(fn, file):
	#reads file and isplays words longer then 20 chars
	lc = 0.0
	wc = 0.0
	f = open(file)
	for line in f:
		word = line.strip()
		lc += 1.0
		if  fn(word) :
			wc += 1.0
			print(word)
	f.close()
	print('percentage',100*wc/lc)

def read_word_list(file):
	f = open(file)
	for line in f:
		word = line.strip()
		print(word)
	f.close()


read_words(no_e,'c:\\src-code\\python\\words.txt')
read_words(wordln,'c:\\src-code\\python\\words.txt')
