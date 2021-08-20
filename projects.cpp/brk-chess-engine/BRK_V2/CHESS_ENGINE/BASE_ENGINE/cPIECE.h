//*******************************************************************
//              
//  FILE:       cPIECE.h
//              
//  AUTHOR:     Teemu Lätti
//              
//  PROJECT:    CHESS_ENGINE
//              
//  COMPONENT:  -
//              
//  DATE:       11.10.2004
//              
//  COMMENTS:   - base piece class
//              
//              
//*******************************************************************

// Pragmas

// Includes

#include "cBitArray.h"

#ifndef __cPIECE_H
#define __cPIECE_H

class cPIECE 
{
    private:
        SIDE_NAMES      side;               // side for piece
        PIECE_NAMES     piece_name;         // piece name
        SQUARE_NAMES    current_sq;         // current pice posistion - an be used as an attack sq index
        cBitArray       current_pos;        // current bit board representation of  location
        
    public:
        cPIECE() : current_pos()
          {
            side = NO_SIDE;
            piece_name = NO_NAME;
            current_sq = NO_SQUARE;
          }

        cPIECE(PIECE_NAME n ,SQUARE_NAME sq) : current_pos(sq)
          {
            current_sq = sq;
            piece_name = n;
            side = ( n < PLACK_PAWN) ? WHITE : BLACK;
          }

        ~cPIECE()
          {
          }

        cPIECE(const cPIECE& p)
         {
            side = p.side;
            piece_name = p.piece_name;
            current_pos = p.current_pos;
            current_sq  = p.current_sq;
         }


        cPIECE& operator=(const cPIECE& p)
         {
            side = p.side;
            piece_name = p.piece_name;
            current_pos = p.current_pos;
            current_sq  = p.current_sq;
            return *this;
         }
};

#endif