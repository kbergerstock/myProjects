#
# Borland C++ IDE generated makefile
# Generated 5/28/2002 at 4:35:28 PM 
#
.AUTODEPEND


#
# Borland C++ tools
#
IMPLIB  = Implib
BCC32   = Bcc32 +BccW32.cfg 
BCC32I  = Bcc32i +BccW32.cfg 
TLINK32 = TLink32
ILINK32 = Ilink32
TLIB    = TLib
BRC32   = Brc32
TASM32  = Tasm32
#
# IDE macros
#


#
# Options
#
IDE_LinkFLAGS32 =  -LC:\dev\BC5\LIB -v -c
IDE_ResFLAGS32 = 
CompLocalOptsAtW32_wbasedlib =  -v -N- -R -He- -WM -W -H-
LinkerLocalOptsAtW32_wbasedlib =  -Tpe -aa -V4.0 -c
ResLocalOptsAtW32_wbasedlib = 
BLocalOptsAtW32_wbasedlib = 
CompOptsAt_wbasedlib = $(CompLocalOptsAtW32_wbasedlib)
CompInheritOptsAt_wbasedlib = -IC:\DEV\BC5\INC;WBASE -DWIN32_LEAN_AND_MEAN
LinkerInheritOptsAt_wbasedlib = -m
LinkerOptsAt_wbasedlib = $(LinkerLocalOptsAtW32_wbasedlib)
ResOptsAt_wbasedlib = $(ResLocalOptsAtW32_wbasedlib)
BOptsAt_wbasedlib = $(BLocalOptsAtW32_wbasedlib)
CompLocalOptsAtW32_controlsdlib =  -N- -WM -W -H-
LinkerLocalOptsAtW32_controlsdlib =  -Tpe -aa -V4.0 -c
ResLocalOptsAtW32_controlsdlib = 
BLocalOptsAtW32_controlsdlib = 
CompOptsAt_controlsdlib = $(CompLocalOptsAtW32_controlsdlib)
CompInheritOptsAt_controlsdlib = -IC:\DEV\BC5\INC;WBASE;ODB3;RSC;SHELL32 -DWIN32_LEAN_AND_MEAN
LinkerInheritOptsAt_controlsdlib = -m
LinkerOptsAt_controlsdlib = $(LinkerLocalOptsAtW32_controlsdlib)
ResOptsAt_controlsdlib = $(ResLocalOptsAtW32_controlsdlib)
BOptsAt_controlsdlib = $(BLocalOptsAtW32_controlsdlib)
CompLocalOptsAtW32_skeletondexe =  -v -R -N -WM -W
LinkerLocalOptsAtW32_skeletondexe =  -Tpe -aa -V4.0 -c
ResLocalOptsAtW32_skeletondexe = 
BLocalOptsAtW32_skeletondexe = 
CompOptsAt_skeletondexe = $(CompLocalOptsAtW32_skeletondexe)
CompInheritOptsAt_skeletondexe = -IC:\DEV\BC5\INC;WBASE;ODB3;RSC;SHELL32 -DWIN32_LEAN_AND_MEAN;_SKELETON_
LinkerInheritOptsAt_skeletondexe = -m
LinkerOptsAt_skeletondexe = $(LinkerLocalOptsAtW32_skeletondexe)
ResOptsAt_skeletondexe = $(ResLocalOptsAtW32_skeletondexe)
BOptsAt_skeletondexe = $(BLocalOptsAtW32_skeletondexe)
CompLocalOptsAtW32_shell32dexe =  -v- -R- -N- -x- -xd- -RT- -W -OS
LinkerLocalOptsAtW32_shell32dexe =  -Tpe -aa -V4.0 -c
ResLocalOptsAtW32_shell32dexe = 
BLocalOptsAtW32_shell32dexe = 
CompOptsAt_shell32dexe = $(CompLocalOptsAtW32_shell32dexe)
CompInheritOptsAt_shell32dexe = -IC:\DEV\BC5\INC;WBASE;ODB3;RSC;SHELL32 -DWIN32_LEAN_AND_MEAN
LinkerInheritOptsAt_shell32dexe = -B:400000 -m
LinkerOptsAt_shell32dexe = $(LinkerLocalOptsAtW32_shell32dexe)
ResOptsAt_shell32dexe = $(ResLocalOptsAtW32_shell32dexe)
BOptsAt_shell32dexe = $(BLocalOptsAtW32_shell32dexe)
CompLocalOptsAtW32_bm_testdexe =  -W
LinkerLocalOptsAtW32_bm_testdexe =  -Tpe -aa -V4.0 -c
ResLocalOptsAtW32_bm_testdexe = 
BLocalOptsAtW32_bm_testdexe = 
CompOptsAt_bm_testdexe = $(CompLocalOptsAtW32_bm_testdexe)
CompInheritOptsAt_bm_testdexe = -IC:\DEV\BC5\INC;WBASE;ODB3;RSC;BM_TEST -DWIN32_LEAN_AND_MEAN
LinkerInheritOptsAt_bm_testdexe = -m
LinkerOptsAt_bm_testdexe = $(LinkerLocalOptsAtW32_bm_testdexe)
ResOptsAt_bm_testdexe = $(ResLocalOptsAtW32_bm_testdexe)
BOptsAt_bm_testdexe = $(BLocalOptsAtW32_bm_testdexe)
CompLocalOptsAtW32_3dcurvesdexe =  -W -v -R -N -O-S -Z- -O- -O-e -O-l -O-b -O-W -O-m -O-p -O-c -O-v
LinkerLocalOptsAtW32_3dcurvesdexe =  -Tpe -aa -V4.0 -c -n
ResLocalOptsAtW32_3dcurvesdexe = 
BLocalOptsAtW32_3dcurvesdexe = 
CompOptsAt_3dcurvesdexe = $(CompLocalOptsAtW32_3dcurvesdexe)
CompInheritOptsAt_3dcurvesdexe = -IC:\DEV\BC5\INC;WBASE;RSC;3D -DWIN32_LEAN_AND_MEAN
LinkerInheritOptsAt_3dcurvesdexe = -m
LinkerOptsAt_3dcurvesdexe = $(LinkerLocalOptsAtW32_3dcurvesdexe)
ResOptsAt_3dcurvesdexe = $(ResLocalOptsAtW32_3dcurvesdexe)
BOptsAt_3dcurvesdexe = $(BLocalOptsAtW32_3dcurvesdexe)

