#include "cPROCESS.h"


cPROCESS::cPROCESS()
 {
        ZeroMemory( &si, sizeof(si) );
        // set the size of the structure
        si.cb = sizeof(si);
        // tell the application that we are setting the window display 
        // information within this structure
        si.dwFlags = STARTF_USESHOWWINDOW;
        // set the window display to HIDE
        si.wShowWindow = SW_HIDE;

        ZeroMemory( &pi, sizeof(pi) );
 }

cPROCESS::~cPROCESS()
 {
    // Wait until child process exits.
    WaitForSingleObject( pi.hProcess, INFINITE );

    // Close process and thread handles. 
    CloseHandle( pi.hProcess );
    CloseHandle( pi.hThread );
 }

int cPROCESS::launch(char * cmdLine)
 {
    // Start the child process. 
    if( !CreateProcess( NULL,   // No module name (use command line). 
            cmdLine,            // Command line. 
            NULL,               // Process handle not inheritable. 
            NULL,               // Thread handle not inheritable. 
            FALSE,              // Set handle inheritance to FALSE. 
            CREATE_NEW_CONSOLE, // No creation flags. 
            NULL,               // Use parent's environment block. 
            NULL,               // Use parent's starting directory. 
            &si,                // Pointer to STARTUPINFO structure.
            &pi )               // Pointer to PROCESS_INFORMATION structure.
      ) 
        throw( "CreateProcess failed." );
    else
        return 0;        
 }


/*
  // set the size of the structure
  StartupInfo.cb = sizeof(STARTUPINFO);
  // tell the application that we are setting the window display 
  // information within this structure
  StartupInfo.dwFlags = STARTF_USESHOWWINDOW;
  // set the window display to HIDE
  StartupInfo.wShowWindow = SW_HIDE;
*/