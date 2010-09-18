// BackSelDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Sol.h"
#include "BackSelDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CBackSelDlg dialog


CBackSelDlg::CBackSelDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CBackSelDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CBackSelDlg)
	m_RadioSelect = -1;
	//}}AFX_DATA_INIT
}


void CBackSelDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CBackSelDlg)
	DDX_Radio(pDX, IDC_RADIO1, m_RadioSelect);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CBackSelDlg, CDialog)
	//{{AFX_MSG_MAP(CBackSelDlg)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CBackSelDlg message handlers
