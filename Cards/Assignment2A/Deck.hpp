//
//  Deck.hpp
//  Assignment2A
//
//  Created by Owen Beringer on 10/9/18.
//  Copyright © 2018 Owen Beringer. All rights reserved.
//

#ifndef Deck_hpp
#define Deck_hpp

#include <iostream>
#include <stdio.h>
#include "d_node.hpp"
#include "card.hpp"

using namespace std;


class Deck {
public:
    int length;
    node<card> *head;
    node<card> *end;
    Deck();
    ~Deck();
    void addcard(card *card);
    void shuffle();
    void print();
    friend ostream& operator<< (ostream& ostr, const Deck& d);
};



#endif
