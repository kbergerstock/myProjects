#include "cSquares.h"

#pragma warning(disable:4786)

cSquares::cSquares()
{
    // fill the list
    insert("A8",A8);    
    insert("B8",B8);
    insert("C8",C8);
    insert("D8",D8);
    insert("E8",E8);    
    insert("F8",F8);
    insert("G8",G8);
    insert("H8",H8);

    insert("A7",A7);    
    insert("B7",B7);
    insert("C7",C7);
    insert("D7",D7);
    insert("E7",E7);    
    insert("F7",F7);
    insert("G7",G7);
    insert("H7",H7);

    insert("A6",A6);    
    insert("B6",B6);
    insert("C6",C6);
    insert("D6",D6);
    insert("E6",E6);    
    insert("F6",F6);
    insert("G6",G6);
    insert("H6",H6);

    insert("A5",A5);    
    insert("B5",B5);
    insert("C5",C5);
    insert("D5",D5);
    insert("E5",E5);    
    insert("F5",F5);
    insert("G5",G5);
    insert("H5",H5);

    insert("A4",A4);    
    insert("B4",B4);
    insert("C4",C4);
    insert("D4",D4);
    insert("E4",E4);    
    insert("F4",F4);
    insert("G4",G4);
    insert("H4",H4);

    insert("A3",A3);    
    insert("B3",B3);
    insert("C3",C3);
    insert("D3",D3);
    insert("E3",E3);    
    insert("F3",F3);
    insert("G3",G3);
    insert("H3",H3);

    insert("A2",A2);    
    insert("B2",B2);
    insert("C2",C2);
    insert("D2",D2);
    insert("E2",E2);    
    insert("F2",F2);
    insert("G2",G2);
    insert("H2",H2);

    insert("A1",A1);    
    insert("B1",B1);
    insert("C1",C1);
    insert("D1",D1);
    insert("E1",E1);    
    insert("F1",F1);
    insert("G1",G1);
    insert("H1",H1);   
 
    SQUARE_ITOR start = square_list.begin();
    SQUARE_ITOR end = square_list.end();
    for(; start != end; start++)
        toLower(start);
}

cSquares::~cSquares()
{
    // empty the list
    square_list.clear();
}

SQUARE_NAMES cSquares::search(string& square)
{
    SQUARE_NAMES r = NO_SQUARE;
    SQUARE_ITOR it = square_list.find(square.c_str() );
    if (it != square_list.end() )
        r = it->second;

    return r;
}

void cSquares::toLower( SQUARE_ITOR t)
{
    char buf[10];
    strcpy( buf,t->first.c_str() );
    SQUARE_NAMES square = t->second;
    // convert comd string to upper case
    strlwr(buf);
    square_list.insert(SQUARE_TYPE(string(buf),square) );

}