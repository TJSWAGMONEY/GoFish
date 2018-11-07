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

int Card::getRank() const {

    return myRank;

}

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

bool Card::operator == (const Card& rhs) const {

    if((rhs.mySuit == this -> mySuit) && (rhs.myRank == this -> myRank)) {
        return true;
    }
    else {
        return false;
    }

}

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
