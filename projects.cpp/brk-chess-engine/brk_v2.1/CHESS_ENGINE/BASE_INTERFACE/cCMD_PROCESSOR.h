#pragma warning(disable:4786)
//*******************************************************************
//              
//  FILE:       cCMD_PROCESSOR.h
//              
//  AUTHOR:     Keith R. Bergerstock
//              
//  PROJECT:    BASE_INTERFACE
//              
//  COMPONENT:  cCMD_PROCESSOR
//              
//  DATE:       10.10.2003
//              
//  COMMENTS:   -
//              
//              
//*******************************************************************


// Includes


#include <deque>
#include <string>
using namespace std;

#include "cCMD_LIST.h"
#include "cGAME_ENGINE.h"

#ifndef __cCMD_PROCESSOR_H
#define __cCMD_PROCESSOR_H

class cCMD_PROCESSOR
{
    private:
        int uci_mode_requested;

        cCMD_LIST       cmd_list;       // the command list
        cGAME_ENGINE&   engine;         // the engine interface object
                
        deque<string> cmd_seq;          // a list of the commands from the parsed input   

        int get(string&);               // the routine to fetch a command
        int dispatch(string&);          // the command dispatch center
        // subroutines to handle specfic commands
        void display_history();         // display the move list    
        void display_board();           // display the current board
        void display_help();            // display help list
        void new_game();                // start a new game
        void setboard();                // routine to handle the set board command
        void uci();                     // routine to handle uci start up command
        void uci_position();            // routnine to hande uci position command    
        void uci_position(string&);     // routine to handle uci position parsed commands 
        void uci_add_moves();           // rotine to handle the moves sub-command
        void display_uci_options();     // routine to output the settable uci options
        void go();                      // routine to handle go command
       
    public:
        cCMD_PROCESSOR(cGAME_ENGINE&);
       ~cCMD_PROCESSOR();

        void display_version();         // display the current version
        
        int process();                  // the cmd processing loop

        void push(string& iCmd)         // place a command into the queue
          { 
            cmd_seq.push_back(iCmd); 
          } 

        void clear()                    // clear the command queue
          {
            cmd_seq.clear();
          }
};
#endif

