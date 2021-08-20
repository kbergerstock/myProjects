//*******************************************************************
//              
//  FILE:       cMOVE_GEN.h
//              
//  AUTHOR:     Keith R. Bergerstock
//              
//  PROJECT:    CHESS_ENGINE
//              
//  COMPONENT:  cPosition
//              
//  DATE:       13.01.2004
//              
//  COMMENTS:   -
//              
//              
//*******************************************************************

// Includes
#include "cBoard.h"

#include "tArray.h"

#ifndef __cMoveGenerator
#define __cMoveGenerator

typedef tARRAY<cMove> MOVE_LIST;

class cMoveGenerator 
{
    private:
        IDX        move_iter;
        // current board that the move generator works from
        MOVE_LIST  move_list;
        cBitArray  attack_board;

        cBitArray create_attack_board(cBoard&);

        void      reset() { move_iter = 0; }
          
        int       eval_material(cBoard&);

        int       eval(cBoard&);  

        void gen_king_moves(cBoard&, int square);   // generate king moves from current position

    public:
        cMoveGenerator();
        ~cMoveGenerator();

        void make_move_list(cBoard& position);

        IDX size() { return move_iter; }

        cMove& operator[](IDX i) { return move_list[i]; }
};

#endif