#
# Dependency List
#
Dep_Wbase = \
   wbase.lib\
   controls.lib\
   skeleton.exe\
   shell32.exe\
   bm_test.exe\
   3dcurves.exe

Wbase : BccW32.cfg $(Dep_Wbase)
  echo MakeNode

Dep_wbasedlib = \
   C:\TMP\cwframe.obj\
   C:\TMP\appbase.obj\
   C:\TMP\windbase.obj\
   C:\TMP\statbar.obj\
   C:\TMP\about.obj\
   C:\TMP\modeless.obj\
   C:\TMP\dialog.obj\
   C:\TMP\dlgext.obj\
   C:\TMP\popfile.obj\
   C:\TMP\drawbm.obj\
   C:\TMP\gppchar.obj\
   C:\TMP\gppf.obj\
   C:\TMP\savebuf.obj\
   C:\TMP\strout.obj

wbase.lib : $(Dep_wbasedlib)
  $(TLIB) $< $(IDE_BFLAGS) $(BOptsAt_wbasedlib) @&&|
 -+C:\TMP\cwframe.obj &
-+C:\TMP\appbase.obj &
-+C:\TMP\windbase.obj &
-+C:\TMP\statbar.obj &
-+C:\TMP\about.obj &
-+C:\TMP\modeless.obj &
-+C:\TMP\dialog.obj &
-+C:\TMP\dlgext.obj &
-+C:\TMP\popfile.obj &
-+C:\TMP\drawbm.obj &
-+C:\TMP\gppchar.obj &
-+C:\TMP\gppf.obj &
-+C:\TMP\savebuf.obj &
-+C:\TMP\strout.obj
|

Dep_CcbTMPbcwframedobj = \
   wbase\cwframe.h\
   wbase\cwframe.cpp

C:\TMP\cwframe.obj : $(Dep_CcbTMPbcwframedobj)
  $(BCC32) -c @&&|
 $(CompOptsAt_wbasedlib) $(CompInheritOptsAt_wbasedlib) -o$@ wbase\cwframe.cpp
|

Dep_CcbTMPbappbasedobj = \
   wbase\appbase.h\
   wbase\appbase.cpp

C:\TMP\appbase.obj : $(Dep_CcbTMPbappbasedobj)
  $(BCC32) -c @&&|
 $(CompOptsAt_wbasedlib) $(CompInheritOptsAt_wbasedlib) -o$@ wbase\appbase.cpp
