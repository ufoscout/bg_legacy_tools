// LocationDlg.cpp : implementation file
//

#include "stdafx.h"
#include "BGEdit.h"
#include "QuadButton.h"
#include "LocationDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CLocationDlg dialog

CLocationDlg::CLocationDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CLocationDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CLocationDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CLocationDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CLocationDlg)
	DDX_Control(pDX, IDC_LOCATION, m_cbLocation);
	DDX_Control(pDX, IDC_AREA, m_cbArea);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CLocationDlg, CDialog)
	//{{AFX_MSG_MAP(CLocationDlg)
	ON_CBN_SELCHANGE(IDC_LOCATION, OnSelchangeLocation)
	ON_CBN_SELCHANGE(IDC_AREA, OnSelchangeArea)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CLocationDlg message handlers

BOOL CLocationDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();

	CString strError("Error subclassing quad button.");
	CString strTitle("Location Subclassing");
	if (!m_btnA1.SubclassDlgItem(IDC_QUAD_A1,this))
		MessageBox(strError,strTitle,MB_ICONWARNING);
	if (!m_btnA2.SubclassDlgItem(IDC_QUAD_A2,this))
		MessageBox(strError,strTitle,MB_ICONWARNING);
	if (!m_btnA3.SubclassDlgItem(IDC_QUAD_A3,this))
		MessageBox(strError,strTitle,MB_ICONWARNING);
	if (!m_btnA4.SubclassDlgItem(IDC_QUAD_A4,this))
		MessageBox(strError,strTitle,MB_ICONWARNING);
	if (!m_btnB1.SubclassDlgItem(IDC_QUAD_B1,this))
		MessageBox(strError,strTitle,MB_ICONWARNING);
	if (!m_btnB2.SubclassDlgItem(IDC_QUAD_B2,this))
		MessageBox(strError,strTitle,MB_ICONWARNING);
	if (!m_btnB3.SubclassDlgItem(IDC_QUAD_B3,this))
		MessageBox(strError,strTitle,MB_ICONWARNING);
	if (!m_btnB4.SubclassDlgItem(IDC_QUAD_B4,this))
		MessageBox(strError,strTitle,MB_ICONWARNING);
	if (!m_btnC1.SubclassDlgItem(IDC_QUAD_C1,this))
		MessageBox(strError,strTitle,MB_ICONWARNING);
	if (!m_btnC2.SubclassDlgItem(IDC_QUAD_C2,this))
		MessageBox(strError,strTitle,MB_ICONWARNING);
	if (!m_btnC3.SubclassDlgItem(IDC_QUAD_C3,this))
		MessageBox(strError,strTitle,MB_ICONWARNING);
	if (!m_btnC4.SubclassDlgItem(IDC_QUAD_C4,this))
		MessageBox(strError,strTitle,MB_ICONWARNING);
	if (!m_btnD1.SubclassDlgItem(IDC_QUAD_D1,this))
		MessageBox(strError,strTitle,MB_ICONWARNING);
	if (!m_btnD2.SubclassDlgItem(IDC_QUAD_D2,this))
		MessageBox(strError,strTitle,MB_ICONWARNING);
	if (!m_btnD3.SubclassDlgItem(IDC_QUAD_D3,this))
		MessageBox(strError,strTitle,MB_ICONWARNING);
	if (!m_btnD4.SubclassDlgItem(IDC_QUAD_D4,this))
		MessageBox(strError,strTitle,MB_ICONWARNING);

	m_btnA1.SetNumber(1);
	m_btnA2.SetNumber(2);
	m_btnA3.SetNumber(3);
	m_btnA4.SetNumber(4);
	m_btnB1.SetNumber(5);
	m_btnB2.SetNumber(6);
	m_btnB3.SetNumber(7);
	m_btnB4.SetNumber(8);
	m_btnC1.SetNumber(9);
	m_btnC2.SetNumber(10);
	m_btnC3.SetNumber(11);
	m_btnC4.SetNumber(12);
	m_btnD1.SetNumber(13);
	m_btnD2.SetNumber(14);
	m_btnD3.SetNumber(15);
	m_btnD4.SetNumber(16);

	int nItem;
	int j;
	for (int i=0;_mapInfo[i].pszArea;i++)
		if (_mapInfo[i].bArea)
		{
			nItem = m_cbArea.AddString(_mapInfo[i].pszDescription);
			m_cbArea.SetItemData(nItem,i);

			if (m_strArea == _mapInfo[i].pszArea)
				m_cbArea.SetCurSel(nItem);
			else
			{
				// Possible for the person to be in a location with a different
				// area code. Need to walk the AR values under this area to see
				// if there is a match as well.
				for (j=i+1;_mapInfo[j].pszArea && _mapInfo[j].bArea == FALSE;j++)
					if (m_strArea == _mapInfo[j].pszArea)
						m_cbArea.SetCurSel(nItem);
			}
		}

	if (m_cbArea.GetCurSel() == CB_ERR)
	{
		m_btnA1.DisableButtons();
	}
	else
	{
		FillLocations();
		int nCol = m_nMapX / QUADX;
		int nRow = m_nMapY / QUADY;
		if (nCol < 0 || nCol >= QUADX)
			nCol = 0;
		if (nRow < 0 || nRow >= QUADY)
			nRow = 0;
		int nNumber = nRow*4+nCol+1;
		m_btnA1.SetSelectedByNumber(nNumber);
	}
	
	return TRUE;  // return TRUE unless you set the focus to a control
}

