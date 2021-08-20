//

#ifndef __WINDOWS_H
#define STRICT
#include <windows.h>
#endif


bool isMenuItemChecked(HWND hwnd, int menu_item_id)
{
	bool r = false;
	HMENU hMenu = GetMenu(hwnd);
    HMENU sMenu = GetSubMenu(hMenu,1);
    if(sMenu)
      {
    	int menu_state = GetMenuState(sMenu,menu_item_id,MF_BYCOMMAND);
        if(menu_state & MF_CHECKED)			// item is checked
         {
            CheckMenuItem(sMenu,menu_item_id, MF_BYCOMMAND | MF_UNCHECKED);
            r = false;
         }
        else								// item is not checked
         {
            CheckMenuItem(sMenu,menu_item_id, MF_BYCOMMAND | MF_CHECKED);
            r = true;
         }
	  }
	DrawMenuBar(hwnd);
    SetFocus(hwnd);
	return r;
}
