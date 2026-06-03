// CharacteristicsDlg.cpp : implementation file
//

#include "stdafx.h"
#include "BGEdit.h"
#include "CharacteristicsDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCharacteristicsDlg dialog


CCharacteristicsDlg::CCharacteristicsDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CCharacteristicsDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CCharacteristicsDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CCharacteristicsDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CCharacteristicsDlg)
	DDX_Control(pDX, IDC_MAGE_SPECIALTY, m_cboSpecialty);
	DDX_Control(pDX, IDOK, m_btnOk);
	DDX_Control(pDX, IDC_SEX, m_cboSex);
	DDX_Control(pDX, IDC_RACE, m_cboRace);
	DDX_Control(pDX, IDC_CLASS, m_cboClass);
	DDX_Control(pDX, IDC_ALIGNMENT, m_cboAlignment);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CCharacteristicsDlg, CDialog)
	//{{AFX_MSG_MAP(CCharacteristicsDlg)
	ON_CBN_SELCHANGE(IDC_CLASS, OnSelchangeClass)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCharacteristicsDlg message handlers

BOOL CCharacteristicsDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	int nIndex;
	int nItem;

	nIndex = 0;
	while(_sex[nIndex].pszSex)
	{
		nItem = m_cboSex.AddString(_sex[nIndex].pszSex);
		m_cboSex.SetItemData(nItem,_sex[nIndex].chSex);
		if (_sex[nIndex].chSex == m_chSex)
			m_cboSex.SetCurSel(nItem);
		nIndex++;
	}

	nIndex = 0;
	while(_race[nIndex].pszRace)
	{
		nItem = m_cboRace.AddString(_race[nIndex].pszRace);
		m_cboRace.SetItemData(nItem,_race[nIndex].chRace);
		if (_race[nIndex].chRace == m_chRace)
			m_cboRace.SetCurSel(nItem);
		nIndex++;
	}

	nIndex = 0;
	while(_alignment[nIndex].pszAlignment)
	{
		nItem = m_cboAlignment.AddString(_alignment[nIndex].pszAlignment);
		m_cboAlignment.SetItemData(nItem,_alignment[nIndex].chAlignment);
		if (_alignment[nIndex].chAlignment == m_chAlignment)
			m_cboAlignment.SetCurSel(nItem);
		nIndex++;
	}

	nIndex = 0;
	while(_class[nIndex].pszClass)
	{
		nItem = m_cboClass.AddString(_class[nIndex].pszClass);
		m_cboClass.SetItemData(nItem,_class[nIndex].chClass);
		if (_class[nIndex].chClass == m_chClass)
			m_cboClass.SetCurSel(nItem);
		nIndex++;
	}

	nIndex = 0;
	while(_mageSpecialty[nIndex].pszSpecialty)
	{
		nItem = m_cboSpecialty.AddString(_mageSpecialty[nIndex].pszSpecialty);
		m_cboSpecialty.SetItemData(nItem,_mageSpecialty[nIndex].nSpecialty);
		if (_mageSpecialty[nIndex].nSpecialty == m_nMageSpecialty)
			m_cboSpecialty.SetCurSel(nItem);
		nIndex++;
	}

	// Need to make sure there is a valid selection in each box.
	if (m_cboClass.GetCurSel() == CB_ERR || m_cboRace.GetCurSel() == CB_ERR ||
		 m_cboAlignment.GetCurSel() == CB_ERR || m_cboSex.GetCurSel() == CB_ERR ||
		 m_cboSpecialty.GetCurSel() == CB_ERR)
	{
		AfxMessageBox("Unknown value, unable to save changes.",MB_ICONWARNING);
		m_btnOk.EnableWindow(FALSE);
	}

	OnSelchangeClass();
	
	return TRUE;  // return TRUE unless you set the focus to a control
}

void CCharacteristicsDlg::OnSelchangeClass() 
{
	int nIndex = m_cboClass.GetCurSel();
	if (nIndex == CB_ERR)
	{
		m_cboSpecialty.EnableWindow(FALSE);
		return;
	}

	if (m_cboClass.GetItemData(nIndex) != CLASS_MAGE)
	{
		m_cboSpecialty.EnableWindow(FALSE);
		int nCount = m_cboSpecialty.GetCount();
		for (int i=0;i<nCount;i++)
			if (m_cboSpecialty.GetItemData(i) == MAGE_MAGE)
			{
				m_cboSpecialty.SetCurSel(i);
				break;
			}
	}
	else
		m_cboSpecialty.EnableWindow(TRUE);
}

void CCharacteristicsDlg::OnOK() 
{
	int nClassIndex = m_cboClass.GetCurSel();
	int nRaceIndex = m_cboRace.GetCurSel();
	int nAlignmentIndex = m_cboAlignment.GetCurSel();
	int nSexIndex = m_cboSex.GetCurSel();
	int nSpecialtyIndex = m_cboSpecialty.GetCurSel();

	if (nClassIndex == CB_ERR || nRaceIndex == CB_ERR || nAlignmentIndex == CB_ERR || nSexIndex == CB_ERR || nSpecialtyIndex == CB_ERR)
		return;

	m_chClass = (unsigned char)m_cboClass.GetItemData(nClassIndex);
	m_chRace = (unsigned char)m_cboRace.GetItemData(nRaceIndex);
	m_chAlignment = (unsigned char)m_cboAlignment.GetItemData(nAlignmentIndex);
	m_chSex = (unsigned char)m_cboSex.GetItemData(nSexIndex);
	m_nMageSpecialty = (short)m_cboSpecialty.GetItemData(nSpecialtyIndex);

	CDialog::OnOK();
}

