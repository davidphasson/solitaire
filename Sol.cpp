// Sol.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "Sol.h"
#include "SolDlg.h"
#include "Cards.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


/////////////////////////////////////////////////////////////////////////////
// CSolApp

BEGIN_MESSAGE_MAP(CSolApp, CWinApp)
	//{{AFX_MSG_MAP(CSolApp)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG
	ON_COMMAND(ID_HELP, CWinApp::OnHelp)
END_MESSAGE_MAP()


CSolApp::CSolApp()
{
	
}


CSolApp theApp;


BOOL CSolApp::InitInstance()
{
//  Extra Stuff
//	AfxEnableControlContainer();

#ifdef _AFXDLL
//	Enable3dControls();			// Call this when using MFC in a shared DLL
#else
//	Enable3dControlsStatic();	// Call this when linking to MFC statically
#endif

	SetRegistryKey(_T("Funtaff"));

	CSolDlg dlg;
	m_pMainWnd = &dlg;
	int nResponse = dlg.DoModal();
	
	return FALSE;
}
