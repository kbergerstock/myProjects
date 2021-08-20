//*******************************************************************
//              
//  FILE:       cBOARD.cpp
//              
//  AUTHOR:     Keith R. Bergerstock
//              
//  PROJECT:    BASE_ENGINE
//              
//  COMPONENT:  - cBOARD
//              
//  DATE:       25.11.2003
//              
//  COMMENTS:   -
//              
//              
//*******************************************************************


// Includes

#include "cBoard.h"


cBoard::cBoard()
{
    NewGame();
}

// copy constructor
cBoard::cBoard(const cBoard& b )
{
    current_board = b.current_board;
    black_pieces  = b.black_pieces;
    white_pieces  = b.white_pieces;
    pawns         = b.pawns;
    rooks         = b.rooks;
    knights       = b.knights;
    bishops       = b.bishops;
    queens        = b.queens;
    kings         = b.kings;

    blackKside    = b.blackKside;
    blackQside    = b.blackQside;
    whiteKside    = b.whiteKside;
    whiteQside    = b.whiteQside;
    to_move       = b.to_move;
}

// assignement constructor
cBoard& cBoard::operator=(const cBoard& b)
{
    current_board = b.current_board;
    black_pieces  = b.black_pieces;
    white_pieces  = b.white_pieces;
    pawns         = b.pawns;
    rooks         = b.rooks;
    knights       = b.knights;
    bishops       = b.bishops;
    queens        = b.queens;
    kings         = b.kings;
    to_move       = b.to_move;

    blackKside    = b.blackKside;
    blackQside    = b.blackQside;
    whiteKside    = b.whiteKside;
    whiteQside    = b.whiteQside;

    return *this;
}

void cBoard::NewGame()
{
    // clear the old board
    Clear();

    pawns.set(RANK_2,0xFF);
    pawns.set(RANK_7,0xFF);

    rooks.set(RANK_1,0x81);
    rooks.set(RANK_8,0x81);

    knights.set(RANK_1,0x42);
    knights.set(RANK_8,0x42);

    bishops.set(RANK_1,0x24);
    bishops.set(RANK_8,0x24);

    queens.set(RANK_1,0x08);
    queens.set(RANK_8,0x08);

    kings.set(RANK_1,0x10);
    kings.set(RANK_8,0x10);

    black_pieces.set(RANK_8,0xFF);
    black_pieces.set(RANK_7,0xFF);

    white_pieces.set(RANK_2,0xFF);
    white_pieces.set(RANK_1,0xFF);

    current_board = white_pieces | black_pieces;

    // set the castling flags
    blackKside = 1;
    blackQside = 1;
    whiteKside = 1;
    whiteQside = 1;
    to_move = WHITE;
}

void cBoard::Clear()
{
    current_board = 0;
    black_pieces  = 0;
    white_pieces  = 0;
    pawns         = 0;
    rooks         = 0;
    knights       = 0;
    bishops       = 0;
    queens        = 0;
    kings         = 0;

    blackKside    = 0;
    blackQside    = 0;
    whiteKside    = 0;
    whiteQside    = 0;
    to_move       = NO_SIDE;
}


int cBoard::getPiece(SQUARE_NAMES sq)
{
   
    int piece = NO_PIECE;

    cBitArray w(white_pieces.getPiece(sq) );
    cBitArray b(black_pieces.getPiece(sq) );

    if( w != 0)
     {
        if((w & pawns) != 0)
            piece = WHITE_PAWN;
        else if((w & bishops) != 0)
            piece = WHITE_BISHOP;
        else if((w & knights) != 0)
            piece = WHITE_KNIGHT;
        else if((w & rooks) != 0)
            piece = WHITE_ROOK;
        else if((w & queens) != 0)
            piece = WHITE_QUEEN;
        else if((w & kings) != 0)
            piece = WHITE_KING;
     }
    else if(b != 0)
     {
        if((b & pawns) != 0)
            piece = BLACK_PAWN;
        else if((b & bishops) != 0)
            piece = BLACK_BISHOP;
        else if((b & knights) != 0)
            piece = BLACK_KNIGHT;
        else if((b & rooks) != 0)
            piece = BLACK_ROOK;
        else if((b & queens) != 0)
            piece = BLACK_QUEEN;
        else if((b & kings) != 0)
            piece = BLACK_KING;
      }

    return piece;
}

