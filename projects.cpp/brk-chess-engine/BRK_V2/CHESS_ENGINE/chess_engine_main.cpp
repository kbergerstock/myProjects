//*******************************************************************
//              
//  FILE:       chess_engine_main.cpp
//              
//  AUTHOR:     Keith R. Bergerstock
//              
//  PROJECT:    CHESS_ENGINE
//              
//  COMPONENT:  - main module
//              
//  DATE:       08.10.2003
//              
//  COMMENTS:   -
//              
//              
//*******************************************************************


// Includes

#include "cAPP.h"
#include "cSQUARES.h"
#include <iostream>
using namespace std;

cSQUARES  square_list;

int main(int argc, char* argv[])
{
   
    try 
     {
        // the application and user interface
        cAPP    app(argc,argv);            
     }
    catch(...)
     {
        cout << " unhandled exception " << endl;
     }
  
    return 0;
}
