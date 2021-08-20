//*******************************************************************
//              
//  FILE:       cFEN.h
//              
//  AUTHOR:     Teemu Lätti
//              
//  PROJECT:    BASE_INTERFACE
//              
//  COMPONENT:  -
//              
//  DATE:       21.01.2004
//              
//  COMMENTS:   - FEN diagam class
//              
//              
//*******************************************************************

// Includes
#include <string>
using namespace std;

#ifndef __cFEN_H
#define __cFEN_H

enum FEN_FLDS
{
    FEN_1 = 0,
    FEN_2,
    FEN_3,
    FEN_4,
    FEN_5,
    FEN_6,
    MAX_FEN,
    
};

class cFEN
{
    private:
        string fen_data[6];
        string chess_diagram;

    public:
        void clear() { for (int i = FEN_1; i < MAX_FEN; i++) fen_data[i] = ""; }

        string& operator[](FEN_FLDS n) { return fen_data[n]; }

        string& diagram()
          {
            if(fen_data[FEN_1].size() != 0)
             {
                string& s = fen_data[FEN_1];    
                if(chess_diagram.size() == 0)
                 {
                    int l = s.size();    
                    for(int i = 0; i < l; i++)
                        switch(s[i])
                        {
                            case '/':break;
                            case '1':chess_diagram+="0"; break;
                            case '2':chess_diagram+="00"; break;
                            case '3':chess_diagram+="000"; break;
                            case '4':chess_diagram+="0000"; break;
                            case '5':chess_diagram+="00000"; break;
                            case '6':chess_diagram+="000000"; break;
                            case '7':chess_diagram+="0000000"; break;
                            case '8':chess_diagram+="00000000"; break;
                            default: chess_diagram+= s[i]; break;
                        }
                 }
             }
            return chess_diagram;
          }
};

#endif