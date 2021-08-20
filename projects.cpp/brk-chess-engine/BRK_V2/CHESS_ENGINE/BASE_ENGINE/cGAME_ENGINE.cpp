#pragma warning(disable:4786)

//*******************************************************************
//              
//  FILE:       cGAME_ENGINE.cpp
//              
//  AUTHOR:     Keith R. Bergerstock
//              
//  PROJECT:    CHESS_ENGINE
//              
//  COMPONENT:  - base engine
//              
//  DATE:       07.11.2003
//              
//  COMMENTS:   - primary interface to engine functions
//              
//              
//*******************************************************************


// Includes
#include "cGAME_ENGINE.h"
#include <iostream>
using namespace std;

cGAME_ENGINE::cGAME_ENGINE()
{
}

cGAME_ENGINE::~cGAME_ENGINE()
{
}

int cGAME_ENGINE::add_move(cGAME_MOVE& m)
{
    // fix verify legality of move

    // add the move to the list
    game.add_move(m);

    return 0;
}

int cGAME_ENGINE::take_back()
{
    game.take_back();

    return 0;
}

int cGAME_ENGINE::new_game()
{
    game.new_game();
    return 0;
}

void cGAME_ENGINE::display_history(ostream& out)
{
    game.display_history(out);
}

#if 0
void cGAME_ENGINE::display_board(ostream& out)
{
    RANK_NAMES ranks[MAX_RANK] = { RANK_8, RANK_7, RANK_6, RANK_5, RANK_4, RANK_3, RANK_2, RANK_1 };
    FILE_NAMES files[MAX_FILE] = { FILE_A, FILE_B, FILE_C, FILE_D, FILE_E, FILE_F, FILE_G, FILE_H };

    int rank,file;

    out << "  a b c d e f g h  " << endl;

    for(rank = 0; rank < MAX_RANK; rank++)
       { 
        int rn = ranks[rank]+1;
         cout << rn <<  " " ;   
         for(file = FILE_A; file < MAX_FILE; file++)
           {
             char p = '.';
             switch(game.getPiece(ranks[rank],files[file]) )
              {
                case  WHITE_PAWN:     p = 'p';break;
                case  WHITE_KNIGHT:   p = 'n';break;
                case  WHITE_BISHOP:   p = 'b';break;
                case  WHITE_ROOK:     p = 'r';break;
                case  WHITE_QUEEN:    p = 'q';break;
                case  WHITE_KING:     p = 'k';break;

                case  BLACK_PAWN:     p = 'P';break;
                case  BLACK_KNIGHT:   p = 'N';break;
                case  BLACK_BISHOP:   p = 'B';break;
                case  BLACK_ROOK:     p = 'R';break;
                case  BLACK_QUEEN:    p = 'Q';break;
                case  BLACK_KING:     p = 'K';break;
              }

            out << p << " " ;
           }
               
         out << " " << endl;
        }   
}
#else
void cGAME_ENGINE::display_board(ostream& out)
{
    RANK_NAMES ranks[MAX_RANK] = { RANK_8, RANK_7, RANK_6, RANK_5, RANK_4, RANK_3, RANK_2, RANK_1 };
    FILE_NAMES files[MAX_FILE] = { FILE_A, FILE_B, FILE_C, FILE_D, FILE_E, FILE_F, FILE_G, FILE_H };

    char* sep = " +---+---+---+---+---+---+---+---+";

    int rank,file;

    out << "  a   b   c   d   e   f   g   h  " << endl;
    out << sep << endl;

    for(rank = 0; rank < MAX_RANK; rank++)
       { 
         int rn = ranks[rank]+1;
         cout << rn <<  "|" ;   
         for(file = FILE_A; file < MAX_FILE; file++)
           {
             char *p = "   |";
             switch(game.getPiece(ranks[rank],files[file]) )
              {
                case  WHITE_PAWN:     p = " P |";break;
                case  WHITE_KNIGHT:   p = " N |";break;
                case  WHITE_BISHOP:   p = " B |";break;
                case  WHITE_ROOK:     p = " R |";break;
                case  WHITE_QUEEN:    p = " Q |";break;
                case  WHITE_KING:     p = " K |";break;

                case  BLACK_PAWN:     p = " *P|";break;
                case  BLACK_KNIGHT:   p = " *N|";break;
                case  BLACK_BISHOP:   p = " *B|";break;
                case  BLACK_ROOK:     p = " *R|";break;
                case  BLACK_QUEEN:    p = " *Q|";break;
                case  BLACK_KING:     p = " *K|";break;

              }
            out << p;
           }
         out << endl << sep << endl;
        }   
}
#endif

void cGAME_ENGINE::set_board(cFEN& fen)
{
    // set up the game bppard to the fen
    game.set_board(fen);
}