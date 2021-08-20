//*******************************************************************
//              
//  FILE:       cPositionTree.h
//              
//  AUTHOR:     Keith R. Bergerstock
//              
//  PROJECT:    CHESS_ENGINE
//              
//  COMPONENT:  cPositionTree
//              
//  DATE:       07.03.2006
//              
//  COMMENTS:   - tree listing of possible positions
//              - each row element contains an eval and 
//              - a pointer back to start pos for this position
//              - and a copy of the move that made it
//              
//              
//*******************************************************************

#pragma warning (disable:4786)

// Includes

#include "tarray.h"
#include "cBoard.h"
#include "cMOVE_GEN.h"


#ifndef __cPositionTree_h
#define __cPositionTree_h

class cPositionTree;            // all the position tree access to private members

class cNode
{
    private:
        cMove   move;
        IDX     parent;         // index to parent node
        IDX     child;          // index to first child node

        friend class cPositionTree;
    public:

        cNode(): move() , parent(0), child(0) {}

        cNode(cMove& nm, IDX p)
         {
            set(nm,p);
         }

        void set(cMove& nm, IDX p)
         {
            move = nm;
            parent = p;
            child = 0;
         }

        void set(IDX c)
         {
            if(child == 0)
                child = c;
         }

        cNode(const cNode& a)
         {
            move     = a.move;
            parent   = a.parent;
            child    = a.child;   
         }

        cNode& operator=(const cNode& a)
         {
            move     = a.move;
            parent   = a.parent;
            child    = a.child;   
            return *this;
         }

        cMove& mv() { return move; }
};

typedef tARRAY<cNode> POSITION_LIST;

class cPositionTree
{
    private:
        int ply;

        int idx;
        int pdx;
        int ndx;
        
        cBoard          start_position;
        cMoveGenerator  mg;

        POSITION_LIST   search_list;
        
        void add(cMove& nm,IDX parent);
		void addPosition(cBoard &sp,IDX parent);

        /*
        void addChild(cPosition* np, int ply);   
        void add_move_list(cPosition&);
        void prunePlys(const cBoard&);

        cMove search(int ply);              // search the given ply for the best move
        */

        void  dump_move_list();
        
        cPositionTree(cPositionTree&);

    public:
        cPositionTree ();

               ~cPositionTree();
        
        void init(cBoard&);

        void go();
                    
        /*
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
        */
};


#endif
