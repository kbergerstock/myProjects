// human interface to chess engine

#pragma warning(disable:4786)

#include <iostream>
#include <strstream>
#include <deque>
#include <string>
using namespace std;

#include "criticalSection.h"
#include "cBoard.h"

#ifndef __cInterface_h
#define __cInterface_h

class cOUTPUT 
{
    private:
        criticalSection cs;
        int xboard_on;
    public:
        void eol();
        void echo(string & s);
        void echo(const char *s);
        void echo(strstream& os);
        void prompt(string & s);
        void prompt(const char *s);
        void dumpBoard(cBoard& board);
        

        void setXboard()    { xboard_on = true; }
        void clearXboard()  { xboard_on = false; }
};


class cInterface : public cOUTPUT
{
    private:
        // a list of the commands from the parsed input
        deque<string> cmd_seq;

    protected:
        string inputCmd;
        string the_prompt;

    public:
        cInterface();
        
        ~cInterface();

        void fetchCmd();

        int get(string &);
        void error(string& s);
        void setNormalPrompt()  {  clearXboard(); the_prompt = "BRK_V1>"; }
        void setXboardPrompt()  {  setXboard(); the_prompt = ""; }
        
};
#endif
