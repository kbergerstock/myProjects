// cYIELD.h
// header file for class to display count totals
//

#include "cYield.h"

#if defined(__BORLANDC__)
#pragma argsused
#endif
cYIELD::cYIELD(HWND hwnd,LPSTR Name)
{
	SetSize(244,34,200,100);
    SetStyle(WS_VISIBLE | WS_CHILD );
    SetName("YIELD");
    Log.Init(Name);

    Cells = new cCELL[6];
}

cYIELD::~cYIELD()
{
	delete [] Cells;
}

HWND cYIELD::Create(HWND hwnd, int id)
{
	HWND tHwnd = cWinFrame::Create(hwnd,id);
    
    if(! Cells[0].IsRegistered() )
	    Cells[0].Register();	// register the cell class

    int left = 4;
    int top  =  4;
    int right = 64;
    int bottom = 20;

	if( tHwnd)
      {
        for(int i = 0; i < 3; i++ )
          {
          	Cells[i].SetSize(left,top,right,bottom);
            Cells[i].SetStyle(WS_VISIBLE | WS_CHILD );
        	Cells[i].Create(tHwnd,id+i+1);
            top += 25;
          }

        top = 4;
        left = 64;
        for(int i = 3; i < 6; i++ )
          {
          	Cells[i].SetSize(left,top,right,bottom);
            Cells[i].SetStyle(WS_VISIBLE | WS_CHILD );
        	Cells[i].Create(tHwnd,id+i+1);
            top += 25;
          }
		Cells[0].Draw(LPSTR("TOTAL"));
        Cells[1].Draw(LPSTR("GOOD"));
        Cells[2].Draw(LPSTR("YIELD"));
        Cells[5].SetResolution(2);
      }

    return tHwnd;
}

#if defined(__BORLANDC__)
#pragma argsused
#endif
void cYIELD::Paint(HWND hwnd,HDC hdc)
{
}

void cYIELD::Inc(int k)
{
	PartCounter.inc(k);
    Cells[3].Draw(long(PartCounter.GetTotal()) );
    Cells[4].Draw(long(PartCounter.GetGood()) );
    Cells[5].Draw(double(PartCounter.GetYield()) );
}

void cYIELD::Reset(void)
{
	// save out the current data
	data.total = PartCounter.GetTotal();
    data.good = PartCounter.GetGood();
    data.yield = PartCounter.GetYield();
    Log.Append(data);

	// reset the counters and display to zero
	PartCounter.reset();
    for(int i = 3; i < 6; i++)
    	Cells[i].Reset();
}


