//
//  main.cpp
//  Assignment2A
//
//  Created by Owen Beringer on 10/9/18.
//  Copyright © 2018 Owen Beringer. All rights reserved.
//

#include <iostream>
#include "Deck.hpp"
#include <cmath>
using namespace std;

int getInput() {
    int n;
    cin >> n;
    
    while (cin.fail() or n < 0 or n > 24) {
        cout << "Error: Please enter a positive integer for Card Number less than 24: ";
        cin.clear();
        cin.ignore(256,'\n');
        cin >> n;
    }
    return n;
}

string getPlay() {
    string n;
    cin >> n;
    
    while (cin.fail() || ((n != "y") && (n !="n"))) {
        cout << "Error: Please enter y or n: ";
        cin.clear();
        cin.ignore(256,'\n');
        cin >> n;
    }
    return n;
}

void playFlip(){
    Deck deck;
    int points = 0;
    int input;
    string play;
    Deck hand(0);
    double temp;
    for (int i = 0; i < 3; i++){
        deck.shuffle();
    }
    cout << deck;
    for (int i = 0; i < 24; i++){
        card *temp = new card();
        *temp = deck.deal();
        hand.replace(temp);
    }
    cout << hand;
    cout << "Welcome to Flip!\n\n";
    for (int i = 1; i <= 24; i++) {
        
        cout << "Would you like to flip a card? (y/n): ";
        play = getPlay();
        
        if (play == "n"){
            cout << "GAME OVER!\n";
            return;
        }
        
        cout << "Which Card would you like to flip? (#): ";
        input = getInput();
        
        hand.temp = hand.head;
        for (int j = 0; j < input; j++){
            hand.temp = hand.temp->next;
        }
        card card = *(hand.temp->data);
        string val = card.getval();
        string suit = card.getsuit();
        cout << "You flipped the " << *(hand.temp->data) << endl;
        if (suit == "Hearts")
            points = points + 1;
        if (val == "A")
            points = points + 10;
        else if (val == "J" || val == "Q" || val == "K")
            points = points + 5;
        else if (val == "8" || val == "9" || val == "10")
            points = points;
        else if (val == "7"){
            temp = double (points);
            temp = ceil(temp/2);
            points = temp;
        }
        else if (val == "2" || val == "3" || val == "4" || val == "5" || val == "6")
            points = 0;
        cout << "Current Points: " << points << endl;
        }

}

int main() {
    playFlip();
}
