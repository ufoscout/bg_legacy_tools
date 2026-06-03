// QuadButton.cpp : implementation file
//

#include "stdafx.h"
#include "BGEdit.h"
#include "QuadButton.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CQuadButton

#define QBM_DESELECT		WM_USER+100

// Retuns the value set in the button if the button is
// selected.
#define QBM_GETNUMBER	WM_USER+101

#define QBM_DISABLE		WM_USER+102
#define QBM_ENABLE		WM_USER+103

// Causes the button with the number passed in WPARAM to
// set itself as selected. All buttons not matching the
// number deselect themselves.
#define QBM_SELECTBYNUM	WM_USER+104

CQuadButton::CQuadButton()
{
	m_bSelected = FALSE;
	m_nNumber = 0;
}

CQuadButton::~CQuadButton()
{
}

BEGIN_MESSAGE_MAP(CQuadButton, CButton)
	//{{AFX_MSG_MAP(CQuadButton)
	ON_WM_LBUTTONUP()
	//}}AFX_MSG_MAP
	ON_MESSAGE(QBM_DESELECT,OnDeselect)
	ON_MESSAGE(QBM_GETNUMBER,OnGetNumber)
	ON_MESSAGE(QBM_DISABLE,OnDisableButton)
	ON_MESSAGE(QBM_ENABLE,OnEnableButton)
	ON_MESSAGE(QBM_SELECTBYNUM,OnSelectByNum)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CQuadButton message handlers

void CQuadButton::DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct) 
{
	CDC dc;
	
	if (!dc.Attach(lpDrawItemStruct->hDC))
		AfxMessageBox("Owner draw button failed.");

	if (lpDrawItemStruct->itemAction & ODA_DRAWENTIRE)
		DrawEntire(dc,lpDrawItemStruct->itemState,lpDrawItemStruct->rcItem);

	if (lpDrawItemStruct->itemAction & ODA_FOCUS)
		DrawFocus(dc,lpDrawItemStruct->itemState,lpDrawItemStruct->rcItem);

	if (lpDrawItemStruct->itemAction & ODA_SELECT)
		DrawSelect(dc,lpDrawItemStruct->itemState,lpDrawItemStruct->rcItem);

	dc.Detach();
}

void CQuadButton::DrawFocus(CDC &dc, UINT nItemState, RECT &r)
{
	DrawEntire(dc,nItemState,r);
	CRect rect(r);
	rect.DeflateRect(4,4);
	dc.DrawFocusRect(&rect);
}

void CQuadButton::DrawSelect(CDC &dc, UINT nItemState, RECT &r)
{
	DrawEntire(dc,nItemState,r);
}

void CQuadButton::DrawBorder(CDC &dc, UINT nItemState, RECT &r)
{

	if (nItemState & ODS_SELECTED)
	{
		CBrush brShadow;
		CBrush brBlack;
		brShadow.CreateStockObject(GRAY_BRUSH);
		brBlack.CreateStockObject(BLACK_BRUSH);
		CRect rect(r);
		dc.FrameRect(&rect,&brBlack);
		rect.DeflateRect(1,1);
		dc.FrameRect(&rect,&brShadow);
	}
	else
	{
		CRect rect(r);
		
		if (nItemState & ODS_FOCUS)
		{
			CBrush brBlack;
			brBlack.CreateStockObject(BLACK_BRUSH);
			dc.FrameRect(&rect,&brBlack);

			rect.DeflateRect(1,1);
		}

		CPen penBlack;
		CPen penWhite;
		CPen penShadow;
		CPen *pOldPen;

		penBlack.CreateStockObject(BLACK_PEN);
		penWhite.CreateStockObject(WHITE_PEN);
		penShadow.CreatePen(PS_SOLID,1,GetSysColor(COLOR_3DSHADOW));
		pOldPen = dc.SelectObject(&penWhite);

		dc.MoveTo(rect.left,rect.top);
		dc.LineTo(rect.right,rect.top);
		dc.MoveTo(rect.left,rect.top);
		dc.LineTo(rect.left,rect.bottom);
		dc.SelectObject(&penBlack);
		dc.MoveTo(rect.left,rect.bottom-1);
		dc.LineTo(rect.right,rect.bottom-1);
		dc.MoveTo(rect.right-1,rect.top);
		dc.LineTo(rect.right-1,rect.bottom);
		dc.SelectObject(&penShadow);
		dc.MoveTo(rect.left+1,rect.bottom-2);
		dc.LineTo(rect.right-2,rect.bottom-2);
		dc.MoveTo(rect.right-2,1);
		dc.LineTo(rect.right-2,rect.bottom-1);

		dc.SelectObject(pOldPen);
	}
}

