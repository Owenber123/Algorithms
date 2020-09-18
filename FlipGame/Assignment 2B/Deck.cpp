//
//  Deck.cpp
//  Assignment2A
//
//  Created by Owen Beringer on 10/9/18.
//  Copyright © 2018 Owen Beringer. All rights reserved.
//

#include "Deck.hpp"
#include <iostream>
#include <string>
#include<vector>
using namespace std;


Deck::Deck() {
    head = NULL;
    length = 52;
    vector<string> suits = { "Spades", "Diamonds", "Hearts", "Clubs" };
    vector<string> vals = { "K", "Q", "J", "10", "9", "8", "7", "6", "5", "4", "3", "2", "A" };
    vector<int> value = { 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 };
    for (int i = 1; i <= length / 13; i++) {
        for (int j = 1; j <= length / 4; j++) {
            card* Card = new card(vals[j-1], suits[i-1], value[i-1]);
            addcard(*Card);
        }
    }
}

Deck::Deck(card card){
    Node* node = new Node();
    node->data = &card;
    node->next = NULL;
    head = node;
}

Deck::~Deck() {
    //Node *temp = head;
    //while (temp != NULL){
        //head = head->next;
        //delete temp->data;
        //delete temp;
    //}
    cout << "Deck Deleted!!!\n";
}

void Deck::addcard(card& card) {
    Node* node = new Node();
    node->data = &card;
    node->next = this->head;
    if (head == NULL)
        end = node;
    head = node;
}

void Deck::shuffle() {
    cout << "SHUFFLING CARDS!!!\n";
    temp = head;
    srand((unsigned)time(0));
    for ( int i = 0; i < 50; i++){
        shiftcard();
    }
    getend();
}

void Deck::shiftcard(){
    int loop = rand() % 51;
    for (int i = 0; i < loop; i++){
        temp = (*temp).next;
    }
    
    card* tempcard = new card();
    tempcard = head->data;
    head->data = temp->data;
    temp->data = tempcard;
    temp = head->next;
}

void Deck::getend(){
    end = head;
    while (end != NULL)
        end = end->next;
}

card Deck::deal() {
    temp = head;
    card Card = *temp->data;
    head = head->next;
    delete temp;
    return Card;
}

void Deck::replace(card* Card){
    Node* node = new Node();
    if (head == NULL){
        head = node;
        end = node;
    }
    else {
        temp = end;
        temp->next = node;
    }
    node->next = NULL;
    node->data = Card;
    end = node;
}

bool Deck::is_empty(){
    return head->next == NULL;
}

ostream& operator<< (ostream& ostr, Deck& deck) {
    Node *temp = deck.head;
    int num = 0;
    while(temp != NULL){
        num = num + 1;
        card *Card = temp->data;
        ostr << num << ": " << *Card;
        temp = temp->next;
    }
    return ostr;
}
