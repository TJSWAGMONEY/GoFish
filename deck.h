// deck.h
//
// On our honor, this programming project is our own work and we have not
// provided this code to any other student.
//
// Troy Jackson and James Lin
//
// taj777 and jl62356
//
// Section 5 digit ID: 16240

#ifndef _DECK_H
#define _DECK_H

#include "card.h"


class Deck
{
  static const int SIZE = 52;
  
  public:
    
    
    Deck();           // pristine, sorted deck

    void shuffle();   // shuffle the deck, all 52 cards present
    Card dealCard();   // get a card, after 52 are dealt, fail 

    int  size() const; // # cards left in the deck
  
    ~Deck();

  private:

    Card myCards[SIZE];
    int myIndex;  // current card to deal
};

#endif
