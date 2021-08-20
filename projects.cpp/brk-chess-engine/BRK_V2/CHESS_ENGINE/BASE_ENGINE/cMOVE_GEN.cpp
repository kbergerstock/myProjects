//*******************************************************************
//              
//  FILE:       cMOVE_GEN.cpp
//              
//  AUTHOR:     Keith R. Bergerstock
//              
//  PROJECT:    CHESS_ENGINE
//              
//  COMPONENT:  -
//              
//  DATE:       13.01.2004
//              
//  COMMENTS:   -
//              
//              
//*******************************************************************

// Includes

#include "cMOVE_GEN.h"

// move vectors     
static int king_moves[8] = { -9,-8,-7,-1,1,7,8,9 };
static int white_pawn_attacks[2] = { 7, 9 };
static int black_pawn_attacks[2] = {-7,-9 };

cMoveGenerator::cMoveGenerator()
{
}

cMoveGenerator::~cMoveGenerator()
{
}

void cMoveGenerator::generate_king_attack_squares(int square)
{
    cBitArray start((SQUARE_NAMES) square);

    for(int i = 0; i < 8; i++)
        attack_board |= start.rotate(king_moves[i]);
}

void cMoveGenerator::generate_white_pawn_attack_squares(int square)
{
    cBitArray start((SQUARE_NAMES) square);

    for(int i = 0; i < 2; i++)
        attack_board |= start.rotate(white_pawn_attacks[i]);
}

void cMoveGenerator::generate_black_pawn_attack_squares(int square)
{
    cBitArray start((SQUARE_NAMES) square);

    for(int i = 0; i < 2; i++)
        attack_board |= start.rotate(black_pawn_attacks[i]);
}

void cMoveGenerator::generate_knight_attack_squares(int square)
{
}

void cMoveGenerator::generate_bishop_attack_squares(int square)
{
}

void cMoveGenerator::generate_rook_attack_squares(int square)
{
}

void cMoveGenerator::generate_queen_attack_squares(int square)
{
}



void cMoveGenerator::calc_attack_board()
{
    int square;
    int piece;

    attack_board = 0;

    // calc the attacked squares by the opponent for the current board
    for(square = A1; square < NO_SQUARE; square++)
     {
        if(opp_side.getPiece((SQUARE_NAMES)square) != 0 )
         {
            piece = this_position->getPiece((SQUARE_NAMES)square);
                        switch(piece)
             {
                 case WHITE_KING:
                 case BLACK_KING:
                    generate_king_attack_squares(square);
                    break;

                 case WHITE_PAWN:    
                    generate_white_pawn_attack_squares(square);
                    break;
                 case BLACK_PAWN:
                    generate_black_pawn_attack_squares(square);
                    break;

                 case WHITE_KNIGHT:
                 case BLACK_KNIGHT:
                    generate_knight_attack_squares(square);
                    break;
    
                 case WHITE_BISHOP:
                 case BLACK_BISHOP:
                    generate_bishop_attack_squares(square);
                    break;

                 case WHITE_ROOK:
                 case BLACK_ROOK:
                    generate_rook_attack_squares(square);
                    break;

                 case WHITE_QUEEN:
                 case BLACK_QUEEN:
                    generate_queen_attack_squares(square);
                    break;
              }
         }
     }

}
void cMoveGenerator::make(cBoard& position)
{
    // empty the current move list
    move_list.clear();

    // save a pointer to the current posisition
    this_position = &position;

    // set up bit array copys of the sid to move and the opponents side
    if(position.toMove() == WHITE)
      {
        this_side = position.white_pieces;
        opp_side  = position.black_pieces;
      }
    else
      {
        this_side = position.black_pieces;
        opp_side  = position.white_pieces;
      }
        
    // calc the attack boards
    calc_attack_boards();    

    int square;
    int piece;
    // for each square on the board generate a move if a piece sits on it
    for(square = A1; square < NO_SQUARE; square++)
      {
        if(this_side.getPiece((SQUARE_NAMES)square) != 0 )
         {
            piece = position.getPiece((SQUARE_NAMES)square);
            switch(piece)
             {
                 case WHITE_KING:
                 case BLACK_KING:
                    generate_king_moves(square);
                    break;

                 case WHITE_PAWN:    
                 case BLACK_PAWN:
                    generate_pawn_moves();
                    break;

                 case WHITE_KNIGHT:
                 case BLACK_KNIGHT:
                    generate_knight_moves();
                    break;
    
                 case WHITE_BISHOP:
                 case BLACK_BISHOP:
                    generate_bishop_moves();
                    break;

                 case WHITE_ROOK:
                 case BLACK_ROOK:
                    generate_rook_moves();
                    break;

                 case WHITE_QUEEN:
                 case BLACK_QUEEN:
                    generate_queen_moves();
                    break;
              }
          }
        }
}


void cMoveGenerator::generate_king_moves(int square)
{

    cBitArray from((SQUARE_NAMES)square);
    cBitArray to;
    for(int i = 0; i < 8; i++)
     {
        to = from.rotate(king_moves[i]);
        // if the the proposed square is empty and not attacked 
        if((to & this_position->current_board) == 0 && (to & attack_board) == 0)
         {
            cMove nm(to,from,this_position->to_move,NO_PIECE,0);
            move_list.push_back(nm);
         }

        else if((to & opp_side) != 0)
         {
            int p = this_position->getPiece((SQUARE_NAMES)square);
            cMove nm(to,from,this_position->to_move,(PIECE_NAMES)p,0);
            move_list.push_back(nm);
         }
     }
}

void cMoveGenerator::generate_pawn_moves()
{
}

void cMoveGenerator::generate_knight_moves()
{
}

void cMoveGenerator::generate_bishop_moves()
{
}

void cMoveGenerator::generate_rook_moves()
{
}

void cMoveGenerator::generate_queen_moves()
{
}