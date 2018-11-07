// FILE: card_demo.cpp
// This is a small demonstration program showing how the Card and Deck classes are used.
#include <iostream>    // Provides cout and cin
#include <cstdlib>     // Provides EXIT_SUCCESS
#include "card.h"
#include "player.h"
#include "deck.h"

using namespace std;

// PROTOTYPES for functions used by this demonstration program:
void dealHand(Deck &d, Player &p, int numCards);

int main() {

    srand(time(0));

    int winCon = 0;
    int numCards = 7;
    Player p1("James");
    Player p2("Troy");

    Deck d;
    d.shuffle();

    dealHand(d, p1, numCards);
    dealHand(d, p2, numCards);

    Card* temp1 = new Card;
    Card* temp2 = new Card;

    while(p1.checkHandForBook(temp1, temp2)) {
        p1.bookCards(*temp1, *temp2);
        p1.removeCardFromHand(*temp1);
        p1.removeCardFromHand(*temp2);
    }
    while(p2.checkHandForBook(temp1, temp2)) {
        p2.bookCards(*temp1, *temp2);
        p2.removeCardFromHand(*temp1);
        p2.removeCardFromHand(*temp2);
    }

    while(winCon != 26) {

        //if p1turn
        //   if p1 has at least 1 card
        //      p1 chooses a card from hand
        //      p1 asks p2 if they have a card of that number
        //      if p2 has cards of that number
        //         p1 gets the cards
        //         and p2 loses the cards
        //      else
        //         p1 attempts to take a card from the deck
        //      check p1 for books
        //   else
        //      p1 attempts to take a card from the deck
        //   p1turn = false
        //   p2turn = true
        //else if p2turn
        //   if p2 has at least 1 card
        //      p2 chooses a card from hand
        //      p2 asks p1 if they have a card of that number
        //      if p1 has cards of that number
        //         p2 gets the cards
        //         and p1 loses the cards
        //      else
        //         p2 attempts to take a card from the deck
        //      check p2 for books
        //   else
        //      p2 attempts to take a card from the deck
        //   p2turn = false
        //   p1turn = true

        winCon = (p1.getBookSize() + p2.getBookSize()) / 2;

    }

    //compare book sizes and announce the winner

    delete temp1;
    delete temp2;

    return EXIT_SUCCESS;
}

void dealHand(Deck &d, Player &p, int numCards) {
    for (int i=0; i < numCards; i++)
        p.addCard(d.dealCard());
}

