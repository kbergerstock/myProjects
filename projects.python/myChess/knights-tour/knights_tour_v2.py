#knights tour
# the real purpose of this is to figure out how to handle search trees
# implement next version using 0x88 board format

BLOCKED = 2
KNIGHT  = 3

# translate frome normal board coodrinates to array coordintates	
def tRow(r):
	return 10 - r

def tCol(c):
	return c + 1	

class Board:
	def __init__ (self, brd = None):
		if brd is None:
			self.b = bytearray(144)
		else:
			self.b = brd.b[:]
		
	def __getitem__(self,idx):
		return self.b[idx]

	def set(self,row,col,piece):
		self.b[row * 12 + col] = piece
		
	def get(self,row,col):
		return self.b[row *12 + col]
	
	def set_square(self,r,c,piece):
		self.b[ tRow(r) * 12 + tCol(c) ] = piece
		
	def get_square(self,r,c):
		return self.b[ tRow(r) * 12 + tCol(c) ]

	
class Move:
	def __init__(self,r1=0,c1=0,r2=0,c2=0,p = 0):
		self.r1=r1		# x1 = frm
		self.c1=c1		# x2 = to
		self.r2=r2
		self.c2=c2	
		self.piece = p
	
	def set(self,r1=0,c1=0,r2=0,c2=0,p = 0):
		self.r1=r1		# x1 = frm
		self.c1=c1		# x2 = to
		self.r2=r2
		self.c2=c2	
		self.piece = p

	def moveto(self,board):
		board.set(self.r2,self.c2,self.piece)

	def block(self,board):
		board.set(self.r1,self.c1,BLOCKED)		

	def moveback(self,board):
		board.set(self.r1,self.c1,self.piece)		
		board.set(self.r2.self.c2,0)
		
	def __str__(self):
		return 'move ( {self.r1}, {self.c1},{self.r2},{self.c2})'.format(self=self)

def tSqr(m):
	if m is None:
		return None
	else:	
		return  (( 9 - m.r2 ) * 8) + (m.c2 - 1 )		
		
class Piece:		
	def __init__(self,r = 0, c = 0, p = 0):
		self.r = r
		self.c = c
		self.piece = p	

	def set_piece(self,board):
		board.set(self.r,self.c,self.piece)
		
	def generate_move_list(self, board, ml = None):
		return ml
		
		
_knmr = [ -2,-2,-1,-1, 1, 1, 2, 2 ]
_knmc = [ -1, 1,-2, 2,-2, 2,-1, 1 ]
		
class Knight(Piece):
	def __init__(self,r = 0, c = 0, d = 0):
		self.r = r
		self.c = c
		self.d = d
		self.piece = KNIGHT
	
	#this function generats a move list for the knights tour problem and uses Warnsdorff's algorithm to prune the move tree	
	def generate_move_list(self, board, ml = None):
		w = 8
		tl = []
		if ml is None:
			ml = []	
		for i in range(8):
			r = self.r + _knmr[i]
			c = self.c + _knmc[i] 
			if board.get(r,c) == 0:
				d = 0
				# find the number of availble sqares for the square under consideration
				for j in range(8):
					if board.get(r+_knmr[j],c+_knmc[j]) == 0:
						d+=1
				# if the curreent sqaure has less moves the the last square keep it and throw away the previous list		
				if	d < w:
					tl = []
					w = d				
					m = Move(self.r, self.c, r, c,KNIGHT)
					tl.append(m)
				elif d == w:	# if the cureent square equal the current min count add to tree
					m = Move(self.r, self.c, r, c,KNIGHT)
					tl.append(m)
		# appedn the generated movelist to pass in move list				
		if len(tl) > 0:
			for m in tl:
				ml.append(m)
		#return the move list		
		return ml		

# #generate a move list
def generate_move_list(board,move_list = None):
	if move_list is None:
		move_list = []
	# generate a move list
	for i in range(12):
		for j in range(12):
			if board.get(i,j) == KNIGHT:
				knight = Knight(i,j)
				knight.generate_move_list(board,move_list) 
	return move_list
	
def init_board(b):
	for i in range(12):
		b.set(0,i,99)
		b.set(1,i,99)
		b.set(10,i,99)
		b.set(11,i,99)
	for i in (2,3,4,5,6,7,8,9):		
		for j in (0,1,10,11):
			b.set(i,j,99)		
					
def dump_board(b):
	for i in range (8):
		s = (i+2) * 12
		print(8-i,b[s+2],b[s+3],b[s+4],b[s+5],b[s+6],b[s+7],b[s+8],b[s+9])

#reutrns true as long as the knight tour is incomplete		
# def is_not_tour_complete(b):
	# for i in range(72):
		# if b[24+i] == 0:
			# return True
	# return False			


class cNode:
	#current board
	# reference toparent node
	# list of generated boards form calulcated move list
	def __init__(self,board,move = None , parent = None):
		self._board = board
		self._move = move
		self._parent = parent
		self._children = []
		if parent is None:
			self._ply =  0
		else:
			self._ply = parent._ply + 1
		self._walked = False

	def get_parent(self):
		return self._parent
		
	def get_board(self):
		return self._board
		
	def get_children(self):
		return self._children
		
	def generate(self):
		#genereate move list
		moves = generate_move_list(self._board)
		nm = len(moves)
		#for each move allocate a duplicate board and make move
		# ie create tree
		if nm > 0:
			for m in moves:
				nb = Board(self._board)
				m.moveto(nb)
				m.block(nb)
				node = cNode(nb,m,self)
				self._children.append(node)
		return nm
		
	def walked(self):
		return self._walked
			
	def set_walked(self):
		self._walked = True
		
	def del_children(self):
		del(self._children[:])
	
	def next_child(self):
		for node in self._children:
			if not node._walked:
				return node
		return None		

	def search(self):
		n = self
		move_counter = 0
		#while is_not_tour_complete(n._board):			# while solution not found
		while n._ply < 3:								# alt test - have enough moves been made to cover board
			if n.walked():								# if current node has been walked delete its children and go up the tree
				n = n.get_parent()
			else:										# otherwise 
				if len(n._children)>0:					# if current node hase cildren and all are walked set current not wlak flag to true
					p = n.next_child()
					if p is None:
						n.set_walked()
						n.del_children()
						n = n.get_parent()
					else:
						n = p
				else:
					move_counter += n.generate()		# no children and not walked	generate children
					p = n.next_child()  			    # go to next leaf intree
					if p is None:
						n.set_walked()
						print("move counter : ", move_counter)	
					else: 
						n = p

		print("move counter : ", move_counter)
		print("solution found")
		dump_board(n.get_board())
		p = n
		ml = []
		while p != None:
			ml.append(p._move)
			p = p.get_parent()
		ml.reverse()
		ml.pop(0)
		k = 0
		for m in ml:
			print('{:2}'.format(tSqr(m) ),end = ' ' )
			k += 1
			if  k % 8 == 0:
				print(end = '\n')
		
	
def main():
	print("knights tour")
	board = Board()
	init_board(board)
	
	knight = Knight(tRow(1), tCol(2) )
	knight.set_piece(board)
	dump_board(board)
	
	tree = cNode(board)
	tree.search()
	
		
if __name__ == '__main__':
	main()			

					
			