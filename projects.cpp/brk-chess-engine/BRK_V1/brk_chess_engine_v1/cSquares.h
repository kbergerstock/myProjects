// this class converts the string values for a square to a numerica values that can be used to 
// set a piece into a bit board

#pragma warning(disable:4786)

#include <string>
#include <map>
using namespace std;

#include "cBitArray.h"

#ifndef __cSquares_h
#define __cSquares_h

class cSquares
{
    private:
        // game list is implemented as a map
        typedef map<string,SQUARE_NAMES> SQUARE_LIST;
        typedef SQUARE_LIST::value_type SQUARE_TYPE;
        typedef SQUARE_LIST::iterator   SQUARE_ITOR;

        SQUARE_LIST square_list;

        void insert(char* sz, SQUARE_NAMES sq )
            {
               square_list.insert(SQUARE_TYPE( string(sz), sq) );
            }

        void toLower( SQUARE_ITOR t);

    public:  
        cSquares();
        ~cSquares();

        SQUARE_NAMES search(string&);
  
};

#endif


