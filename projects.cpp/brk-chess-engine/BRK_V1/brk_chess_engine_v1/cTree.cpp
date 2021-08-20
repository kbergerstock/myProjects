#include "cTree.h"
#include <iostream>
using namespace std;

cTree::cTree() 
{
    cPosition* np = new cPosition;
    addChild(np,np->getPly() );
}

cTree::~cTree()
{
    POSITION_LIST::iterator iter;
    int size;

    for(int ply = 0; ply < 300; ply++)
      {
        size = search_list[ply].size();
        if(size)
            {
                for(iter = search_list[ply].begin(); iter != search_list[ply].end() ; iter++)    
                        delete *iter;
            }
      }
}

void cTree::prunePlys(const cBoard& b)
{
    POSITION_LIST::iterator iter;
    int size;

    for(int ply = 0; ply < 300; ply++)
      {
        size = search_list[ply].size();
        if(size)
            {
                for(iter = search_list[ply].begin(); iter != search_list[ply].end() ; iter++) 
                        delete *iter;

                search_list[ply].clear();
            }
      }
}


void cTree::addChild(cPosition* np,int ply)
{
    search_list[ply].push_back(np);    
}

void cTree::add_move_list(cPosition& p)
{
    // move list of possible moves from positin
    MOVE_LIST move_list;

    int next_move = p.to_move == WHITE ? BLACK : WHITE;
    int next_ply = p.getPly() + 1 ;
    
    MOVE_LIST::iterator iter;
    int size = p.move_gen(p.to_move,move_list);

    p.m_start = search_list[next_ply].end();

    if(size)
        for(iter = move_list.begin(); iter!= move_list.end(); iter++) 
            {
                cPosition* np = new cPosition(p);
                // update the position
                np->move(*iter);
                // fix - check for valid moves and do a prelim positon eval here to weed out the idiotic moves
                if(np->eval() > STUPID_MOVE)
                  {
                    // now add the new positon to the game tree
                    np->set_half_ply(next_ply);
                    np->set_to_move(next_move);
                    np->set_parent(&p);
                    np->set_last_move(*iter);
                    addChild(np,next_ply);
                    // take the move back so the next position can be evaluated
                  } 
                else
                    delete np;      // if not added to list delete it
            }
    
    p.m_end = search_list[next_ply].end();
    // if no valid moves found for this position set mate flag to true
    if(p.m_start == p.m_end)
        p.mate_flag = 1;
  
}

void cTree::growPly(int ply)
{
    int size = search_list[ply].size();
    if(size)
        {
            POSITION_LIST::iterator iter;
            for(iter = search_list[ply].begin(); iter != search_list[ply].end(); iter++ )     
                add_move_list(**iter);
         
        }
}

void cTree::dumpPly(cOUTPUT& out,int ply)
{
    cPosition *p;
    strstream os;
    int size = search_list[ply].size();
    if(size)
        {
            os << "ply " << ply << " ply size " << size << endl;
            out.echo(os);
            POSITION_LIST::iterator iter;
            for(iter = search_list[ply].begin(); iter != search_list[ply].end(); iter++ )    
               {
                    p = *iter;
                    p->dumpPosition(out);
                }
         
        }
}

void cTree::pruneTree(const cBoard& board)
{
    // create a new position
    cPosition* np = new cPosition(board);
    // kill all entryies in list
    // fix future enhencment - copy all positions at of below this position to top of tree
    prunePlys(board);
    // add the positin to the empty tree
    addChild(np,np->getPly() );
    // calc the fist ply below position
    growPly(0);
}

//search the given ply for the best move
cMove cTree::search(int ply)
{
    cPosition *p;
    cMove nm;

    int r = STUPID_MOVE;
    int size = search_list[ply].size();
    if(size)
        {
            POSITION_LIST::iterator iter;
            // search the list for the best move
            for(iter = search_list[ply].begin(); iter != search_list[ply].end(); iter++ )    
               {
                    if((*iter)->getValue() > r)
                        {
                            p = *iter;
                            r = p->getValue();
                                                   }
                }
            // form the move to be made from the position
            nm = p->diff();
         
        }

    return nm;
}

// routine to search position tree for best move from root position
cMove cTree::search()
 {
    cPosition* p = getRootPos();
    int new_ply = p->getPly() + 1;
    return search(new_ply);
 }