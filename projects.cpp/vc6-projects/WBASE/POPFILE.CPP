#ifndef  __POPFILE_H
#include "popfile.h"
#endif

POPFILE::POPFILE(HWND hWnd, LPSTR szFilter)
{
    int i = 0;
    while(szFilter[i] != '\1')
     { szfilter[i] = szFilter[i]; i++; }
     szfilter[i] = '\0';

	ofn.lStructSize         = sizeof( OPENFILENAME );
	ofn.hwndOwner           = hWnd;             // An invalid hWnd causes non-modality
	ofn.hInstance           = NULL;
	ofn.lpstrFilter         = szfilter;
	ofn.lpstrCustomFilter   = NULL;
	ofn.nMaxCustFilter      = 0;
	ofn.nFilterIndex        = 0;
	ofn.lpstrFile           = NULL;
	ofn.nMaxFile            = _MAX_PATH;
	ofn.lpstrFileTitle      = NULL;
	ofn.nMaxFileTitle       = _MAX_FNAME + _MAX_EXT;
	ofn.lpstrInitialDir     = NULL;
	ofn.lpstrTitle          = NULL;
	ofn.Flags               = 0;
	ofn.nFileOffset         = 0;
	ofn.nFileExtension      = 0;
	ofn.lpstrDefExt         = "*";
	ofn.lCustData           = 0l;
	ofn.lpfnHook            = NULL;
	ofn.lpTemplateName      = NULL;

}

BOOL POPFILE::OpenDlg(HWND hWnd, LPSTR lpstrFileName, LPSTR lpstrTitleName)
{
	ofn.hwndOwner       = hWnd;
	ofn.lpstrFile       = lpstrFileName;
	ofn.lpstrFileTitle  = lpstrTitleName;
	ofn.Flags           = OFN_FILEMUSTEXIST | OFN_HIDEREADONLY | OFN_PATHMUSTEXIST;

	return GetOpenFileName( &ofn );
}

BOOL POPFILE::SaveDlg(HWND hWnd, LPSTR lpstrFileName, LPSTR lpstrTitleName)
{
	ofn.hwndOwner       = hWnd;
	ofn.lpstrFile       = lpstrFileName;
	ofn.lpstrFileTitle  = lpstrTitleName;
	ofn.Flags           = OFN_OVERWRITEPROMPT;

	return GetSaveFileName( &ofn );
}

