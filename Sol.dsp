# Microsoft Developer Studio Project File - Name="Sol" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Application" 0x0101

CFG=Sol - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "Sol.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "Sol.mak" CFG="Sol - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "Sol - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "Sol - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "Sol - Win32 Release"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 6
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /Yu"stdafx.h" /FD /c
# ADD CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Yu"stdafx.h" /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "NDEBUG" /d "_AFXDLL"
# ADD RSC /l 0x409 /d "NDEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /machine:I386
# ADD LINK32 /nologo /subsystem:windows /machine:I386

!ELSEIF  "$(CFG)" == "Sol - Win32 Debug"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 6
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "c:\sol\Debug"
# PROP Intermediate_Dir "c:\sol\Debug"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /Yu"stdafx.h" /FD /GZ /c
# ADD CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /FR /Yu"stdafx.h" /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "_DEBUG" /d "_AFXDLL"
# ADD RSC /l 0x409 /d "_DEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept
# ADD LINK32 /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept

!ENDIF 

# Begin Target

# Name "Sol - Win32 Release"
# Name "Sol - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\BackSelDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\Cards.cpp
# End Source File
# Begin Source File

SOURCE=.\Sol.cpp
# End Source File
# Begin Source File

SOURCE=.\Sol.rc
# End Source File
# Begin Source File

SOURCE=.\SolDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\StdAfx.cpp
# ADD CPP /Yc"stdafx.h"
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=.\BackSelDlg.h
# End Source File
# Begin Source File

SOURCE=.\Cards.h
# End Source File
# Begin Source File

SOURCE=.\Resource.h
# End Source File
# Begin Source File

SOURCE=.\Sol.h
# End Source File
# Begin Source File

SOURCE=.\SolDlg.h
# End Source File
# Begin Source File

SOURCE=.\StdAfx.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# Begin Source File

SOURCE=.\res\aceclubs.bmp
# End Source File
# Begin Source File

SOURCE=.\res\aceheart.bmp
# End Source File
# Begin Source File

SOURCE=.\res\acehrts.bmp
# End Source File
# Begin Source File

SOURCE=.\res\back.bmp
# End Source File
# Begin Source File

SOURCE=.\res\bicycleback01.bmp
# End Source File
# Begin Source File

SOURCE=.\res\bitmap1.bmp
# End Source File
# Begin Source File

SOURCE=.\res\bmp00001.bmp
# End Source File
# Begin Source File

SOURCE=.\res\bmp00002.bmp
# End Source File
# Begin Source File

SOURCE=.\res\bmp00003.bmp
# End Source File
# Begin Source File

SOURCE=.\res\bmp00004.bmp
# End Source File
# Begin Source File

SOURCE=.\res\bmp00005.bmp
# End Source File
# Begin Source File

SOURCE=.\res\bmp00006.bmp
# End Source File
# Begin Source File

SOURCE=.\res\bmp00007.bmp
# End Source File
# Begin Source File

SOURCE=.\res\bmp00008.bmp
# End Source File
# Begin Source File

SOURCE=.\res\bmp00009.bmp
# End Source File
# Begin Source File

SOURCE=.\res\bmp00010.bmp
# End Source File
# Begin Source File

SOURCE=.\res\bmp00011.bmp
# End Source File
# Begin Source File

SOURCE=.\res\bmp00012.bmp
# End Source File
# Begin Source File

SOURCE=.\res\bmp00013.bmp
# End Source File
# Begin Source File

SOURCE=.\res\bmp00014.bmp
# End Source File
# Begin Source File

SOURCE=.\res\bmp00015.bmp
# End Source File
# Begin Source File

SOURCE=.\res\bmp00016.bmp
# End Source File
# Begin Source File

SOURCE=.\res\bmp00017.bmp
# End Source File
# Begin Source File

SOURCE=.\res\bmp00018.bmp
# End Source File
# Begin Source File

SOURCE=.\res\bmp00019.bmp
# End Source File
# Begin Source File

