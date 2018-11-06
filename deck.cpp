#include <cstdlib>
#include <iostream>
#include <string>
#include <ctime>
#include <sstream>
#include <vector>
#include <algorithm>
#include "deck.h"

using namespace std;

Card Deck::dealCard() {

    if(size() == 0) {
        return myCards[0];//This should never actually occur, because
                          //players cannot deal from an empty deck.
    }
    else {
        Card newCard = myCards[myIndex];
        myIndex--;
        return newCard;
    }

}

int Deck::size() const {

    return(52-myIndex);

}

void Deck::shuffle() {

    //

}



