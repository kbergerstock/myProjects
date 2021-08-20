# Microsoft Developer Studio Project File - Name="WBASE32" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Static Library" 0x0104

CFG=WBASE32 - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "WBASE32.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "WBASE32.mak" CFG="WBASE32 - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "WBASE32 - Win32 Release" (based on "Win32 (x86) Static Library")
!MESSAGE "WBASE32 - Win32 Debug" (based on "Win32 (x86) Static Library")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
RSC=rc.exe

!IF  "$(CFG)" == "WBASE32 - Win32 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_MBCS" /D "_LIB" /YX /FD /c
# ADD CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_MBCS" /D "_LIB" /YX /FD /c
# ADD BASE RSC /l 0x409 /d "NDEBUG"
# ADD RSC /l 0x409 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo
# ADD LIB32 /nologo

!ELSEIF  "$(CFG)" == "WBASE32 - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_MBCS" /D "_LIB" /YX /FD /GZ /c
# ADD CPP /nologo /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_MBCS" /D "_LIB" /FD /GZ /c
# SUBTRACT CPP /YX
# ADD BASE RSC /l 0x409 /d "_DEBUG"
# ADD RSC /l 0x409 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo
# ADD LIB32 /nologo

!ENDIF 

# Begin Target

# Name "WBASE32 - Win32 Release"
# Name "WBASE32 - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\ABOUT.CPP
# End Source File
# Begin Source File

SOURCE=.\cAPPBASE.CPP
# End Source File
# Begin Source File

SOURCE=.\cDIALOG.CPP
# End Source File
# Begin Source File

SOURCE=.\cDLGWIN.cpp
# End Source File
# Begin Source File

SOURCE=.\cMODELESS.CPP
# End Source File
# Begin Source File

SOURCE=.\CWFRAME.CPP
# End Source File
# Begin Source File

SOURCE=.\Windbase.cpp
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=.\ABOUT.H
# End Source File
# Begin Source File

SOURCE=.\cAPPBASE.H
# End Source File
# Begin Source File

SOURCE=.\cDIALOG.H
# End Source File
# Begin Source File

SOURCE=.\cDLGWIN.h
# End Source File
# Begin Source File

SOURCE=.\cMODELESS.H
# End Source File
# Begin Source File

SOURCE=.\CWFRAME.H
# End Source File
# Begin Source File

SOURCE=.\WINDBASE.H
# End Source File
# Begin Source File

SOURCE=.\WM_MSGS.H
# End Source File
# Begin Source File

SOURCE=.\WMACROS.H
# End Source File
# End Group
# Begin Group "wBITMAPS"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\bitBlit.cpp
# End Source File
# Begin Source File

SOURCE=.\cBITMAP.CPP
# End Source File
# Begin Source File

SOURCE=.\cBITMAP.H
# End Source File
# Begin Source File

SOURCE=.\cSPRITE.CPP
# End Source File
# Begin Source File

SOURCE=.\cSPRITE.h
# End Source File
# End Group
# Begin Group "WCONTROLS"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\cDIAMOND.CPP
# End Source File
# Begin Source File

SOURCE=.\cDIAMOND.H
# End Source File
# Begin Source File

SOURCE=.\CLED.CPP
# End Source File
# Begin Source File

SOURCE=.\CLED.H
# End Source File
# Begin Source File

SOURCE=.\LED.CPP
# End Source File
# Begin Source File

SOURCE=.\LED.H
# End Source File
# Begin Source File

SOURCE=.\STATBAR.CPP
# End Source File
# Begin Source File

SOURCE=.\STATBAR.H
# End Source File
# Begin Source File

SOURCE=.\Wstdio.cpp
# End Source File
# Begin Source File

SOURCE=.\WSTDIO.H
# End Source File
# End Group
# Begin Group "misc"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\CRANDOM.H
# End Source File
# End Group
# End Target
# End Project
