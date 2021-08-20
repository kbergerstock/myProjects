// class cTree
// used to manupulate the game list

#include "cPosition.h"

#ifndef __cTree_h
#define __cTree_h

class cTree
{
    private:
        POSITION_LIST search_list[300];       // allow room for 150 half moves 

        void addChild(cPosition* np, int ply);   
        void add_move_list(cPosition&);
        void prunePlys(const cBoard&);

        cMove search(int ply);              // search the given ply for the best move

    public:
        cTree ();

        cTree(cTree&);
        cTree(cPosition&);
        ~cTree();
        
        void growPly(int ply);   
        void dumpPly(cOUTPUT& out, int ply);
        int  getPlySize(int ply)        { return search_list[ply].size(); }
        void pruneTree(const cBoard& );

        cPosition* getRootPos()        
         { 
            return search_list[0][0];
         }            

        // reutine to search position tree for best move from root position
        cMove search();
};


#endif
