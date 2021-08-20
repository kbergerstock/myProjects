// -----------------------------------------------
//  demo.cpp
//  (c) K. R. Bergerstock,1996
//  version 1 - initial attempt
// --------------------------------------------------

#include <windows.h>

LRESULT CALLBACK _export MainWndProc (HWND , UINT , WPARAM, LPARAM);

inline void *GetPointer(HWND hWnd)
{
#if defined(__SMALL__) || defined(__MEDIUM__)
    return (void*)GetWindowWord(hWnd, 0);
#else
    return (void*)GetWindowLong(hWnd, 0);
#endif
}

inline void SetPointer(HWND hWnd, void *ptr)
{
#if defined(__SMALL__) || defined(__MEDIUM__)
    SetWindowWord(hWnd, 0, (WORD)ptr);
#else
    SetWindowLong(hWnd, 0, (LONG)ptr);
#endif
}


//--------------------------------------------------------------------

class MAIN
{
  private:
   HINSTANCE hInstance;
   HINSTANCE hPinstance;
   int nCmdShow;
  public:
  MAIN(HINSTANCE,HINSTANCE,int);
  int Run(void);
};

//-------------------------------------------------------------------- 

class Window
{
  protected:
   HINSTANCE  hInstance;
   HWND hWnd;
   
  public:

   void Show( int nCmdShow) { ShowWindow(hWnd, nCmdShow); }

   void Update(void) { UpdateWindow(hWnd); }

};

//------------------------------------------------------------------

class AppWin : public Window
{
  private:
    char*       szAppName;
    char*       szAppDesc;
            
    short cxClient,cyClient;            // holds width and height of client screen

  public:

    AppWin(HINSTANCE , char *, char *);

    void Register(void);

    void Create(void);

    void DrawHat(HWND hwnd);

    friend LRESULT CALLBACK _export MainWndProc (HWND, UINT, UINT, LONG) ;

};

