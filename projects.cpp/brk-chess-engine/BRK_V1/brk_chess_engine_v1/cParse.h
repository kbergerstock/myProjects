// parser for input commands

#pragma warning(disable:4786)

#ifndef __cPARSE_H
#define __cPARSE_H

#include <string>
#include <map>
    
using namespace std;

enum
{
    // user commands
    BYE = 100,
    HELP,
    NEW,
    DRAW,
    RESULT,
    UNDO,
    DISPLAY,
    BENCH,
    XBOARD,
    ON,
    OFF,
    MOVE,
    HARD,
    EASY,
    VERSION,
    LIST,

    // xboard commands
    xFORCE  = 200,
    xWHITE,
    xBLACK,
    xSL,
    xSD,
    xTIME,
    xOTIM,
    xGO,
    xHINT,
    xUNDO,
    xREMOVE,
    xPOST,
    xNOPOST,
    xPROTOVER,
    xPLAYOTHER,
    xUSERMOVE,
    xPING,
    xRATING,
    xANALYZE,
};


class cPARSE
{
  
    private:
        // word list is implemented as a map
        typedef map<string,int> CMD_LIST;   
        typedef CMD_LIST::value_type CMD_TYPE;
        typedef CMD_LIST::iterator   CMD_ITOR;
    
        // the list of commands
        CMD_LIST cmd_list;


        void toUpper( CMD_ITOR );
        void insert(char* s,int cmd)
            {
               cmd_list.insert(CMD_TYPE(string(s),cmd) );
            }

    protected:

    public:
        cPARSE();
        ~cPARSE();
        
         int search(string&);
     
};

#endif