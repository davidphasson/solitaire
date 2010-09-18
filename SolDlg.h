// SolDlg.h : header file
//

#if !defined(AFX_SOLDLG_H__7A878826_7224_11D6_B21F_CE91F39A7224__INCLUDED_)
#define AFX_SOLDLG_H__7A878826_7224_11D6_B21F_CE91F39A7224__INCLUDED_

#include "Cards.h"	// Added by ClassView
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CSolDlg dialog

class CSolDlg : public CDialog
{
// Construction
public:
	CSolDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CSolDlg)
	enum { IDD = IDD_SOL_DIALOG };
	CString	m_StatusText;
	CString	m_StatusText2;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSolDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CSolDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnNewGame();
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnCardbackSel();
	afx_msg void OnChgbackgrnd();
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	afx_msg void OnAboutBox();
	afx_msg void OnClose();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	// Drawing Functions
	
	void ShowBitmap(CDC *pdc, CPoint point, int hbitmap);
	//pre:  hbitmap exists in the resources in the executable
	//post: paints the bitmap at point using pdc
	void DrawStack(CCards *stack, CPoint point, CDC *pdc, int StackType, CRect & workingRect);
	//pre:  workingRect is the working area of stack and is up to date
	//post: draws a whole stack using ShowBitmap() at point, and updates workingRect to reflect
	//		the actual position and size of the drawn stack
	void DrawDecks(CDC *pdc);			// draws all decks in myStacks[12]
	void PartialRedraw(int numStack);	// draws only the numStack stack, without a full OnPaint()
	void saveScreenRect(CPoint point);	// saves a rectangle into h[71][96]
	void PaintBG(CDC * pdc);			// paints the colorBackGround onto the window using pdc

	int bmpID_CardBack;

	// Drag and Drop Functionality

	void DoActionDrag(int clickedStack, int clickedCard, CPoint point);
	//pre:  card has just been "picked up"
	//post: coordinates the moving process, ie calls StartMove, etc.
	bool DoActionDrop(int clickedStack, int clickedCard, CPoint point);
	//pre:  card has just been "dropped"
	//post: coordinates the moving process, ie calls ProcessMove, etc.
	
	COLORREF h[71][96];		// "Old Fashioned" style bitmap used for redraw
	CPoint lastMouse;		// buffer indicating where the mouse was last
	bool isDragging;		// Flag indicating that the card is "in the air"
	CPoint MouseOffset;		// Relative location of the mouse to the corner of the card
	int MovingID;			// ID of the bitmap of the moving card

		
	// Standard Click Functionality
	
	void DoAction(int clickedDeck, int clickedCard);
	//post:  Figures out what the user is trying to do to the deck/card, and calls Move
	//			functions accordingly.  Old Fashioned, depreciated
	void DoActionDlbClick(int clickedStack, int clickedCard);
	//post:	 This is a special case.  Either deals the deck a second time (dblClick override)
	//			or checks to see if the clicked card can go "up top" and does so


	// General Card Movement Functionality
	void MapClick(CPoint point, int lMouseDown);
	//pre:  lMouseDown is from 0-2 specifying if the button has single, double clicked
	//		or if it has just been released
	//post: Maps a click to the stack and card it is over, then processes the move based on
	//		lMouseDown
	bool StartMove(int fromStack, int fromCard);
	//post:	Copies appropriate cards from the stack into the tempStack buffer
	bool ProcessMove(int fromStack, int fromCard, int toStack);
	//post: Determines if the move is valid and does so if it is
	bool CancelMove(int fromStack, int fromCard);
	//post: Moves cards from buffer back to the source (if ProcessMove fails, etc)
	
	CCards tempStack;		// Where these "cards" are stored temporarily

	int c_moveFromCard;				// actually is the number of cards-1 that are getting moved
	int c_moveTo;					// specifying the stack the card(s) move to
	int c_moveFrom;					// specifying the stack the card(s) move from

	// Card dealing Functions
	void dealDeck();
	
	int iDealAmt;		// How many cards can be delt at a time
	int dealMod;		// Used to keep drawing functions from showing too many cards
	int dealModTEMP;		// Temporary change pending on whether the move completes
	
	// Game initialization
	void InitPads();				// Depreciated
	void UpdateStacks();			// Depreciated, used to update text boxes with deck info
	void InitializeGame();			// Called from Init to setup systemwide variables

	bool isRunning;					// False until a game is dealt
	
	// Appearance & Settings
	COLORREF colorBackGround;		// the current bgColor
	
	// the main data for the 12 stacks
	
	CCards myStacks[13];			// Actual Card Stacks
	CRect l_StacksInitial[13];		// Location of the base card for each
	CRect l_StacksRunning[13];		// Running rectangle of the area each stack occupies
	CRect l_StacksRunningLast[13];	// the Last StacksRunning (for redraw purposes)

	// Strings for Registry Settings
		
	CString		strSectionLabel;	// The Section this app stores it settings in under "funtaff"
	CString		strBGColorLabel;	// the name of the BackGround color setting
	CString		strCardColorLabel;	// the name of the CardBack label (huh?)

	// Other
	void didWeWin();				// Used for checking to see if the game is finished after every move
	
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SOLDLG_H__7A878826_7224_11D6_B21F_CE91F39A7224__INCLUDED_)
