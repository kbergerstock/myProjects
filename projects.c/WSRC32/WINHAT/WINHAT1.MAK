#-----------------------
# winhat.MAK make file
#-----------------------

WINCC   = bcc -ms -c -w-par -P -W -2
WINLINK = tlink /c /n /Tw /Lc:\dev\bc\lib c0ws
WINLIB  = import mathws cws
WINRC   = rc -r -i\dev\bc\inc

LISTOBJS = winhat1.obj drawhat.obj

winhat1.exe : $(LISTOBJS) winhat1.def
     $(WINLINK) /m $(LISTOBJS), winhat1, winhat1, $(WINLIB), winhat1
     rc -t winhat1.exe

winhat1.obj : winhat1.cpp
     $(WINCC) winhat1.cpp

drawhat.obj : drawhat.cpp
    $(WINCC) drawhat.cpp
