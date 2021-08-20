// idialog.cpp
#include "iDialog.h"
#include "itimedlg.rh"

/**//* convert date components year, month, day to a julian date */

long date2jd(long year, long month, long day)
  {
  long y = year;
  long m = month;
  long d = day;
  long b,w;                    /* temp variables */
  long j;                      /* julian date */

  w = (m < 3 ? -1 : 0);
  j = ( (y+4800+w)/4*1461) + ((y+4800+w)%4*365);
  b = 367*(m-2-w*12)/12;
  j +=(b+(b < 0 ?1 :0) );
  b = (3*(y+4900+w)/100)/4;
  return(j + d - 32075 - b);
  }



iDialog::iDialog(HINSTANCE hInst , LPSTR lpszTemplate) : cDLGWIN(hInst)
{

	jd_2000 =  date2jd(2033,1,1);
    create(lpszTemplate);
}


iDialog::~iDialog()
{

}

void iDialog::UpdateDisplay(HWND hDlg)
{
	long jd;

     // retrieve the current system local time
    GetLocalTime(&now);
	// form the data
    jd = date2jd(now.wYear,now.wMonth,now.wDay);
    days = jd_2000 - jd;
    hours = 24-now.wHour;
    minutes = 60 - now.wMinute;
    seconds = 60 - now.wSecond;
    // now display it
    SetDlgItemInt(hDlg,IDC_EDIT1,days,false);
    SetDlgItemInt(hDlg,IDC_EDIT2,hours,false);
    SetDlgItemInt(hDlg,IDC_EDIT3,minutes,false);
    SetDlgItemInt(hDlg,IDC_EDIT4,seconds,false);

    // retrieve the current UTC (greenwich mean) time
    GetSystemTime(&now);
   	// form the data
    jd = date2jd(now.wYear,now.wMonth,now.wDay);
    days = jd_2000 - jd;
    hours = 24-now.wHour;
    minutes = 60 - now.wMinute;
    seconds = 60 - now.wSecond;
    // now display it
    SetDlgItemInt(hDlg,IDC_EDIT5,days,false);
    SetDlgItemInt(hDlg,IDC_EDIT6,hours,false);
    SetDlgItemInt(hDlg,IDC_EDIT7,minutes,false);
    SetDlgItemInt(hDlg,IDC_EDIT8,seconds,false);
}

BOOL iDialog::dlgProc(HWND hDlg, UINT msg, WPARAM wParam, LPARAM lParam)
{
	bool r = false;

	switch(msg)
     {
     	case WM_CLOSE:
        	KillTimer(hDlg,1);
        	PostQuitMessage(0);
        	DestroyWindow(hDlg);
            r = true;
            break;

	    case WM_WIN_CREATED:
        	SetTimer(hDlg,1,1000,NULL);
        	UpdateDisplay(hDlg);
        	r = true;
        	break;

        case WM_TIMER:
        	UpdateDisplay(hDlg);
           	r = true;
            break;

     }

	return r;
}
