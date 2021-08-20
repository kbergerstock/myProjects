#pragma warning(disable:4786)

//*******************************************************************
//              
//  FILE:       cMove.h
//              
//  AUTHOR:     Keith R. Bergerstock
//              
//  PROJECT:    BASE_ENGINE
//              
//  COMPONENT:  -
//              
//  DATE:       20.12.2003
//              
//  COMMENTS:   -
//              
//              
//*******************************************************************

// Includes
#include "cBitArray.h"

#include <vector>
using namespace std;

#ifndef __cMove_h
#define __cMove_h

class cMove
{
    private:
        cBitArray   from;
        cBitArray   to;
        SIDE_NAMES  side_moved;

        int captured_piece;
        int piece_moved;
        int castle_flag;

        friend class cBoard;

    public:
        cMove()
            {
                piece_moved = 0;
                side_moved  = NO_SIDE;
                captured_piece = 0;
                castle_flag = 0;
            }

        cMove(const cMove& m) 
            {
                from            = m.from;
                to              = m.to;
                piece_moved     = m.piece_moved;
                side_moved      = m.side_moved;
                captured_piece  = m.captured_piece;
                castle_flag     = m.castle_flag;
            }

        cMove(SQUARE_NAMES start, SQUARE_NAMES end, SIDE_NAMES side)
         {
            from.setPiece(start);
            to.setPiece(end);
            side_moved = side;
            captured_piece = 0;
            castle_flag = 0;
         }

        cMove(cBitArray start, cBitArray end, SIDE_NAMES side,PIECE_NAMES n, int cf)
         {
            from = start;
            to = end;
            side_moved = side;
            captured_piece = n;
            castle_flag = cf;
         }

        void set(SQUARE_NAMES start, SQUARE_NAMES end, SIDE_NAMES side)
         {
            from.setPiece(start);
            to.setPiece(end);
            side_moved = side;
            captured_piece = 0;
            castle_flag = 0;
         }

        void set(cBitArray start, cBitArray end, SIDE_NAMES side,PIECE_NAMES n, int cf)
         {
            from = start;
            to = end;
            side_moved = side;
            captured_piece = n;
            castle_flag = cf;
         }

        int  getColor()                 { return side_moved; }  

        bool operator==(const cMove& a)
             {
                return (from == a.from) && (to == a.to) && (piece_moved == a.piece_moved);
             }
};

// move list is implemented as a vector - 
// contains all moves made to reach current position on board
typedef vector<cMove>       MOVE_LIST;
typedef MOVE_LIST::iterator MOVE_ITOR;

#endif