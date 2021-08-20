#include "cBitArray.h"
#include <iostream>
using namespace std;

/*
#ifdef __SHIFT__
	void cBitArray::ror(int b)
	{
	
	     bb.ba[0] >>= b;
	     bb.ba[1] >>= b;
	     bb.ba[2] >>= b;
	     bb.ba[3] >>= b;
	     bb.ba[4] >>= b;
	     bb.ba[5] >>= b;
	     bb.ba[6] >>= b;
	     bb.ba[7] >>= b;
	}
	
	void cBitArray::rol(int b)
	{
	     bb.ba[0] <<= b;
	     bb.ba[1] <<= b;
	     bb.ba[2] <<= b;
	     bb.ba[3] <<= b;
	     bb.ba[4] <<= b;
	     bb.ba[5] <<= b;
	     bb.ba[6] <<= b;
	     bb.ba[7] <<= b;
	}
	
	void cBitArray::rup(int b)
	{
	    // fix fill in this function if required
}
#endif //__SHIFT__


cBitArray::cBitArray(bROW _rows[8])     // constuctor from a row array 
{
    for(int i = 0; i < 8; i++)
        bb.ba[i] = _rows[i];   
}

*/

void cBitArray::dump()
{
    RANK_NAMES ranks[MAX_RANK] = { RANK_8, RANK_7, RANK_6, RANK_5, RANK_4, RANK_3, RANK_2, RANK_1 };
    FILE_NAMES files[MAX_FILE] = { FILE_A, FILE_B, FILE_C, FILE_D, FILE_E, FILE_F, FILE_G, FILE_H };

    int rank,file;

    cout << "  a b c d e f g h  " << endl;

    char p = '.';

    for(rank = 0; rank < MAX_RANK; rank++)
       { 
        int rn = ranks[rank]+1;
         cout << rn <<  " " ;   
         for(file = FILE_A; file < MAX_FILE; file++)
           {
             
            p = isEmpty(ranks[rank],files[file]) ? '.' : '1';
                               
            cout << p << " " ;

           }
               
         cout << " " << endl;
        }

}