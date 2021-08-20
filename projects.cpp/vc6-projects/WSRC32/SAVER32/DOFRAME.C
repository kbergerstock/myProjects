#include <windows.h>
#include <stdlib.h>

// A simple routine to draw something on the screen
void DrawFrame(HWND hWnd)
{
	HDC hDC = GetDC(hWnd); // Get the DC for the window
    RECT rect;
	
    // If we didn't get a DC for the window then bail
    if (!hDC)
        return;

	// Get our drawing surface extents
    GetClientRect(hWnd, &rect);

    { // ****** Insert your own drawing code between here 

        int x,y,r,g,b;
	    HBRUSH hbr;

        // Get location for ellipse center point
	    x = rand() % rect.right;
	    y = rand() % rect.bottom;
	    
	    // Get color for ellipse
	    r = rand() % 256;
	    g = rand() % 256;
	    b = rand() % 256;

	    // Set the colors
	    SelectObject(hDC, GetStockObject(BLACK_PEN));
	    hbr = CreateSolidBrush(RGB(r,g,b));
	    if (hbr)
            SelectObject(hDC, hbr);

	    // Draw the ellipse
	    Ellipse(hDC, x-18, y-18, x+18, y+18);

	    //Clean up
	    SelectObject(hDC, GetStockObject(BLACK_BRUSH));
	    DeleteObject(hbr);

    } // ****** and here 

    ReleaseDC(hWnd, hDC);
}     

