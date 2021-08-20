//*******************************************************************
//              
//  FILE:       cPGN.h
//              
//  AUTHOR:     Keith R. Bergerstock
//              
//  PROJECT:    CHESS_ENGINE
//              
//  COMPONENT:  -
//              
//  DATE:       03.11.2003
//              
//  COMMENTS:   - pgn component
//              
//              
//*******************************************************************



// Includes
#include "bSTRING.h"

#ifndef __cPGN_H
#define __cPGN_H

class cPGN
{
    private:
        bSTRING event;
        bSTRING white;
        bSTRING black;
        bSTRING eco;
        bSTRING date;

    public:

        cPGN();
       ~cPGN();
       
        int read(bSTRING);
        int write(); 
};

#endif
