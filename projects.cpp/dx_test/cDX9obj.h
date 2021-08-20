//*******************************************************************
//              
//  FILE:       cDX8obj.h
//              
//  AUTHOR:     Keith R. Bergerstock
//              
//  PROJECT:    dx_test
//              
//  COMPONENT:  cDX8obj
//              
//  DATE:       05.07.2005
//              
//  COMMENTS:   - interface for the cDX8obj class
//              
//              
//*******************************************************************

#pragma warning (disable:4786)

// Includes
#include <d3d9.h>

#ifndef __cDX8obj_h
#define __cDX8obj_h

class cDX9obj  
{
    private:
        // Used to create the D3DDevice
        LPDIRECT3D9            g_pD3D; 

    public:
	    cDX9obj();

	    virtual ~cDX9obj();

        const LPDIRECT3D9& operator->() { return g_pD3D; }

};


class cDX9device
{
    private:

        LPDIRECT3DDEVICE9       g_pd3dDevice;   // Our rendering device

    public:
        cDX9device();
        virtual ~cDX9device();

        HRESULT create(cDX9obj&,HWND);

        const LPDIRECT3DDEVICE9& operator->() { return g_pd3dDevice; }
};


#endif
