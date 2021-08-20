#pragma warning(disable:4786)

//*******************************************************************
//              
//  FILE:       cGAME_ENGINE.h
//              
//  AUTHOR:     Keith R. Bergerstock
//              
//  PROJECT:    CHESS_ENGINE
//              
//  COMPONENT:  - 
//              
//  DATE:       07.11.2003
//              
//  COMMENTS:   - primary interface to the engine functions
//              
//              
//*******************************************************************

// Includes

#include "cGAME_BOARD.h"
#include "cFEN.h"

#ifndef __cGAME_ENGINE_H
#define __cGAME_ENGINE_H

class cGAME_ENGINE
{
    private:
        // contains a list of the moves
        cGAME_BOARD  game;

    public:
        cGAME_ENGINE();

        ~cGAME_ENGINE();

        int add_move(cGAME_MOVE&);
        int take_back();
        int new_game();

        // displays the move hoistory of the current game
        void display_history(ostream& out);

        // displays the current board
        void display_board(ostream& out);

        // set a board up from a decoded fen diagram
        void set_board(cFEN&);
};    

#endif
