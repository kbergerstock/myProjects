#include "cSIMPLE_SERVER.H"

#include "cPARSE.h"
#include <iostream>
#include <fstream>
using namespace std;

#define ESC 27

cSIMPLE_SERVER::cSIMPLE_SERVER() : ws(WS22)
{
    if(ws.getStatus() == 0)
        cout << " connection to dll successful " << endl;

    // get the address of the server           
    ws.getServerAddress(DEFAULT_PORT,local);
    // open the socket
    listen.Open();
    // now bind to local address
    listen.Bind(local);
    // set the run flag
    run_flag = 1;
}

cSIMPLE_SERVER::~cSIMPLE_SERVER()
{
    server.Close();

    listen.Close();
}

int cSIMPLE_SERVER::Listen()
{
    // set the connection to listening
    return listen.Listen();
}

int cSIMPLE_SERVER::Accept()
{
    server.Accept(listen);
    cout << " Accepted connection form " << server.getFromAddress() \
        << ", port " << server.getFromPort() << endl;
    return 0;
}


int cSIMPLE_SERVER::Read()
{
    int status = server.Read();

    if(status <= 0)
        {
            cout << "client closed connection" << endl;
        }
    else
        {
            cout << " recieved " << status << " bytes " << endl;
            // if the buffer contains a command reset the output to say command processed
            if( processCommands(server.getBuf() ) )
                server.Respond("COMMAND PROCESSED");
        }
    
    return status;        
}



int cSIMPLE_SERVER::Write()
{
    int status = 0;
    if(server.getLen() )
     {
        cout << " echoing data back to client " << endl;
        status = server.Echo("< sever response > ");
      }
    return status;
}


void cSIMPLE_SERVER::run()
{
    // set the connection to listening
    Listen();

    cout << "listening on port " << DEFAULT_PORT << endl;

    int status;

    while(run_flag)
     {
        // accept connection
        status = Accept();
        
        do
         {
            status = Read();
            Write();

         } while(status > 0);
            
        
     }  

    cout << " terminating server" << endl;
}

// command format is command,subcommand,data
int cSIMPLE_SERVER::processCommands(char *_msg)
{
    int r = 0;
    cPARSE commands(_msg);

    if(r == 0)
     {
        int s1 = commands.command.find("save");
        int s2 = commands.command.find("SAVE");

        if(s1 >= 0 || s2 >= 0)
        {
            saveData(commands.subcommand,commands.data);
            r = 1;
        }
     }

    if(r == 0)
     {
        int s1 = commands.command.find("exit");
        int s2 = commands.command.find("EXIT");

        if(s1 >= 0 || s2 >= 0)
        {
            run_flag = 0;
            r = 2;
        }
     }
     
    return r;
}

int cSIMPLE_SERVER::saveData(string fileName,string data)
{
    ofstream fout(fileName.c_str(),ios::app);
    fout << data << endl;

    return 0;
}
