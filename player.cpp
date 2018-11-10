// player.cpp
//
// On our honor, this programming project is our own work and we have not
// provided this code to any other student.
//
// Troy Jackson and James Lin
//
// taj777 and jl62356
//
// Section 5 digit ID: 16240

#include <cstdlib>
#include <iostream>
#include <string>
#include <ctime>
#include <sstream>
#include <vector>
#include <algorithm>
#include "deck.h"
#include "player.h"

Player::Player() {
    myName = '\0';
}

//adds a card to player's hand
void Player::addCard(Card c) {
    myHand.push_back(c);
}

//adds card to player's book 
void Player::bookCards(Card c1, Card c2) {
    myBook.push_back(c1);
    myBook.push_back(c2);
}

//checks player's hand for a pair 
bool Player::checkForBook(Card *c1, Card *c2) {
    for(int i = 0; i < getHandSize()-1; i++) {
        *c1 = myHand[i];
        for(int j = i+1; j < getHandSize(); j++) {
            *c2 = myHand[j];
            if (c1->getRank() == c2->getRank())
                return true;
        }
    }
    return false;
}

//bool Player::rankInHand(Card c) const {}

//randomly selects a card from player's hand
Card Player::chooseCardFromHand() const {
    int randIdx = rand() % getHandSize();
    Card myCard = myHand[randIdx];
    return myCard;
}

//checks if card with a specific rank is in player's hand
bool Player::cardInHand(Card c) const {
    //iterates through players hand
    for(int i = 0; i < myHand.size(); i++) {
        if (myHand[i].getRank() == c.getRank())
            return true;
    }
    return false;
}

//removes card from player's hand depending on rank
Card Player::removeCardFromHand(Card c) {
    int idx = 0;
    for(; myHand[idx].getRank() != c.getRank(); idx++);

    Card myCard = myHand[idx];
    myHand.erase(myHand.begin()+idx);

    return myCard;
}

//concatenates string of players cards in hand
string Player:: showHand() const {

    string handString = "";

    for(int i = 0; i < getHandSize(); i++) {
        handString = handString + ((myHand[i]).toString()) + " ";
    }

    return handString;

}

//concatenates string of players cards in book
string Player:: showBooks() const {

    string bookString = "";

    for(int i = 0; i < getBookSize() * 2; i++) {
        bookString = bookString + ((myBook[i]).toString()) + " ";
    }

    return bookString;

}

//returns the number of cards in player's hand
int Player::getHandSize() const {

    return myHand.size();

}

//returns the number of cards in player's book
int Player::getBookSize() const{

    return (myBook.size() / 2);

}

//bool Player::checkHandForPair(Card &c1, Card &c2);

//bool Player::sameRankInHand(Card c) const {}

Player::~Player() {
    //The destructor
}
