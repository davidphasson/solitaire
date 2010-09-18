// BackSelDlg.h - Header for the Background Select Dialog Class

#if !defined(AFX_BACKSELDLG_H__23CA07AC_E71D_4AA1_AB98_E8962692B6EC__INCLUDED_)
#define AFX_BACKSELDLG_H__23CA07AC_E71D_4AA1_AB98_E8962692B6EC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// BackSelDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CBackSelDlg dialog

class CBackSelDlg : public CDialog
{
// Construction
public:
	CBackSelDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CBackSelDlg)
	enum { IDD = IDD_CARDBACK };
	int		m_RadioSelect;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBackSelDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CBackSelDlg)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BACKSELDLG_H__23CA07AC_E71D_4AA1_AB98_E8962692B6EC__INCLUDED_)
