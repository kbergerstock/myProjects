// cInterface.cpp
#include "cInterface.h"
#include <ctype.h>

void cOUTPUT::eol()
{
    Lock l(cs);
    cout << endl;
}

void cOUTPUT::echo(string & s)
{
    Lock l(cs);
    cout << s << endl;
    cout.flush();
}

void cOUTPUT::prompt(string & s)
{
    Lock l(cs);
    cout << s ;
    cout.flush();
}

void cOUTPUT::echo(const char *s)
{
    Lock l(cs);
    cout << s << endl;
    cout.flush();
}

void cOUTPUT::prompt(const char *s)
{
    Lock l(cs);
    cout << s ;
    cout.flush();
}
void cOUTPUT::echo(strstream& os)
{
    os << '\0';
    cout << os.str() << endl;
    cout.flush();
}

void cOUTPUT::dumpBoard(cBoard &board)
{
    if(!xboard_on)
     {
        int rank, file;
        Lock l(cs);
        cout << "  a b c d e f g h  " << endl;
        for(rank = 8; rank > 0; rank--)
           { 
             cout << rank <<  " " ;   
             for(file = 1; file <= 8; file++)
                    cout << board.get(rank,file) << " " ;
             cout << " " << endl;
            }   
    }
}

cInterface::cInterface() 
{
    setNormalPrompt(); 
}

cInterface::~cInterface()
{
}

// fetch commands from the user and store into a fifo (deque) list
void cInterface::fetchCmd()
{
    inputCmd = "";
    char chr_in;

    prompt(the_prompt);
    cmd_seq.clear();
    do {
         cin.get(chr_in);
         if(isspace(chr_in) )
            {
             cmd_seq.push_back(inputCmd);   
             inputCmd = "";
            }
          else
            inputCmd+= chr_in;   
            
       } while (chr_in != '\n');
}

// fetch the first command from the list
// the return val should be the size of the list
int cInterface::get(string&  s)
{

    s = cmd_seq[0];
    cmd_seq.pop_front();
    // if the fist char is a comment then dump the whole input and return 0
    if(s[0] == '*')
     {
        s = "";
        cmd_seq.clear();
     }
    return cmd_seq.size();
}

void cInterface::error(string& s)
{
    string os;
    os += "Error (unknown command): ";
    os += s;
    echo(os);
}