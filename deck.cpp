#include <cstdlib>
#include <iostream>
#include <string>
#include <ctime>
#include <sstream>
#include <vector>
#include <algorithm>
#include "deck.h"

using namespace std;

//Default constructor creates sorted pristine deck spades, diamonds, clubs, hearts
Deck::Deck() {
    myIndex = 0;
    int idx;
    //for each suit
    for (int i = 0; i < 4; i++) {
        //for each rank
        for (int j = 1; j < 14; j++) {
            idx = j - 1;
            if (i == 0) {
                Card addCard(j, Card::spades);
                myCards[idx] = addCard;
            }
            if (i == 1) {
                Card addCard(j, Card::diamonds);
                myCards[13+idx] = addCard;
            }
            if (i == 2) {
                Card addCard(j, Card::clubs);
                myCards[26+idx] = addCard;
            }
            if (i == 3) {
                Card addCard(j, Card::hearts);
                myCards[39+idx] = addCard;
            }
        }
    }
}

Card Deck::dealCard() {

    if(size() == 0) {
        return myCards[0];//This should never actually occur, because
                          //players cannot deal from an empty deck.
    }
    else {
        Card newCard = myCards[myIndex];
        myIndex++;
        return newCard;
    }

}

int Deck::size() const {

    return(52-myIndex);

}

void Deck::shuffle() {

    Card tempCard;
    int randNum

    if(size() > 1) {
        for(int i=0; i<(20*52); i++) {
            randNum = 51 - ((rand()) % (51 - myIndex));
            tempCard = myCards[myIndex];
            myCards[myIndex] = myCards[randNum];
            myCards[randNum] = tempCard;
        }
    }

    //Our shuffle function swaps random cards a set number of times.
    //If there are only two cards left, that effectively results in
    //the same outcome every time, so we wrote this edge case to fix
    //that problem and maintain the outcome of a randomly shuffled deck.
    else if(size() == 2) {
        randNum = (rand() % 10) + 1;
        for(int i=0; i < randNum; i++) {
            tempCard = myCards[50];
            myCards[50] = myCards[51];
            myCards[51] = tempCard;
        }
    }

}

Deck::~Deck() {
    //The destructor
}


