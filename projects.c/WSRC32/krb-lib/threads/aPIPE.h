//*******************************************************************
//              
//  FILE:       aPIPE.h
//              
//  AUTHOR:     Keith R. Bergerstock
//              
//  PROJECT:    pipeTest
//              
//  COMPONENT:  - aPIPE
//              
//  DATE:       15.03.2004
//              
//  COMMENTS:   - anonymous pipe object with read and writer connect points
//              
//              
//*******************************************************************

#pragma warning (disable:4786)

// Includes

#include <windows.h>
#include "tSEMAPHORE.h"
#include "aPIPE_BUF.h"

#ifndef __aPIPE_h
#define __aPIPE_h

class aREADER;
class aWRITER;


// anonymous pipe ipc handle class
class aPIPE
{
    protected:
        HANDLE      read;
        HANDLE      write;
        tSEMAPHORE  has_data;

        friend class aREADER;
        friend class aWRITER;

    public:
        aPIPE();
        ~aPIPE();

        BOOL    create();

        HANDLE  gethandle()  { return has_data.GetHandle(); }
}; 

// the reader and writer class implement an anonymous pipe connection that
// read an writes a IPCBUFSIZE char array between them

// anonymous pipe writer class
class aWRITER
{
    protected:
        HANDLE      write;
        tSEMAPHORE& has_data;      

    public:
        aWRITER(aPIPE& p) : has_data(p.has_data)
         {
            write = p.write;
         }

        int writeBuf(aPIPE_BUF&);

		int	writeLine(char *line);
        int end();
};

// anonymous pipe reader class
class aREADER 
{
    protected:
        HANDLE      read;
        tSEMAPHORE& has_data;

        aPIPE_BUF buf;

    public:
        aREADER(aPIPE& p) : has_data(p.has_data) 
         {
            read = p.read;
         }

        HANDLE  gethandle()  { return has_data.GetHandle(); }

        int  readBuf(aPIPE_BUF&);

		int  readLine();

        char* bufContents() { return buf; }
};


class aTWO_WAY
{
    protected:
        aWRITER     op;                 // output pipe
        aREADER     ip;                 // input pipe
    public:        
        aTWO_WAY(aPIPE& aip, aPIPE& aop) : ip(aip), op(aop) {}
        
        HANDLE  gethandle()                 { return ip.gethandle(); }

        int  readBuf(aPIPE_BUF& ipc)        { return ip.readBuf(ipc); }

        int  writeBuf(aPIPE_BUF& ipc)       { return op.writeBuf(ipc); }
            
};

#endif


