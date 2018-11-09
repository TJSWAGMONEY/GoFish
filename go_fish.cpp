// go_fish.cpp
//
// On our honor, this programming project is our own work and we have not
// provided this code to any other student.
//
// Troy Jackson and James Lin
//
// taj777 and jl62356
//
// Section 5 digit ID: 16240

#include <iostream>    // Provides cout and cin
#include <cstdlib>     // Provides EXIT_SUCCESS
#include <ctime>
#include <fstream>
#include "card.h"
#include "player.h"
#include "deck.h"

using namespace std;

// PROTOTYPES for functions used by this demonstration program:
void dealHand(Deck &d, Player &p, int numCards);

int main() {
 
    //Initializes the output file
    ofstream outFile;
    outFile.open("gofish_results.txt");

    srand(time(0));

    //Initial declaration of variables
    int winCon = 0;
    int numCards = 7;
    Player p1("James");
    Player p2("Troy");

    Deck d;
    d.shuffle();

    outFile << "-----------Dealing Cards to Players-----------" << endl;
    dealHand(d, p1, numCards);
    dealHand(d, p2, numCards);

    outFile << p1.getName() << "' Hand: " << p1.showHand() << endl;
    outFile << p1.getName() << "' Books: " << p1.showBooks() << endl;
    outFile << p2.getName() << "'s Hand: " << p2.showHand() << endl;
    outFile << p2.getName() << "'s Books: " << p2.showBooks() << endl;

    //Allocates memory for temp cards used to check for books and trade cards
    Card* temp1 = new Card;
    Card* temp2 = new Card;

    //Sets it so that player 1 goes first
    bool p1turn = true;
    bool p2turn = false;

    //Checks' player 1's hand for books
    outFile << "\n-----------Initial Check for Books-----------" << endl;
    outFile << p1.getName() << " lays down his books.\n";
    while(p1.checkForBook(temp1, temp2)) {
        p1.bookCards(*temp1, *temp2);
        p1.removeCardFromHand(*temp1);
        p1.removeCardFromHand(*temp2);
    }
    outFile << p1.getName() << "' Hand: " << p1.showHand() << endl;
    outFile << p1.getName() << "' Books: " << p1.showBooks() << "\n" << endl;

    //Checks player 2's hand for books
    outFile << p2.getName() << " lays down his books.\n";
    while(p2.checkForBook(temp1, temp2)) {
        p2.bookCards(*temp1, *temp2);
        p2.removeCardFromHand(*temp1);
        p2.removeCardFromHand(*temp2);
    }

    outFile << p2.getName() << "'s Hand: " << p2.showHand() << endl;
    outFile << p2.getName() << "'s Books: " << p2.showBooks() << endl;

    outFile << "\n-----------Game Mechanics Begin-----------" << endl;

    //Loops until the game ends, as determined by a variable that checks
    //the total number of books
    while(winCon != 26) {

        if(p1turn) {
            if((p1.getHandSize()) > 0) {
                *(temp1) = p1.chooseCardFromHand();
                outFile << p1.getName() << " asks - Do you have a " << temp1->getRank() << endl;

                if(p2.cardInHand(*temp1)) {
                    outFile << p2.getName() << " says - Yes. I have a " << temp1->getRank() << endl;
                    while(p2.cardInHand(*temp1)) {//Removes the card from player 2's hand
                                                  //and gives it to player 1
                        p1.addCard(p2.removeCardFromHand(*temp1));
                    }
                }
                else {//Attempts to draw cards from the deck if player 2 does not have the card
                    if((d.size()) > 0) {
                        outFile << p2.getName() << " says - Go Fish" << endl;
                        *temp2 = d.dealCard();
                        p1.addCard(*temp2);
                        outFile << p1.getName() << " draws " << *temp2 << endl;
                    }
                }
            }
            else {//Player 1 attempts to draw cards from the deck
                outFile << p1.getName() << " is out of cards and draws a card from the deck\n";
                if((d.size()) > 0) {
                    p1.addCard(d.dealCard());
                }
            }

            //Checks player 1's hand for books
            outFile << p1.getName() << " books the " << temp1->getRank() << "..\n";
            while(p1.checkForBook(temp1, temp2)) {
                p1.bookCards(*temp1, *temp2);
                p1.removeCardFromHand(*temp1);
                p1.removeCardFromHand(*temp2);
            }

            //Ends player 1's turn and sets it to player 2's turn
            p1turn = false;
            p2turn = true;

        }

        //Code for player 2's turn
        else if(p2turn) {
            if((p2.getHandSize()) > 0) {
                *(temp2) = p2.chooseCardFromHand();
                outFile << p2.getName() << " asks - Do you have a " << temp2->getRank() << endl;
                if(p1.cardInHand(*temp2)) {
                    outFile << p1.getName() << " says - Yes. I have a " << temp2->getRank() << endl;
                    while(p1.cardInHand(*temp2)) {//Removes the card from the other player
                                                  //and gives it to player 2
                        p2.addCard(p1.removeCardFromHand(*temp2));
                    }
                }
                else {
                    if((d.size()) > 0) {//Attempts to draw cards from deck if the other player
                                        //does not have the card
                        outFile << p1.getName() << " says - Go Fish" << endl;
                        *temp1 = d.dealCard();
                        p2.addCard(*temp1);
                        outFile << p2.getName() << " draws " << *temp1 <<  endl;
                    }
                }

            }
            else {//Attempts to draw cards from the deck
                outFile << p2.getName() << " is out of cards and draws a card from the deck\n";
                if((d.size()) > 0) {
                    p2.addCard(d.dealCard());
                }
            }

            //Checks player 2's hand for books
            outFile << p2.getName() << " books the " << temp2->getRank() << "..\n";
            while(p2.checkForBook(temp1, temp2)) {
                p2.bookCards(*temp1, *temp2);
                p2.removeCardFromHand(*temp1);
                p2.removeCardFromHand(*temp2);
            }
            
            //Changes whose turn it is from player 2 to player 1
            p2turn = false;
            p1turn = true;

        }

        outFile << "\n" << p1.getName() << "' Hand: " << p1.showHand() << endl;
        outFile << p1.getName() << "' Books: " << p1.showBooks() << endl;
        outFile << p2.getName() << "'s Hand: " << p2.showHand() << endl;
        outFile << p2.getName() << "'s Books: " << p2.showBooks() << "\n" << endl;

        winCon = (p1.getBookSize() + p2.getBookSize()) / 2;//Checks if the game is over

    }

    outFile << "Game is Finished!" << endl;

    //Determines the winner
    if((p1.getBookSize()) > (p2.getBookSize())) {
        outFile << p1.getName() << " is the winner!!\n";
    }
    else if((p2.getBookSize()) > (p1.getBookSize())) {
        outFile << p2.getName() << " is the winner!!\n";
    } else {
        outFile << "It's a Draw!!\n";
    }

    //Frees memory
    delete temp1;
    delete temp2;

    outFile.close();

    return EXIT_SUCCESS;
}

//Method provided for dealing cards at the beginning of the game
void dealHand(Deck &d, Player &p, int numCards) {
     for (int i=0; i < numCards; i++)
        p.addCard(d.dealCard());
}
