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
        cCMD_LIST       cmd_list;       // the command list
        cGAME_ENGINE    engine;         // the engine interface object
                
        deque<string> cmd_seq;          // a list of the commands from the parsed input   

        int get(string&);               // the routine to fetch a command
        int dispatch(string&);          // the command dispatch center

        // subroutines to handle specfic commands
        void display_history();         // display the move list    
        void display_board();           // display the current board
        void display_help();            // display help list
        void new_game();                // start a new game
        void setboard();                // routint to handle the set board command
       
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

