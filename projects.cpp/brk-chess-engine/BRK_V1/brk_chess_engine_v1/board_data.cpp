#include "cBitArray.h"

cBitArray valid_board;
cBitArray knightMoves[8][8];


void fillValidBoard(void)
{
    for(int rank = 1; rank <= 8; rank++)
        valid_board.set(rank,0xff);
}

