//*******************************************************************
//              
//  FILE:       board_data.cpp
//              
//  AUTHOR:     Teemu Lätti
//              
//  PROJECT:    CHESS_ENGINE
//              
//  COMPONENT:  -
//              
//  DATE:       03.12.2004
//              
//  COMMENTS:   -
//              
//              
//*******************************************************************

// Pragmas

// Includes
#include "board_data.h"

cBitArray king_attack_boards[64];
cBitArray queen_attack_boards[64];
cBitArray rook_attack_boards[64];
cBitArray bishop_attack_boards[64];
cBitArray knight_attack_boards[64];

// piece attack / move vectors
int king_attack_squares[8]      = { -9,-8,-7,-1,1,7,8,9 };
int queen_attack_squares[8]     = { -9,-8,-7,-1,1,7,8,9 };
int bishop_attack_squares[4]    = { -9, -7, 7, 9 };
int knight_attack_squares[8]    = { -17,-15,-10,-6,6,10,15,17};
int rook_attack_squares[4]      = { -8, -1, 1, 8 };

// pawn attack vectors
int white_pawn_attacks[2]       = { 7, 9 };
int black_pawn_attacks[2]       = {-7,-9 };

void gen_king_attack_board(int kings_square)
{
    int s;
    for(int m = 0; m < 8; m++)
        {
            s = kings_square + king_attack_squares[m];
            // to square is withen bounds and empty of same color piece
            if(s >= A1 && s < NO_SQUARE)
             {     
                king_attack_boards[s].setPiece(SQUARE_NAMES(s));
             }
        }
            
}

void gen_queen_attack_board(int queens_square)
{
    int s;
    for(int m = 0; m < 8; m++)
     {
        s = queens_square + queen_attack_squares[m];
        while(s >= A1 && s < NO_SQUARE)
         {
            queen_attack_boards[s].setPiece(SQUARE_NAMES(s));
            s += queen_attack_squares[m];
         }
     }
}

void gen_bishop_attack_board(int bishops_square)
{
    int s;
    for(int m = 0; m < 4; m++)
     {
        s = bishops_square + bishop_attack_squares[m];
        while(s >= A1 && s < NO_SQUARE)
         {
            bishop_attack_boards[s].setPiece(SQUARE_NAMES(s));
            s += bishop_attack_squares[m];
         }
     }
}

void gen_knight_attack_board(int knights_square)
{
    int s;
    for(int m = 0; m < 8; m++)
        {
            s = knights_square + knight_attack_squares[m];
            // to square is withen bounds and empty of same color piece
            if(s >= A1 && s < NO_SQUARE)
             {     
                knight_attack_boards[s].setPiece(SQUARE_NAMES(s));
             }
        }
}

void gen_rook_attack_board(int rooks_square)
{
    int s;
    for(int m = 0; m < 4; m++)
     {
        s = rooks_square + rook_attack_squares[m];
        while(s >= A1 && s < NO_SQUARE)
         {
            rook_attack_boards[s].setPiece(SQUARE_NAMES(s));
            s += rook_attack_squares[m];
         }
     }
}

void form_attack_boards()
{
    // form king attack boards
    for(int s = A1; s < NO_SQUARE; s++)
     {
        gen_king_attack_board(s);
        gen_queen_attack_board(s);
        gen_knight_attack_board(s);
        gen_bishop_attack_board(s);
        gen_rook_attack_board(s);
     }   
}