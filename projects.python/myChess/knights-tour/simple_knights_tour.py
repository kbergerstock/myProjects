#!/usr/bin/env python
 
"""knights_walk.py A simple Knight's Tour random walk."""
__author__      = "Jon Bringhurst <jon@bringhurst.org>"
 
import random
 
def main():
    width = 8; height = 8
 
    random_start = random.randint(0, width*height-1)
    x = random_start%width
    y = (random_start-x)/width
 
    board = []; map(lambda y: board.append(['x']*width), range(height))
    print(make_a_move((x, y), 0, board, width, height))
 
def make_a_move(position, counter, board, width, height):
    (x, y) = position; board[x][y] = str(counter)
 
    valid_jumps = filter(lambda x: 
        True if 0<=x[0]<width and 0<=x[1]<height and board[x[0]][x[1]] == 'x' 
        else False, map(lambda x: tuple(map(sum, zip(position, x))), 
        [(-2,1), (-1,2), (1,2), (2,1), (2,-1), (1,-2), (-1,-2), (-2,-1)]))
 
    if len(valid_jumps) == 0: return board
    return make_a_move(valid_jumps[random.randint(0, len(valid_jumps)-1)], 
        counter+1, board, width, height)
 
if __name__ == "__main__":
    main()
