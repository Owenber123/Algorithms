//
//  card.cpp
//  Assignment 2B
//
//  Created by Owen Beringer on 10/16/18.
//  Copyright © 2018 Owen Beringer. All rights reserved.
//

#include "card.hpp"
#include <iostream>
using namespace std;

card::card(card& card){
    value = card.getval();
    suit = card.getsuit();
}


void card::setval(string val) {
    value = val;
}

void card::setsuit(string st) {
    suit = st;
}

int card::getnum(){
    return num;
}

string card::getsuit() {
    return suit;
}

string card::getval() {
    return value;
}

ostream& operator<< (ostream& ostr, card& card) {
    ostr << card.getval() << " of " << card.getsuit() << ".\n";
    return ostr;
}
