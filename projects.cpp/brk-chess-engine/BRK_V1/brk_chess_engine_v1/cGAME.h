// the class to keep track of a game 

#pragma warning(disable:4786)

#include <string>
#include <vector>
using namespace std;

#include "cBoard.h"
#include "cPosition.h"

#ifndef __cGAME_H
#define __cGAME_H

class cGamePosition
{
    protected:
        cBoard position;            // current board (position) that this node works from
        cMove  move;                // copy of move that created this position
    public:
        cGamePosition(cBoard& b,cMove& m)
         {
            position = b;
            move = m;
         }

        cGamePosition(const cGamePosition& g)
         {
            position = g.position;
            move = g.move;
         }

    cBoard& getPosition()   { return position; }
    cMove&  getMove()       { return move; }
    int     toMove()        { return position.toMove(); }
    int     getColor()      { return move.getColor() ; }
};

typedef vector<cGamePosition> GAME_LIST;

class cGAME
{
    private:
        // game list is implemented as a vector of board move pairs
        GAME_LIST game_list;
        // list of valid moves form this position
        MOVE_LIST valid_moves;

        int     current_ply;
        
    public:
        cGAME();
        ~cGAME();    
        // start a new game list
        int new_game();
        // make a move to the current position via a pair of square names 
        int make_move(SQUARE_NAMES from_square, SQUARE_NAMES to_square);
        // make a move to the current position via a move structure - engine interface
        int make_move(cMove& );
        // take the last move back from the list
        int take_back();
        // get a reference to the current position this ensures that outside modifications are not done
        cBoard& getPosition()    { return game_list[current_ply].getPosition(); }
        int toMove()             { return game_list[current_ply].toMove(); }
        int getCurrentPly()      { return current_ply; }
        cMove& getLastMove()     { return game_list[current_ply].getMove(); }
        
        void list(cOUTPUT&);
        void outputReply(cOUTPUT&);
            
};

#endif
