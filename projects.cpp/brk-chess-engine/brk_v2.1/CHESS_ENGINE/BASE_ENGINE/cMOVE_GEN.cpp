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

#include <iostream>
using namespace std;

cMoveGenerator::cMoveGenerator() : move_iter(0)
{
    cout << " move generator constructed" << endl;
    // size move list to 100 possible moves per posisition;
    move_list.size(100);    
}

cMoveGenerator::~cMoveGenerator()
{
}

cBitArray cMoveGenerator::create_attack_board(cBoard& position)
{
    // for the attack board for the oppsite color to move
    cBitArray& t = (position.toMove() == WHITE) ? position.black_pieces : position.white_pieces;
    cBitArray  b = 0;

    int piece = NO_PIECE;
    // for each square on the board generate a 
    for( int square = A1; square < NO_SQUARE; square++)
      {
        if(t.getPiece((SQUARE_NAMES)square) != 0 )
         {
            piece = position.getPiece((SQUARE_NAMES)square);
            switch(piece)
             {
                 case WHITE_KING:
                 case BLACK_KING:
                    b |= kingAttackSquares[square];
                    break;

                 case WHITE_PAWN:    
                 case BLACK_PAWN:
                    break;

                 case WHITE_KNIGHT:
                 case BLACK_KNIGHT:
                    break;
    
                 case WHITE_BISHOP:
                 case BLACK_BISHOP:
                    break;

                 case WHITE_ROOK:
                 case BLACK_ROOK:
                    break;

                 case WHITE_QUEEN:
                 case BLACK_QUEEN:
                    break;

                default:
                    break;
              }
          }
       }  // end of for each square

    return b;
}

int cMoveGenerator::eval_material(cBoard& t)
{
    int white_mat = 0;
    int black_mat = 0;
    int piece = 0;

    // for each square on the board generate a 
    for( int square = A1; square < NO_SQUARE; square++)
      {
        if(t.getPiece((SQUARE_NAMES)square) != 0 )
         {
            piece = t.getPiece((SQUARE_NAMES)square);
            switch(piece)
             {
                 case WHITE_KING:
                    white_mat += KING; 
                    break;

                 case BLACK_KING:
                    black_mat += KING; 
                    break;

                 case WHITE_PAWN: 
                    white_mat += PAWN;
                    // fix trun this if not in endgame
                    // adjust for rank advancement
                    white_mat += (square / 8) * 10;     
                    break;
                       
                 case BLACK_PAWN:
                    black_mat += PAWN;
                    // adjust for rank advancement
                    black_mat += (7 - (square/8) ) * 10;
                    break;

                 case WHITE_KNIGHT:
                    white_mat += KNIGHT;
                    break;

                 case BLACK_KNIGHT:
                    black_mat += KNIGHT;
                    break;
    
                 case WHITE_BISHOP:
                    white_mat += BISHOP;
                    break;

                 case BLACK_BISHOP:
                    black_mat += BISHOP;
                    break;

                 case WHITE_ROOK:
                    white_mat += ROOK;
                    break;

                 case BLACK_ROOK:
                    black_mat += ROOK;
                    break;

                 case WHITE_QUEEN:
                    white_mat += QUEEN;
                    break;

                 case BLACK_QUEEN:
                    black_mat += QUEEN;
                    break;

                default:
                    break;
              }
          }
       } 

    // invert the return value to here - a to move of black means that
    // we are evaluating a position from whites perspective
    return  t.toMove() == WHITE ? black_mat - white_mat : white_mat - black_mat ;
}

int cMoveGenerator::eval(cBoard& t)
{
    // start by evaluationg material
    int e = eval_material(t);
    return e;
}

void cMoveGenerator::make_move_list(cBoard& position)
{
    // empty the current move list
    reset();

    // create the attack board for this posisition
    attack_board = create_attack_board(position);
    
    cBitArray& t = (position.toMove() == WHITE) ? position.white_pieces : position.black_pieces;

    int square;
    int piece;
    
    // for each square on the board generate a 
    for(square = A1; square < NO_SQUARE; square++)
      {
        if(t.getPiece((SQUARE_NAMES)square) != 0 )
         {
            piece = position.getPiece((SQUARE_NAMES)square);
            switch(piece)
             {
                 case WHITE_KING:
                 case BLACK_KING:
                    gen_king_moves(position, square);
                    break;

                 case WHITE_PAWN:    
                 case BLACK_PAWN:
                    break;

                 case WHITE_KNIGHT:
                 case BLACK_KNIGHT:
                    break;
    
                 case WHITE_BISHOP:
                 case BLACK_BISHOP:
                    break;

                 case WHITE_ROOK:
                 case BLACK_ROOK:
                    break;

                 case WHITE_QUEEN:
                 case BLACK_QUEEN:
                    break;
              }
          }
       }  // end of for each square

    // fix add a general purpose routine to dump illegall moves here
}

static int king_moves[8] = {-9,-8,-7,-1,1,7,8,9};

void cMoveGenerator::gen_king_moves(cBoard& position, int square)
{
    int sqto;
    
    cBitArray& t = (position.toMove() == WHITE) ? position.white_pieces : position.black_pieces;
    
    for(int i = 0; i < 8; i++ )
     {
        sqto = square + king_moves[i];
        // if the square is in bounds and empty or has am opposing pice on it \ th emove is valid
        if(sqto >= A1 && sqto < NO_SQUARE && attack_board.isEmpty(SQUARE_NAMES(sqto)) && t.isEmpty((SQUARE_NAMES)sqto) )
         {
            // fix check for illegal moves here ie moves that place king on captured square
            cMove nm( (SQUARE_NAMES)square,(SQUARE_NAMES)sqto, (SIDE_NAMES)position.toMove() );
            // form a temporay position and move the piece on this copy of the board
            // fix replace with take back once its been debugged
            cBoard p = position;
            p.movePiece(nm);                      
            nm.set_eval(eval(p) ); 

            // fix check for illegal / silly  moves here ie moves that place king on captured square
            move_list[move_iter++] = nm;
         }
     }       
}