|

Dep_CcbTMPbwindbasedobj = \
   wbase\windbase.h\
   wbase\wmacros.h\
   wbase\windbase.cpp

C:\TMP\windbase.obj : $(Dep_CcbTMPbwindbasedobj)
  $(BCC32) -c @&&|
 $(CompOptsAt_wbasedlib) $(CompInheritOptsAt_wbasedlib) -o$@ wbase\windbase.cpp
|

Dep_CcbTMPbstatbardobj = \
   wbase\statbar.h\
   wbase\statbar.cpp

C:\TMP\statbar.obj : $(Dep_CcbTMPbstatbardobj)
  $(BCC32) -c @&&|
 $(CompOptsAt_wbasedlib) $(CompInheritOptsAt_wbasedlib) -o$@ wbase\statbar.cpp
|

Dep_CcbTMPbaboutdobj = \
   wbase\about.h\
   wbase\about.cpp

C:\TMP\about.obj : $(Dep_CcbTMPbaboutdobj)
  $(BCC32) -c @&&|
 $(CompOptsAt_wbasedlib) $(CompInheritOptsAt_wbasedlib) -o$@ wbase\about.cpp
|

Dep_CcbTMPbmodelessdobj = \
   wbase\modeless.h\
   wbase\modeless.cpp

C:\TMP\modeless.obj : $(Dep_CcbTMPbmodelessdobj)
  $(BCC32) -c @&&|
 $(CompOptsAt_wbasedlib) $(CompInheritOptsAt_wbasedlib) -o$@ wbase\modeless.cpp
|

Dep_CcbTMPbdialogdobj = \
   wbase\dialog.h\
   wbase\dialog.cpp

C:\TMP\dialog.obj : $(Dep_CcbTMPbdialogdobj)
  $(BCC32) -c @&&|
 $(CompOptsAt_wbasedlib) $(CompInheritOptsAt_wbasedlib) -o$@ wbase\dialog.cpp
|

C:\TMP\dlgext.obj :  wbase\dlgext.cpp
  $(BCC32) -c @&&|
 $(CompOptsAt_wbasedlib) $(CompInheritOptsAt_wbasedlib) -o$@ wbase\dlgext.cpp
|

Dep_CcbTMPbpopfiledobj = \
   wbase\popfile.h\
   wbase\popfile.cpp

C:\TMP\popfile.obj : $(Dep_CcbTMPbpopfiledobj)
  $(BCC32) -c @&&|
 $(CompOptsAt_wbasedlib) $(CompInheritOptsAt_wbasedlib) -o$@ wbase\popfile.cpp
|

C:\TMP\drawbm.obj :  wbase\drawbm.cpp
  $(BCC32) -c @&&|
 $(CompOptsAt_wbasedlib) $(CompInheritOptsAt_wbasedlib) -o$@ wbase\drawbm.cpp
|

C:\TMP\gppchar.obj :  wbase\gppchar.cpp
  $(BCC32) -c @&&|
 $(CompOptsAt_wbasedlib) $(CompInheritOptsAt_wbasedlib) -o$@ wbase\gppchar.cpp
|

C:\TMP\gppf.obj :  wbase\gppf.cpp
  $(BCC32) -c @&&|
 $(CompOptsAt_wbasedlib) $(CompInheritOptsAt_wbasedlib) -o$@ wbase\gppf.cpp
|

Dep_CcbTMPbsavebufdobj = \
   wbase\savebuf.h\
   wbase\savebuf.cpp

C:\TMP\savebuf.obj : $(Dep_CcbTMPbsavebufdobj)
  $(BCC32) -c @&&|
 $(CompOptsAt_wbasedlib) $(CompInheritOptsAt_wbasedlib) -o$@ wbase\savebuf.cpp
|

C:\TMP\strout.obj :  wbase\strout.cpp
  $(BCC32) -c @&&|
 $(CompOptsAt_wbasedlib) $(CompInheritOptsAt_wbasedlib) -o$@ wbase\strout.cpp
|

Dep_controlsdlib = \
   C:\TMP\wrt2file.obj\
   C:\TMP\kterm.obj\
   C:\TMP\keybuf.obj\
   C:\TMP\wstdio.obj\
   C:\TMP\timer.obj\
   C:\TMP\rptbox.obj\
   C:\TMP\cyield.obj\
   C:\TMP\y_log.obj\
   C:\TMP\log.obj\
   C:\TMP\cntr.obj\
   C:\TMP\cled.obj\
   C:\TMP\led.obj\
   C:\TMP\diamond.obj\
   C:\TMP\cvalue.obj\
   C:\TMP\cslide.obj

