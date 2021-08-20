//*******************************************************************
//              
//  FILE:       cPositionTree.cpp
//              
//  AUTHOR:     Keith R. Bergerstock
//              
//  PROJECT:    CHESS_ENGINE
//              
//  COMPONENT:  cTree
//              
//  DATE:       07.03.2006
//              
//  COMMENTS:   -
//              
//              
//*******************************************************************

#pragma warning (disable:4786)

// Includes

#include "cPositionTree.h"
#include "cSQUARES.h"
#include <iostream>
using namespace std;

cPositionTree::cPositionTree() : mg()
{
    cout << " position tree constructed" << endl;
    // initlize the list to 500,000 nodes
    search_list.size(500000);
}

cPositionTree::cPositionTree(cPositionTree& p)
{
    throw("unimplemented copy constructor");
}

cPositionTree::~cPositionTree()
{
}

void cPositionTree::init(cBoard& position)
{
    // initilize the start position
	start_position = position;
    // reset the search list
    ndx = pdx = idx = 0;
    // resdet the ply counter
    ply = 0;
}

void cPositionTree::dump_move_list()
{
    cMove mp;
    
    if(idx > 0)
     {
        if(idx < 2000)
         {
            for(IDX i = 0; i < idx ; i++)
             {
                mp = search_list[i].mv();
                cout << square_list.search(mp.sq_from() ) << " - " << square_list.search(mp.sq_to() ) << " : " ;
                cout << mp.get_eval() << endl;
             }
          }

        cout << " move size" << sizeof(mp) << endl;
        cout << " number of ply's " << ply << endl;
        cout << " number of moves " << idx << endl;
     }
     else
     {
        cout << "empty move list" << endl;
     }
}

void cPositionTree::add(cMove& nm,IDX parent)
{
    // set parent node point to first child node
    search_list[parent].set(idx);
    // create childe note and store parent node in it
    cNode n(nm,parent);
    // add it to the node list
    search_list[idx++] = n;
}

void cPositionTree::addPosition(cBoard &sp, IDX parent)
{
    mg.make_move_list(sp);
    for(int i = 0; i < mg.size(); i++)
     {
        add(mg[i],parent);
     }
}

void cPositionTree::go()
{
    IDX i;
    int search_depth = 4;
    // add first half ply
    addPosition(start_position,0); 
    ply++;      
    
    // allows for 100 half ply's deep - fix - might break
    IDX move_list[100];

    IDX n = ndx;
    IDX e = idx;

    // add first end ply
    for( i = n; i < e; i++)
     {
        cMove& mv = search_list[i].move;
        start_position.movePiece(mv);
        addPosition(start_position,i);
        start_position.take_back(mv);
     }

     n = e;             // set start of ply
     e = idx;           // set end of ply
     ply++;
     
     // add 
     for( ; ply < search_depth; ply++)
      {
        for( i = n; i < e; i++)
         {
            int j = 0;
            IDX p = i;
            // form move list
            do{
                move_list[j++] = p;
                p = search_list[p].parent;
              } while(search_list[p].parent != 0);

            // now form the position for the current move
            cBoard cp = start_position;
            for(int k = 0; k < j; k++)
             {
                cp.movePiece(search_list[move_list[j-k-1] ].move );
                addPosition(cp,i);
             }
         }
        n = e;
        e = idx;
      }

     dump_move_list();
}
