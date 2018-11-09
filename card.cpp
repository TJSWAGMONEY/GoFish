// card.cpp
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
#include "card.h"

using namespace std;

//default constructor
Card::Card() {
    myRank = 1;
    mySuit = spades;
}

//overloaded constructor, sets rank and suit
Card::Card(int rank, Suit s) {
    this->myRank = rank;
    this->mySuit = s;
}

//method returns card as a string
string Card::toString() const {
    string rank = rankString(myRank);
    string suit = suitString(mySuit);
    return rank+suit;
}

//returns the rank of the card as an integer
int Card::getRank() const {

    return myRank;

}

//returns true if the cards are the same suit
bool Card::sameSuitAs(const Card& c) const {

    if(c.mySuit == this -> mySuit) {
        return true;
    }
    else {
        return false;
    }

}

//returns rank of card as string
string Card::rankString(int r) const {
    //array of card ranks
    string myCards[][1] = {"/0", "A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"};
    return myCards[0][r];
}

//returns the string form of a card's suit
string Card::suitString(Suit s) const {

    if(s == spades) {
        return "s";
    }
    else if(s == hearts) {
        return "h";
    }
    else if(s == diamonds) {
        return "d";
    }
    else if(s == clubs) {
        return "c";
    }
    else {
        cout << "The suitString method is written incorrectly." << endl;
        return "error";
    }

}

//overloads the == operator
bool Card::operator == (const Card& rhs) const {

    if((rhs.mySuit == this -> mySuit) && (rhs.myRank == this -> myRank)) {
        return true;
    }
    else {
        return false;
    }

}

//overloads the != operator
bool Card::operator != (const Card& rhs) const {

    if((rhs.mySuit == this -> mySuit) && (rhs.myRank == this -> myRank)) {
        return false;
    }
    else {
        return true;
    }

}

//overrides cout, so that we can print the card object
ostream& operator << (ostream& out, const Card &c)
{
    out << c.toString();
    return out;
}

Card::~Card() {
    //The destructor
}
