// Sol.h : main header file for the SOL application
//

#if !defined(AFX_SOL_H__7A878824_7224_11D6_B21F_CE91F39A7224__INCLUDED_)
#define AFX_SOL_H__7A878824_7224_11D6_B21F_CE91F39A7224__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CSolApp:
// See Sol.cpp for the implementation of this class
//

class CSolApp : public CWinApp
{
public:
	CSolApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSolApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CSolApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:

};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SOL_H__7A878824_7224_11D6_B21F_CE91F39A7224__INCLUDED_)
