// BGEditDoc.h : interface of the CBGEditDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_BGEDITDOC_H__DC8AAB0B_A406_11D2_9611_8C5D1421B743__INCLUDED_)
#define AFX_BGEDITDOC_H__DC8AAB0B_A406_11D2_9611_8C5D1421B743__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#define HINT_LOAD					1
#define HINT_SAVE					2
#define HINT_CLEAR				3

#define MAX_NON_PARTY			100

struct CHAR_BUFS
{
	// Length of the data allocated.
	UINT	nBufLen;

	// Character's data.
	unsigned char* pCharacter;
};

class CBGEditDoc : public CDocument
{
protected: // create from serialization only
	CBGEditDoc();
	DECLARE_DYNCREATE(CBGEditDoc)

// Attributes
public:
	// Returns TRUE if the file being edited is an exported character.
	BOOL IsExported()									{ return(m_bExported); }

	// Pointer to the header data of the saved game file. This is just a pointer
	// into the main data buffer, don't try to delete it. This pointer in only
	// valid when editing a saved game.
	FILE_HEADER* m_pFileHeader;

	// This is only valid when editing an exported character.
	CHR_HEADER* m_pChrHeader;

	// The saved game data.
	unsigned char* m_pData;

	// Size of the save game buffer.
	UINT m_nBufSize;

	// Full pathname of the file being edited.
	CString m_strFilename;

	// When a file is loaded the players are broken down into 
	// the following parts. The view modifies these individual
	// buffers by growing or shrinking them and changing the
	// data as needed. When the file is saved the document
	// reconstructs the file and adjusts all the file offsets
	// from these buffers.
	CHAR_BUFS m_character[6];

	// Variable list of characters which are NOT in the party.
	// Possible to edit these but DON't. I haven't made adjustments
	// in the saving for these varying in length. I'm only 
	// storing them separately because there are offsets in
	// each one that need to change.
	CHAR_BUFS m_nonPartyCharacter[MAX_NON_PARTY];

	// Calculates the length of the NPC data. This looks at all the
	// info in the header to figure out how long MY code expects the
	// record to be. This is NOT the length stored in the NPC_INFO
	// structure.
	UINT CalcNpcLength(NPC_HEADER *pHeader);

	// Pass in a buffer with a name, capitalizes first letter, makes the 
	// rest lower case.
	CString FixName(const char *pszName);

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBGEditDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	virtual void DeleteContents();
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CBGEditDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
	BOOL m_bExported;

// Generated message map functions
protected:
	//{{AFX_MSG(CBGEditDoc)
	afx_msg void OnFileOpen();
	afx_msg void OnFileSave();
	afx_msg void OnFileOpenChr();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BGEDITDOC_H__DC8AAB0B_A406_11D2_9611_8C5D1421B743__INCLUDED_)
