// Cards.cpp: implementation of the CCards class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Sol.h"
#include "Cards.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////


CCards::CCards()
{
	myCapacity=1;
	theDeck = new card[1];
	
	myLength=0;
	myBottomCard=0;
	myTopCard=-1;
}

CCards::CCards(int size)
{
	if(size > 0 && size < MAX_DECKSIZE) {
		theDeck = new card[size];
		myCapacity = size;
	} else 
	{
		myCapacity = 0;
	}

	myLength = 0;
	myBottomCard = 0;
	myTopCard = -1;
}

CCards::CCards(const CCards & src)
{
	/*
	card buffer;

	myLength = src.Length();
	myCapacity = src.Capacity();
    theDeck = new char[myCapacity];

	while(src.Length > 0) {
		buffer = src.FetchCard;
		PutCard(buffer);
	}
	*/
}

CCards::~CCards()
{
	delete [] theDeck;
}

void CCards::Shuffle() 
{
	int a, b;
	card temp;

	srand( (unsigned)time( NULL ) );

	for(int x=0; x<100; x++) 
	{
		a = rand() % (myLength);
		b = rand() % (myLength);
		temp = theDeck[a];
		theDeck[a] = theDeck[b];
		theDeck[b] = temp;
	}
	
}

CString CCards::GetCard(int suite, int value)
{
	CString r_value;
	value = value+1;
	suite = suite;
	switch(value) 
	{
	case 1:
		r_value += "A";
		break;
	case 2:
	case 3:
	case 4:
	case 5:
	case 6:
	case 7:
	case 8:
	case 9:
		r_value += ('0' + value);
		break;
	case 10:
		r_value += "10";
		break;
	case 11:
		r_value += "J";
		break;
	case 12:
		r_value += "Q";
		break;
	case 13:
		r_value += "K";
		break;
	default:
		r_value += "E";
	}
	
	r_value += " ";

	switch(suite) {
	case 0:
		r_value += "Clbs";
		break;
	case 1:
		r_value += "Dmds";
		break;
	case 2:
		r_value += "Hrts";
		break;
	case 3:
		r_value += "Spds";
		break;
	default:
		r_value += "Err";
	};

	return r_value;
}
		


CString CCards::GetWholeDeck()
{
	CString output = "";
	for(int x=myBottomCard; x<=myTopCard; x++) {
		output += ToString(x) + "\r\n";
	}
	return output;

}

CString CCards::ToString(int loc)
{
	return GetCard(theDeck[loc].suite, theDeck[loc].value);
}

void CCards::CreateDeck()
{
	delete[] theDeck;
	myCapacity = 52;
	card * newDeck = new card[myCapacity];
	myLength = 0;
	myBottomCard = 0;
	myTopCard = -1;
	

	int pos=0;
	while(pos < 52) 
	{	for(int x=0; x<4; x++) {
			for(int y=0; y<13; y++) {
				newDeck[pos].suite = (Suite)x;
				newDeck[pos].value = y;
				newDeck[pos].isVisible = true;
				myLength++;
				myTopCard++;
				pos++;
			}
		}
	}

	theDeck = newDeck;

}

void CCards::PutCard(const card & input)
{
	if(myCapacity <= myLength) {
		Resize(myCapacity * 2);
	}

	myTopCard++;
	myLength++;
	theDeck[myTopCard] = input;
	

}

card CCards::FetchTopCard(bool save)
{
	card topcard;
	if(myLength > 0 ) {
		topcard = theDeck[myTopCard];
		if(!save) {
			myTopCard--;
			myLength--;
		}
	} 
	return topcard;
}

card CCards::FetchBottomCard(bool save)
{
	card bottomcard;
	if(myLength > 0 ) {
		bottomcard = theDeck[myBottomCard];
		if(!save) {
			myBottomCard++;
			myLength--;
		}
	} 
	return bottomcard;
}



int CCards::Capacity() const
{
	return myCapacity;
}

int CCards::Length() const
{
	return myLength;
}

void CCards::Resize(int cap)
{
	int y=0;
	if(cap > 0 && cap < MAX_DECKSIZE) {
		card * newDeck = new card[cap];
		for(int x=myBottomCard; x<=myTopCard; x++) {
			if(y < cap) {
				newDeck[y] = theDeck[x];
				y++;
			}
		}
		delete[] theDeck;
		theDeck = newDeck;
		myCapacity = cap;
		myBottomCard = 0;
		myTopCard = y-1;
		myLength = y;
	}
}

void CCards::Flush()
{
	delete [] theDeck;
	theDeck = new card[myCapacity];
	myTopCard = -1;
	myBottomCard = 0;
	myLength = 0;
}

int CCards::ReturnBitmapResource(card input)
{
	if(isSane(input)) {
		return ((input.suite + 1)*1000 + input.value + 1);
	} else
		return IDB_ERROR;

	
}



int CCards::ReturnBitmapResource(int id)
{
	if(id >= myBottomCard && id <= myTopCard && isSane(theDeck[id])) {
		return ((theDeck[id].suite + 1)*1000 + theDeck[id].value + 1);
	} else
		return IDB_ERROR;
}

int CCards::TopCard() const
{
	return myTopCard;
}

int CCards::BottomCard() const
{
	return myBottomCard;
}

void CCards::SetVisible(int id, bool visible)
{
	if(id >= myBottomCard && id <= myTopCard) {
		theDeck[id].isVisible = visible;
	}
}

int CCards::isVisible(int id) const
{
	if(id >= myBottomCard && id <= myTopCard) {
		return theDeck[id].isVisible;
	} 
	return false;
}

card CCards::operator [] (int k) const
// precondition: 0 <= index < length
// postcondition: return index-th item
{
    if (k < myBottomCard && k > myTopCard)
    {
		//TODO:  Find a way to safely signal the host app
	}
      
    return theDeck[k];
}

const CCards & CCards::operator = (const CCards & rhs)
// postcondition: normal assignment via copying has been performed;
//                if vector and rhs were different sizes, vector
//                has been resized to  match the size of rhs
{
    if (this != &rhs && rhs.Length() > 0)                           // don't assign to self!
    {
        delete [] theDeck;                       // get rid of old storage
        myLength = rhs.Length();
        theDeck = new card[myLength];         // allocate new storage
		myBottomCard=0;
		myTopCard=myLength-1;

            // copy rhs
        int k, c=0;
        for(k=rhs.BottomCard(); k <= rhs.TopCard(); k++)
        {
            theDeck[c] = rhs[k];
			c++;
        }
    }
    return *this;                               // permit a = b = c = d
}

void CCards::SetLocation(int id, const CRect &rect)
{
	if(id >= myBottomCard && id <= myTopCard) {
		theDeck[id].myLocation = rect;
	} 
}

CRect CCards::GetLocation(int id) const
{
	if(id >= myBottomCard && id <= myTopCard) {
		return theDeck[id].myLocation;
	} 
	return CRect(0,0,0,0);
}


// Global Stuff

bool isSane(card input)
{
	if(input.value >= 0 && input.value < 13
			&& input.suite >=0 && input.suite < 4)
			return true;
	
	return false;
}

bool areSameSuite(const card & a, const card & b)
{
	return(a.suite == b.suite);
}

bool areSequential(const card & a, const card & b)
		// true iff card a comes after card b
{
	return(a.value == b.value+1);
}

bool areOppositeColors(const card & a, const card & b)
	// true if card a is red and card b is black and v.v.
{
	return( ((a.suite==1 || a.suite==2) && (b.suite==0 || b.suite==3)) ||
		    ((a.suite==0 || a.suite==3) && (b.suite==1 || b.suite==2))
		  );
}