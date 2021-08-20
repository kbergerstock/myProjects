//*******************************************************************
//              
//  FILE:       cNetConnection.h
//              
//  AUTHOR:     Keith R. Bergerstock
//              
//  PROJECT:    -
//              
//  COMPONENT:  - cNetConnection
//              
//  DATE:       17.02.2004
//              
//  COMMENTS:   - wrapper class around WNet funtions - to create a connection point over
//                the local network explicitly opens and closes a share  
//              
//              
//*******************************************************************

#pragma warning (disable:4786)

// Includes
#include <windows.h>
#include <winnetwk.h>

#ifndef __cNetConnection_h
#define __cNetConnection_h

class cNetConnection
{
    private:
        NETRESOURCE nr;                 // connection details
        DWORD err;  
    public:
        cNetConnection()
         {
            nr.dwType = RESOURCETYPE_DISK;
            nr.lpLocalName = NULL;
            nr.lpRemoteName = NULL;
            nr.lpProvider = NULL;
         }


        cNetConnection(LPCSTR nc, LPCSTR oper, LPCSTR pwd)
         {
            open(nc,oper,pwd);
         }

        ~cNetConnection()
         {
            close();
         }

        DWORD error()   { return err; }

        DWORD open(LPCSTR nc, LPCSTR oper, LPCSTR pwd)
         {
            nr.dwType = RESOURCETYPE_DISK;
            nr.lpLocalName = NULL;
            nr.lpRemoteName = const_cast<LPTSTR>(nc);
            nr.lpProvider = NULL;

            err = WNetAddConnection3(NULL, &nr ,pwd , oper , CONNECT_INTERACTIVE);

            if( err == ERROR_ALREADY_ASSIGNED || err == ERROR_DEVICE_ALREADY_REMEMBERED )
                err = 0;

            return err;
         }

        DWORD close()
         {
            err = WNetCancelConnection2(nr.lpRemoteName,CONNECT_UPDATE_PROFILE,TRUE);
            return err;
         }
}; 

#endif

