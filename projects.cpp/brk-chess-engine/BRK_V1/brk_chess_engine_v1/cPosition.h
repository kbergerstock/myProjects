// position class
// contains the current board it's working from
// and a list (vector) of valid moves from that position

#include "cInterface.h"
#include "cBoard.h"
#include <vector>
using namespace std ;

#ifndef __cPosition_h
#define __cPosition_h

// foward declarations;
class cTree;
class cPosition;
typedef vector<cMove> MOVE_LIST;
typedef vector<cPosition*> POSITION_LIST;

class cPosition
{
    private:
        int half_ply;               // half ply count of position    
        int to_move;                // which side has the move
        int value;                  // value of this position
        int mate_flag;              // set true if now legal moves are found for this position
        cBoard position;            // current board (position) that this node works from
        cMove  last_move;           // copy of move that created this position

        // tree node requirements
        cPosition*              m_parent;    // pointer to parent position in tree
        POSITION_LIST::iterator m_start;     // start and stop points in ply list for child positions   
        POSITION_LIST::iterator m_end;
        POSITION_LIST::iterator m_current;  
        int                     m_child_count;

        void gen_sl_move(MOVE_LIST& move_list,cBitArray &t,int piece,int rank, int file, int rank_move,int file_move);
        void gen_pawn_move(MOVE_LIST& move_list,cBitArray &,int rank, int file );
        void gen_knight_move(MOVE_LIST& move_list,cBitArray &,int rank, int file);
        void gen_bishop_move(MOVE_LIST& move_list,cBitArray &,int rank, int file);
        void gen_rook_move(MOVE_LIST& move_list,cBitArray &,int rank, int file);
        void gen_queen_move(MOVE_LIST& move_list,cBitArray &,int rank, int file);
        void gen_king_move(MOVE_LIST& move_list,cBitArray &,int rank, int file);

        int is_attacked(int rank,int file);
        int gen_attack(int sq_rank,int sq_file,int rank,int file);

        // pass thorughs to make moves  on the current board
        void move(cMove &m)      { position.move(m); }
        int  evalMaterial();
        int  evalKingSaftey();

        void set_last_move(cMove &m)  { last_move = m; }
        void set_half_ply(int p)      { half_ply = p; }
        void set_to_move(int p)       { to_move = p; }
        void set_parent(cPosition* p) { m_parent = p; }

        friend class cTree;

    public:
        ~cPosition();
        cPosition() : half_ply(0), to_move(WHITE) { position.NewGameBoard(); }
        cPosition(const cBoard& );
        cPosition(const cPosition &);
        cPosition& operator=(const cPosition &);

        cPosition* getParent()                  { return m_parent;}
        POSITION_LIST::iterator getChildren()   { return m_start; }
        int childCount()                        { return m_child_count; }
        int getPly()                            { return half_ply; }
        int toMove()                            { return to_move; }
        int getValue()                          { return value; }
        int isMated()                           { return mate_flag; }
       
        void NewGame() { half_ply = 0; position.NewGameBoard(); }

        // function to generate the list of moves
        int move_gen(int , MOVE_LIST&);        
        
        // evaluate the current position
        int  eval();  

        // returns  the move that created this position               
         cMove diff() { return last_move; }

        void dumpPosition(cOUTPUT& out)    { out.dumpBoard(position); }
};

#endif