#include <time.h>

// engine worker thread
#include "cEngine.h"

cENGINE::cENGINE(cOUTPUT& _out) : cThread() , out(_out), squares(), game(), game_tree()
{
    i = 0;
    start = clock();
    count = 0;
    game_tree.dumpPly(out,0);
    // defaults for engine
    state = WAIT_UI;
    color = BLACK;
    ply = game.getCurrentPly();
    mode = VERIFY_MODE;
    // set up defaults for signals
    signal.Reset();
    done.Set();
}

cENGINE::~cENGINE()
{
    stopThread();
}

int cENGINE::makeCompMove()
{
    // update game_tree - prune list
    game_tree.pruneTree(game.getPosition() );

    cPosition *p = game_tree.getRootPos();
    if(p->isMated() )
     {
        if(p->toMove() == WHITE)
            out.echo("WHITE IS MATED");
        else
            out.echo("BLACK IS MATED");
     }
    else
     {
        cMove em = game_tree.search();
        game.make_move(em);
        game.outputReply(out);
        out.dumpBoard(game.getPosition() );
      }
    done.Set();
    return 0;
}

void cENGINE::runThread()
{
    // signal event - so figure out what changed and adjust state
    if(signal.isSet() )
      {
        int new_ply = game.getCurrentPly();
        if(new_ply != ply && game.toMove() == color  || mode == VERIFY_MODE)
            {
                state = ACCEPT_MOVE;
                // turn off signal saying event is processed
                signal.Reset();
            }
      }

    switch(state)
     {
        case PONDER:
            break;

        case ACCEPT_MOVE:
            out.dumpBoard(game.getPosition() );
            if(mode == PLAY_MODE)
                state = MAKE_MOVE;
            else        
                state = WAIT_UI;
             break;

        case MAKE_MOVE:
            // routine to have computer make move here
            makeCompMove();
            state = WAIT_UI;    
            break;

        case TAKE_BACK:
            break;

        case WAIT_UI:
            // signal event has been processed
            done.Set();
        default:
            break;
     }  

}

int cENGINE::makeMove(string& ms)
{
    // make sure that the event complete event is off
    done.Reset();

    // split the input string into pairs
    string m1 = ms.substr(0,2);
    string m2 = ms.substr(2,2);
    // convert strings to enumerated square names
    SQUARE_NAMES from_square = squares.search(m1);
    SQUARE_NAMES to_square =   squares.search(m2);

    if(!(from_square == NO_SQUARE || to_square == NO_SQUARE) )
     {
            
            stopThread();           // stop the engine thread
            if( game.make_move(from_square,to_square) == 0)
                {
                    // turn on the signal that tells the engine that an event has occured
                    signal.Set();
                }
             else
                {
                    out.echo("ILEGAL MOVE");
                    done.Set();
                }   
            startThread();
     }
    else
     {
        out.echo("ILEGAL MOVE");
        done.Set();
     }
    return 0;
}