controls.lib : $(Dep_controlsdlib)
  $(TLIB) $< $(IDE_BFLAGS) $(BOptsAt_controlsdlib) @&&|
 -+C:\TMP\wrt2file.obj &
-+C:\TMP\kterm.obj &
-+C:\TMP\keybuf.obj &
-+C:\TMP\wstdio.obj &
-+C:\TMP\timer.obj &
-+C:\TMP\rptbox.obj &
-+C:\TMP\cyield.obj &
-+C:\TMP\y_log.obj &
-+C:\TMP\log.obj &
-+C:\TMP\cntr.obj &
-+C:\TMP\cled.obj &
-+C:\TMP\led.obj &
-+C:\TMP\diamond.obj &
-+C:\TMP\cvalue.obj &
-+C:\TMP\cslide.obj
|

C:\TMP\wrt2file.obj :  wbase\wrt2file.cpp
  $(BCC32) -c @&&|
 $(CompOptsAt_controlsdlib) $(CompInheritOptsAt_controlsdlib) -o$@ wbase\wrt2file.cpp
|

Dep_CcbTMPbktermdobj = \
   wbase\kterm.h\
   wbase\kterm.cpp

C:\TMP\kterm.obj : $(Dep_CcbTMPbktermdobj)
  $(BCC32) -c @&&|
 $(CompOptsAt_controlsdlib) $(CompInheritOptsAt_controlsdlib) -o$@ wbase\kterm.cpp
|

Dep_CcbTMPbkeybufdobj = \
   wbase\keybuf.h\
   wbase\tque.h\
   wbase\keybuf.cpp

C:\TMP\keybuf.obj : $(Dep_CcbTMPbkeybufdobj)
  $(BCC32) -c @&&|
 $(CompOptsAt_controlsdlib) $(CompInheritOptsAt_controlsdlib) -o$@ wbase\keybuf.cpp
|

Dep_CcbTMPbwstdiodobj = \
   wbase\wstdio.h\
   wbase\wstdio.cpp

C:\TMP\wstdio.obj : $(Dep_CcbTMPbwstdiodobj)
  $(BCC32) -c @&&|
 $(CompOptsAt_controlsdlib) $(CompInheritOptsAt_controlsdlib) -o$@ wbase\wstdio.cpp
|

Dep_CcbTMPbtimerdobj = \
   wbase\timer.h\
   wbase\timer.cpp

C:\TMP\timer.obj : $(Dep_CcbTMPbtimerdobj)
  $(BCC32) -c @&&|
 $(CompOptsAt_controlsdlib) $(CompInheritOptsAt_controlsdlib) -o$@ wbase\timer.cpp
|

Dep_CcbTMPbrptboxdobj = \
   wbase\rptbox.h\
   wbase\rptbox.cpp

C:\TMP\rptbox.obj : $(Dep_CcbTMPbrptboxdobj)
  $(BCC32) -c @&&|
 $(CompOptsAt_controlsdlib) $(CompInheritOptsAt_controlsdlib) -o$@ wbase\rptbox.cpp
|

Dep_CcbTMPbcyielddobj = \
   wbase\cyield.h\
   wbase\cyield.cpp

C:\TMP\cyield.obj : $(Dep_CcbTMPbcyielddobj)
  $(BCC32) -c @&&|
 $(CompOptsAt_controlsdlib) $(CompInheritOptsAt_controlsdlib) -o$@ wbase\cyield.cpp
|

Dep_CcbTMPby_logdobj = \
   wbase\y_log.h\
   wbase\y_log.cpp

C:\TMP\y_log.obj : $(Dep_CcbTMPby_logdobj)
  $(BCC32) -c @&&|
 $(CompOptsAt_controlsdlib) $(CompInheritOptsAt_controlsdlib) -o$@ wbase\y_log.cpp
|

Dep_CcbTMPblogdobj = \
   wbase\log.h\
   wbase\log.cpp

C:\TMP\log.obj : $(Dep_CcbTMPblogdobj)
  $(BCC32) -c @&&|
 $(CompOptsAt_controlsdlib) $(CompInheritOptsAt_controlsdlib) -o$@ wbase\log.cpp
