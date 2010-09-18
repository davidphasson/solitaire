// SolDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Sol.h"
#include "SolDlg.h"
#include "Cards.h"
#include "BackSelDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

//Deck styles (for drawing)
#define ST_DECK			0		// A deck that displays a few cards at a time
#define ST_TOPCARDUP	1		// A pile where you can see the face of the top card
#define ST_PLAYPILE		2		// A pile with face up and face down cards for playing	
#define CARD_WIDTH		71	
#define CARD_HEIGHT		96

// Globals
const int iCardOffsetH = 8;
const int iCardOffsetV = 5;		// Visible
const int iCardOffsetVv = 16;		// Not visible
const int iCardSpacing = 12;
COLORREF clrTransparent = RGB(0, 255, 0);
//


/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// CSolDlg dialog

CSolDlg::CSolDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CSolDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CSolDlg)
	m_StatusText = _T("");
	m_StatusText2 = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CSolDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSolDlg)
	DDX_Text(pDX, IDC_StatusText, m_StatusText);
	DDX_Text(pDX, IDC_StatusText2, m_StatusText2);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CSolDlg, CDialog)
	//{{AFX_MSG_MAP(CSolDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_COMMAND(ID_NEW_GAME, OnNewGame)
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONDOWN()
	ON_COMMAND(IDR_CARDBACK, OnCardbackSel)
	ON_COMMAND(ID_CHGBACKGRND, OnChgbackgrnd)
	ON_WM_LBUTTONDBLCLK()
	ON_COMMAND(ID_ABOUT, OnAboutBox)
	ON_WM_CLOSE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSolDlg message handlers

