// cSERVER CLASS FUNCTIONS
#include "cSERVER.h"
#include "cPARSE.h"
#include <iostream>
#include <fstream>
using namespace std;

#define ESC 27

cSERVER::cSERVER(cWINSOCK& ws)
{
    // get the address of the server           
    ws.getServerAddress(DEFAULT_PORT,local);
    // open the socket
    listen.Open();
    // now bind to local address
    listen.Bind(local);
    // allocate socket list space
    socket_list = new cSERVER_SOCKET[FD_SETSIZE];
    num_sockets = 0;
}

cSERVER::~cSERVER()
{
    for(int i = 0; i < num_sockets; i++)
        if(socket_list[i].isActive() )
            socket_list[i].Close();

    listen.Close();
    // empty the vector
    delete[] socket_list;
}

void cSERVER::set_fds()
{
    fds.Zero();
    fds.Set(listen);
    for(int i = 0; i < num_sockets; i++)
     if(socket_list[i].isActive() )
        fds.Set(socket_list[i]);
}


int cSERVER::Accept()
{
    for(int i = 0; i < FD_SETSIZE; i++)
     if(! socket_list[i].isActive() )
       break;
    
    if(i < FD_SETSIZE)
     {
        socket_list[i].Accept(listen);
        socket_list[i].setNonBlocking();
        if(i >= num_sockets)
            num_sockets++;
        cout << " Accepted connection form " << socket_list[i].getFromAddress() \
            << ", port " << socket_list[i].getFromPort() << endl;
     }
    else
     {
        cout << "exceeded allowed number of connections " << endl;
     }




    return 0;
}


int cSERVER::Read(int i)
{
    int status = socket_list[i].Read();
    fds.Clr(socket_list[i]);

    if(status <= 0)
        {
            cout << "client closed connection" << endl;
        }
    else
        {
            cout << " recieved " << status << " bytes " << endl;
            // if the buffer contains a command reset the output to say command processed
            if( processCommands(socket_list[i].getBuf() ) )
                socket_list[i].Respond("COMMAND PROCESSED");
        }
    
    return status;        
}



int cSERVER::Write(int i)
{
    int status = 0;
    if(socket_list[i].getLen() )
     {
        cout << " echoing data back to client " << endl;
        status = socket_list[i].Echo("< sever response > ");
        fds.Clr(socket_list[i]);
      }
    return status;
}


void cSERVER::run()
{
    // set the connection to listening
    listen.Listen();
    // turn non blocking mode i
    listen.setNonBlocking();

    cout << "listening on port " << DEFAULT_PORT << endl;

    int status;

    while(1)
     {
        // init the fds foe theis pass
        set_fds();
        // listen
        status = listen.Select(fds,500);

        if(status > 0)
         {
            if(fds.isReadSet( listen) )
               { 
                    Accept();
                    status--;
               }
            if(status > 0)
                for(int i = 0; i < num_sockets; i++)
                 {
                    if(fds.isReadSet(socket_list[i]) )
                        Read(i);

                    if(fds.isWriteSet(socket_list[i]) )
                        Write(i);
                 }
         }

     }

    cout << " terminating server" << endl;
}

// command format is command,subcommand,data
int cSERVER::processCommands(char *_msg)
{
    int r = 0;
    cPARSE commands(_msg);
    int s1 = commands.command.find("save");
    int s2 = commands.command.find("SAVE");
    if(s1 >= 0 || s2 >= 0)
     {
        saveData(commands.subcommand,commands.data);
        r = 1;
     }
     
    return r;
}

int cSERVER::saveData(string fileName,string data)
{
    ofstream fout(fileName.c_str(),ios::app);
    fout << data << endl;

    return 0;
}
