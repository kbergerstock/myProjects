#include "cGAME.h"
#include <algorithm>

using namespace std;
cGAME::cGAME()
{
    new_game();
}

cGAME::~cGAME()
{
    game_list.clear();    
}

// start a new game 
int cGAME::new_game()
{
    // empty the current list
    game_list.clear();          
    // create a new board
    cBoard nb;
    // creat an empty move
    cMove  nm;
    // fill in the new board with the start positions
    nb.NewGameBoard();
    // create a game position
    cGamePosition sp(nb,nm);
    // add the move to the list
    game_list.push_back(sp);
    // set ply to 0
    current_ply = 0;
    
    return  0;
}

int cGAME::make_move(SQUARE_NAMES from_square, SQUARE_NAMES to_square)
{
    // get a copy of the current position    
    cBoard cp = getPosition();
    // create a move structure from the input data
    cMove nm = cp.convert(from_square,to_square);
    
    return make_move(nm);
}

int cGAME::make_move(cMove &nm)
{
    int r = -1;
    // get a copy of the current position    
    cBoard current_board = getPosition();
    // erase the valid move list
    valid_moves.clear();
    // create a position for the current board
    cPosition np(current_board); 
    // create a valid move list
    np.move_gen(current_board.toMove(),valid_moves);
    // search valid move list for new move and add to move list if found
    MOVE_LIST::iterator l = find(valid_moves.begin() ,valid_moves.end(),nm);
    if(l != valid_moves.end() )
      {
            // update the position with the new move
            current_board.move(nm);
            // create a new game position
            cGamePosition ngp(current_board,nm);
            // add the game position to the list
            game_list.push_back(ngp);
            // advance the ply 
            current_ply++;

            r = 0;
      }

    return r;
}

int cGAME::take_back()
{
    if(current_ply > 0)
     {
        game_list.pop_back();
        current_ply--;
     }
    return 0;
}

void cGAME::list(cOUTPUT &out)
{
    char *w;
    string os;

    if(current_ply > 0)
     {
        for(int i = 0; i <= current_ply; i++)
          {
            w = convert(game_list[i].getMove() );
            os += w;
            
            if(game_list[i].getColor() == BLACK)
                {
                    out.echo(os);
                    os = "";
                }
            else
              os += "   "; 
    
          }  
        os += "...";
        out.echo(os);    
      }
    else
      out.echo("NO MOVES IN LIST");
}

void cGAME::outputReply(cOUTPUT & out)
{
    char *w;
    string os;
    if( current_ply > 0)
     {
        os += "move ";
        w = convertReply(game_list[current_ply].getMove() );
        os += w;
        out.echo(os);
     }
}