#pragma warning(disable:4786)

//*******************************************************************
//              
//  FILE:       cGAME_MOVE.cpp
//              
//  AUTHOR:     Keith R. Bergerstock
//              
//  PROJECT:    BASE_ENGINE
//              
//  COMPONENT:  - cGAME_MOVE
//              
//  DATE:       24.10.2003
//              
//  COMMENTS:   -
//              
//              
//*******************************************************************

// Includes
#include "cGAME_MOVE.h"

//*******************************************************************
//              
//  FUNCTION:   - convert
//              
//  RETURNS:    - bool 
//                  0 - illegal move
//                  1 - move found test it            
//              
//  PARAMETERS: -   a string containing the move pair
//                  the list of enumerated strings that match the board a cSQUARES list
//              
//  COMMENTS:   -
//              
//              
//*******************************************************************

int cGAME_MOVE::convert(string& move_str)
{
    // if the string contains a dash parse it as fs-ts else parse it as fsts

    int l = move_str.find('-');
    if(l == move_str.npos)
        l = 2;
    else
        l++;

    // split the input string into pairs
    string m1 = move_str.substr(0,2);
    string m2 = move_str.substr(l,2);

    // convert strings to enumerated square names
    from_square = square_list.search(m1);
    to_square =   square_list.search(m2);

    // if either square is invalid return 0 for failure otherwise return 1 for sucess
    return (from_square == NO_SQUARE || to_square== NO_SQUARE) ? 0 : 1; 
}


const char* cGAME_MOVE::get_move()
{
    static string move_str;

    move_str = square_list.search(from_square);
    move_str += "-";
    move_str += square_list.search(to_square);

    return move_str.c_str();
}