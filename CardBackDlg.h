#if !defined(AFX_CARDBACKDLG_H__9C4D5D0E_ADD3_47C6_905B_7CAA229D2664__INCLUDED_)
#define AFX_CARDBACKDLG_H__9C4D5D0E_ADD3_47C6_905B_7CAA229D2664__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// CardBackDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CCardBackDlg dialog

class CCardBackDlg : public CDialog
{
// Construction
public:
	CCardBackDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CCardBackDlg)
	enum { IDD = IDD_CARDBACK };
	int		m_RadioSelect;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCardBackDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CCardBackDlg)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CARDBACKDLG_H__9C4D5D0E_ADD3_47C6_905B_7CAA229D2664__INCLUDED_)