|

Dep_CcbTMPbcntrdobj = \
   wbase\cntr.h\
   wbase\cntr.cpp

C:\TMP\cntr.obj : $(Dep_CcbTMPbcntrdobj)
  $(BCC32) -c @&&|
 $(CompOptsAt_controlsdlib) $(CompInheritOptsAt_controlsdlib) -o$@ wbase\cntr.cpp
|

Dep_CcbTMPbcleddobj = \
   wbase\cled.h\
   wbase\cled.cpp

C:\TMP\cled.obj : $(Dep_CcbTMPbcleddobj)
  $(BCC32) -c @&&|
 $(CompOptsAt_controlsdlib) $(CompInheritOptsAt_controlsdlib) -o$@ wbase\cled.cpp
|

Dep_CcbTMPbleddobj = \
   wbase\led.h\
   wbase\led.cpp

C:\TMP\led.obj : $(Dep_CcbTMPbleddobj)
  $(BCC32) -c @&&|
 $(CompOptsAt_controlsdlib) $(CompInheritOptsAt_controlsdlib) -o$@ wbase\led.cpp
|

Dep_CcbTMPbdiamonddobj = \
   wbase\diamond.h\
   wbase\diamond.cpp

C:\TMP\diamond.obj : $(Dep_CcbTMPbdiamonddobj)
  $(BCC32) -c @&&|
 $(CompOptsAt_controlsdlib) $(CompInheritOptsAt_controlsdlib) -o$@ wbase\diamond.cpp
|

Dep_CcbTMPbcvaluedobj = \
   wbase\cvalue.h\
   wbase\cvalue.cpp

C:\TMP\cvalue.obj : $(Dep_CcbTMPbcvaluedobj)
  $(BCC32) -c @&&|
 $(CompOptsAt_controlsdlib) $(CompInheritOptsAt_controlsdlib) -o$@ wbase\cvalue.cpp
|

Dep_CcbTMPbcslidedobj = \
   wbase\cslide.h\
   wbase\cslide.cpp

C:\TMP\cslide.obj : $(Dep_CcbTMPbcslidedobj)
  $(BCC32) -c @&&|
 $(CompOptsAt_controlsdlib) $(CompInheritOptsAt_controlsdlib) -o$@ wbase\cslide.cpp
|

Dep_skeletondexe = \
   C:\TMP\skeleton.obj\
   C:\TMP\datawin.obj\
   C:\TMP\cprocess.obj\
   C:\TMP\skeleton.res\
   controls.lib\
   wbase.lib

skeleton.exe : $(Dep_skeletondexe)
  $(ILINK32) @&&|
 /v $(IDE_LinkFLAGS32) $(LinkerOptsAt_skeletondexe) $(LinkerInheritOptsAt_skeletondexe) +
C:\dev\BC5\LIB\c0w32.obj+
C:\TMP\skeleton.obj+
C:\TMP\datawin.obj+
C:\TMP\cprocess.obj
$<,$*
controls.lib+
wbase.lib+
C:\dev\BC5\LIB\bidst.lib+
C:\dev\BC5\LIB\ctl3d32.lib+
C:\dev\BC5\LIB\import32.lib+
C:\dev\BC5\LIB\cw32mt.lib

C:\TMP\skeleton.res

|
Dep_CcbTMPbskeletondobj = \
   wbase\skeleton.h\
   wbase\skeleton.cpp

C:\TMP\skeleton.obj : $(Dep_CcbTMPbskeletondobj)
  $(BCC32) -c @&&|
 $(CompOptsAt_skeletondexe) $(CompInheritOptsAt_skeletondexe) -o$@ wbase\skeleton.cpp
|

Dep_CcbTMPbdatawindobj = \
   wbase\datawin.h\
   wbase\datawin.cpp

C:\TMP\datawin.obj : $(Dep_CcbTMPbdatawindobj)
  $(BCC32) -c @&&|
 $(CompOptsAt_skeletondexe) $(CompInheritOptsAt_skeletondexe) -o$@ wbase\datawin.cpp
|

Dep_CcbTMPbcprocessdobj = \
   wbase\cprocess.h\
   wbase\cprocess.cpp

C:\TMP\cprocess.obj : $(Dep_CcbTMPbcprocessdobj)
  $(BCC32) -c @&&|
 $(CompOptsAt_skeletondexe) $(CompInheritOptsAt_skeletondexe) -o$@ wbase\cprocess.cpp
