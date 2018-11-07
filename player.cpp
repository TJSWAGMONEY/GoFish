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

void Player::addCard(Card c) {
    myHand.push_back(c);
}

void Player::bookCards(Card c1, Card c2) {
    myBook.push_back(c1);
    myBook.push_back(c2);
}

//bool Player::checkHandForBook(Card &c1, Card &c2) {}

//bool Player::rankInHand(Card c) const {}

Card Player::chooseCardFromHand() const {
    int randIdx = rand() % getHandSize();
    Card myCard = myHand[randIdx];
    return myCard;
}

bool Player::cardInHand(Card c) const {
    //iterates through players hand
    for(int i = 0; i < myHand.size(); i++) {
        if (myHand[i] == c)
            return true;
    }
    return false;
}

Card Player::removeCardFromHand(Card c) {
    int idx = 0;
    for(; myHand[idx] != c; idx++);

    Card myCard = myHand[idx];
    myHand.erase(myHand.begin()+idx);

    return myCard;
}

string Player:: showHand() const {

    string handString = "";

    for(int i = 0; i < getHandSize(); i++) {
        handString = handString + ((myHand[i]).toString()) + " ";
    }

    return handString;

}

string Player:: showBooks() const {

    string bookString = "";

    for(int i = 0; i < getBookSize(); i++) {
        bookString = bookString + ((myBook[i]).toString()) + " ";
    }

    return bookString;

}

int Player::getHandSize() const {

    return myHand.size();

}

int Player::getBookSize() const{

    return myBook.size();

}

//bool Player::checkHandForPair(Card &c1, Card &c2);

//bool Player::sameRankInHand(Card c) const {}

Player::~Player() {
    //The destructor
}
