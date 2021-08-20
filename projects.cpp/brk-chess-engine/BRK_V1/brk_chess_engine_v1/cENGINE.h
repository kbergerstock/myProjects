// maine engine/application class


#include <time.h>
#include "cGame.h"
#include "cTree.h"
#include "cThread.h"
#include "cInterface.h"
#include "cSquares.h"

#ifndef __cENGINE_H
#define __cENGINE_H

enum ENGINE_STATES
{
    PONDER = 100,                   // default state where it is analyzing current position
    ACCEPT_MOVE,                    // signal state to accept user move
    MAKE_MOVE,                      // when board t0_move == engine color calc and output a move
    FORCE_MOVE,                     // signal state to cut pndering short
    TAKE_BACK,                      // signal state to allow a move to be taken back ie removed from list
    WAIT_UI,                        // signal state wait for user input to start
                
    PLAY_MODE = 1,                  // engine modes of operation
    PONDER_MODE,
    VERIFY_MODE = 0,
};

class cENGINE : public cThread
{
    private:
        void runThread();
        int  makeCompMove();
    
        cOUTPUT&    out;            // reference to the output class
        cSquares    squares;        // square name list
        cGAME       game;           // the game list
        cTree       game_tree;      // the game tree

        // engine controls
        tEVENT          signal;     // used to control engine signal event
        tEVENT          done;       // used to signal external control that event processing is complete
        int             color;      // when board color to_move == engine color have engine make a move
        int             ply;        // current ply that game is at    
        int             mode;       // play mode vs verify / ponder mode
        ENGINE_STATES   state;      // state that engine is in

        clock_t     start;
        clock_t     elapsed;
        double      duration;
        double      count0;
        double      count;
        
        int i;  

    public:
        cENGINE( cOUTPUT& _out);
        ~cENGINE();

        // make a move on the current board - returns 0 if vaild move otherewise an error code
        int makeMove(string& ms);
        void dumpBoard() { out.dumpBoard(game.getPosition() ); }
        // commands
        void list()      { game.list(out); }   
        void on()        { mode = PLAY_MODE; done.Reset(); signal.Set();  }
        void off()       { mode = VERIFY_MODE; done.Set(); }
        void ponder()    { mode = PONDER_MODE; }

        bool isSet()     { return signal.isSet(); }
        bool isDone()    { return done.isSet(); }
};

#endif