|

C:\TMP\skeleton.res :  wbase\skeleton.rc
  $(BRC32) -R @&&|
 $(IDE_ResFLAGS32) $(ROptsAt_skeletondexe) $(CompInheritOptsAt_skeletondexe)  -FO$@ wbase\skeleton.rc
|
C:\TMP\about.res :  wbase\about.rc
  $(BRC32) -R @&&|
 $(IDE_ResFLAGS32) $(ROptsAt_skeletondexe) $(CompInheritOptsAt_skeletondexe)  -FO$@ wbase\about.rc
|
Dep_shell32dexe = \
   C:\TMP\shell32.obj\
   C:\TMP\hat.obj\
   C:\TMP\shell32.res\
   wbase.lib

shell32.exe : $(Dep_shell32dexe)
  $(ILINK32) @&&|
 /v $(IDE_LinkFLAGS32) $(LinkerOptsAt_shell32dexe) $(LinkerInheritOptsAt_shell32dexe) +
C:\dev\BC5\LIB\c0w32.obj+
C:\TMP\shell32.obj+
C:\TMP\hat.obj
$<,$*
wbase.lib+
C:\dev\BC5\LIB\ctl3d32.lib+
C:\dev\BC5\LIB\import32.lib+
C:\dev\BC5\LIB\cw32.lib

C:\TMP\shell32.res

|
Dep_CcbTMPbshell32dobj = \
   shell32\shell32.h\
   shell32\shell32.cpp

C:\TMP\shell32.obj : $(Dep_CcbTMPbshell32dobj)
  $(BCC32) -c @&&|
 $(CompOptsAt_shell32dexe) $(CompInheritOptsAt_shell32dexe) -o$@ shell32\shell32.cpp
|

C:\TMP\hat.obj :  shell32\hat.cpp
  $(BCC32) -c @&&|
 $(CompOptsAt_shell32dexe) $(CompInheritOptsAt_shell32dexe) -o$@ shell32\hat.cpp
|

C:\TMP\shell32.res :  shell32\shell32.rc
  $(BRC32) -R @&&|
 $(IDE_ResFLAGS32) $(ROptsAt_shell32dexe) $(CompInheritOptsAt_shell32dexe)  -FO$@ shell32\shell32.rc
|
Dep_bm_testdexe = \
   C:\TMP\bm_test.obj\
   C:\TMP\csprite.obj\
   C:\TMP\cbitmap.obj\
   C:\TMP\cprocess.obj\
   C:\TMP\bm_test.res\
   wbase.lib

bm_test.exe : $(Dep_bm_testdexe)
  $(ILINK32) @&&|
 /v $(IDE_LinkFLAGS32) $(LinkerOptsAt_bm_testdexe) $(LinkerInheritOptsAt_bm_testdexe) +
C:\dev\BC5\LIB\c0w32.obj+
C:\TMP\bm_test.obj+
C:\TMP\csprite.obj+
C:\TMP\cbitmap.obj+
C:\TMP\cprocess.obj
$<,$*
wbase.lib+
C:\dev\BC5\LIB\bidsf.lib+
C:\dev\BC5\LIB\import32.lib+
C:\dev\BC5\LIB\cw32.lib

C:\TMP\bm_test.res

|
Dep_CcbTMPbbm_testdobj = \
   bm_test\bm_test.h\
   bm_test\bm_test.cpp

C:\TMP\bm_test.obj : $(Dep_CcbTMPbbm_testdobj)
  $(BCC32) -c @&&|
 $(CompOptsAt_bm_testdexe) $(CompInheritOptsAt_bm_testdexe) -o$@ bm_test\bm_test.cpp
|

C:\TMP\csprite.obj :  bm_test\csprite.cpp
  $(BCC32) -c @&&|
 $(CompOptsAt_bm_testdexe) $(CompInheritOptsAt_bm_testdexe) -o$@ bm_test\csprite.cpp
|

Dep_CcbTMPbcbitmapdobj = \
   bm_test\cbitmap.h\
   bm_test\cbitmap.cpp

C:\TMP\cbitmap.obj : $(Dep_CcbTMPbcbitmapdobj)
  $(BCC32) -c @&&|
 $(CompOptsAt_bm_testdexe) $(CompInheritOptsAt_bm_testdexe) -o$@ bm_test\cbitmap.cpp
|

