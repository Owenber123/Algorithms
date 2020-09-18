//
//  Deck.cpp
//  Assignment2A
//
//  Created by Owen Beringer on 10/9/18.
//  Copyright © 2018 Owen Beringer. All rights reserved.
//

#include "Deck.hpp"
#include "d_node.hpp"
#include "card.hpp"
#include <iostream>
#include <string>
#include<vector>
using namespace std;


Deck::Deck() {
    head = NULL;
    length = 52;
    vector<string> suits = { "Spades", "Diamonds", "Hearts", "Clubs" };
    vector<string> vals = { "K", "Q", "J", "10", "9", "8", "7", "6", "5", "4", "3", "2", "A" };
    for (int i = 1; i <= length / 13; i++) {
       for (int j = 1; j <= length / 4; j++) {
           card *Card = new card(vals[j-1], suits[i-1]);
           addcard(Card);
       }
    }
}

 Deck::~Deck() {
     cout << "Deck Deleted!!!\n";
 }
 
void Deck::addcard(card* Card) {
    node<card> node;
    node.nodeValue = Card;
    if (this->head == NULL)
        end = &node;
    node.next = this->head;
    head = &node;
};

void Deck::shuffle(){
    node<card> *temp = head;
    srand((unsigned)time(0));
    int loop = rand() % 51;
    for (int i = 0; i < loop; i++){
        temp = temp->next;
    }
    
    card* tempcard = new card();
    tempcard = head->nodeValue;
    head->nodeValue = temp->nodeValue;
    temp = head->next;
}

void Deck::print() {
    node<card> *temp = this->head;
    int i = 1;
    while (head) {
        card card = *temp->nodeValue;
        cout << i << ": " << card.getval() << " of " << card.getsuit() << endl;
        temp = temp->next;
        i++;
    }
}

 ostream& operator<< (ostream& ostr, const Deck& deck) {
     node<card> *temp = deck.head;
     while(temp != NULL){
         ostr << temp->nodeValue << endl;
         temp = temp->next;
     }
     return ostr;
 }


