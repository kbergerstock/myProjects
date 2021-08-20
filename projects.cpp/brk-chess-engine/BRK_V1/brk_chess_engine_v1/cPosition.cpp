#include "cPosition.h"
#include <iostream>
using namespace std;

template<class T> sign(const T& x)
 {
    return x > 0 ? 1 : (x < 0 ? -1 : 0);
 }

cPosition::cPosition(const cBoard &b) : position(b) 
{
    half_ply = 0;
    to_move = b.to_move;
    m_parent = 0;
    m_child_count = 0;
    mate_flag = 0;
}

cPosition::cPosition(const cPosition &p) : position(p.position)
{
    half_ply = p.half_ply;
    to_move = p.to_move;
    value = p.value;
    mate_flag = p.mate_flag;
    m_parent = 0; 
    m_start = 0;  
    m_end = 0;
    m_current = 0;  
}

cPosition::~cPosition()
{
   
}

cPosition& cPosition::operator=(const cPosition &p)
{
    position = p.position;
    last_move = p.last_move;
    mate_flag = p.mate_flag;
    half_ply = p.half_ply;
    to_move = p.to_move;
    value = p.value; 
    // fix add pointer asignments or set them to null

    return *this;
}


void cPosition::gen_pawn_move(MOVE_LIST& move_list,cBitArray &t,int rank, int file )
{
    static int pawn_file_moves[2] = { -1,1} ;

    int new_file = file;
    int new_rank;

    // 2 square movement direction
    int sr = (to_move == WHITE) ? 2 : 7; 

    if(rank == sr)
     {  
        new_rank = rank + ((to_move == WHITE) ? 2 : -2);
        if(new_rank > 0 && new_rank < 9 && position.current_board.isEmpty(new_rank,new_file) )
         {
            cMove nm1(file,rank,new_file,new_rank,PAWN,to_move,0);
            move_list.push_back(nm1);
          }
     }

    // 1 square movement direction
    new_rank = rank + ((to_move == WHITE) ? 1 : -1);   
    if(new_rank > 0 && new_rank < 9 && position.current_board.isEmpty(new_rank,new_file) )
     {
        cMove nm1(file,rank,new_file,new_rank,PAWN,to_move,0);
        move_list.push_back(nm1);
      }
    

    // add pawn capture here
    new_file = file + 1;
    // if the new positin is withen bonds and not occupied by one of our own pieces
    if(new_rank > 0 && new_rank < 9  && new_file > 0 && new_file < 9 && !t.getPiece(new_rank,new_file) )
        {
            // and is accupied by an oppoents piece then capture is possible
            if(position.current_board.getPiece(new_rank,new_file) )
              {
                cMove nm(file,rank,new_file,new_rank,PAWN,to_move,1);
                move_list.push_back(nm);
              }
        }
    new_file = file -1;
    if(new_rank > 0 && new_rank < 9 &&  new_file > 0 && new_file < 9 && !t.getPiece(new_rank,new_file) )
        {
            if(position.current_board.getPiece(new_rank,new_file) )
              {
                cMove nm(file,rank,new_file,new_rank,PAWN,to_move,1);
                move_list.push_back(nm);
              }
        }

    // add en passent capture here
    // add pawn promotion here
        /*
        if(new_rank == 8)
          {
          }
        */
    
}

static  int knight_rank_moves[8] = { 2,2,1,-1,-2,-2,1,-1 };
static int knight_file_moves[8] = { 1,-1,2,2,1,-1,-2,-2 };

void cPosition::gen_knight_move(MOVE_LIST& move_list,cBitArray &t,int rank, int file )
{
    // get the posiible knight moves from this position
    int new_rank;
    int new_file;

    for(int m = 0; m < 8; m++)
        {
            new_rank = rank + knight_rank_moves[m];
            new_file = file + knight_file_moves[m];
            // to square is withen bounds and empty of same color piece
            if(new_rank > 0 && new_rank < 9 && new_file > 0 && new_file < 9 && !t.getPiece(new_rank,new_file))
             {     
                int x = position.current_board.getPiece(new_rank,new_file);
                cMove nm(file,rank,new_file,new_rank,KNIGHT,to_move,x);
                move_list.push_back(nm);
             }
        }

}