int cBoard::setPiece(SQUARE_NAMES sq,PIECE_NAMES p)
{
    current_board.setPiece(sq);
    switch(p)
     {
        case WHITE_PAWN:
        case WHITE_KNIGHT:
        case WHITE_BISHOP:
        case WHITE_ROOK:
        case WHITE_QUEEN:
        case WHITE_KING:
            white_pieces.setPiece(sq);
            break;

        case BLACK_PAWN:
        case BLACK_ROOK:
        case BLACK_BISHOP:
        case BLACK_KNIGHT:
        case BLACK_QUEEN:
        case BLACK_KING:
            black_pieces.setPiece(sq);
            break;

        default:
            break;

     }

    switch(p)
     {
        case WHITE_PAWN:
        case BLACK_PAWN:
            pawns.setPiece(sq);
            break;

        case WHITE_BISHOP:
        case BLACK_BISHOP:
            bishops.setPiece(sq);
            break;

        case WHITE_KNIGHT:
        case BLACK_KNIGHT:
            knights.setPiece(sq);
            break;

        case WHITE_ROOK:
        case BLACK_ROOK:
            rooks.setPiece(sq);
            break;

        case WHITE_QUEEN:
        case BLACK_QUEEN:        
            queens.setPiece(sq);
            break;

        case WHITE_KING:
        case BLACK_KING:
            kings.setPiece(sq);
            break;

        default:
            break;

     }

    return 0;

}

int cBoard::setPiece(RANK_NAMES r,FILE_NAMES f,PIECE_NAMES p)
{
    int sq = r * MAX_RANK + f;
    return setPiece((SQUARE_NAMES)sq,p);
}

int cBoard::getPiece(RANK_NAMES r,FILE_NAMES f)
{
    int sq = r * MAX_RANK + f;
    return getPiece((SQUARE_NAMES)sq);
}

void cBoard::movePiece(cMove &m)
{
    
    // update the opposing side if it's piece was captured
    cBitArray t = ((to_move == WHITE) ? black_pieces : white_pieces );
    cBitArray s = ((to_move == WHITE) ? white_pieces : black_pieces );

    // verify the the side to move has a pices on the start square and no piece on the end square
    if( ((s & m.from) == m.from) && ((s & m.to) == 0) )
     {     
        // if the end posistion and the opposite side is set then a capture takes place
        if( (t & m.to)  == m.to)
         {
            cBitArray capture_mask = ~m.to;

            if((pawns & m.to ) == m.to)
                m.captured_piece = PAWN;
            else if((rooks & m.to ) == m.to)
                m.captured_piece = ROOK;
            else if((knights & m.to ) == m.to)
                m.captured_piece = KNIGHT;
            else if((bishops & m.to ) == m.to)
                m.captured_piece = BISHOP;
            else if((queens & m.to ) == m.to)
                m.captured_piece = QUEEN;

            pawns   &= capture_mask;
            rooks   &= capture_mask;
            knights &= capture_mask;
            bishops &= capture_mask;
            queens  &= capture_mask;
            kings   &= capture_mask;

            if(to_move == WHITE)
                black_pieces &= capture_mask;
            else
                white_pieces &= capture_mask;
         }


        // update the side to move
        if(to_move == WHITE)
         {
            white_pieces ^= m.from;
            white_pieces ^= m.to;
         }
        else
         {
            black_pieces ^= m.from;
            black_pieces ^= m.to;
         }

        // update the piece positions
        if( ( pawns & m.from) == m.from)
         {
            pawns ^= m.from;
            pawns ^= m.to;
            m.piece_moved = PAWN;
         }
        else if( (rooks & m.from) == m.from)
         {
            rooks ^= m.from;
            rooks ^= m.to;
             m.piece_moved = ROOK;
         }
        else if( (knights & m.from) == m.from)
         {
            knights ^= m.from;
            knights ^= m.to;
             m.piece_moved = KNIGHT;
         }
        else if( (bishops & m.from) == m.from)
         {
            bishops ^= m.from;
            bishops ^= m.to;
            m.piece_moved = BISHOP;
         }
        else if( (queens & m.from) == m.from)
         {
            queens ^= m.from;
            queens ^= m.to;
            m.piece_moved = QUEEN;
         }
        else if( (kings & m.from) == m.from)
         {
            kings ^= m.from;
            kings ^= m.to;
            m.piece_moved = KING;
         }

        // update the current board
        current_board = white_pieces | black_pieces;

        // update the color for who moves next
        // this matches the obligation to move requirement
        to_move = (to_move == WHITE) ? BLACK : WHITE;
    }
}

