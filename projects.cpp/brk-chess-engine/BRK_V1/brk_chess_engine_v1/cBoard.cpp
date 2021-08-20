#include "cBoard.h"

const bROW cols[9] = { 0x00,0x01,0x02,0x04,0x08,0x10,0x20,0x40,0x80 };

cBoard::cBoard()
{

}

// copy constructor
cBoard::cBoard(const cBoard& b )
{
    current_board.copy(b.current_board);
    black_pieces.copy(b.black_pieces);
    white_pieces.copy(b.white_pieces);
    pawns.copy(b.pawns);
    rooks.copy(b.rooks);
    knights.copy(b.knights);
    bishops.copy(b.bishops);
    queens.copy(b.queens);
    kings.copy(b.kings);
    blackKside = b.blackKside;
    blackQside = b.blackQside;
    whiteKside = b.whiteKside;
    whiteQside = b.whiteQside;
    to_move = b.to_move;
}

// assignement constructor
cBoard& cBoard::operator=(const cBoard& b)
{
    current_board = b.current_board;
    black_pieces = b.black_pieces;
    white_pieces = b.white_pieces;
    pawns = b.pawns;
    rooks = b.rooks;
    knights = b.knights;
    bishops = b.bishops;
    queens = b.queens;
    kings = b.kings;
    to_move = b.to_move;
    blackKside = b.blackKside;
    blackQside = b.blackQside;
    whiteKside = b.whiteKside;
    whiteQside = b.whiteQside;

    return *this;
}

void cBoard::NewGameBoard()
{
    pawns.set(2,0xFF);
    pawns.set(7,0xFF);

    rooks.set(1,0x81);
    rooks.set(8,0x81);

    knights.set(1,0x42);
    knights.set(8,0x42);

    bishops.set(1,0x24);
    bishops.set(8,0x24);

    queens.set(1,0x08);
    queens.set(8,0x08);

    kings.set(1,0x10);
    kings.set(8,0x10);

    black_pieces.set(8,0xFF);
    black_pieces.set(7,0xFF);

    white_pieces.set(2,0xFF);
    white_pieces.set(1,0xFF);

    current_board = white_pieces;
    current_board.or(black_pieces);

    // set the castling flags
    blackKside = 1;
    blackQside = 1;
    whiteKside = 1;
    whiteQside = 1;
    to_move = WHITE;
}

char cBoard::get(int rank,int file)
{
    char r = '.';
    bROW mask;
    if( (mask = current_board.getPiece(rank,file))  )
        if(mask & black_pieces[rank])
          {
            if(mask & pawns[rank] )
                r = 'P';
            else if(mask & rooks[rank] )
                r = 'R';
            else if(mask & knights[rank] )
                r = 'N';
            else if(mask & bishops[rank] )
                r = 'B';
            else if(mask & queens[rank] )
                r = 'Q';
            else if(mask & kings[rank] )
                r = 'K';
            else
                r = 1;

          } 
        else if(mask & white_pieces[rank])
          {
            if(mask & pawns[rank] )
                r = 'p';
            else if(mask & rooks[rank] )
                r = 'r';
            else if(mask & knights[rank] )
                r = 'n';
            else if(mask & bishops[rank] )
                r = 'b';
            else if(mask & queens[rank] )
                r = 'q';
            else if(mask & kings[rank] )
                r = 'k';
            else
                r = 1;
          }


    return r;
}

