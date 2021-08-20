#pragma warning(disable:4786)

#ifndef __cAPP_H
#define __cAPP_H

#include "cInterface.h"
#include "cParse.h"
#include "cEngine.h"


class cAPP
{
    private:
    cInterface ui;
    cPARSE parser;
    cENGINE engine;
    threadPool pool;

    public:
      cAPP(); 
     ~cAPP();
      
      void run();    
      int  dispatch(string&);
};

#endif