void cBoard::castle(cMove &k, cMove& r)
{
        // update the side to move
        if(to_move == WHITE)
         {
            white_pieces ^= k.from;
            white_pieces ^= k.to;
            white_pieces ^= r.from;
            white_pieces ^= r.to;
         }
        else
         {
            black_pieces ^= k.from;
            black_pieces ^= k.to;
            black_pieces ^= r.from;
            black_pieces ^= r.to;
         }

        kings ^= k.from;
        kings ^= k.to;

        rooks ^= r.from;
        rooks ^= r.to;


        k.piece_moved = CASTLE;
        k.captured_piece = 0;

        // update the current board
        current_board = white_pieces | black_pieces;

        // update the color for who moves next
        // this matches the obligation to move requirement
        to_move = (to_move == WHITE) ? BLACK : WHITE;
}

void cBoard::white_castle_king_side(cMove &k)
{
    whiteKside = 0;
    whiteQside = 0;
   
    cMove r(H1,F1,WHITE);
    k.castle_flag = WHITE_KING_SIDE;

    castle(k,r);
}

void cBoard::white_castle_queen_side(cMove &k)
{
    whiteKside = 0;
    whiteQside = 0;
    cMove r(A1,D1,WHITE);
    k.castle_flag = WHITE_QUEEN_SIDE;
    castle(k,r);
}

void cBoard::black_castle_king_side(cMove &k)
{
    blackKside = 0;
    blackQside = 0;
    cMove r(H8,F8,BLACK);
    k.castle_flag = BLACK_KING_SIDE;
    castle(k,r);
}

void cBoard::black_castle_queen_side(cMove &k)
{
    blackKside = 0;
    blackQside = 0;
    cMove r(A8,D8,BLACK);
    k.castle_flag = BLACK_QUEEN_SIDE;
    castle(k,r);
}



int cBoard::take_back(cMove &m)
{
    cMove r;

    // if a piece was captured restore it
    if(m.captured_piece)
     {
        switch(m.captured_piece)
         {
            case PAWN:      pawns   |= m.to; break;
            case ROOK:      rooks   |= m.to; break;
            case KNIGHT:    knights |= m.to; break;
            case BISHOP:    bishops |= m.to; break;
            case QUEEN:     queens  |= m.to; break;
            case KING:      kings   |= m.to; break;
         }
        if(m.side_moved == WHITE)
            black_pieces |= m.to;
        else 
            white_pieces |= m.to;
     }

    // restore the position of the moved piece

    // restore the side moved
    if(m.side_moved == WHITE)
     {
        white_pieces ^= m.from;
        white_pieces ^= m.to;
     }
    else
     {
        black_pieces ^= m.from;
        black_pieces ^= m.to;
     }

    // restore the piece moved position 
    switch(m.piece_moved)
     {
        case PAWN: 
            pawns ^= m.from;
            pawns ^= m.to;                     
            break;
        case ROOK:
            rooks ^= m.from;
            rooks ^= m.to;  
            break;     
        case KNIGHT:   
            knights ^= m.from;
            knights ^= m.to;  
            break;
        case BISHOP:
            bishops ^= m.from;
            bishops ^= m.to;     
            break;
        case QUEEN: 
            queens ^= m.from;
            queens ^= m.to;   
            break;

        case KING:     
            kings ^= m.from;
            kings ^= m.to;  
            break;

        case CASTLE:
            kings ^= m.from;
            kings ^= m.to; 
            switch(m.castle_flag)
              {
                  case WHITE_KING_SIDE:
                    whiteKside = 1;
                    whiteQside = 1;
                    r.set(H1,F1,WHITE);
                  break;  

                  case WHITE_QUEEN_SIDE:
                    whiteKside = 1;
                    whiteQside = 1;
                    r.set(A1,D1,WHITE);
                  break;  

                  case BLACK_KING_SIDE: 
                    blackKside = 1;
                    blackQside = 1;
                    r.set(H8,F8,BLACK);
                  break;  

                  case BLACK_QUEEN_SIDE:
                    blackKside = 1;
                    blackQside = 1;
                    r.set(A8,D8,BLACK);
                  break;   
              } 

            rooks ^= r.from;
            rooks ^= r.to; 

            // restore the side moved
            if(m.side_moved == WHITE)
             {
                white_pieces ^= r.from;
                white_pieces ^= r.to;
             }
            else
             {
                black_pieces ^= r.from;
                black_pieces ^= r.to;
             }

            break;

     }

    // restore the board color
    to_move = m.side_moved;
    // update the current board
    current_board = white_pieces | black_pieces;


    return 0;

}