void cBoard::move(cMove &m)
{
    
    // update the opposing side if it's piece was captured
    if(m.capture)
     {
        cBitArray *t = (m.color == WHITE) ? &black_pieces : &white_pieces;
        cBitArray n;
        n.not(m.to);
        m.captured_piece = 0;
       
        for(int i = 1; i <= 8 && !m.captured_piece; i++)
          {
            if(pawns[i] & m.to[i])
                m.captured_piece = PAWN;
            else if(rooks[i] & m.to[i])
                m.captured_piece = ROOK;
            else if(knights[i] & m.to[i])
                m.captured_piece = KNIGHT;
            else if(bishops[i] & m.to[i])
                m.captured_piece = BISHOP;
            else if(queens[i] & m.to[i])
                m.captured_piece = QUEEN;
          }   

        t->and(n)   ;
        pawns.and(n);
        rooks.and(n);
        knights.and(n);
        bishops.and(n);
        queens.and(n);
        kings.and(n);
     }   

    // update the side to move
    if(m.color == WHITE)
     {
        white_pieces.xor(m.from);
        white_pieces.xor(m.to);
     }
    else
     {
        black_pieces.xor(m.from);
        black_pieces.xor(m.to);
     }

    // update the piece positions
    switch(m.piece)
      {
            case PAWN:
                pawns.xor(m.from);
                pawns.xor(m.to);
                break;
            case ROOK:
                rooks.xor(m.from);
                rooks.xor(m.to);
                 break;
            case KNIGHT:
                knights.xor(m.from);
                knights.xor(m.to);
                break;
            case BISHOP:
                bishops.xor(m.from);
                bishops.xor(m.to);
                break;
            case QUEEN:
                queens.xor(m.from);
                queens.xor(m.to);
                break;
            case KING:
                kings.xor(m.from);
                kings.xor(m.to);
                break;

            case CASTLE:                
                kings.xor(m.from);
                kings.xor(m.to);
                if(m.color == WHITE)
                     {
                        cMove rm;
                        if(m.to.getPiece(1,7) )     // kingside
                            rm.setMove(8,1,6,1,CASTLE,m.color,0);
                        else  
                            rm.setMove(1,1,4,1,CASTLE,m.color,0);

                            white_pieces.xor(rm.from);
                            white_pieces.xor(rm.to);
                            rooks.xor(rm.from);
                            rooks.xor(rm.to);
                     }
                    else
                     {
                        cMove rm;
                        if(m.to.getPiece(8,7) )     // kingside
                            rm.setMove(8,8,6,8,CASTLE,m.color,0);
                        else  
                            rm.setMove(1,8,4,8,CASTLE,m.color,0);

                            black_pieces.xor(rm.from);
                            black_pieces.xor(rm.to);
                            rooks.xor(rm.from);
                            rooks.xor(rm.to);
                     }
                    break;

      }    
    // update the current board
    current_board= white_pieces;
    current_board.or(black_pieces);

    // update the color for who moves next
    // this matches the obligation to move requirement
    to_move = (to_move == WHITE) ? BLACK : WHITE;
}

/*
void cBoard::takeback(cMove &m)
{
    // update the side to move
    if(m.color == WHITE)
     {
        white_pieces.xor(m.from);
        white_pieces.xor(m.to);
     }
    else
     {
        black_pieces.xor(m.from);
        black_pieces.xor(m.to);
     }

    switch(m.piece)
      {
            case PAWN:
                pawns.xor(m.from);
                pawns.xor(m.to);
                break;
            case ROOK:
                rooks.xor(m.from);
                rooks.xor(m.to);
                 break;
            case KNIGHT:
                knights.xor(m.from);
                knights.xor(m.to);
                break;
            case BISHOP:
                bishops.xor(m.from);
                bishops.xor(m.to);
                break;
            case QUEEN:
                queens.xor(m.from);
                queens.xor(m.to);
                break;
            case KING:
                kings.xor(m.from);
                kings.xor(m.to);
                break;
            case CASTLE:
                kings.xor(m.from);
                kings.xor(m.to);                
                if(m.color == WHITE)
                     {
                        cMove rm;

                        if(m.to.getPiece(1,7) )     // kingside
                            rm.setMove(8,1,6,1,CASTLE,m.color,0);
                        else  
                            rm.setMove(1,1,4,1,CASTLE,m.color,0);

                            white_pieces.xor(rm.from);
                            white_pieces.xor(rm.to);
                            rooks.xor(rm.from);
                            rooks.xor(rm.to);
                     }
                    else
                     {
                        cMove rm;
                        if(m.to.getPiece(8,7) )     // kingside
                            rm.setMove(8,8,6,8,CASTLE,m.color,0);
                        else  
                            rm.setMove(1,8,4,8,CASTLE,m.color,0);

                            black_pieces.xor(rm.from);
                            black_pieces.xor(rm.to);
                            rooks.xor(rm.from);
                            rooks.xor(rm.to);
                     }
                    break;
      }

    if(m.capture)
     {
        cBitArray *t = (m.color == WHITE) ? &black_pieces : &white_pieces;
        t->or(m.to);
        // update the piece positions
        switch(m.captured_piece)
          {
                case PAWN:
                    pawns.or(m.to);
                    break;
                case ROOK:
                    rooks.or(m.to);
                     break;
                case KNIGHT:
                    knights.or(m.to);
                    break;
                case BISHOP:
                    bishops.or(m.to);
                    break;
                case QUEEN:
                    queens.or(m.to);
                    break;
                case KING:
                    kings.or(m.to);
                    break;
          }

     }

    // update the current board
    // update the current board
    current_board = white_pieces;
    current_board.or(black_pieces);
}
*/
int cBoard::getPiece(cBitArray& t)
{
    int piece = 0;

    if(t & pawns )
        piece = PAWN;
    else if(t & bishops)
        piece = BISHOP;
    else if(t & knights)
        piece = KNIGHT;
    else if(t & rooks)
        piece = ROOK;
    else if(t & queens)
        piece = QUEEN;
    else if(t & kings)
        piece = KING;

    return piece;
}