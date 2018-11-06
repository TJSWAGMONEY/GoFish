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
}

string toString() {

    //

}

int getRank() const {

    return myRank;

}

bool sameSuitAs(const Card& c) const {

    if(c.mySuit == this.mySuit) {
        return true;
    }
    else {
        return false;
    }

}

string suitString(Suit s) const {

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

bool operator == (const Card& rhs) const {

    if((rhs.mySuit == this.mySuit) && (rhs.myRank == this.myRank)) {
        return true;
    }
    else {
        return false;
    }

}

bool operator != (const Card& rhs) const {

    if((rhs.mySuit == this.mySuit) && (rhs.myRank == this.myRank)) {
        return false;
    }
    else {
        return true;
    }

}

