#pragma warning(disable:4786)

//*******************************************************************
//              
//  FILE:       cGAME_MOVE.cpp
//              
//  AUTHOR:     Keith R. Bergerstock
//              
//  PROJECT:    CHESS_ENGINE
//              
//  COMPONENT:  -
//              
//  DATE:       24.10.2003
//              
//  COMMENTS:   - class to hold the definition of a game move
//              
//              
//*******************************************************************

// Includes

#include "cSQUARES.h"
#include "cMove.h"

#define MIN_MOVE_SIZE 3             // a move string has to be greater than this to be processed

#ifndef __cGAME_MOVE_H
#define __cGAME_MOVE_H

class cGAME_MOVE
{
    private:
        SIDE_NAMES    this_side;     // name of side whos move this is
        SQUARE_NAMES  from_square;
        SQUARE_NAMES  to_square;
        cMove         move; 

    public:
        cGAME_MOVE() : move()
         {
            this_side = NO_SIDE;
            from_square = to_square = NO_SQUARE;
         }

        cGAME_MOVE(const cGAME_MOVE& g)
         {
            this_side   = g.this_side;
            from_square = g.from_square;
            to_square   = g.to_square;
            move        = g.move;
         }

        const cGAME_MOVE& operator=(cGAME_MOVE g)
         {
            this_side   = g.this_side;    
            from_square = g.from_square;
            to_square   = g.to_square;
            move        = g.move;
            return *this;
         }

        bool operator==(cGAME_MOVE g)
         {
            return from_square == g.from_square && to_square == g.to_square && this_side == g.this_side;
         }

        SQUARE_NAMES from()     { return from_square; }
        SQUARE_NAMES to()       { return to_square; }
        void set(SIDE_NAMES s)  { this_side = s; } 
        SIDE_NAMES get_side()   { return this_side; }

        int convert(string& move_str);

        const char* get_move();

};

#endif