void CQuadButton::DrawEntire(CDC &dc, UINT nItemState, RECT &r)
{
	CBrush brBackground;
	brBackground.CreateStockObject(LTGRAY_BRUSH);
	dc.FillRect(&r,&brBackground);

	DrawBorder(dc,nItemState,r);

	CString strText;
	GetWindowText(strText);

	CRect rect(r);
	CSize size(dc.GetTextExtent(strText));
	if (m_bSelected)
	{
		CRect rElipse(
			rect.Width()/2-size.cx/2-5,
			rect.Height()/2-size.cy/2-5,
			rect.Width()/2+size.cx/2+6,
			rect.Height()/2+size.cy/2+6);
		CBrush brSelect, brSelect2;
		brSelect.CreateSolidBrush(RGB(0,0,128));
		brSelect2.CreateSolidBrush(RGB(0,255,0));
		dc.FrameRect(&rElipse,&brSelect);
		rElipse.InflateRect(1,1);
		dc.FrameRect(&rElipse,&brSelect2);
		rElipse.InflateRect(1,1);
		dc.FrameRect(&rElipse,&brSelect);

	}
	dc.SetBkMode(TRANSPARENT);
	if (nItemState & ODS_DISABLED)
	{
		dc.SetTextColor(GetSysColor(COLOR_3DHILIGHT));
		dc.TextOut((rect.Width()/2-size.cx/2)+1,(rect.Height()/2-size.cy/2)+1,strText);
		dc.SetTextColor(GetSysColor(COLOR_GRAYTEXT));
		dc.TextOut(rect.Width()/2-size.cx/2,rect.Height()/2-size.cy/2,strText);
	}
	else
	{
		dc.SetTextColor(GetSysColor(COLOR_WINDOWTEXT));
		dc.TextOut(rect.Width()/2-size.cx/2,rect.Height()/2-size.cy/2,strText);
	}
}

void CQuadButton::OnLButtonUp(UINT nFlags, CPoint point) 
{
	CRect rect;
	GetClientRect(&rect);
	if (rect.PtInRect(point))
	{
		m_bSelected = TRUE;
		DeselectSiblings();
	}
	CButton::OnLButtonUp(nFlags, point);
}

void CQuadButton::SetSelected(BOOL bSelected)
{
	if (bSelected)
	{
		DeselectSiblings();
		m_bSelected = TRUE;
	}
	else
	{
		m_bSelected = FALSE;
		ForceRedraw();
	}
}

void CQuadButton::SetSelectedByNumber(int nNumber)
{
	GetParent()->SendMessageToDescendants(QBM_SELECTBYNUM,(WPARAM)nNumber,0,FALSE,FALSE);
}

void CQuadButton::DeselectSiblings()
{
	GetParent()->SendMessageToDescendants(QBM_DESELECT,0,(LPARAM)this,FALSE,FALSE);
}

LRESULT CQuadButton::OnDeselect(WPARAM,LPARAM pWnd)
{
	if ((CQuadButton*)pWnd != this && m_bSelected)
	{
		m_bSelected = FALSE;
		ForceRedraw();
	}
	return(TRUE);
}

LRESULT CQuadButton::OnGetNumber(WPARAM,LPARAM)
{
	if (m_bSelected)
		return(m_nNumber);
	return(0);
}

int CQuadButton::GetSelectedNumber()
{
	int nNumber;
	CWnd *pWnd = GetParent()->GetWindow(GW_CHILD);
	while(pWnd)
	{
		nNumber = pWnd->SendMessage(QBM_GETNUMBER,0,0);
		if (nNumber)
			return(nNumber);
		pWnd = pWnd->GetNextWindow();
	}
	return(0);
}

void CQuadButton::ForceRedraw()
{
	CRect rect;
	GetClientRect(&rect);
	InvalidateRect(&rect,FALSE);
	UpdateWindow();
}

void CQuadButton::DisableButtons()
{
	GetParent()->SendMessageToDescendants(QBM_DISABLE,0,0,FALSE,FALSE);
}

void CQuadButton::EnableButtons()
{
	GetParent()->SendMessageToDescendants(QBM_ENABLE,0,0,FALSE,FALSE);
}

LRESULT CQuadButton::OnEnableButton(WPARAM,LPARAM)
{
	EnableWindow(TRUE);
	return(0);
}

LRESULT CQuadButton::OnDisableButton(WPARAM,LPARAM)
{
	EnableWindow(FALSE);
	return(0);
}

LRESULT CQuadButton::OnSelectByNum(WPARAM wNumber,LPARAM)
{
	if ((int)wNumber == m_nNumber && !m_bSelected)
	{
		m_bSelected = TRUE;
		ForceRedraw();
	}
	else
		if ((int)wNumber != m_nNumber && m_bSelected)
		{
			m_bSelected = FALSE;
			ForceRedraw();
		}
	return(0);
}
