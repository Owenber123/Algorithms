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
#include "card.hpp"


using namespace std;

class Node {
public:
    Node() {};
    Node* next;
    Node* previous;
    card* data;
};


class Deck {
public:
    int length;
    Node* head;
    Node* end;
    Node* temp;
    Deck();
    Deck(card x);
    ~Deck();
    void addcard(card& card);
    void shiftcard();
    void shuffle();
    void print();
    void getend();
    card deal();
    void replace(card *Card);
    bool is_empty();
    friend ostream& operator<< (ostream& ostr, Deck& deck);
};



#endif