SOURCE=.\res\bmp00020.bmp
# End Source File
# Begin Source File

SOURCE=.\res\bmp00021.bmp
# End Source File
# Begin Source File

SOURCE=.\res\bmp00022.bmp
# End Source File
# Begin Source File

SOURCE=.\res\bmp00023.bmp
# End Source File
# Begin Source File

SOURCE=.\res\bmp00024.bmp
# End Source File
# Begin Source File

SOURCE=.\res\bmp00025.bmp
# End Source File
# Begin Source File

SOURCE=.\res\bmp00026.bmp
# End Source File
# Begin Source File

SOURCE=.\res\bmp00027.bmp
# End Source File
# Begin Source File

SOURCE=.\res\bmp00028.bmp
# End Source File
# Begin Source File

SOURCE=.\res\bmp00029.bmp
# End Source File
# Begin Source File

SOURCE=.\res\bmp00030.bmp
# End Source File
# Begin Source File

SOURCE=.\res\bmp00031.bmp
# End Source File
# Begin Source File

SOURCE=.\res\bmp00032.bmp
# End Source File
# Begin Source File

SOURCE=.\res\bmp00033.bmp
# End Source File
# Begin Source File

SOURCE=.\res\bmp00034.bmp
# End Source File
# Begin Source File

SOURCE=.\res\bmp00035.bmp
# End Source File
# Begin Source File

SOURCE=.\res\bmp00036.bmp
# End Source File
# Begin Source File

SOURCE=.\res\bmp00037.bmp
# End Source File
# Begin Source File

SOURCE=.\res\bmp00038.bmp
# End Source File
# Begin Source File

SOURCE=.\res\bmp00039.bmp
# End Source File
# Begin Source File

SOURCE=.\res\bmp00040.bmp
# End Source File
# Begin Source File

SOURCE=.\res\bmp00041.bmp
# End Source File
# Begin Source File

SOURCE=.\res\bmp00042.bmp
# End Source File
# Begin Source File

SOURCE=.\res\bmp00043.bmp
# End Source File
# Begin Source File

SOURCE=.\res\bmp00044.bmp
# End Source File
# Begin Source File

SOURCE=.\res\bmp00045.bmp
# End Source File
# Begin Source File

SOURCE=.\res\bmp00046.bmp
# End Source File
# Begin Source File

SOURCE=.\res\bmp00047.bmp
# End Source File
# Begin Source File

SOURCE=.\res\bmp00048.bmp
# End Source File
# Begin Source File

SOURCE=.\res\bmp00049.bmp
# End Source File
# Begin Source File

SOURCE=.\res\bmp00050.bmp
# End Source File
# Begin Source File

SOURCE=.\res\hey.bmp
# End Source File
# Begin Source File

SOURCE=.\res\hey2.bmp
# End Source File
# Begin Source File

SOURCE=.\res\jackclub.bmp
# End Source File
# Begin Source File

SOURCE=.\res\kingclub.bmp
# End Source File
# Begin Source File

SOURCE=.\res\kingspad.bmp
# End Source File
# Begin Source File

SOURCE=.\res\psyc2_bk.bmp
# End Source File
# Begin Source File

SOURCE=.\res\psyc3_bk.bmp
# End Source File
# Begin Source File

SOURCE=.\res\sixclubs.bmp
# End Source File
# Begin Source File

SOURCE=.\res\Sol.ico
# End Source File
# Begin Source File

SOURCE=.\res\Sol.rc2
# End Source File
# Begin Source File

SOURCE=.\Solitaire.ico
# End Source File
# Begin Source File

SOURCE=.\res\tenspade.bmp
# End Source File
# Begin Source File

SOURCE=.\res\threedmd.bmp
# End Source File
# Begin Source File

SOURCE=.\res\untitled.bmp
# End Source File
# Begin Source File

SOURCE=.\res\untitled1.bmp
# End Source File
# Begin Source File

SOURCE=.\res\untitled2.bmp
# End Source File
# End Group
# End Target
# End Project
