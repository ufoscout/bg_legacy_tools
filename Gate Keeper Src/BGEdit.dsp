# Microsoft Developer Studio Project File - Name="BGEdit" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Application" 0x0101

CFG=BGEdit - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "BGEdit.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "BGEdit.mak" CFG="BGEdit - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "BGEdit - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "BGEdit - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "BGEdit - Win32 Release"

# PROP BASE Use_MFC 5
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 5
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /Yu"stdafx.h" /FD /c
# ADD CPP /nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /Yu"stdafx.h" /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "NDEBUG"
# ADD RSC /l 0x409 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /machine:I386
# ADD LINK32 /nologo /subsystem:windows /machine:I386 /out:"Release/GateKeeper.exe"

!ELSEIF  "$(CFG)" == "BGEdit - Win32 Debug"

# PROP BASE Use_MFC 5
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 6
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /Yu"stdafx.h" /FD /GZ /c
# ADD CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /D "_AFXDLL" /Yu"stdafx.h" /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "_DEBUG"
# ADD RSC /l 0x409 /d "_DEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept
# ADD LINK32 /nologo /subsystem:windows /debug /machine:I386 /out:"Debug/GateKeeper.exe" /pdbtype:sept

!ENDIF 

# Begin Target

# Name "BGEdit - Win32 Release"
# Name "BGEdit - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\AppearanceDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\BGEdit.cpp
# End Source File
# Begin Source File

SOURCE=.\BGEdit.rc
# End Source File
# Begin Source File

SOURCE=.\BGEditDoc.cpp
# End Source File
# Begin Source File

SOURCE=.\BGEditView.cpp
# End Source File
# Begin Source File

SOURCE=.\ChangeNameDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\CharacteristicsDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\DualClassDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\GameLocationDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\ItemsDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\LocationDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\MagicDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\MagicMemorizeDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\MainFrm.cpp
# End Source File
# Begin Source File

SOURCE=.\MiscAbilitiesDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\OpenCharacterDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\OpenGameDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\ProficienciesDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\QuadButton.cpp
# End Source File
# Begin Source File

SOURCE=.\SavingThrowDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\SpellsDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\StdAfx.cpp
# ADD CPP /Yc"stdafx.h"
# End Source File
# Begin Source File

SOURCE=.\ThiefSkillsDlg.cpp
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=.\AppearanceDlg.h
# End Source File
# Begin Source File

SOURCE=.\BGEdit.h
# End Source File
# Begin Source File

SOURCE=.\BGEditDoc.h
# End Source File
# Begin Source File

SOURCE=.\BGEditView.h
# End Source File
# Begin Source File

SOURCE=.\ChangeNameDlg.h
# End Source File
# Begin Source File

SOURCE=.\CharacteristicsDlg.h
# End Source File
# Begin Source File

SOURCE=.\DataFile.h
# End Source File
# Begin Source File

SOURCE=.\DualClassDlg.h
# End Source File
# Begin Source File

SOURCE=.\EditorStructs.h
# End Source File
# Begin Source File

SOURCE=.\GameLocationDlg.h
# End Source File
# Begin Source File

SOURCE=.\ItemsDlg.h
# End Source File
# Begin Source File

SOURCE=.\LocationDlg.h
# End Source File
# Begin Source File

SOURCE=.\MagicDlg.h
# End Source File
# Begin Source File

SOURCE=.\MagicMemorizeDlg.h
# End Source File
# Begin Source File

SOURCE=.\MainFrm.h
# End Source File
# Begin Source File

SOURCE=.\MiscAbilitiesDlg.h
# End Source File
# Begin Source File

SOURCE=.\OpenCharacterDlg.h
# End Source File
# Begin Source File

SOURCE=.\OpenGameDlg.h
# End Source File
# Begin Source File

SOURCE=.\ProficienciesDlg.h
# End Source File
# Begin Source File

SOURCE=.\QuadButton.h
# End Source File
# Begin Source File

SOURCE=.\Resource.h
# End Source File
# Begin Source File

SOURCE=.\SavingThrowDlg.h
# End Source File
# Begin Source File

SOURCE=.\SpellsDlg.h
# End Source File
# Begin Source File

SOURCE=.\StdAfx.h
# End Source File
# Begin Source File

SOURCE=.\ThiefSkillsDlg.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# Begin Source File

SOURCE=.\res\armor.bmp
# End Source File
# Begin Source File

SOURCE=.\res\arrow_do.bmp
# End Source File
# Begin Source File

SOURCE=.\res\arrow_up.bmp
# End Source File
# Begin Source File

SOURCE=.\res\belt.bmp
# End Source File
# Begin Source File

SOURCE=.\res\BGEdit.ico
# End Source File
# Begin Source File

SOURCE=.\res\BGEdit.rc2
# End Source File
# Begin Source File

SOURCE=.\res\BGEditDoc.ico
# End Source File
# Begin Source File

SOURCE=.\res\bitmap1.bmp
# End Source File
# Begin Source File

SOURCE=.\res\body.bmp
# End Source File
# Begin Source File

SOURCE=.\res\boots.bmp
# End Source File
# Begin Source File

SOURCE=.\res\cloak.bmp
# End Source File
# Begin Source File

SOURCE=.\res\gauntlet.bmp
# End Source File
# Begin Source File

SOURCE=.\res\helm.bmp
# End Source File
# Begin Source File

SOURCE=.\res\ico00001.ico
# End Source File
# Begin Source File

SOURCE=.\res\icon1.ico
# End Source File
# Begin Source File

SOURCE=.\res\necklace.bmp
# End Source File
# Begin Source File

SOURCE=.\res\quiver.bmp
# End Source File
# Begin Source File

SOURCE=.\res\ring.bmp
# End Source File
# Begin Source File

SOURCE=.\res\shield.bmp
# End Source File
# Begin Source File

SOURCE=.\res\Toolbar.bmp
# End Source File
# Begin Source File

SOURCE=.\res\weapon.bmp
# End Source File
# End Group
# Begin Source File

SOURCE=.\ReadMe.txt
# End Source File
# End Target
# End Project
