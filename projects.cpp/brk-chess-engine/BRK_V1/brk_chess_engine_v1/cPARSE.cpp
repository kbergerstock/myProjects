#include "cPARSE.h"

#include <algorithm>

using namespace std;


#pragma warning(disable:4786)


void cPARSE::toUpper( CMD_ITOR t)
{
    char buf[100];
    strcpy( buf,t->first.c_str() );
    int cmd = t->second;
    // convert comd string to upper case
    strupr(buf);
    cmd_list.insert(CMD_TYPE(string(buf),cmd) );

}


cPARSE::cPARSE()
{
    // fill in the map of user and xboard commands
    insert("bye",BYE);
    insert("quit",BYE);
    insert("end",BYE);
    insert("exit",BYE);

    insert("help",HELP);
    insert("new",NEW);
    insert("draw",DRAW);
    insert("result",RESULT);
    insert("display",DISPLAY);
    insert("d",DISPLAY);
    insert("on",ON);
    insert("off",OFF);
    insert("hard",HARD);
    insert("easy",EASY);
    insert("version",VERSION);
    insert("list",LIST);
    

    // specific xboard commands
    insert("xboard",XBOARD);
    insert("force",xFORCE);
    insert("white",xWHITE);
    insert("black",xBLACK);
    insert("sl",xSL);
    insert("sd",xSD);
    insert("time",xTIME);
    insert("otim",xOTIM);
    insert("go",xGO);
    insert("hint",xHINT);
    insert("undo",xUNDO);
    insert("remove",xREMOVE);
    insert("post",xPOST);
    insert("nopost",xNOPOST);
    insert("protover",xPROTOVER);
    insert("playother",xPLAYOTHER);
    insert("usermove",xUSERMOVE);
    insert("ping",xPING);
    insert("rating",xRATING);
    insert("analyze",xANALYZE);
    
    CMD_ITOR start = cmd_list.begin();
    CMD_ITOR end = cmd_list.end();
    for(; start != end; start++)
        toUpper(start);
        

}

cPARSE::~cPARSE()
{
    // empty the list
    cmd_list.clear();
}

int cPARSE::search(string& cmd)
{
    int r = 0;
    CMD_ITOR it = cmd_list.find(cmd.c_str() );
    if (it != cmd_list.end() )
        r = it->second;

    return r;
}