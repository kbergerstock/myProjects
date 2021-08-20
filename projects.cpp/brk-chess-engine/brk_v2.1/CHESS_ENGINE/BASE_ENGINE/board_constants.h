// constants used to define board and pice values

#ifndef __board_constants_h
#define __board_constants_h

enum SIDE_NAMES
{
    WHITE = 100,
    BLACK,
    NO_SIDE
};

/*
    typical representaiton of a board
          abcdefgh          
    1     xxxxxxxx  0   
    2     xxxxxxxx  1
    3     xxxxxxxx  2
    4     xxxxxxxx  3
    5     xxxxxxxx  4
    6     xxxxxxxx  5
    7     xxxxxxxx  6
    8     xxxxxxxx  7
          01234567  

*/

enum SQUARE_NAMES
{
    A1,B1,C1,D1,E1,F1,G1,H1,
    A2,B2,C2,D2,E2,F2,G2,H2,
    A3,B3,C3,D3,E3,F3,G3,H3,
    A4,B4,C4,D4,E4,F4,G4,H4,
    A5,B5,C5,D5,E5,F5,G5,H5,
    A6,B6,C6,D6,E6,F6,G6,H6,
    A7,B7,C7,D7,E7,F7,G7,H7,
    A8,B8,C8,D8,E8,F8,G8,H8,
    NO_SQUARE
};

enum FILE_NAMES 
{ 
    FILE_A = 0, 
    FILE_B, 
    FILE_C, 
    FILE_D, 
    FILE_E, 
    FILE_F, 
    FILE_G, 
    FILE_H,
    MAX_FILE,
} ;

enum RANK_NAMES 
{
    RANK_1 = 0, 
    RANK_2, 
    RANK_3, 
    RANK_4, 
    RANK_5, 
    RANK_6, 
    RANK_7, 
    RANK_8,
    MAX_RANK,
};

enum PIECE_NAMES
{
    WHITE_PAWN    = 200,
    WHITE_KNIGHT,
    WHITE_BISHOP,
    WHITE_ROOK,
    WHITE_QUEEN,
    WHITE_KING,
    BLACK_PAWN,    
    BLACK_KNIGHT,
    BLACK_BISHOP,
    BLACK_ROOK,
    BLACK_QUEEN,
    BLACK_KING,
    NO_PIECE,
};

// piece values 
enum PIECE_VALUES
{
    PAWN    =  90,
    KNIGHT  = 295,
    BISHOP  = 300,
    ROOK    = 500,
    QUEEN   = 900,
    KING    = 30000,
    CASTLE  = 800,                  // SPECIAL MOVE
    CEP     = 155,                  // capture en pansent

    STUPID_MOVE = -10000,
};

enum CASTLE_DEFS
{
    WHITE_KING_SIDE = 51,   
    WHITE_QUEEN_SIDE,
    BLACK_KING_SIDE,
    BLACK_QUEEN_SIDE,
};


#endif