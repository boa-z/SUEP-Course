# Microsoft Developer Studio Project File - Name="TLV70233_FT_1SITE_A0_TW" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Dynamic-Link Library" 0x0102

CFG=TLV70233_FT_1SITE_A0_TW - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "TMPL.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "TMPL.mak" CFG="TLV70233_FT_1SITE_A0_TW - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "TLV70233_FT_1SITE_A0_TW - Win32 Debug" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe
# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir ".\Debug"
# PROP BASE Intermediate_Dir ".\Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 2
# PROP Use_Debug_Libraries 1
# PROP Output_Dir ".\Debug"
# PROP Intermediate_Dir ".\Debug"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MDd /W3 /Gm /GX /Zi /Zm200 /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /YX /c
# ADD CPP /nologo /Zp8 /W3 /GX /ZI /Zm200 /Od /I "./programs/multisite/,..\..\..\System\Include"  /D "_DEBUG,WIN32,_MT,_DLL,_WINDOWS,NT,USER_CODE,TEST_EXE,USER_FUN" /Yu"asl.h" /FD /c
# ADD BASE MTL /nologo /D "_DEBUG" /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "_DEBUG" /d "_AFXDLL"
# ADD RSC /l 0x409 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /dll /debug /machine:I386
# ADD LINK32  test.lib board.lib develop.lib handler.lib commdevice.lib intfal.lib errorprocess.lib msvcrtd.lib UserCode.lib Assistant.lib Gpib-32.obj fftdll.lib NIDAQmx.lib SmartVariable.lib CommonShared.lib StatusReport.lib /nologo /entry:"_DllMainCRTStartup@12" /subsystem:windows /dll /debug /machine:I386 /nodefaultlib:"libc.lib" /nodefaultlib:"libcmt.lib" /nodefaultlib:"msvcrt.lib" /nodefaultlib:"libcd.lib" /nodefaultlib:"libcmtd.lib" /libpath:"..\..\..\System\Lib"
# SUBTRACT LINK32 /map
# Begin Target

# Name "TLV70233_FT_1SITE_A0_TW - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "*.cpp"
# Begin Source File

SOURCE=.\T01_OS.CPP
# End Source File
# Begin Source File

SOURCE=.\T02_current_test.CPP
# End Source File
# Begin Source File

SOURCE=.\T03_VOLTAGE.CPP
# End Source File
# Begin Source File

SOURCE=.\T04_UVL0.CPP
# End Source File
# Begin Source File

SOURCE=.\T05_Ilimit_Ishort.CPP
# End Source File
# Begin Source File

SOURCE=.\T06_TIME.CPP
# End Source File
# Begin Source File

SOURCE=.\T07_OS_TEST.CPP
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "*.h"
# Begin Source File

SOURCE=.\T01_OS.H
# End Source File
# Begin Source File

SOURCE=.\T02_current_test.H
# End Source File
# Begin Source File

SOURCE=.\T03_VOLTAGE.H
# End Source File
# Begin Source File

SOURCE=.\T04_UVL0.H
# End Source File
# Begin Source File

SOURCE=.\T05_Ilimit_Ishort.H
# End Source File
# Begin Source File

SOURCE=.\T06_TIME.H
# End Source File
# Begin Source File

SOURCE=.\T07_OS_TEST.H
# End Source File
# End Group
# Begin Group "System Files"
# Begin Source File

SOURCE=.\BRD_CFG.CPP
# End Source File
# Begin Source File

SOURCE=.\DLLMAIN.CPP
# End Source File
# Begin Source File

SOURCE=.\FUNCTION.H
# End Source File
# Begin Source File

SOURCE=.\LIST.CPP
# End Source File
# Begin Source File

SOURCE=.\REGISTER.CPP
# End Source File
# Begin Source File

SOURCE=.\USER.CPP
# ADD CPP /Yc"asl.h"
# End Source File
# Begin Source File

SOURCE=.\USER.H
# End Source File
# PROP Default_Filter ""
# End Group
# End Target
# End Project
