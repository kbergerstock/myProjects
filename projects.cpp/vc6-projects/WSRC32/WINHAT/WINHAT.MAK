#-----------------------
# winhat.MAK make file
#-----------------------

WINCC 	= bcc32  -4 -c -w-par -P -W
WINLINK = tlink32 /Tpe /c /n /Lc:\dev\bc5\lib C0W32.obj
WINLIB	= import32.lib cw32.lib
WINRC 	= rc -r -ic:\dev\bc5\inc

LISTOBJS = winhat.obj hat.obj

winhat.exe : winhat.obj hat.obj winhat.def
		 $(WINLINK) /m winhat hat, winhat, winhat, $(WINLIB), winhat
		 rc -t winhat.exe

winhat.obj : winhat.c
		 $(WINCC) winhat.c

hat.obj : hat.c
		$(WINCC) hat.c
