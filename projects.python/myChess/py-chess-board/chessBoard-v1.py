#python chess board
# krb

#imports
from tkinter import *

class dBoard():
	#init internal variables
	def __init__(self,root):
		self.root = root
		self.squares = []
	# populate the grid with canvasas	
	def create(self,white,black):
		colors = [white,black]
		c = 1
		for i in range(8):
			for j in range(8):
				sq = Canvas(self.root,width=50,height=50,bg=colors[c]) 
				sq.grid(row = i, column = j+1)
				self.squares.append(sq)
				c ^= 1
			c ^=1
		ranks =  [ '8','7','6','5','4','3','2','1' ] 	
		files =  [ 'a','b','c','d','e','f','g','h' ] 	
		for  i in range(8):
			rl = Label(self.root,text = ranks[i])
			rl.grid(row = i,column = 0)
			fl = Label(self.root,text = files[i])
			fl.grid(row = 9, column = i+1)
			
		
class mApp():
	#create the board
	def __init__(self):
		self.root = Tk()
		self.board = dBoard(self.root)
		white = '#005076'
		black = '#008096'
		self.board.create(white,black)
	# execute the application
	def run(self):
		mainloop()


def main():
	app = mApp()
	app.run()

	
if __name__ == '__main__':
	main()