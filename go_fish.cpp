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

    bool p1turn = true;
    bool p2turn = false;

    while(p1.checkForBook(temp1, temp2)) {
        p1.bookCards(*temp1, *temp2);
        p1.removeCardFromHand(*temp1);
        p1.removeCardFromHand(*temp2);
    }
    while(p2.checkForBook(temp1, temp2)) {
        p2.bookCards(*temp1, *temp2);
        p2.removeCardFromHand(*temp1);
        p2.removeCardFromHand(*temp2);
    }

    while(winCon != 26) {

        if(p1turn) {
            if((p1.getHandSize()) > 0) {
                *(temp1) = p1.chooseCardFromHand();
                if(p2.cardInHand(*temp1)) {
                    while(p2.cardInHand(*temp1)) {
                        p1.addCard(p2.removeCardFromHand(*temp1));
                    }
                }
                else {
                    if((d.size()) > 0) {
                        p1.addCard(d.dealCard());
                    }
                }
            }
            else {
                if((d.size()) > 0) {
                    p1.addCard(d.dealCard());
                }
            }

            while(p1.checkForBook(temp1, temp2)) {
                p1.bookCards(*temp1, *temp2);
                p1.removeCardFromHand(*temp1);
                p1.removeCardFromHand(*temp2);
            }

            p1turn = false;
            p2turn = true;

        }

        else if(p2turn) {
            if((p2.getHandSize()) > 0) {
                *(temp2) = p2.chooseCardFromHand();
                if(p1.cardInHand(*temp2)) {
                    while(p1.cardInHand(*temp2)) {
                        p2.addCard(p1.removeCardFromHand(*temp2));
                    }
                }
                else {
                    if((d.size()) > 0) {
                        p2.addCard(d.dealCard());
                    }
                }

            }
            else {
                if((d.size()) > 0) {
                    p2.addCard(d.dealCard());
                }
            }

            while(p2.checkForBook(temp1, temp2)) {
                p2.bookCards(*temp1, *temp2);
                p2.removeCardFromHand(*temp1);
                p2.removeCardFromHand(*temp2);
            }

            p2turn = false;
            p1turn = true;

        }

        winCon = (p1.getBookSize() + p2.getBookSize()) / 2;

    }

    if((p1.getBookSize()) > (p2.getBookSize())) {
        //Declare p1 as the winner
    }
    else if((p2.getBookSize()) > (p1.getBookSize())) {
        //Declare p2 as the winner
    }

    delete temp1;
    delete temp2;

    return EXIT_SUCCESS;
}

void dealHand(Deck &d, Player &p, int numCards) {
    for (int i=0; i < numCards; i++)
        p.addCard(d.dealCard());
}