void CLocationDlg::OnSelchangeArea() 
{
	FillLocations();
}

void CLocationDlg::FillLocations()
{
	m_cbLocation.ResetContent();
	int nAreaIndex = m_cbArea.GetCurSel();
	if (nAreaIndex == CB_ERR)
		return;
	nAreaIndex = m_cbArea.GetItemData(nAreaIndex);
	int nItem = m_cbLocation.AddString("(choose map quadrant)");
	m_cbLocation.SetItemData(nItem,MAPQUAD);
	m_cbLocation.SetCurSel(nItem);

	for (int i=nAreaIndex+1;_mapInfo[i].pszArea && !_mapInfo[i].bArea;i++)
	{
		nItem = m_cbLocation.AddString(_mapInfo[i].pszDescription);
		m_cbLocation.SetItemData(nItem,i);
	}

	OnSelchangeLocation();
}

void CLocationDlg::OnSelchangeLocation() 
{
	int nIndex = m_cbLocation.GetCurSel();
	if (nIndex == CB_ERR)
	{
		m_btnA1.DisableButtons();
		ShowQuadrant(-1);
		return;
	}
	if (m_cbLocation.GetItemData(nIndex) == MAPQUAD)
	{
		int nMapIndex = m_cbArea.GetItemData(m_cbArea.GetCurSel());
		m_btnA1.EnableButtons();
		ShowQuadrant(nMapIndex);
	}
	else
	{
		m_btnA1.DisableButtons();
		ShowQuadrant(m_cbLocation.GetItemData(nIndex));
	}
}

void CLocationDlg::ShowQuadrant(int nMapInfo)
{
	if (nMapInfo == -1)
	{
		m_btnA1.SetSelectedByNumber(100);
		return;
	}

	int nRow, nCol;
	nCol = _mapInfo[nMapInfo].nX / QUADX;
	nRow = _mapInfo[nMapInfo].nY / QUADY;

	if (nCol < 0 || nCol >= QUADX)
		nCol = 0;
	if (nRow < 0 || nRow >= QUADY)
		nRow = 0;

	int nNumber = nRow*4+nCol+1;
	m_btnA1.SetSelectedByNumber(nNumber);
}

void CLocationDlg::OnOK() 
{
	int nIndex = m_cbLocation.GetCurSel();
	if (nIndex == CB_ERR)
		return;
	int nMapInfo = m_cbLocation.GetItemData(nIndex);
	if (nMapInfo == MAPQUAD)
	{
		int nNumber = m_btnA1.GetSelectedNumber();
		if (nNumber < 1 || nNumber > 16)
			return;
		nNumber--;
		int nRow = nNumber / 4;
		int nCol = nNumber % 4;
		m_nMapX = nCol * QUADX + QUADX / 2;
		m_nMapY = nRow * QUADY + QUADY / 2;
		m_strArea = _mapInfo[m_cbArea.GetItemData(m_cbArea.GetCurSel())].pszArea;
	}
	else
	{
		m_nMapX = _mapInfo[nMapInfo].nX;
		m_nMapY = _mapInfo[nMapInfo].nY;
		m_strArea = _mapInfo[nMapInfo].pszArea;
	}
	
	CDialog::OnOK();
}

