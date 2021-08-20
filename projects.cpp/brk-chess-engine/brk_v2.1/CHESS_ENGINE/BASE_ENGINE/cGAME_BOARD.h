//*******************************************************************
//              
//  FILE:       cGAME_BOARD.h
//              
//  AUTHOR:     Keith R. Bergerstock
//              
//  PROJECT:    BASE_ENGINE
//              
//  COMPONENT:  -
//              
//  DATE:       19.12.2003
//              
//  COMMENTS:   -
//              
//              
//*******************************************************************


// Includes

#include <vector>
#include <iostream>
using namespace std;

#include "cBOARD.h"
#include "cGAME_MOVE.h"
#include "cFEN.h"

#ifndef __cGAME_BOARD_H
#define __cGAME_BOARD_H

enum
{
    MAX_PLYS  = 400,
};

class cGAME_BOARD : public cBoard
{
    private:
        // result of game
        int         game_result;        

        // game list is implemented as a vector
        typedef vector<cGAME_MOVE>      GAME_LIST;
        typedef GAME_LIST::iterator     GAME_ITOR;

        // create the base list
        GAME_LIST game_list;

        int make_move(SQUARE_NAMES start,SQUARE_NAMES end);
        int set_piece(RANK_NAMES r,FILE_NAMES f,char pn);

    public: 
        cGAME_BOARD();
        ~cGAME_BOARD();

        int new_game();
        int set_board(cFEN& fen);
        int add_move(cGAME_MOVE&);
        int take_back();

        void display_history(ostream&);


};

#endif