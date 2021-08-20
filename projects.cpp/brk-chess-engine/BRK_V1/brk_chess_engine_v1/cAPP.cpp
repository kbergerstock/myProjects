
#include "cAPP.h"

cAPP::cAPP() : engine(ui)
{
    ui.echo("BRK CHESS ENGINE V1"); 
    pool.start(engine);
    run();
}

cAPP::~cAPP()
{
    pool.KillThreads();
}

int cAPP::dispatch(string& s)
{
    int r = parser.search(s);

    switch(r)
     {
        case XBOARD:
            ui.setXboardPrompt();
            break;

        case BYE:
            pool.KillThreads();
            break;
        case DISPLAY:
            engine.dumpBoard();
            break;
        case ON:
             engine.on();
             break;
        case OFF:
             engine.off();
             break;               
        case LIST:
            engine.list();
            break;
            
        // if we make it to here then try the move command in the engine
        default:
            if(r)   // if r is set then we have an unsupported command
             {
                ui.error(s);
             }
            else
             {
                // if the engine signal is set than it is still processing the last input
                // so throw this away - since it has to be an illegal move
               if(s.size() > 3 && !engine.isSet() )
                   r = engine.makeMove(s);
             }   
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
                t = ui.get(s);          // fetch a command string from the stdin
                r = dispatch(s);        // dispatch the command to the engine    
                while(!engine.isDone() )
                    Sleep(25);
              } while(t);   
            
        } while(r != BYE);
}
