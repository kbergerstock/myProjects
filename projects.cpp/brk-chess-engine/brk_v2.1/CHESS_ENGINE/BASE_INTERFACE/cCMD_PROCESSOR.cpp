#pragma warning(disable:4786)
//*******************************************************************
//              
//  FILE:       cCMD_PROCESSOR.cpp
//              
//  AUTHOR:     Keith R. Bergerstock
//              
//  PROJECT:    BASE_INTERFACE
//              
//  COMPONENT:  -
//              
//  DATE:       10.10.2003
//              
//  COMMENTS:   - class to process winboard, xboard and ui chess engine commands
//              
//              
//*******************************************************************

// Includes
#include "..\\chess_engine_version.h"
#include "cCMD_PROCESSOR.H"
#include "cGAME_MOVE.h"
#include "cFEN.h"
#include <iostream>
using namespace std;

#define DEBUG_RESPONSE 1

cCMD_PROCESSOR::cCMD_PROCESSOR(cGAME_ENGINE& _engine) : engine(_engine)
{
    uci_mode_requested = 0;
}


cCMD_PROCESSOR::~cCMD_PROCESSOR()
{
}


// the command dispatch center
int cCMD_PROCESSOR::dispatch(string& cmd)
{
    cGAME_MOVE m;
    // convert string to command
    int icmd = cmd_list.search(cmd);
    switch(icmd)
     {
        case NO_CMD:	 
            // if the commmand is not regonized - try to parse it into a move
            if(cmd.size() > MIN_MOVE_SIZE && m.convert(cmd) )
                engine.add_move(m);         // legitmate move pair send to engine for processing
            else
                cout << "cmd not reconized  ->  " << cmd << endl;
            break;

        case uUCI:
            uci();
            break;

        case TAKE_BACK:
            engine.take_back();
            break;

        case xSETBOARD:
            setboard();           
            break;

        case uPOSITION:
            uci_position();
            break;

        case GO:
            go();
            break;

        case xQUIT:
            cmd_seq.clear();
            #if DEBUG_RESPONSE == 1
            cout << "user exit initiated" << endl;
            #endif
            break;

        case LIST:      
            display_history();  
            break;

        case VERSION:   
            display_version();  
            break;

        case DISPLAY:   
            display_board();    
            break;

        case HELP:      
            display_help();     
            break;

        case xNEW:    
            new_game();         
            break;

        default:
            cout << cmd << endl;
            break;
            
      }
    return icmd;    
}

// fetch the first command from the list
// the return val should be the size of the list
int cCMD_PROCESSOR::get(string&  cmd)
{
    cmd = cmd_seq[0];
    cmd_seq.pop_front();
    // if the fist char is a comment then dump the whole input and return 0
    if(cmd[0] == '*' || cmd[0] == '#')
     {
        cmd = "";
        cmd_seq.clear();
     }
    return cmd_seq.size();
}

// the command processing loop
int cCMD_PROCESSOR::process()
{
    string cmd;
    int r = NO_CMD;

    while(cmd_seq.size() )
     {
        get(cmd);
        r = dispatch(cmd);
     }

    return r;
}

void cCMD_PROCESSOR::uci()
{
    uci_mode_requested = 1;
    display_version();
}

void cCMD_PROCESSOR::uci_position()
{
    string scmd;
    while(cmd_seq.size() )
     {
        get(scmd); 
        uci_position(scmd);       
     }
}

void cCMD_PROCESSOR::uci_position(string& scmd)
{
    // convert string to command
    // fix need and oder here so that moves are on;y added to a valid position
    int icmd = cmd_list.search(scmd);
    switch(icmd)
     {
        case uMOVES:
            uci_add_moves();
            break;

        case uFEN:
            setboard();
            break;
        
        default:
        case uSTARTPOS:
            new_game();
            break;

     }
}


void cCMD_PROCESSOR::uci_add_moves()
{
    string scmd;
    cGAME_MOVE m;
    while(cmd_seq.size() )
     {
        get(scmd); 
        if(scmd.size() > MIN_MOVE_SIZE && m.convert(scmd) )
          {
                engine.add_move(m);         // legitmate move pair send to engine for processing
           }
     }	
}

void cCMD_PROCESSOR::go()
{
	if(uci_mode_requested)
     {
        cout << "UCI-GO" << endl;
        engine.uGo();
     }
    else
     {
        // fix add x-go command here
     }
}


void cCMD_PROCESSOR::display_history()
{
    engine.display_history(cout);
}

void cCMD_PROCESSOR::display_board()
{
    engine.display_board(cout);
}

void cCMD_PROCESSOR::display_help()
{
    #if DEBUG_RESPONSE == 1
    cout << "help reached " << endl;
    #endif
}

void cCMD_PROCESSOR::new_game()
{
    #if DEBUG_RESPONSE == 1
    cout << "new game started" << endl;
    #endif
    engine.new_game();
}

void cCMD_PROCESSOR::display_version()
{
    if(uci_mode_requested)
     {
        cout << " id name " << ce_title << " " <<  ce_version << endl;
        cout << " id author " << ce_author << endl;
        display_uci_options();
        cout << " uciok " << endl;
     }
    else
     {
        cout << ce_title << endl;
        cout << ce_author << endl;
        cout << ce_version << " Build Date " << __DATE__ << endl;
     }
}

void cCMD_PROCESSOR::display_uci_options()
{
	// 
}


void cCMD_PROCESSOR::setboard()
{
    #if DEBUG_RESPONSE == 1
    cout << "setBoard reached : processing FEN"  << endl;
    #endif

    cFEN fen;
    int ndx = FEN_1;
    string fld;

    // fill  in a fen descriptor class
    while(cmd_seq.size() )
     {
        get(fld);
        fen[(FEN_FLDS)ndx] = fld;
        ndx++;
     }

    
    #if DEBUG_RESPONSE == 1
    // dump the fen class
    for(int i = FEN_1; i < MAX_FEN; i++)
        cout << i << " : " << fen[(FEN_FLDS)i] << endl;
    cout << " diagram : " << fen.diagram() << endl;
    #endif

    // set up the board based on the fen diagram
    engine.set_board(fen);
}