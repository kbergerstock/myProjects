//*******************************************************************
//              
//  FILE:       dx_test.cpp
//              
//  AUTHOR:     Keith R. Bergerstock
//              
//  PROJECT:    dx_test
//              
//  COMPONENT:  -
//              
//  DATE:       05.07.2005
//              
//  COMMENTS:   -
//              
//              
//*******************************************************************

#pragma warning (disable:4786)

// Includes

#include <ddraw.h>

#include "cAppBase.h"
#include "cDX9obj.h"
#include "HAT.h"
#include "cDXcanvas.h"

class cDXshell: public cAppWinFrame
{

    private:
        cDX9obj     dxObj;
        cDX9device  dxDevice;

        void Paint(HDC hdc);
    public:

        cDXshell(HINSTANCE hI,int nc) : cAppWinFrame(hI,nc)
         {
           // place windows specfic start up code here
           SetName("DX test","DX test shell");
           // register and create the window
           if(Create() )
             {
                // display the window
                Show(nc);
                // create the dx device tied to the window
                if(dxDevice.create(dxObj,hWnd) == S_OK)
                 {
                    // start the message loop
                    Run();
                 }     
             }  
         }
        ~cDXshell() 
         {
         }
};

int PASCAL WinMain (HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdLine, int nCmdShow)
{
    try
     {
        cDXshell app(hInstance,nCmdShow);        
     }
    catch(char * em)
     {
        MessageBox(NULL,em,"ERROR",MB_OK);
     }
    catch(...)
     {
        MessageBox(NULL,"Undefined application exception","ERROR",MB_OK);
     }

    
    return 0;
}

void cDXshell::Paint(HDC hdc)
{
    // Clear the backbuffer to a blue color
    dxDevice->Clear( 0, NULL, D3DCLEAR_TARGET, D3DCOLOR_XRGB(0,128,0), 1.0f, 0 );
    
    // Begin the scene
    if( SUCCEEDED( dxDevice->BeginScene() ) )
    {
        // Rendering of scene objects can happen here

        // step one create a canvas tied to the direct draw system
        cDX9canvas canvas(dxDevice,640,480);

        // step two pass the canvas to the draw har routine
        cHAT draw_hat(canvas);
    
        // End the scene
        dxDevice->EndScene();
    }

    // Present the backbuffer contents to the display
    dxDevice->Present( NULL, NULL, NULL, NULL );

}