void cPosition::gen_sl_move(MOVE_LIST& move_list,cBitArray &t,int piece, int rank, int file, int rank_move,int file_move)
{
    int new_rank = rank + rank_move;
    int new_file = file + file_move;
    int x = 0;
    
    while(new_rank > 0 && new_rank < 9 && new_file > 0 && new_file < 9 && !t.getPiece(new_rank,new_file) && x == 0)
        {
            x = position.current_board.getPiece(new_rank,new_file);
            cMove nm(file,rank,new_file,new_rank,piece,to_move,x);
            move_list.push_back(nm);

            new_rank+=rank_move;
            new_file+=file_move; 
        }
}

int cPosition::gen_attack(int sq_rank,int sq_file,int rank,int file)
{
    int dr = sign(sq_rank - rank);
    int df = sign(sq_file - file);
    int r = 0;

    while( (rank != sq_rank || file != sq_file)  && r == 0)
     {
        rank += dr;
        file += df;
        r = position.current_board.getPiece(rank,file);
     }
    return rank == sq_rank && file == sq_file && r ? 1 : 0;
}

void cPosition::gen_bishop_move(MOVE_LIST& move_list,cBitArray &t,int rank, int file )
{
    static int bishop_rank_move[4] = { 1,1,-1,-1 };
    static int bishop_file_move[4] = { 1,-1,-1,1 };            
    for(int i = 0; i < 4; i++)
        gen_sl_move(move_list,t,BISHOP, rank, file, bishop_rank_move[i],bishop_file_move[i]);
}

void cPosition::gen_rook_move(MOVE_LIST& move_list,cBitArray &t,int rank, int file )
{
    static int rook_rank_move[4] = { 1,-1, 0,0 };
    static int rook_file_move[4] = { 0,0, -1,1 };            
    for(int i = 0; i < 4; i++)
        gen_sl_move(move_list,t,ROOK, rank, file, rook_rank_move[i],rook_file_move[i]);

}

void cPosition::gen_queen_move(MOVE_LIST& move_list,cBitArray &t,int rank, int file )
{
    static int queen_rank_move[8] = { 1,1,-1,-1, 1,-1, 0, 0 };
    static int queen_file_move[8] = { 1,-1,-1,1, 0, 0,-1, 1 };            
    for(int i = 0; i < 8; i++)
        gen_sl_move(move_list,t,QUEEN, rank, file, queen_rank_move[i],queen_file_move[i]);

}
void cPosition::gen_king_move(MOVE_LIST& move_list,cBitArray &t,int rank, int file )
{
    static int king_rank_moves[8] = { 1, 1 , 1, 0, 0,-1,-1,-1 };
    static int king_file_moves[8] = {-1, 0 , 1,-1, 1,-1, 0, 1 };  
    int new_rank;
    int new_file;
    for(int m = 0; m < 8; m++)
        {
            new_rank = rank + king_rank_moves[m];
            new_file = file + king_file_moves[m];
            // to square is withen bounds and empty of same color piece
            if(new_rank > 0 && new_rank < 9 && new_file > 0 && new_file < 9 && !t.getPiece(new_rank,new_file))
             {     
                int x = position.current_board.getPiece(new_rank,new_file);
                cMove nm(file,rank,new_file,new_rank,KING,to_move,x);
                move_list.push_back(nm);
             }
        }
    // generate castling
    if(to_move == WHITE)
     {
        if(position.whiteKside == 1 && ( ( position.current_board[1] & kSide) == 0) )
         {
            cMove nm(5,1,7,1,CASTLE,to_move,0);            
            move_list.push_back(nm);
         }
        else if(position.whiteQside == 1 && ( ( position.current_board[1] & qSide) == 0) )
         {
            cMove nm(5,1,3,1,CASTLE,to_move,0);            
            move_list.push_back(nm);
         }
     }
    else
     {
       if(position.blackKside == 1 && ( ( position.current_board[8] & kSide) == 0 ) )
         {
            cMove nm(5,8,7,8,CASTLE,to_move,0);            
            move_list.push_back(nm);
         }
        else if(position.blackQside == 1 && ( ( position.current_board[8] & qSide) == 0) )
         {
            cMove nm(5,8,3,8,CASTLE,to_move,0);            
            move_list.push_back(nm);
         }
     }
            
}


