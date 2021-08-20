# Microsoft Developer Studio Project File - Name="CHESS_ENGINE" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Console Application" 0x0103

CFG=CHESS_ENGINE - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "CHESS_ENGINE.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "CHESS_ENGINE.mak" CFG="CHESS_ENGINE - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "CHESS_ENGINE - Win32 Release" (based on "Win32 (x86) Console Application")
!MESSAGE "CHESS_ENGINE - Win32 Debug" (based on "Win32 (x86) Console Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
RSC=rc.exe

!IF  "$(CFG)" == "CHESS_ENGINE - Win32 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "c:\temp"
# PROP Intermediate_Dir "c:\temp\Release"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_CONSOLE" /D "_MBCS" /YX /FD /c
# ADD CPP /nologo /MT /W3 /GX /O2 /I "base_interface" /I "base_engine" /I "base_mods" /D "WIN32" /D "NDEBUG" /D "_CONSOLE" /D "_MBCS" /FD /c
# SUBTRACT CPP /YX
# ADD BASE RSC /l 0x409 /d "NDEBUG"
# ADD RSC /l 0x409 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /machine:I386
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /machine:I386

!ELSEIF  "$(CFG)" == "CHESS_ENGINE - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "c:\temp"
# PROP Intermediate_Dir "c:\temp\Debug"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /D "_MBCS" /YX /FD /GZ /c
# ADD CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /I "base_interface" /I "base_engine" /I "base_mods" /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /D "_MBCS" /FD /GZ /c
# SUBTRACT CPP /YX
# ADD BASE RSC /l 0x409 /d "_DEBUG"
# ADD RSC /l 0x409 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /debug /machine:I386 /pdbtype:sept
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /debug /machine:I386 /pdbtype:sept

!ENDIF 

# Begin Target

# Name "CHESS_ENGINE - Win32 Release"
# Name "CHESS_ENGINE - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\cAPP.cpp
# End Source File
# Begin Source File

SOURCE=.\chess_engine_main.cpp
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=.\cAPP.h
# End Source File
# Begin Source File

SOURCE=.\chess_engine_version.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# End Group
# Begin Group "BASE_ENGINE"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\BASE_ENGINE\attackSquares.cpp
# End Source File
# Begin Source File

SOURCE=.\BASE_ENGINE\board_constants.h
# End Source File
# Begin Source File

SOURCE=.\BASE_ENGINE\cBitArray.cpp
# End Source File
# Begin Source File

SOURCE=.\BASE_ENGINE\cBitArray.h
# End Source File
# Begin Source File

SOURCE=.\BASE_ENGINE\cBOARD.cpp
# End Source File
# Begin Source File

SOURCE=.\BASE_ENGINE\cBOARD.h
# End Source File
# Begin Source File

SOURCE=.\BASE_ENGINE\cFEN.h
# End Source File
# Begin Source File

SOURCE=.\BASE_ENGINE\cGAME_BOARD.cpp
# End Source File
# Begin Source File

SOURCE=.\BASE_ENGINE\cGAME_BOARD.h
# End Source File
# Begin Source File

SOURCE=.\BASE_ENGINE\cGAME_ENGINE.cpp
# End Source File
# Begin Source File

SOURCE=.\BASE_ENGINE\cGAME_ENGINE.h
# End Source File
# Begin Source File

SOURCE=.\BASE_ENGINE\cGAME_MOVE.cpp
# End Source File
# Begin Source File

SOURCE=.\BASE_ENGINE\cGAME_MOVE.h
# End Source File
# Begin Source File

SOURCE=.\BASE_ENGINE\cMove.h
# End Source File
# Begin Source File

SOURCE=.\BASE_ENGINE\cMOVE_GEN.cpp
# End Source File
# Begin Source File

SOURCE=.\BASE_ENGINE\cMOVE_GEN.h
# End Source File
# Begin Source File

SOURCE=.\BASE_ENGINE\cPositionTree.cpp
# End Source File
# Begin Source File

SOURCE=.\BASE_ENGINE\cPositionTree.h
# End Source File
# Begin Source File

SOURCE=.\BASE_ENGINE\cSquares.cpp
# End Source File
# Begin Source File

SOURCE=.\BASE_ENGINE\cSquares.h
# End Source File
# Begin Source File

SOURCE=.\BASE_MODS\Tarray.h
# End Source File
# End Group
# Begin Group "BASE_INTERFACE"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\BASE_INTERFACE\cCMD_LIST.cpp
# End Source File
# Begin Source File

SOURCE=.\BASE_INTERFACE\cCMD_LIST.h
# End Source File
# Begin Source File

SOURCE=.\BASE_INTERFACE\cCMD_PROCESSOR.cpp
# End Source File
# Begin Source File

SOURCE=.\BASE_INTERFACE\cCMD_PROCESSOR.h
# End Source File
# End Group
# Begin Source File

SOURCE=..\brk.txt
# End Source File
# Begin Source File

SOURCE=.\ubrk.txt
# End Source File
# End Target
# End Project
