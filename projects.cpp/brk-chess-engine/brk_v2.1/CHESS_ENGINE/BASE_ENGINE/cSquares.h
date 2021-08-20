//*******************************************************************
//              
//  FILE:       cSquares.h
//              
//  AUTHOR:     Keith R. Bergerstock
//              
//  PROJECT:    CHESS_ENGINE
//              
//  COMPONENT:  cSquares
//              
//  DATE:       24.10.2003
//              
//  COMMENTS:   - this class converts the string values for a square to a numerical values 
//                that can be used to set a piece into a bit board
//              
//              
//*******************************************************************

// Pragmas

#pragma warning(disable:4786)

// Includes

#include <string>
#include <map>
#include <vector>
using namespace std;

#include "board_constants.h"

#ifndef __cSQUARES_H
#define __cSQUARES_H

class cSQUARES
{
    private:
        // square list is implemented as a map - map string to integer names
        typedef map<string,SQUARE_NAMES>    SQUARE_LIST;
        typedef SQUARE_LIST::value_type     SQUARE_TYPE;
        typedef SQUARE_LIST::iterator       SQUARE_ITOR;

        typedef vector<string>              NAME_LIST;

        SQUARE_LIST     square_list;
        NAME_LIST       name_list;

        void insert(char* sz, SQUARE_NAMES sq );

        void toLower( SQUARE_ITOR t);

    public:  
        cSQUARES();
        ~cSQUARES();

        SQUARE_NAMES search(string&);
        string& search(SQUARE_NAMES);
};

extern cSQUARES square_list;

#endif


