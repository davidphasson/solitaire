// CardBackDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Sol.h"
#include "CardBackDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCardBackDlg dialog


CCardBackDlg::CCardBackDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CCardBackDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CCardBackDlg)
	m_RadioSelect = -1;
	//}}AFX_DATA_INIT
}


void CCardBackDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CCardBackDlg)
	DDX_Radio(pDX, IDC_RADIO1, m_RadioSelect);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CCardBackDlg, CDialog)
	//{{AFX_MSG_MAP(CCardBackDlg)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCardBackDlg message handlers
