#pragma warning(disable:4786)
//*******************************************************************
//              
//  FILE:       cCMD_LIST.cpp
//              
//  AUTHOR:     Keith R. Bergerstock
//              
//  PROJECT:    BASE_INTERFACE
//              
//  COMPONENT:  cCMD_LIST
//              
//  DATE:       10.10.2003
//              
//  COMMENTS:   -
//              
//              
//*******************************************************************

// Includes

#include "cCMD_LIST.h"
#include <algorithm>
using namespace std;

// the xCOMMAND set board and uci command uPOSITION fen
// perform the same operation set up the board from a fen diagram

cCMD_LIST::cCMD_LIST()
{
    // fill in the map of user and xboard commands
    // specific xboard commands
    insert("xboard",xBOARD);
    insert("protover",xPROTOVER);
    insert("accepted",xACCEPTED);
    insert("rejected",xREJECTED);
    insert("new",xNEW);
    insert("variant",xVARIANT);
    insert("random",xRANDOM);
    insert("force",xFORCE);
    insert("playother",xPLAYOTHER);
    insert("white",xWHITE);
    insert("black",xBLACK);
    insert("level",xLEVEL);
    insert("st",xST);
    insert("sd",xSD);
    insert("time",xTIME);
    insert("otim",xOTIM);
    insert("move",xMOVE);    
    insert("usermove",xUSERMOVE);
    insert("ping",xPING);
    insert("draw",xDRAW);
    insert("result",xRESULT);
    insert("setboard",xSETBOARD);
    insert("hint",xHINT);
    insert("bk",xBK);
    insert("undo",xUNDO);
    insert("remove",xREMOVE);
    insert("hard",xHARD);
    insert("easy",xEASY);
    insert("post",xPOST);
    insert("nopost",xNOPOST);
    insert("rating",xRATING);
    insert("name",xNAME);
    insert("analyze",xANALYZE); 
    insert("ics",xICS);
    insert("computer",xCOMPUTER);
    insert("pause",xPAUSE);
    insert("resume",xRESUME);

    // specific uci cmds
    insert("uci",uUCI);
    insert("debug",uDEBUG);
    insert("isready",uISREADY);
    insert("setoption",uSETOPTION);
    insert("register",uREGISTER);
    insert("ucinewgame",uUCINEWGAME);

    insert("position",uPOSITION);
    insert("fen",uFEN);
    insert("startpos",uSTARTPOS);
    insert("moves",uMOVES);

    insert("searchmoves",uGO_SEARCHMOVES);
    insert("ponder",uGO_PONDER);
    insert("wtime",uGO_WTIME);
    insert("btime",uGO_BTIME);
    insert("winc",uGO_WINC);
    insert("binc",uGO_BINC);
    insert("movestogo",uGO_MOVESTOGO);
    insert("depth",uGO_DEPTH);
    insert("nodes",uGO_NODES);
    insert("mate",uGO_MATE);
    insert("move_time",uGO_MOVE_TIME);
    insert("infinite",uGO_INFINITE);
    insert("stop",uSTOP);
    insert("ponderhit",uPONDERHIT);
    insert("quit",uQUIT);

    insert("go",GO);

    insert("bye",xQUIT);
    insert("quit",xQUIT);
    insert("end",xQUIT);
    insert("exit",xQUIT);

    insert("help",HELP);
    
    insert("display",DISPLAY);
    insert("d",DISPLAY);
    insert("on",ON);
    insert("off",OFF);

    insert("version",VERSION);
    insert("list",LIST);
    insert("history",LIST);
    insert("takeback",TAKE_BACK); 
 }

cCMD_LIST::~cCMD_LIST()
{
    // empty the list
    cmd_list.clear();
}

void cCMD_LIST::insert(char* s,int cmd)
{
    char t[100];
    strcpy(t,s);
    strupr(t);

    string z(s); 
    string x(t);

   // add the orignial command
   cmd_list.insert(CMD_TYPE(z,cmd) );
   // add the upper case version of the command
   cmd_list.insert(CMD_TYPE(x,cmd) );
}

int cCMD_LIST::search(string& cmd)
{
    int r = NO_CMD;
    CMD_ITOR it = cmd_list.find(cmd.c_str() );
    if (it != cmd_list.end() )
        r = it->second;

    return r;
}

