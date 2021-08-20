//*******************************************************************
//              
//  FILE:       attackSquares.cpp
//              
//  AUTHOR:     Keith R. Bergerstock
//              
//  PROJECT:    CHESS_ENGINE
//              
//  COMPONENT:  -
//              
//  DATE:       28.02.2006
//              
//  COMMENTS:   - arrays of attack squares that can be used to form 
//              - an attack board quickly and simply
//              
//              
//*******************************************************************

#pragma warning (disable:4786)

// Includes
#include "cBoard.h"

cBitArray kingAttackSquares[64];

static int king_moves[8] = {-9,-8,-7,-1,1,7,8,9};

void fillKingAttackArrays()
{
    for(int i = A1; i < NO_SQUARE; i++)
      for(int j = 0; j < 8; j++)
        {
            int sq = i + king_moves[j];
            if(sq >= A1 && sq < NO_SQUARE)
              {
                kingAttackSquares[i].setPiece(sq);
              }
        }
}

void fillAttackArrays()
{
    fillKingAttackArrays();
}