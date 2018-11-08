// FILE: card_demo.cpp
// This is a small demonstration program showing how the Card and Deck classes are used.
#include <iostream>    // Provides cout and cin
#include <cstdlib>     // Provides EXIT_SUCCESS
#include <ctime>
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

    cout << "-----------Dealing Cards to Players-----------" << endl;
    dealHand(d, p1, numCards);
    dealHand(d, p2, numCards);

    cout << p1.getName() << "' Hand: " << p1.showHand() << endl;
    cout << p1.getName() << "' Books: " << p1.showBooks() << endl;
    cout << p2.getName() << "'s Hand: " << p2.showHand() << endl;
    cout << p2.getName() << "'s Books: " << p2.showBooks() << endl;

    Card* temp1 = new Card;
    Card* temp2 = new Card;

    bool p1turn = true;
    bool p2turn = false;

    cout << "\n-----------Initial Check for Books-----------" << endl;
    cout << p1.getName() << " lays down his books.\n";
    while(p1.checkForBook(temp1, temp2)) {
        p1.bookCards(*temp1, *temp2);
        p1.removeCardFromHand(*temp1);
        p1.removeCardFromHand(*temp2);
    }
    cout << p1.getName() << "' Hand: " << p1.showHand() << endl;
    cout << p1.getName() << "' Books: " << p1.showBooks() << "\n" << endl;

    cout << p2.getName() << " lays down his books.\n";
    while(p2.checkForBook(temp1, temp2)) {
        p2.bookCards(*temp1, *temp2);
        p2.removeCardFromHand(*temp1);
        p2.removeCardFromHand(*temp2);
    }

    cout << p2.getName() << "'s Hand: " << p2.showHand() << endl;
    cout << p2.getName() << "'s Books: " << p2.showBooks() << endl;

    cout << "\n-----------Game Mechanics Begin-----------" << endl;
    while(winCon != 26) {

        if(p1turn) {
            if((p1.getHandSize()) > 0) {
                *(temp1) = p1.chooseCardFromHand();
                cout << p1.getName() << " asks - Do you have a " << temp1->getRank() << endl;

                if(p2.cardInHand(*temp1)) {
                    cout << p2.getName() << " says - Yes. I have a " << temp1->getRank() << endl;
                    while(p2.cardInHand(*temp1)) {
                        p1.addCard(p2.removeCardFromHand(*temp1));
                    }
                }
                else {
                    if((d.size()) > 0) {
                        cout << p2.getName() << " says - Go Fish" << endl;
                        *temp2 = d.dealCard();
                        p1.addCard(*temp2);
                        cout << p1.getName() << " draws " << *temp2 << endl;
                    }
                }
            }
            else {
                cout << p1.getName() << " is out of cards and draws a card from the deck\n";
                if((d.size()) > 0) {
                    p1.addCard(d.dealCard());
                }
            }

            cout << p1.getName() << " books the " << temp1->getRank() << "..\n";
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
                cout << p2.getName() << " asks - Do you have a " << temp2->getRank() << endl;
                if(p1.cardInHand(*temp2)) {
                    cout << p1.getName() << " says - Yes. I have a " << temp2->getRank() << endl;
                    while(p1.cardInHand(*temp2)) {
                        p2.addCard(p1.removeCardFromHand(*temp2));
                    }
                }
                else {
                    if((d.size()) > 0) {
                        cout << p1.getName() << " says - Go Fish" << endl;
                        *temp1 = d.dealCard();
                        p2.addCard(*temp1);
                        cout << p2.getName() << " draws " << *temp1 <<  endl;
                    }
                }

            }
            else {
                cout << p2.getName() << " is out of cards and draws a card from the deck\n";
                if((d.size()) > 0) {
                    p2.addCard(d.dealCard());
                }
            }

            cout << p2.getName() << " books the " << temp2->getRank() << "..\n";
            while(p2.checkForBook(temp1, temp2)) {
                p2.bookCards(*temp1, *temp2);
                p2.removeCardFromHand(*temp1);
                p2.removeCardFromHand(*temp2);
            }

            p2turn = false;
            p1turn = true;

        }

        cout << "\n" << p1.getName() << "' Hand: " << p1.showHand() << endl;
        cout << p1.getName() << "' Books: " << p1.showBooks() << endl;
        cout << p2.getName() << "'s Hand: " << p2.showHand() << endl;
        cout << p2.getName() << "'s Books: " << p2.showBooks() << "\n" << endl;

        winCon = (p1.getBookSize() + p2.getBookSize()) / 2;

    }

    cout << "Game is Finished!" << endl;

    if((p1.getBookSize()) > (p2.getBookSize())) {
        cout << p1.getName() << " is the winner!!\n";
    }
    else if((p2.getBookSize()) > (p1.getBookSize())) {
        cout << p2.getName() << " is the winner!!\n";
    } else {
        cout << "It's a Draw!!\n";
    }

    delete temp1;
    delete temp2;

    return EXIT_SUCCESS;
}

void dealHand(Deck &d, Player &p, int numCards) {
    for (int i=0; i < numCards; i++)
        p.addCard(d.dealCard());
}
