#include <string>
using namespace std;
#include "cBitArray.h"

#ifndef __cBoard_h
#define __cBoard_h

enum
{
    WHITE = 1,
    BLACK = 2,
    KING    = 400,
    QUEEN   = 900,
    ROOK    = 500,
    KNIGHT  = 295,
    BISHOP  = 300,
    PAWN    = 100,
    CASTLE  = 800,                  // SPECIAL MOVE

    STUPID_MOVE = -10000,
};

class cMove;
class cPosition;

const bROW kSide = 0x60;
const bROW qSide = 0x0E;

extern const bROW cols[9];

class cBoard
{
	private:        
        int to_move;                // which side has the move from this board
        cBitArray current_board;
        cBitArray black_pieces;
        cBitArray white_pieces;
        cBitArray pawns;
        cBitArray rooks;
        cBitArray knights;
        cBitArray bishops;
        cBitArray queens;
        cBitArray kings;
        // csatling flags
        int blackKside;
        int blackQside;
        int whiteKside;
        int whiteQside;

        friend class cPosition;
        
	public:

        cBoard();                           // null constructor
        cBoard(const cBoard &);             // copy constructor
        cBoard& operator=(const cBoard&);   // assignement constructor
        void NewGameBoard();
        char get(int,int);
        void move(cMove &);
        cMove convert(SQUARE_NAMES,SQUARE_NAMES);
        void setColor(int c) { to_move = c; }
        int  toMove()  { return to_move; }
        int  getPiece(cBitArray &);
};

class cMove
{
    private:
        cBitArray from;
        cBitArray to;
        int piece;
        int color;
        int capture;
        int captured_piece; 

        friend class cBoard;
        friend char* convert(cMove&);
        friend char* convertReply(cMove&);

    public:
        cMove()
            {
                piece = 0;
                color = 0;
                capture = 0;
            }

        void setMove(int f0,int r0,int f1,int r1,int p,int c,int x)
            {
                piece = p;
                color = c;
                capture = x;
                from.setPiece(r0,f0);
                to.setPiece(r1,f1);
            }
        cMove(int f0,int r0 ,int f1,int r1 ,int p ,int c,int x) { setMove(f0,r0,f1,r1,p,c,x); }

        void set(int r0, bROW w0 ,int r1, bROW w1 ,int p ,int c ,int x)
            {
                piece = p;
                color = c;
                capture = x;   
                from.set(r0,w0);
                to.set(r1,w1);
            }

        cMove(int r0,bROW m0,int r1, bROW m1,int p ,int c,int x) { set(r0,m0,r1,m1,p,c,x); }
  
        cMove(const cMove& m) 
            {
                from = m.from;
                to = m.to;
                piece = m.piece;
                color = m.color;
                capture = m.capture;
                captured_piece = m.captured_piece;
            }


        void setFrom(cBitArray t)   { from = t; }
        void setTo(cBitArray t)     { to = t; }            
        void setColor(int c)        { color = c; }
        int  getColor()             { return color; }  
        void setPiece(int p)        { piece = p; } 
        void setCapture(int x)      { capture = x; }
        int  valid()                { return piece; }
        

        bool operator==(const cMove& a)
             {
                return (from == a.from) && (to == a.to) && (piece == a.piece || (piece == KING && a.piece == CASTLE) || (piece == CASTLE && a.piece == KING) );
             }

};
#endif