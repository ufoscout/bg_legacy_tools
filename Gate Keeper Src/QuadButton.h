#if !defined(AFX_QUADBUTTON_H__286BC661_AC3D_11D2_9611_8D2E41DF3543__INCLUDED_)
#define AFX_QUADBUTTON_H__286BC661_AC3D_11D2_9611_8D2E41DF3543__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// QuadButton.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CQuadButton window

class CQuadButton : public CButton
{
// Construction
public:
	CQuadButton();

// Attributes
public:
	void DrawEntire(CDC &dc, UINT nItemState, RECT &rect);
	void DrawFocus(CDC &dc, UINT nItemState, RECT &rect);
	void DrawSelect(CDC &dc, UINT nItemState, RECT &rect);
	void DrawBorder(CDC &dc, UINT nItemState, RECT &rect);

	void DeselectSiblings();

	// Sets the button as selected and deselects all the others.
	void SetSelected(BOOL bSelected);

	// Selects the button that has nNumber set.
	void SetSelectedByNumber(int nNumber);

	// This gets the number from the selected button, not necessarily THIS
	// button.
	int GetSelectedNumber();

	BOOL GetSelected()								{ return(m_bSelected); }

	void SetNumber(int nNumber)					{ m_nNumber = nNumber; }
	int  GetNumber()									{ return(m_nNumber); }


	// Affects all the Quad Buttons on the dialog.
	void DisableButtons();
	void EnableButtons();

	// Causes the button to invalidate and redraw itself.
	void ForceRedraw();

private:
	// Draws the button differnetly if this is chosen. This is differnt than
	// the button state passed in to draw the button.
	BOOL m_bSelected;

	// User defined value. Can be anything but 0.
	int m_nNumber;

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CQuadButton)
	public:
	virtual void DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CQuadButton();

	// Generated message map functions
protected:
	//{{AFX_MSG(CQuadButton)
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	//}}AFX_MSG
	afx_msg LRESULT OnDeselect(WPARAM,LPARAM);
	afx_msg LRESULT OnGetNumber(WPARAM,LPARAM);
	afx_msg LRESULT OnDisableButton(WPARAM,LPARAM);
	afx_msg LRESULT OnEnableButton(WPARAM,LPARAM);
	afx_msg LRESULT OnSelectByNum(WPARAM,LPARAM);

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_QUADBUTTON_H__286BC661_AC3D_11D2_9611_8D2E41DF3543__INCLUDED_)
