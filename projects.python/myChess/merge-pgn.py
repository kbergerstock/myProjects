#merge pgn files 
#k.r.bergerstock

#imports
import os


def  read_file(fn, file):
	#reads file
	f = open(file)
	for line in f:
		fn(line)
	f.close()

def walk(fn,dir):
	for name in os.listdir(dir):
		path = os.path.join(dir,name)
		# add a check her to ensure that it is a pgn file
		if  'pgn' in path:
			read_file(fn,path)
			fn('\n')
		
def main():
	path = 'c:\\users\\keith\\chess-games'
	walk(print, path)
	pgn = os.path.join(path,'chess_games.pgn')
	try:
		fout = open(pgn,'w')
		walk(fout.write,path)
		fout.close()
	except:
		print('oops')
						
	try:
		read_file(print,pgn)
	except:
		print(' not able to read pgn file')	
	print('done')
	
if __name__ == '__main__':
	main()
	