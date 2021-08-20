#pragma warning(disable:4786)

//*******************************************************************
//              
//  FILE:       cBOARD.h
//              
//  AUTHOR:     Keith R. Bergerstock
//              
//  PROJECT:    BASE_ENGINE
//              
//  COMPONENT:  - cBOARD
//              
//  DATE:       25.11.2003
//              
//  COMMENTS:   - definition of a chess board and a position upon it
//              - definition of a chess move expressed as a bit board
//              - both classes are base on bit arrays     
//
//				08/14/2007 - revamped  board rpresentation
//				-- changed it to a list of bitboards per side
//				-- where the bit board repersensts a single piced  
//              
//              
//*******************************************************************


// Includes
#include "cBitArray.h"
#include "cMove.h"

#ifndef __cBOARD_H
#define __cBOARD_H

class cMoveGenerator;

void   fillAttackArrays();
extern cBitArray kingAttackSquares[64];

class cBoard
{
    protected:        
        SIDE_NAMES  to_move;            // which side has the move from this position
        cBitArray   current_board;      // bit board of all pieces


        // castling flags               // these flags indicate castling rights
        U8 blackKside;
        U8 blackQside;
        U8 whiteKside;
        U8 whiteQside;

        void castle(cMove &,cMove&);

        // casling routines
        void white_castle_king_side( cMove &m);
        void white_castle_queen_side(cMove &m);
        void black_castle_king_side(cMove &m);
        void black_castle_queen_side(cMove &m);

        friend class cMoveGenerator;

    public:

        cBoard();                           // null constructor
        cBoard(const cBoard &);             // copy constructor
        cBoard& operator=(const cBoard&);   // assignement constructor

        void NewGame();
        void Clear();

        int getPiece(SQUARE_NAMES );
        int getPiece(RANK_NAMES ,FILE_NAMES );
        int setPiece(SQUARE_NAMES,PIECE_NAMES);
        int setPiece(RANK_NAMES r,FILE_NAMES f,PIECE_NAMES p);

        void setSide(SIDE_NAMES c)  { to_move = c; }
        int  toMove()               { return to_move; }

        void movePiece(cMove &m);
        int take_back(cMove &);
};


#endif
