//*******************************************************************
//              
//  FILE:       aPIPE.cpp
//              
//  AUTHOR:     Keith R. Bergerstock
//              
//  PROJECT:    pipeTest
//              
//  COMPONENT:  -
//              
//  DATE:       15.03.2004
//              
//  COMMENTS:   -
//              
//              
//*******************************************************************


// Includes

#include "aPIPE.h"

aPIPE::aPIPE()
{
	// Construct
    // default values 
    read  = 0;
    write = 0;    

    if( create() == 0 )
        throw " unable to create ipc anonymous pipe ";
}

aPIPE::~aPIPE()
{
	// Destruct
    // close open handles
    if(!read)
        CloseHandle(read);

    if(!write)
        CloseHandle(write);
}

BOOL aPIPE::create()
{
    int size = 100 * IPCBUFSIZE;
    // create an anonymous pipe
    return CreatePipe( &read,&write,NULL,size);
}

/* ----- aWRITER ----- */

int aWRITER::writeBuf(aPIPE_BUF& buf)
{
    int r = 0;

    // make sure that the prsious buffer has bben processed
    // while(has_data.isSet() )Sleep(25) ;
    
    // send data through pipe
    if(write != INVALID_HANDLE_VALUE)
     {
        unsigned long lin;
        r = WriteFile(write,buf,IPCBUFSIZE,&lin,NULL);
        has_data.inc();
     }

    return r;        
}

int aWRITER::writeLine(char *line)
{
    aPIPE_BUF buf;
    lstrcpy(buf,line);
    return writeBuf(buf);
}

int aWRITER::end()
{
    aPIPE_BUF buf;
    return writeBuf(buf);
}

/* ----- aREADER ----- */

int aREADER::readBuf(aPIPE_BUF& ipc_buf)
{
    ipc_buf[0] = 0;
    int r = 0;

    if( read != INVALID_HANDLE_VALUE)
     {
       unsigned long numberOfBytesRead;
       r = ReadFile(read,ipc_buf,IPCBUFSIZE,&numberOfBytesRead, NULL);
     }

    return r;
}

int aREADER::readLine()
{
    int r = readBuf(buf);
    if(buf[0] == 0 && buf[1] == 0)
            r = 0;
    return r;
}