#pragma warning(disable:4786)
//*******************************************************************
//              
//  FILE:       cCMD_LIST.h
//              
//  AUTHOR:     Keith R. Bergerstock
//              
//  PROJECT:    BASE_INTERFACE
//              
//  COMPONENT:  cCMD_LIST
//              
//  DATE:       10.10.2003
//              
//  COMMENTS:   map of the winboard enumerated commands to strings
//              
//              
//*******************************************************************


// Includes


#ifndef __cCMD_LIST_h
#define __cCMD_LIST_h

#include <string>
#include <map>
    
using namespace std;

enum
{
    NO_CMD = 0,

    // winboard | xboard commands
    xBOARD = 100,
    xPROTOVER,
    xACCEPTED,
    xREJECTED,
    xNEW, 
    xVARIANT,
    xQUIT,
    xRANDOM,
    xFORCE,
    xGO,
    xPLAYOTHER,
    xWHITE,
    xBLACK,
    xLEVEL,
    xST,
    xSD,
    xTIME,
    xOTIM,
    xMOVE,
    xUSERMOVE,
    xPING,
    xDRAW,
    xRESULT,
    xSETBOARD,
    xHINT,
    xBK,
    xUNDO,
    xREMOVE,
    xHARD,
    xEASY,
    xPOST,
    xNOPOST,
    xANALYZE,
    xNAME,
    xRATING,
    xICS,
    xCOMPUTER,
    xPAUSE,
    xRESUME,

    // user commands
    HELP,
    DISPLAY,
    ON,
    OFF,

    VERSION,
    LIST,
    TAKE_BACK,
};


class cCMD_LIST
{
  
    private:
        // word list is implemented as a map
        typedef map<string,int> CMD_LIST;   
        typedef CMD_LIST::value_type CMD_TYPE;
        typedef CMD_LIST::iterator   CMD_ITOR;
    
        // the list of commands
        CMD_LIST cmd_list;

        void insert(char* s,int cmd);

    protected:

    public:
        cCMD_LIST();
        ~cCMD_LIST();
        
         int search(string&);
     
};

#endif

