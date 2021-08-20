# python template
# k. r. bergerstock

#imports
import random
import os

def  read_words(word_list, file):
	#reads file and stores in a dictionary
	lc = 0
	f = open(file)
	for line in f:
         word = line.strip()
         lc += 1
         word_list[word] = lc
	f.close()
     
# main if used     
def main():
	word_list = dict()
	try:
		path = os.getcwd() + '\\words.txt'
		read_words(word_list,path)
		print('aback' in word_list)
		print('keith' in word_list)
		print('zoos' in word_list)
	except OSError:
		print(os.getcwd() )
	finally:
		pass
 
if __name__ == '__main__':
    main()