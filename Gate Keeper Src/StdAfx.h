// stdafx.h : include file for standard system include files,
//  or project specific include files that are used frequently, but
//      are changed infrequently
//

#if !defined(AFX_STDAFX_H__DC8AAB07_A406_11D2_9611_8C5D1421B743__INCLUDED_)
#define AFX_STDAFX_H__DC8AAB07_A406_11D2_9611_8C5D1421B743__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#define VC_EXTRALEAN		// Exclude rarely-used stuff from Windows headers

#include <afxwin.h>         // MFC core and standard components
#include <afxext.h>         // MFC extensions
#include <afxdisp.h>        // MFC Automation classes
#include <afxdtctl.h>		// MFC support for Internet Explorer 4 Common Controls
#ifndef _AFX_NO_AFXCMN_SUPPORT
#include <afxcmn.h>			// MFC support for Windows Common Controls
#endif // _AFX_NO_AFXCMN_SUPPORT

#include <atlbase.h>

#include "DataFile.h"
#include "EditorStructs.h"

#define MAX_QTY_POTION			20
#define MAX_QTY					10000

#define HINIBBLE(byte)			((unsigned char)((byte >> 4) & 0x0F))
#define LONIBBLE(byte)			((unsigned char)(byte & 0x0F))

#define MAKEBYTE(loNib,hiNib)	((unsigned char)((hiNib << 4) | loNib))


extern CString _strGamePath;
extern BOOL _bAllowChrEdit;
extern ITEMTYPE _itemType[];
extern ITEMPOS _itemPos[NUM_ITEM_SLOTS];
extern KNOWNITEM _items[];
extern SPELLDESC _spells[];
extern RACE _race[];
extern SEX _sex[];
extern CLASS _class[];
extern MAGESPECIALTY _mageSpecialty[];
extern ALIGNMENT _alignment[];
extern THIEFRACEMOD _thiefRaceMod[NUM_THIEFRACEMOD];
extern THIEFDEXMOD _thiefDexMod[NUM_THIEFDEXMOD];
extern MAPINFO _mapInfo[];

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STDAFX_H__DC8AAB07_A406_11D2_9611_8C5D1421B743__INCLUDED_)
