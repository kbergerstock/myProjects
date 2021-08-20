#include <ctype.h>
#include "cConvert.h"

int file_names[9] = {' ','a','b','c','d','e','f','g','h', };
int rank_names[9] = {' ','1','2','3','4','5','6','7','8' };

int find_rank(char a)
{
    int i;
    for(i = 0; i < 9 ; i++)
        if(a == rank_names[i])
            break;
    return (i > 0 && i < 9) ? i : 0;
}

int find_file(char a)
{
    int i;
    a = toupper(a);
    for(i = 0; i < 9 ; i++)
        if(a == file_names[i])
            break;
    return (i >= 0 && i < 8) ? i+1 : 0;
}


char* convert(cMove &m)
{
    static char tbuf[10];
    int i;
    int j;
    bROW r;
    if(m.from.active() && m.to.active() )
     {
        // find rank of piece start position
        for(i = 1; i<9 && !m.from[i]; i++);
        // find file of piece start position
        for(r = m.from[i],j = 1; j<9  && !(r & cols[j]); j++);
        // convert coodinates to letter combo
        tbuf[0] = file_names[j];
        tbuf[1] = rank_names[i];
        tbuf[2] = '-';
        // find rank of pices end position
        for(i = 1; i<9 && !m.to[i]; i++);
        // find file of pices end position
        for(r = m.to[i],j = 1; j<9  && !(r & cols[j]); j++);
        // convert  to letter combo
        tbuf[3] = file_names[j];
        tbuf[4] = rank_names[i];
        // null terminate
        tbuf[5] = '\0';        
       }
     else
        tbuf[0] = '\0'; 

    // return result of conversion
    return tbuf;
}

char* convertReply(cMove &m)
{
    static char tbuf[10];
    int i;
    int j;
    bROW r;
    if(m.from.active() && m.to.active() )
     {
        // find rank of piece start position
        for(i = 1; i<9 && !m.from[i]; i++);
        // find file of piece start position
        for(r = m.from[i],j = 1; j<9  && !(r & cols[j]); j++);
        // convert coodinates to letter combo
        tbuf[0] = file_names[j];
        tbuf[1] = rank_names[i];
        // find rank of pices end position
        for(i = 1; i<9 && !m.to[i]; i++);
        // find file of pices end position
        for(r = m.to[i],j = 1; j<9  && !(r & cols[j]); j++);
        // convert  to letter combo
        tbuf[2] = file_names[j];
        tbuf[3] = rank_names[i];
        // null terminate
        tbuf[4] = '\0';        
       }
     else
        tbuf[0] = '\0'; 

    // return result of conversion
    return tbuf;
}


cMove cBoard::convert(SQUARE_NAMES from_square, SQUARE_NAMES to_square)
{
    cMove nm;
    // step 1 determine start and end positions of piece
    nm.from.setPiece(from_square);
    nm.to.setPiece(to_square);
    // step 2 determine color of piece to move

    int piece = getPiece(nm.from);

    int capture = 0;
    
    if(to_move == WHITE)
        {
            if( nm.to & white_pieces )
                piece = 0;
            else
              capture = nm.to & black_pieces ? 1 : 0;
        }
    else 
        {
            if( nm.to & black_pieces)
                piece = 0;
            else
              capture = nm.to & white_pieces ? 1 : 0;
        }

    if(piece)
        {
            nm.setColor(to_move);
            nm.setPiece(piece);
            nm.setCapture(capture);
        }
    else
        nm.setMove(0,0,0,0,0,0,0);

    return nm;
}