
// cDX8obj.cpp: implementation of the cDX8obj class.
//
//////////////////////////////////////////////////////////////////////

#include "cDX9obj.h"
#include "dxerr9.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

cDX9obj::cDX9obj()
{
    g_pD3D = NULL;
    // Create the D3D object, which is needed to create the D3DDevice.
    if( NULL == ( g_pD3D = Direct3DCreate9( D3D_SDK_VERSION ) ) )
     {
        throw("unable to create DX9 object");
     }
}

cDX9obj::~cDX9obj()
{
    // release the object
    if( g_pD3D != NULL)
        g_pD3D->Release();
}


cDX9device::cDX9device()
{
	// Construct
    g_pd3dDevice = NULL;
}

cDX9device::~cDX9device()
{
	// Destruct
    if( g_pd3dDevice != NULL) 
        g_pd3dDevice->Release();
}

HRESULT cDX9device::create(cDX9obj& g_pD3D, HWND hWnd)
{

    // Set up the structure used to create the D3DDevice. Most parameters are
    // zeroed out. We set Windowed to TRUE, since we want to do D3D in a
    // window, and then set the SwapEffect to "discard", which is the most
    // efficient method of presenting the back buffer to the display.  And 
    // we request a back buffer format that matches the current desktop display 
    // format.
    D3DPRESENT_PARAMETERS d3dpp; 
    ZeroMemory( &d3dpp, sizeof(d3dpp) );
    d3dpp.Windowed = TRUE;
    d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;
    d3dpp.BackBufferFormat = D3DFMT_UNKNOWN;

    // Create the Direct3D device. Here we are using the default adapter (most
    // systems only have one, unless they have multiple graphics hardware cards
    // installed) and requesting the HAL (which is saying we want the hardware
    // device rather than a software one). Software vertex processing is 
    // specified since we know it will work on all cards. On cards that support 
    // hardware vertex processing, though, we would see a big performance gain 
    // by specifying hardware vertex processing.
    HRESULT hr = g_pD3D->CreateDevice( D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, hWnd,
                                      D3DCREATE_SOFTWARE_VERTEXPROCESSING,
                                      &d3dpp, &g_pd3dDevice );

    if(FAILED(hr) )
    {
        return E_FAIL;
    }

    // Device state would normally be set here

    return S_OK;

}
