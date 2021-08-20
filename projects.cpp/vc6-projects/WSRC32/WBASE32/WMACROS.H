// WMACROS.H
// MACRO FILE


// THIS MACRO SIMPLIFIES POSTING MESSAGES TIED TO FUNCTION KEYS TO
// THE MESSAGE HANDLER
#define HANDLE_KEY(KEY,MSG) \
  case(KEY): PostMessage(hwnd,WM_COMMAND,UINT(MSG),0L); break

// this macro simplifies posting messages to the system menu
#define sHANDLE_KEY(KEY,MSG) \
  case(KEY) : PostMessage(hwnd,WM_SYSCOMMAND,UINT(MSG),0L); break

// THIS MACRO SIMPLIFIES THE HANDLING OF COMMAND MESSAGES
#define HANDLE_COMMAND(COMMAND) \
	case(COMMAND) : on_##COMMAND(hwnd,hwndCtl,codeNotify);break
    
#define DEFINE_COMMAND(COMMAND) \
	void on_##COMMAND(HWND hwnd, HWND hwndCtl, UINT codeNotify)

#define CREATE_COMMAND(CLASS,COMMAND) \
	CLASS::on_##COMMAND(HWND hwnd, HWND hwndCtl, UINT codeNotify)

#define FORWARD_COMMAND(COMMAND) \
	on_##COMMAND(hwnd,hwndCtl,codeNotify)    


// this function simplifies printing a text string to the screen
void StrOut(HDC , int , int , LPSTR );

// this function simplifies optaining a floating point number from an ini file
double GetPrivateProfileFloat(char* section, char* key, char* ini);

void BlitBitMap(HDC hdc, HBITMAP hBitmap, short xStart, short yStart,DWORD dwRop);
void DrawBitMap(HDC hdc, HBITMAP hBitmap, short xStart, short yStart);
