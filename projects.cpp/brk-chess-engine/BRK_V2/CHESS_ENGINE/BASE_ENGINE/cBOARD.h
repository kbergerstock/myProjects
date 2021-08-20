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
//              
//*******************************************************************


// Includes
#include "cBitArray.h"
#include "cMove.h"

#ifndef __cBOARD_H
#define __cBOARD_H

class cMoveGenerator;

class cBoard
{
    protected:        
        SIDE_NAMES  to_move;            // which side has the move from this position
        cBitArray   current_board;      // bit board of all pieces
        cBitArray   black_pieces;       // bit board of all black pieces
        cBitArray   white_pieces;       // bit board of all white pieces
        cBitArray   pawns;              // bit board of all pawns
        cBitArray   rooks;              // bit board of all rooks
        cBitArray   knights;            // bit board of all knights
        cBitArray   bishops;            // bit board of all bishops
        cBitArray   queens;             // bit board of all queens
        cBitArray   kings;              // bit board of all kings

        // castling flags               // these flags indicate castling rights
        int blackKside;
        int blackQside;
        int whiteKside;
        int whiteQside;

        void movePiece(cMove &m);
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
        SIDE_NAMES toMove()               { return to_move; }

        
        int make_move(cMove &);
        int take_back(cMove &);
};


#endif
