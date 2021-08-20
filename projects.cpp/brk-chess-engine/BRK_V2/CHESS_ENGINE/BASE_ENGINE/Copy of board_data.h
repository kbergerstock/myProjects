//*******************************************************************
//              
//  FILE:       board_data.h
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
#include "cBitArray.h"

#ifndef __board_data_h
#define __board_data_h

extern cBitArray king_attack_boards[64];
extern cBitArray queen_attack_boards[64];
extern cBitArray rook_attack_boards[64];
extern cBitArray bishop_attack_boards[64];
extern cBitArray knight_attack_boards[64];

extern int king_attack_squares[8];
extern int queen_attack_squares[8];
extern int bishop_attack_squares[4];
extern int knight_attack_squares[8];
extern int rook_attack_squares[4];
extern int white_pawn_attacks[2];
extern int black_pawn_attacks[2];

void form_attack_boards();

extern cBitArray valid_board;
void fillValidBoard(void);

#endif