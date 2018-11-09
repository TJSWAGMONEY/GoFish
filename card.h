// card.h
//
// On our honor, this programming project is our own work and we have not
// provided this code to any other student.
//
// Troy Jackson and James Lin
//
// taj777 and jl62356
//
// Section 5 digit ID: 16240

#ifndef _CARD_H
#define _CARD_H

#include <iostream>
#include <string>
using namespace std;

class Card
{
  public:


    enum Suit {spades, hearts, diamonds, clubs};
    
    Card();          // default, ace of spades

    Card(int rank, Suit s);

    string toString()              const;  // return string version e.g. Ac 4h Js
    bool sameSuitAs(const Card& c) const;  // true if suit same as c
    int  getRank()                 const;  // return rank, 1..13
    string suitString(Suit s)      const;  // return "s", "h",...
    
    string rankString(int r)       const;  // return "A", "2", ..."Q"  
    
    
    bool operator == (const Card& rhs) const;
    bool operator != (const Card& rhs) const;
    
    ~Card();
    
  private:

    int myRank;
    Suit mySuit;

    
};

ostream& operator << (ostream& out, const Card& c);



#endif
