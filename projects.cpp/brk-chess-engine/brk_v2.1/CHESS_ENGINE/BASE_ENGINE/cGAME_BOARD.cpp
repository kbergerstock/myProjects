//*******************************************************************
//              
//  FILE:       cGAME_BOARD.cpp
//              
//  AUTHOR:     Keith R. Bergerstock
//              
//  PROJECT:    BASE_ENGINE
//              
//  COMPONENT:  -
//              
//  DATE:       19.12.2003
//              
//  COMMENTS:   -
//              
//              
//*******************************************************************


// Includes
#include "cGAME_BOARD.H"

cGAME_BOARD::cGAME_BOARD()
{
    cout << " game board constructed" << endl;
}

cGAME_BOARD::~cGAME_BOARD()
{
    // empty the move list's 
    // move_list.clear();
    game_list.clear();
}

int cGAME_BOARD::new_game()
{
    // empty the move list's 
    // move_list.clear();
    game_list.clear();

    // create a new board
    NewGame();

    return 0;
}

int cGAME_BOARD::set_piece(RANK_NAMES r,FILE_NAMES f,char pn)
{
    switch(pn)
     {
        case 'P': setPiece(r,f,WHITE_PAWN); break;
        case 'p': setPiece(r,f,BLACK_PAWN); break;
        case 'R': setPiece(r,f,WHITE_ROOK); break;
        case 'r': setPiece(r,f,BLACK_ROOK); break;
        case 'B': setPiece(r,f,WHITE_BISHOP); break;
        case 'b': setPiece(r,f,BLACK_BISHOP); break;
        case 'N': setPiece(r,f,WHITE_KNIGHT); break;
        case 'n': setPiece(r,f,BLACK_KNIGHT); break; 
        case 'Q': setPiece(r,f,WHITE_QUEEN); break;
        case 'q': setPiece(r,f,BLACK_QUEEN); break;
        case 'K': setPiece(r,f,WHITE_KING); break;
        case 'k': setPiece(r,f,BLACK_KING); break;                
        default:
            break;                                    
     }

    return 0;
}

int cGAME_BOARD::set_board(cFEN& fen)
{
    // empty the move list's 
    game_list.clear();    
    // get the diagram
    string diagram = fen.diagram();
    // clear the board
    Clear();
    char pn;
    int i = 0;
    int r,f;
    for(r = RANK_8; r >= RANK_1; r--)
     for(f=FILE_A; f < MAX_FILE; f++)
      {
        pn = diagram[i];
        set_piece((RANK_NAMES)r,(FILE_NAMES)f,pn);
        i++;
      }

    to_move = (fen[FEN_2] == "w") ? WHITE : BLACK;

    return 0;
}

int cGAME_BOARD::add_move(cGAME_MOVE& move)
{
     
    // set the moves color
    move.set(to_move);

    // add move to list and increment index value
    game_list.push_back(move);

    // make the move on the current board
    make_move(move.from(),move.to() );

    return 0;       
}

int cGAME_BOARD::take_back()
{
    // if the list has a move - remove it
    if(game_list.size() > 0)
     {
        game_list.pop_back();
        #if 0
        // fix not needed ofr uci
        // but needed for xboard
        // take the last move off the board position
        cMove m = move_list.back();
        move_list.pop_back();
        cBoard::take_back(m);       
        #endif

     }

    return 0;
}


int cGAME_BOARD::make_move(SQUARE_NAMES start,SQUARE_NAMES end)
{

    cMove new_move(start,end,to_move);

    if(start == E1 && end == G1)
        white_castle_king_side(new_move);
    else if(start == E1 && end == C1)
        white_castle_queen_side(new_move);
    else if(start == E8 && end == G8)
        black_castle_king_side(new_move);
    else if(start == E8 && end == C8)
        black_castle_queen_side(new_move);
    else
      {      
        movePiece(new_move);
      }  

    // add the move to the list
    // move_list.push_back(new_move);
    // fix not needed for uci but needed for xboard
    return 0;
}



void cGAME_BOARD::display_history(ostream& out)
{
    // make sure that the list is not empty
    if(game_list.size() > 0)
     {
        // starting move number
        int line = 1;
        int to_move;

        out << "\t\tWHITE\t\tBLACK" << endl;

        // process each move in the list
        for( GAME_ITOR move_iter = game_list.begin(); move_iter!= game_list.end(); move_iter++)
         {
            // extract which side is making the move
            to_move = move_iter->get_side();

            // place move in correct column
            if(to_move == WHITE) 
                out <<"\t" << line++ << " \t" << move_iter->get_move();
            else
                out << "\t\t" << move_iter->get_move() << endl;
         }

    // clean up the output
    if(to_move == WHITE)
        out << "\t\t..." << endl;
    }         

}