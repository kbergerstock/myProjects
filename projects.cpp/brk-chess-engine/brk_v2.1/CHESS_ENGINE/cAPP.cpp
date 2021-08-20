//*******************************************************************
//              
//  FILE:       cAPP.cpp
//              
//  AUTHOR:     Keith R. Bergerstock
//              
//  PROJECT:    CHESS_ENGINE
//              
//  COMPONENT:  cAPP
//              
//  DATE:       10.10.2003
//              
//  COMMENTS:   entry point for the chess engine applicatione
//              
//              
//*******************************************************************

// Pragmas

#pragma warning(disable:4786)

// Includes
#include <windows.h>
#include <iostream>
#include <strstream>
#include <fstream>
using namespace std;

#include "cAPP.h"

#include "chess_engine_version.h"

cAPP::cAPP(int argv,char* argc[]) : cmd_processor(engine)
{
    // display the software version
    cmd_processor.display_version();

    // parse the command line parameters
    process_command_line(argv,argc);

    // execute the application
    run();

}

cAPP::~cAPP()
{
}

void cAPP::process_command_line(int argc, char* argv[])
{
    while(argc--)
     {
        string arg(*argv);
        argv++;
        if(arg[0] == '@')
         {
            // process script file
            process_script(arg);    
         }
        else if(arg[0] == '-')
          {  
            switch(arg[1])
              {
                case 'h':
                case 'H':
                    cout << "command line switchs" << endl;
                    cout << " .. -h help " << endl;
                    cout << " .. @script    == process script file" << endl;
                    break;

                default:
                    break;

              }  
          }  

     }
}

// routine to process an input line containing commands
int cAPP::processLine(string& inputLine)
{
    int r = 0;

    // process script file 
    if(inputLine[0] == '@')
        process_script(inputLine);	
    // ignore comment lines and echo them out
    else if(inputLine[0] == '#' || inputLine[0] == '*')
        cout << inputLine << endl;
    // process command
    else	
     {
        string inputCmd = "";
        int i = 0;    
        char chr_in;
        // parse the line useing spaces as delimiters
        while(i < inputLine.size() )
         {
            chr_in = inputLine[i++];
            if(isspace(chr_in) )
              {
                // add commands to command processor
	            cmd_processor.push(inputCmd);  
                inputCmd = "";
              }
            else
              {
                inputCmd+= chr_in; 
              } 
         }

        // make sure that the last command in a line is processed
        if(inputCmd != "")
            cmd_processor.push(inputCmd);
        
        // process the entered command and return the resultant   
        r = cmd_processor.process();
     } 
    
    return r;
}


// routine to fetch the input to the engine from stdin
int cAPP::fetchCmd(string& the_prompt)
{
    string inputLine;
    // display the prompt
    cout << the_prompt;
    // fetch the user input
    cin >> inputLine;
    // send the user input to the command processor
	return processLine(inputLine);
}

// routine to process a script file 
int cAPP::process_script(string& inputCmd)
{
    if(inputCmd.size() > MIN_FILE_NAME)
     {
	    string fn = inputCmd.substr(1,inputCmd.size() - 1);
	    cout << "processing script file " << fn << endl;
	    fstream script;
        string inputLine;
	    script.open(fn.c_str(), ios_base::in  );
	    if(script.is_open() )
	    {
		    do
		    {
                getline(script,inputLine);
                processLine(inputLine);
		    }while(!script.eof() );

		    script.close();
	    }
	    else
		    cout << " err in opening file " << endl;
       }
	return 0;		
}

// main loop
void cAPP::run()
{
    int r = 0;
    string p(">> ");

    do {
          Sleep(25);
          // fetch and process commands
          r =  fetchCmd(p);
          // until a quit command is recieved
         
        } while(r != xQUIT);

}                         