#
## The following section is generated by duplicate target C:\TMP\cprocess.obj.
##
#Dep_CcbTMPbcprocessdobj = \
#   wbase\cprocess.h\
#   wbase\cprocess.cpp
#
#C:\TMP\cprocess.obj : $(Dep_CcbTMPbcprocessdobj)
#  $(BCC32) -c @&&|
# $(CompOptsAt_bm_testdexe) $(CompInheritOptsAt_bm_testdexe) -o$@ wbase\cprocess.cpp
#|
#
##
## The above section is generated by duplicate target C:\TMP\cprocess.obj.
##
#
#
C:\TMP\bm_test.res :  bm_test\bm_test.rc
  $(BRC32) -R @&&|
 $(IDE_ResFLAGS32) $(ROptsAt_bm_testdexe) $(CompInheritOptsAt_bm_testdexe)  -FO$@ bm_test\bm_test.rc
|
Dep_3dcurvesdexe = \
   C:\TMP\3dcurves.obj\
   C:\TMP\pga6_3.obj\
   C:\TMP\surfaceb.obj\
   C:\TMP\surfacea.obj\
   C:\TMP\three_d1.obj\
   C:\TMP\demo3d.res\
   wbase.lib

3dcurves.exe : $(Dep_3dcurvesdexe)
  $(ILINK32) @&&|
 /v $(IDE_LinkFLAGS32) $(LinkerOptsAt_3dcurvesdexe) $(LinkerInheritOptsAt_3dcurvesdexe) +
C:\dev\BC5\LIB\c0w32.obj+
C:\TMP\3dcurves.obj+
C:\TMP\pga6_3.obj+
C:\TMP\surfaceb.obj+
C:\TMP\surfacea.obj+
C:\TMP\three_d1.obj
$<,$*
wbase.lib+
C:\dev\BC5\LIB\import32.lib+
C:\dev\BC5\LIB\cw32.lib

C:\TMP\demo3d.res

|
Dep_CcbTMPb3dcurvesdobj = \
   3d\3dcurves.h\
   3d\3dcurves.cpp

C:\TMP\3dcurves.obj : $(Dep_CcbTMPb3dcurvesdobj)
  $(BCC32) -c @&&|
 $(CompOptsAt_3dcurvesdexe) $(CompInheritOptsAt_3dcurvesdexe) -o$@ 3d\3dcurves.cpp
|

Dep_CcbTMPbpga6_3dobj = \
   3d\pga6_3.h\
   3d\pga6_3.cpp

C:\TMP\pga6_3.obj : $(Dep_CcbTMPbpga6_3dobj)
  $(BCC32) -c @&&|
 $(CompOptsAt_3dcurvesdexe) $(CompInheritOptsAt_3dcurvesdexe) -o$@ 3d\pga6_3.cpp
|

Dep_CcbTMPbsurfacebdobj = \
   3d\surfaceb.h\
   3d\surfaceb.cpp

C:\TMP\surfaceb.obj : $(Dep_CcbTMPbsurfacebdobj)
  $(BCC32) -c @&&|
 $(CompOptsAt_3dcurvesdexe) $(CompInheritOptsAt_3dcurvesdexe) -o$@ 3d\surfaceb.cpp
|

C:\TMP\surfacea.obj :  3d\surfacea.cpp
  $(BCC32) -c @&&|
 $(CompOptsAt_3dcurvesdexe) $(CompInheritOptsAt_3dcurvesdexe) -o$@ 3d\surfacea.cpp
|

Dep_CcbTMPbthree_d1dobj = \
   3d\three_d1.h\
   3d\three_d1.cpp

C:\TMP\three_d1.obj : $(Dep_CcbTMPbthree_d1dobj)
  $(BCC32) -c @&&|
 $(CompOptsAt_3dcurvesdexe) $(CompInheritOptsAt_3dcurvesdexe) -o$@ 3d\three_d1.cpp
|

C:\TMP\demo3d.res :  3d\demo3d.rc
  $(BRC32) -R @&&|
 $(IDE_ResFLAGS32) $(ROptsAt_3dcurvesdexe) $(CompInheritOptsAt_3dcurvesdexe)  -FO$@ 3d\demo3d.rc
|
# Compiler configuration file
BccW32.cfg : 
   Copy &&|
-w
-R
-v
-WM-
-vi
-H
-H=WBASE.csm
-v
-R
-N
-He-
-5
-x-
-xd-
-RT-
-k
-r-
-H-
| $@


