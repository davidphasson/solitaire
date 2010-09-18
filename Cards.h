// Cards.h: interface for the CCards class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CARDS_H__7A87882E_7224_11D6_B21F_CE91F39A7224__INCLUDED_)
#define AFX_CARDS_H__7A87882E_7224_11D6_B21F_CE91F39A7224__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#define MAX_DECKSIZE 108
	// Solitaire uses a 52 card deck.. so this is fairly safe to cap CCards

enum Suite{clubs, diamonds, hearts, spades};

struct card {
	CRect myLocation;			// Stores a graphical location of the card
	Suite suite;				
	int value;
public:
	bool isVisible;				// Used for turning cards over
};

class CCards					// Custom "stack" with some very Sol specific functions too
{

public:
	// Graphical Location (rectangles)
	CRect GetLocation(int id) const;
	void SetLocation(int id, const CRect & rect);

	// Visibility
	int isVisible(int id) const;
	void SetVisible(int id, bool visible);

	// Accessor Functions
	int BottomCard() const;
	int TopCard() const;
	int Length() const;
	int Capacity() const;
	

	// HBITMAP mapping -> these will only work if the EXE is setup correctly:
	// each card has a four digit integer ID.  the first digit is the suite (1-4)
	// that corresponds to enum Suite + 1, second digit = 0, and last two are the 
	// value.  IE:  4013 = king spades
	int ReturnBitmapResource(int id);
	int ReturnBitmapResource(card input);

	// Push, Pull functions (you can push a card only, but you can pull from top and bottom)
	card FetchTopCard(bool save);			// save indicates whether or not it deletes it
											// equiv:  CCards[CCards::TopCard()];  etc.
	card FetchBottomCard(bool save);
	void PutCard(const card & input);		// put on bottom
	
	
	// General management
	void Flush();			// Clears deck w/o resize or deletion
	void CreateDeck();		// puts all 52 cards, in order, into a new myDeck size 52
	void Shuffle();			// Used with CreateDeck()
	void Resize(int cap);	// cap may be any size... so watch out
	
	// Debug Fucntions
	CString ToString(int loc);		// Returns string equivalent (4 Spds, etc) of card @ loc
	CString GetWholeDeck();			// Returns whole deck in text, dilimated by \r\n's
	CString GetCard(int suite, int value);
	
	// Constructors

	CCards();						// Default Constructor; Capacity=1
	CCards(int size);				// pre:  0 <= size <= MAX_DECKSIZE
	CCards(const CCards & src);		// Copy Constructor

	//Destructor

	virtual ~CCards();

	card CCards::operator [] (int k) const;
							// [] operator does not allow modification ;) this keeps it a "stack" and not
							// an "vector"
	const CCards & CCards::operator = (const CCards & rhs);
							// copies rhs to lhs
	
private:
	int myCapacity;
	int myBottomCard;
	int myTopCard;
	int myLength;

	card * theDeck;

};

bool isSane(card input);								// true iff card is actually a playing card ;)
bool areSameSuite(const card & a, const card & b);		// true iff cards are of the same suite
bool areSequential(const card & a, const card & b);		// true iff card a comes after card b
bool areOppositeColors(const card & a, const card & b);	// true if card a is red and card b is black or v.v.


#endif // !defined(AFX_CARDS_H__7A87882E_7224_11D6_B21F_CE91F39A7224__INCLUDED_)