int cPosition::move_gen(int color, MOVE_LIST& move_list)
{
    cBitArray* t = (color == WHITE) ? &position.white_pieces : &position.black_pieces;
    to_move = color;    
    bROW f;                 // from mask
    int rank,file;
    
    // generate pawn moves
    // gen_pawn_moves(move_list,*t)

    for(rank = 1; rank <=8; rank++)
        for(file = 1; file <=8; file++)
            {
                f = t->getPiece(rank,file);
                if(f)
                  {  
                    if( f & position.pawns[rank])
                        gen_pawn_move(move_list,*t,rank,file);
                    else if(f & position.knights[rank])
                        gen_knight_move(move_list,*t,rank,file);
                    else if(f & position.bishops[rank])
                        gen_bishop_move(move_list,*t,rank,file);
                    else if( f & position.rooks[rank])
                        gen_rook_move(move_list,*t,rank,file);
                    else if( f & position.queens[rank])
                        gen_queen_move(move_list,*t,rank,file);
                    else if( f & position.kings[rank])
                        gen_king_move(move_list,*t,rank,file);
                   } 
            }
          
    // generate castling moves
       
    return move_list.size();
}

int cPosition::is_attacked(int sq_rank,int sq_file)
{
    int attacked = 0;
    bROW f;       
    int rank,file,dr,df;
    // get a pointer to the opposing color pieces
    cBitArray* t = (to_move == WHITE) ? & position.black_pieces : &position.white_pieces;

    // for each square if it contains a piece calc if piece attacks specified square
    for(rank = 1; rank <=8; rank++)
        for(file = 1; file <=8; file++)
            {
                f = t->getPiece(rank,file);
                if(f)
                  {  
                        dr = sq_rank - rank;
                        df = sq_file - file;

                        if( f & position.pawns[rank])
                          {
                            int nr = to_move == WHITE ? -1 : 1;
                            if(dr == nr && (df == 1 || df == -1) )
                                attacked++;
                          }
                        else if(f & position.knights[rank])
                          {
                            for(int m = 0; m < 8; m++)
                                {
                                    if(   dr == knight_rank_moves[m] &&
                                          df == knight_file_moves[m] )
                                            attacked++;
                                }
                          }
                        else if(f & position.bishops[rank])
                          {
                            // calc line of sight 
                            if(abs(dr) == abs(df) )
                                attacked += gen_attack(sq_rank,sq_file,rank,file);   // now check for interposing piece 

                          }  
                        else if( f & position.rooks[rank])
                          {
                          // calc line of sight 
                            if( dr == 0 || df == 0)
                                attacked += gen_attack(sq_rank,sq_file,rank,file);   // now check for interposing piece 
    
                          } 
                        else if( f & position.queens[rank])
                          {
                            // calc line of sight 
                            if(abs(dr) == abs(df) || dr == 0 || df == 0)
                                attacked += gen_attack(sq_rank,sq_file,rank,file);   // now check for interposing piece 
   
                          } 
                        else if( f & position.kings[rank])
                          {
                            if(abs(dr) <= 1 && abs(df) <= 1 )
                                attacked++;
                          }

                            
                  } 
            }

    return attacked;
}

int cPosition::eval()
{
    value = evalKingSaftey();

    if( value > STUPID_MOVE)
        value = evalMaterial();

    // for now use a random number gen to simulate eval
    if(value > -PAWN && value < PAWN)
        value += (rand() % 100);

    return value ;
}

int cPosition::evalMaterial()
{
    int value = 0;
    int m;
    bROW f;                 // from mask
    int rank,file;

    for(rank = 1; rank <=8; rank++)
        for(file = 1; file <=8; file++)
            {
                f = position.current_board.getPiece(rank,file);
                if(f)
                  {  
                     m = (f & position.white_pieces[rank] ) ? 1 : -1;

                    if( f & position.pawns[rank])
                        value += PAWN * m;
                    else if(f & position.knights[rank])
                        value += KNIGHT * m;
                    else if(f & position.bishops[rank])
                        value += BISHOP * m;
                    else if( f & position.rooks[rank])
                        value += ROOK * m;
                    else if( f & position.queens[rank])
                        value += QUEEN * m;
                   } 
            }


    return to_move == WHITE ? value : - value ;
}

// v1 - just return stupid move for anything that leaves the king attacked
int  cPosition::evalKingSaftey()
{
    int rank,file;
    bROW c = 0;

    // get a pointer to the the side to move color pieces
    cBitArray t = (to_move == WHITE) ? position.white_pieces : position.black_pieces;
    t.and(position.kings);

    for(rank = 1; rank <= 8 && c == 0; rank++)
        c = t[rank];

    rank--;

    for(c = 0, file = 1; file <= 8 && c == 0; file++)
        c = t.getPiece(rank,file);
        
    file--;
            
    int r = is_attacked(rank,file) ? STUPID_MOVE : 0;
    return r;
}