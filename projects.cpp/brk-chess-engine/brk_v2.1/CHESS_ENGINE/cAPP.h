#pragma warning(disable:4786)	

//*******************************************************************
//              
//  FILE:       cAPP.h
//              
//  AUTHOR:     Keith R. Bergerstock
//              
//  PROJECT:    CHESS_ENGINE
//              
//  COMPONENT:  cAPP
//              
//  DATE:       10.10.2003
//              
//  COMMENTS:   main application file for the chess engine project
//              
//              
//*******************************************************************

// Includes

#include <string>
using namespace std;

#include "cCMD_PROCESSOR.H"
#include "cGAME_ENGINE.h"

#ifndef __cAPP_H
#define __cAPP_H

const int  MIN_FILE_NAME = 5;

class cAPP
{
    private:
        cGAME_ENGINE    engine;             // the engine interface object
        cCMD_PROCESSOR  cmd_processor;      // the command processor object

        int  processLine(string&);
        int  fetchCmd(string&);             // routine to fetch the routine from stdin
		int  process_script(string&);		// set up and process a script command

        
        void process_command_line(int argc, char* argv[]);

        void run();                         // main loop

    public:
        cAPP(int argc,char* argv[] ); 
        ~cAPP();
       
};

#endif

