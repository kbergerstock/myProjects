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

#ifndef __cMoveGenerator
#define __cMoveGenerator


class cMoveGenerator
{
    private:
                  
        // current board that the move generator works from
        MOVE_LIST  move_list;

        cBoard*     this_position;
        cBitArray   this_side;
        cBitArray   opp_side;
        cBitArray   attack_board;

        void generate_king_attack_squares(int square);
        void generate_white_pawn_attack_squares(int square);
        void generate_black_pawn_attack_squares(int square);
        void generate_knight_attack_squares(int square);
	    void generate_bishop_attack_squares(int square);
	    void generate_rook_attack_squares(int square);

	    void generate_queen_attack_squares(int square);



        void calc_attack_board();           

        void generate_king_moves(int square);
        void generate_pawn_moves();
        void generate_knight_moves();
        void generate_bishop_moves();
        void generate_rook_moves();
        void generate_queen_moves();

    public:
        cMoveGenerator();
        ~cMoveGenerator();

        void make(cBoard& position);

};

#endif