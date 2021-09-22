// dialog box extensions

#include "dlgext.h"

#ifndef __TFCVT_H
#include "tfcvt.h"
#endif

#ifndef __STDLIB_H
#include "stdlib.h"
#endif


float GetDlgItemFloat(HWND hDlg, int Control)
{
	float r = 0.0;
    char buf[40];
    if(GetDlgItemText(hDlg,Control,LPSTR(buf),39) )
    	r = (float)atof(buf);

	return r;
}

BOOL SetDlgItemFloat(HWND hDlg,int Control, float r)
{
	char buf[40];
    TFCVT<float> fcvt;
    fcvt.SetNumDigits(0);
    fcvt.Convert(r,LPSTR(buf));

    return SetDlgItemText(hDlg,Control,LPSTR(buf));
}