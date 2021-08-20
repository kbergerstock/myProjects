// user interface tst file

#pragma warning(disable:4786)

#include "cInterface.h"
#include "cParse.h"

class cAPP
{
    private:
    cInterface ui;
    cPARSE parser;


    public:
      cAPP() { ui.echo(string("BRK CHESS ENGINE V1") ); }
     ~cAPP() {}
      
      void run();    
      int  dispatch(int r);

};

int cAPP::dispatch(int r)
{
    switch(r)
     {
        case XBOARD:
            ui.setXboardPrompt();
            r = 0;
            break;
        default:
            break;
     }
    return r;
}

void cAPP::run()
{
    int r = 0;
    int t = 0;
    string s;

    do {
            ui.fetchCmd();
            do{
                t = ui.get(s);
                r = dispatch(parser.search(s) );
              } while(t);   
            
        } while(r != BYE);
}

void main(void)
{

    cAPP engine;
    engine.run();

}