BOOL CSolDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	InitializeGame();

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CSolDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CSolDlg::OnPaint() 
{
	CPaintDC dc(this);  // device context for painting

	PaintBG(&dc);
	DrawDecks(&dc);
	
	
	if (IsIconic())
	{
	
		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
	
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CSolDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

// Start Real Code
// Events


void CSolDlg::OnLButtonUp(UINT nFlags, CPoint point) 
//post:  actions for when the user releases the left mouse button
{
	CClientDC dc(this);			// Set up device context for manual drawing
	int x, y;					// Counting Variables

	if(isDragging) {			// Only do stuff if an operation was in process
		isDragging = false;
		for(x=0; x<CARD_WIDTH; x++) {
			for(y=0; y<CARD_HEIGHT; y++) {
					dc.SetPixel(lastMouse.x+x, lastMouse.y+y, h[x][y]);
								// Repaint the square of the last card position
			}
		}
		MapClick(point, false);
								// Trigger the move functions when the button has "let go"
	}


	
	CDialog::OnLButtonUp(nFlags, point);
}



void CSolDlg::OnMouseMove(UINT nFlags, CPoint point) 
//post:  actions for whenever the mouse moves.  This happens to be where most 
//		of the card dragging code is
{
	if ((nFlags & MK_LBUTTON) == MK_LBUTTON) {
		int x,y;				// Counting variables
		COLORREF g[CARD_WIDTH][CARD_HEIGHT];		// bitmap buffer (manual array style)
		COLORREF r = RGB(0,0,0);
								// black color

		CClientDC dc(this);

		point = point - MouseOffset;
								// Adjust all operations to be relative to where the
								// Mouse is on the card

		CRect curr(point.x, point.y, point.x + CARD_WIDTH, point.y + CARD_HEIGHT);
								// 
		CRect curr2(lastMouse.x, lastMouse.y, lastMouse.x + CARD_WIDTH, lastMouse.y + CARD_HEIGHT);

		if(isDragging) {
			for(x=0; x<CARD_WIDTH; x++) {
				for(y=0; y<CARD_HEIGHT; y++) {
					if(! (curr.PtInRect( CPoint(lastMouse.x + x, lastMouse.y + y))))
					{
						dc.SetPixel(lastMouse.x+x, lastMouse.y+y, h[x][y]);
					}
				}
			}
		}

		for(x=0; x<CARD_WIDTH; x++) {
			for(y=0; y<CARD_HEIGHT; y++) {
				if(!(curr2.PtInRect( CPoint(point.x + x, point.y + y))))
				{
					g[x][y] = dc.GetPixel(point.x+x, point.y+y);	
				}
				else 
				{
					g[x][y] = h[point.x+x-lastMouse.x][point.y+y-lastMouse.y];
				}
				
			}
		}
	
		for(x=0; x<CARD_WIDTH; x++) {
			for(y=0; y<CARD_HEIGHT; y++) {
				h[x][y] = g[x][y];
			}
		}

		if(isDragging) 
			ShowBitmap(&dc, point, MovingID);
		

		lastMouse = point;

	
	}
	

	CDialog::OnMouseMove(nFlags, point);
}

void CSolDlg::OnLButtonDown(UINT nFlags, CPoint point) 
{
	lastMouse = point;
	isDragging=false;

	if(isRunning)
		MapClick(point, true);

	saveScreenRect(point);
	
	CDialog::OnLButtonDown(nFlags, point);
}

void CSolDlg::OnLButtonDblClk(UINT nFlags, CPoint point) 
{
	lastMouse = point;
	isDragging=false;

	if(isRunning)
		MapClick(point, 2);

	saveScreenRect(point);
	
	CDialog::OnLButtonDblClk(nFlags, point);
}

// Misc

void CSolDlg::OnNewGame() 
// Deal a new game
{
	isRunning = TRUE;
	card temp;

	iDealAmt = 3;

	for(int z=0; z<13; z++) {
		myStacks[z].Flush();
	}
	myStacks[0].CreateDeck();
	myStacks[0].Shuffle();

	for(int x=1; x<8; x++) {
		for(int y=x; y<8; y++) {
			temp = myStacks[0].FetchBottomCard(false);
			if(y != x) temp.isVisible = false;			
			myStacks[y].PutCard(temp);
			Invalidate();
	
			
		}
	}
}


// Drawing

void CSolDlg::ShowBitmap(CDC *pdc, CPoint point, int hbitmap)
{

	CDC dcMem;
	dcMem.CreateCompatibleDC(pdc);


	CBitmap* pBitmap = new CBitmap;
	CBitmap maskBitmap;
	if(pBitmap->LoadBitmap(hbitmap))
	{

		BITMAP bm;
		pBitmap->GetBitmap(&bm);

		CBitmap *pOldBitmap = (CBitmap*)dcMem.SelectObject(pBitmap);

	//	TransparentBlt(pdc->m_hDC, point.x, point.y, (point.x + bm.bmWidth), (point.y + bm.bmHeight), &dcMem.m_hDC, 0, 0, bm.bmWidth, bm.bmHeight, clrTransparent);
		//if(maskBitmap.LoadBitmap(IDB_CARDMASK)) {
		//	if(pdc->MaskBlt(point.x, point.y, (bm.bmWidth), (bm.bmHeight), &dcMem, 0, 0, 
		//		maskBitmap, 0, 0, MAKEROP4(SRCCOPY, NOMIRRORBITMAP)))
		//	{
		//		return;
		//	}
		//}

		pdc->BitBlt(point.x, point.y, (point.x + bm.bmWidth), (point.y + bm.bmHeight), &dcMem, 0, 0, SRCCOPY);
		//m_StatusText = "Transparancy Failed";
		dcMem.SelectObject(pOldBitmap);
	} else
		m_StatusText = "Error Loading Bitmap!!";
	
	delete pBitmap;
	UpdateData(false);

}

void CSolDlg::DrawDecks(CDC *pdc)
{
	int c;		//Count


	for(c=0; c<13; c++)
		l_StacksRunning[c] = l_StacksInitial[c];
	
	if(isRunning)
	{
		DrawStack(&myStacks[12], l_StacksInitial[12].TopLeft(), pdc, 
				ST_DECK, l_StacksRunning[12]);
		for(c=1; c<8; c++) 
			DrawStack(&myStacks[c], l_StacksInitial[c].TopLeft(), pdc, 
				ST_PLAYPILE, l_StacksRunning[c]);
		for(c=8; c<12; c++) 
			DrawStack(&myStacks[c], l_StacksInitial[c].TopLeft(), pdc, 
				ST_TOPCARDUP, l_StacksRunning[c]);	
		if(myStacks[0].Length() == 0)
		{
			CPen lSolidPen(PS_SOLID, 1, RGB(92,92,92));
			CPen *lOldPen;
			lOldPen = pdc->SelectObject(&lSolidPen);

			pdc->Rectangle(l_StacksInitial[0]);

			pdc->SelectObject(lOldPen);

		}
		else
			ShowBitmap(pdc, l_StacksInitial[0].TopLeft(), bmpID_CardBack);
	}
}




void CSolDlg::DrawStack(CCards *stack, CPoint point, CDC *pdc, int StackType, CRect & workingRect)
{
	card temp;
	int BmpID, x;

	CPen lSolidPen(PS_SOLID, 1, RGB(92,92,92));
	CPen *lOldPen;

	if(stack->Length() > 0) {
		switch(StackType) 
		{
		case ST_DECK:
			
			if(stack->BottomCard() <= stack->TopCard()-iDealAmt+1+dealMod) 
				x=stack->TopCard()-iDealAmt+1+dealMod;
			else
				x=stack->BottomCard();
				// Start putting cards out from the bottom, but be careful
			for(; x<=stack->TopCard(); x++) 
			{
				if(x <= stack->TopCard() && x >= stack->BottomCard())
				{
					BmpID = stack->ReturnBitmapResource(x);					
					ShowBitmap(pdc, point, BmpID);
					stack->SetLocation(x, 	CRect(point.x, point.y, point.x+CARD_WIDTH, point.y+CARD_HEIGHT));
					point.x += iCardOffsetH;
					workingRect.InflateRect(0, 0, iCardOffsetH, 0);
				}
		
			}
			point.x += -1*iCardOffsetH;
			workingRect.InflateRect(0, 0, -1*iCardOffsetH, 0);
			break;

		case ST_TOPCARDUP:

			
			if(stack->Length() > 0) {
				BmpID = stack->ReturnBitmapResource(stack->TopCard());
				ShowBitmap(pdc, point, BmpID);
			} 
			
			break;

		case ST_PLAYPILE:

			for(x=stack->BottomCard(); x<=stack->TopCard(); x++) 
			{
				if(stack->isVisible(x)) {
					BmpID = stack->ReturnBitmapResource(x);
					stack->SetLocation(x, 		CRect(point.x, point.y, point.x+CARD_WIDTH, point.y+CARD_HEIGHT));
				} else
					BmpID = bmpID_CardBack;

				ShowBitmap(pdc, point, BmpID);
				
				if(stack->isVisible(x))
				{
					point.y += iCardOffsetVv;
					workingRect.InflateRect(0, 0, 0, iCardOffsetVv);
				} 
				else
				{
					point.y += iCardOffsetV;
					workingRect.InflateRect(0, 0, 0, iCardOffsetV);
				}
			}
			break;

		}
	} else {
		lOldPen = pdc->SelectObject(&lSolidPen);

		pdc->Rectangle(CRect(point.x, point.y, point.x+CARD_WIDTH, point.y+CARD_HEIGHT));

		pdc->SelectObject(lOldPen);
	}
}

void CSolDlg::InitializeGame() 
{

	isRunning = FALSE;
	int c, x, y;		// Counting
	// Set decks to be big enough to hold cards
	// Deck itself will be set up by NewGame()
	for(c=1; c<12; c++) {
		myStacks[c].Resize(20);
	}

	// Location of Deck Discard
	l_StacksInitial[12].SetRect(iCardSpacing+CARD_WIDTH+iCardSpacing, iCardSpacing, 
		iCardSpacing+CARD_WIDTH+iCardSpacing+CARD_WIDTH, CARD_HEIGHT+iCardSpacing);

	// Location of seven play piles
	for(c=1; c<8; c++) 
	{
		x = iCardSpacing + (c-1)*(CARD_WIDTH+iCardSpacing);
		y = iCardSpacing+CARD_HEIGHT+iCardSpacing;
		l_StacksInitial[c].SetRect(x, y, x+CARD_WIDTH, y+CARD_HEIGHT);
	}

	// Location of four discard piles
	for(c=8; c<12; c++)
	{
		x = iCardSpacing + (3 + c - 8)*(CARD_WIDTH+iCardSpacing);
		y = iCardSpacing;
		l_StacksInitial[c].SetRect(x, y, x+CARD_WIDTH, y+CARD_HEIGHT);
	}

	// Location of Deck Pickup
	l_StacksInitial[0].SetRect(iCardSpacing,			 iCardSpacing,
								iCardSpacing+CARD_WIDTH, iCardSpacing+CARD_HEIGHT);
	dealMod=0;		// Dealmod is a special variable that helps the deck drawer know when its not supposed
						// to show everything

		
	strSectionLabel = "Settings";
	strBGColorLabel = "bgColor";
	strCardColorLabel = "cardBack";
	
	// Pickup Settings from Registry
	bmpID_CardBack = AfxGetApp()->GetProfileInt(strSectionLabel, strCardColorLabel, IDB_DEFAULTBACK);
	colorBackGround = AfxGetApp()->GetProfileInt(strSectionLabel, strBGColorLabel, RGB(0, 96, 0));
	
	//bmpID_CardBack = IDB_DEFAULTBACK;	// Set Default Card Back
	//colorBackGround = RGB(0, 192, 0);
		
}


void CSolDlg::MapClick(CPoint point, int lMouseDown)
{
	int c, r, clickedCard=-1, clickedStack=-1;
	CRect tempRect;
	for(c=0; c<13; c++)
	{
		if(l_StacksRunning[c].PtInRect(point)) 
		{
			clickedStack = c;
			for(r=myStacks[c].BottomCard(); r<=myStacks[c].TopCard(); r++) 
			{
				tempRect = myStacks[c].GetLocation(r);
				if(tempRect.PtInRect(point))
				{
					clickedCard = myStacks[c].Length() - (r+1);
					
				}
			}
		}
	}
	if(lMouseDown==1)
		DoActionDrag(clickedStack, clickedCard, point);
	else if(lMouseDown==0)
		DoActionDrop(clickedStack, clickedCard, point);
	else if(lMouseDown==2)
		DoActionDlbClick(clickedStack, clickedCard);
}


void CSolDlg::dealDeck()
{
	int c;
	card temp;

	if(myStacks[0].Length() > 0) {
		for(c=0; c<iDealAmt; c++) 
		{
			if(myStacks[0].Length() > 0) 
			{
				temp = myStacks[0].FetchBottomCard(false);
				if(isSane(temp)) {
					myStacks[12].PutCard(temp);
				}
				dealMod = 0;			// Set dealmod back to zero since we have dealt again
			}
		}
	}
	else
	{
		if(myStacks[12].Length() > 0) 
			myStacks[0] = myStacks[12];
		myStacks[12].Flush();
	
	}
	PartialRedraw(12);
	//if(myStacks[0].Length() <= 0)
		PartialRedraw(0);
}

bool CSolDlg::StartMove(int fromStack, int fromCard)
// Collect Cards from Source
{
	card temp;
	int x;
	tempStack.Flush();
	tempStack.Resize(fromCard+1);

	if(fromStack<=0 || fromStack > 12)
	{
		MessageBox("Error: Move from master deck or non-deck");		// This should never happen
		return 0;
	}
	else if(fromStack > 0 && fromStack < 12) 
	{
		if(myStacks[fromStack].Length() >= fromCard+1 && myStacks[fromStack].Length() > 0)
		{
			for(x=0; x<=fromCard; x++)
			{
		
				temp = myStacks[fromStack].FetchTopCard(false);
				tempStack.PutCard(temp);
			//	PartialRedraw(fromStack);
				saveScreenRect(lastMouse);
			}
			CString hey;
			hey.Format("tempStack.Length() = %d", tempStack.Length());
			m_StatusText = hey;
			UpdateData(false);
		} 
		else 
			return 0;		// We didn't pick up any cards
	}
	else if(fromStack==12)
	{
		if(myStacks[fromStack].Length() >= 1 && dealMod < iDealAmt) 
		{
			temp = myStacks[fromStack].FetchTopCard(false);
			tempStack.PutCard(temp);
			dealMod++;
		//	PartialRedraw(fromStack);
			saveScreenRect(lastMouse);
		}
		else
			return 0;		// We didn't pick up any cards
	} 

	return 1;	
}

bool CSolDlg::ProcessMove(int fromStack, int fromCard, int toStack)
{
	m_StatusText2.Format("");
	card temp;
	
	// Check to see if they are allowed to make this move

	if(toStack<=0 || toStack > 11)
	{
		MessageBox("Error: Move to master deck or non-deck");
		return 0;
	}
	else if(toStack > 0 && toStack < 8) 
	{
		if((areSequential(myStacks[toStack].FetchTopCard(true), tempStack.FetchTopCard(true)) &&
			areOppositeColors(myStacks[toStack].FetchTopCard(true), tempStack.FetchTopCard(true)))
			||
			(myStacks[toStack].Length()==0 && tempStack[tempStack.TopCard()].value==12))
		{
			while(tempStack.Length() > 0) {
				temp = tempStack.FetchTopCard(false);
				myStacks[toStack].PutCard(temp);
			}
		} else
		{
			CancelMove(fromStack, fromCard);
			return 0;		// Not a valid move
		}
	}
	else if(toStack > 7 && toStack < 12)
	{
		if((areSequential(tempStack.FetchTopCard(true), myStacks[toStack].FetchTopCard(true)) &&
			areSameSuite(myStacks[toStack].FetchTopCard(true), tempStack.FetchTopCard(true)))
			||
			(myStacks[toStack].Length()==0 && tempStack[tempStack.TopCard()].value==0))
		{
			while(tempStack.Length() > 0) {
				temp = tempStack.FetchTopCard(false);
				myStacks[toStack].PutCard(temp);
			}
		} else
		{
			CancelMove(fromStack, fromCard);
			return 0;		// Not a valid move
		}
	}

	PartialRedraw(fromStack);
	PartialRedraw(toStack);
	didWeWin();
	return 0;
}

bool CSolDlg::CancelMove(int fromStack, int fromCard)
{
	card temp;
	while(tempStack.Length() > 0) 
	{
		temp = tempStack.FetchTopCard(false);
		myStacks[fromStack].PutCard(temp);
	}
	if(fromStack==12 && dealMod>0) dealMod--;
	PartialRedraw(fromStack);
	return 1;
}

void CSolDlg::OnCardbackSel() 
{
	CBackSelDlg dlg;
	switch(bmpID_CardBack) {
		case IDB_DEFAULTBACK:
			dlg.m_RadioSelect = 0;
			break;
		case IDB_BACK0:
			dlg.m_RadioSelect = 1;
			break;
		case IDB_BACK1:
			dlg.m_RadioSelect = 2;
			break;
		case IDB_BACK2:
			dlg.m_RadioSelect = 3;
			break;
		case IDB_BACK3:
			dlg.m_RadioSelect = 4;
			break;
		case IDB_BACK4:
			dlg.m_RadioSelect = 5;
			break;
		case IDB_BACK5:
			dlg.m_RadioSelect = 6;
			break;
		default:
			dlg.m_RadioSelect = 0;
	}
	

	if(dlg.DoModal() == IDOK) 
	{
		switch(dlg.m_RadioSelect) {
		case 0:
			bmpID_CardBack = IDB_DEFAULTBACK;
			break;
		case 1:
			bmpID_CardBack = IDB_BACK0;
			break;
		case 2:
			bmpID_CardBack = IDB_BACK1;
			break;
		case 3:
			bmpID_CardBack = IDB_BACK2;
			break;
		case 4:
			bmpID_CardBack = IDB_BACK3;
			break;
		case 5:
			bmpID_CardBack = IDB_BACK4;
			break;
		case 6:
			bmpID_CardBack = IDB_BACK5;
			break;
		default:
			bmpID_CardBack = IDB_DEFAULTBACK; 
		}
	
	Invalidate();
	}
	

}

void CSolDlg::OnChgbackgrnd() 
{
	CColorDialog dlg;
	if(dlg.DoModal() == IDOK) 
	{
		colorBackGround = dlg.GetColor();
		Invalidate();
	}	
}

void CSolDlg::DoActionDrag(int clickedStack, int clickedCard, CPoint point)
{
if(clickedStack == -1) {
		c_moveFrom = -1;
		c_moveTo = -1;
		m_StatusText2 = "";
		UpdateData(false);
		return;
	}
	if(clickedStack == 0) {	// Deck 
		dealDeck();
		c_moveFrom = -1;
		c_moveTo = -1;
		m_StatusText2 = "";
		UpdateData(false);
		return;
	}
	if(clickedStack > 0 && clickedStack < 12 && myStacks[clickedStack].Length() > 0 &&
			!myStacks[clickedStack].isVisible(myStacks[clickedStack].TopCard()))
	{
		myStacks[clickedStack].SetVisible(myStacks[clickedStack].TopCard(), true);
		PartialRedraw(clickedStack);
	} else 
	{
		MovingID = myStacks[clickedStack].ReturnBitmapResource(
			myStacks[clickedStack].TopCard() - clickedCard);
		CRect hey = myStacks[clickedStack].GetLocation(myStacks[clickedStack].TopCard() - clickedCard);
		MouseOffset = point - hey.TopLeft();
		isDragging = true;
		StartMove(clickedStack, clickedCard);
		c_moveFrom = clickedStack;
		c_moveFromCard = clickedCard;
	}
}


bool CSolDlg::DoActionDrop(int clickedStack, int clickedCard, CPoint point)
{
	c_moveTo = clickedStack;
	if(clickedStack > 0 && clickedStack < 12) 
	{
		ProcessMove(c_moveFrom, c_moveFromCard, c_moveTo);
	} else
		CancelMove(c_moveFrom, c_moveFromCard);

	return true;
}

void CSolDlg::saveScreenRect(CPoint point)
{
	CClientDC dc(this);
	int x,y;
	for(x=0; x<CARD_WIDTH; x++) {
		for(y=0; y<CARD_HEIGHT; y++) {
			h[x][y] = dc.GetPixel(point.x+x, point.y+y);	
		}
	}
}

void CSolDlg::PartialRedraw(int numStack)
{
	CClientDC mydc(this);
	CRect tempRect;

	CDC tempdc;
	tempdc.CreateCompatibleDC(&mydc);

	l_StacksRunningLast[numStack] = l_StacksRunning[numStack];		// Set "last" rect before it gets changed

	l_StacksRunning[numStack] = l_StacksInitial[numStack];			// Reset the Running area for drawing
	DrawStack(&myStacks[numStack], l_StacksInitial[numStack].TopLeft(), &tempdc,
			ST_DECK, l_StacksRunning[numStack]);
	CRgn hey;
	tempRect.UnionRect(l_StacksRunning[numStack], l_StacksRunningLast[numStack]);
	hey.CreateRectRgn(tempRect.right, tempRect.top, tempRect.left, tempRect.bottom);

	mydc.SelectClipRgn(&hey, RGN_COPY);

	
	CRect thisRect;
	CPen lSolidPen(PS_SOLID, 1, colorBackGround);
	CBrush lSolidBrush(colorBackGround);
	CBrush *lOldBrush;
	CPen *lOldPen;

	GetClientRect(thisRect);
	thisRect.NormalizeRect();

	lOldPen = mydc.SelectObject(&lSolidPen);
	lOldBrush = mydc.SelectObject(&lSolidBrush);

	mydc.Rectangle(thisRect);
	
	DrawDecks(&mydc);

//	DrawStack(&myStacks[numStack], l_StacksInitial[numStack].TopLeft(), &mydc,
//			ST_DECK, l_StacksRunning[numStack]);

//	mydc.BitBlt(0, 0, 200, 200 , &tempdc, 0, 0, SRCCOPY);
              
}

void CSolDlg::PaintBG(CDC *pdc)
{
	CRect thisRect;
	CPen lSolidPen(PS_SOLID, 1, colorBackGround);
	CBrush lSolidBrush(colorBackGround);
	CBrush *lOldBrush;
	CPen *lOldPen;

	GetClientRect(thisRect);
	thisRect.NormalizeRect();

	lOldPen = pdc->SelectObject(&lSolidPen);
	lOldBrush = pdc->SelectObject(&lSolidBrush);

	pdc->Rectangle(thisRect);
}

void CSolDlg::DoActionDlbClick(int clickedStack, int clickedCard)
{
	if(clickedStack==0)
	{
		dealDeck();
		return;
	}

	if(((clickedStack > 0 && clickedStack < 8) || clickedStack==12) && clickedCard==0) 
	{
		for(int x=8; x<12; x++) 
		
			if((areSequential(myStacks[clickedStack].FetchTopCard(true), myStacks[x].FetchTopCard(true)) &&
				areSameSuite(myStacks[x].FetchTopCard(true), myStacks[clickedStack].FetchTopCard(true)))
				||
				(myStacks[x].Length()==0 && myStacks[clickedStack][myStacks[clickedStack].TopCard()].value==0))
			{
				StartMove(clickedStack, 0);
				ProcessMove(clickedStack, 0, x);
			}
	}

}



void CSolDlg::didWeWin()
{
	for(int x=8; x<12; x++) 
	{
		if(myStacks[x][myStacks[x].TopCard()].value != 12)
			return;
	}
	MessageBox("You Won!");
}

void CSolDlg::OnAboutBox() 
{
	CAboutDlg dlgAbout;
	dlgAbout.DoModal();	
}

void CSolDlg::OnClose() 
{
	AfxGetApp()->WriteProfileInt(strSectionLabel, strCardColorLabel, bmpID_CardBack);
	AfxGetApp()->WriteProfileInt(strSectionLabel, strBGColorLabel, colorBackGround);
	
	CDialog::OnClose();
}
