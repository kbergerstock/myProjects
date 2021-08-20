#-----------------------
# winhat.MAK make file
#-----------------------

WINCC   = bcc -ms -c -w-par -P -W -2
WINLINK = tlink /c /n /Tw /Lc:\dev\bc\lib c0ws
WINLIB  = import mathws cws
WINRC   = rc -r -i\dev\bc\inc

LISTOBJS = winhat1.obj drawhat1.obj

winhat2.exe : $(LISTOBJS) winhat1.def
     $(WINLINK) /m $(LISTOBJS), winhat2, winhat2, $(WINLIB), winhat2
     rc -t winhat2.exe

winhat1.obj : winhat1.cpp
     $(WINCC) winhat1.cpp

drawhat1.obj : drawhat1.cpp
    $(WINCC) drawhat1.cpp
