//
//  main.cpp
//  Algorithms Assignment 1B
//
//  This function contains the main and member functions for the game Mastermind
//
//  getLength, getRange, main, and global overloading operators;


//  Created by Owen Beringer and Benjamin Logan on 9/14/18.
//  Copyright © 2018 Benjamin Logan. All rights reserved.
//
#include "Code.hpp"
#include "mastermind.hpp"
#include <vector>
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <unordered_map>
#include <string>
#include <ctime>

using namespace std;

bool operator== (const Response &re1, const Response &re2)                               // Compares response to previous
{
    if (re1.correct == re2.correct && re1.incorrect == re2.incorrect)
        return true;
    else
        return false;
};

ostream& operator<< (ostream& output, const Response &re) {
    output << "(" <<re.correct << ", " << re.incorrect << ")" << endl;               // Prints response after guess
    return output;
};


int getLength() {           // Takes Input For N (Length) And Check For Errors
    int n;
    cout << "Welcome to Mastermind: \n\nEnter the Length of the Secret Code: ";
    cin >> n;
    
    while (cin.fail() or n < 0) {       //Error handling, clears incorrect input and asks again
        cout << "Error: Please enter a positive integer for Length: ";
        cin.clear();
        cin.ignore(256,'\n');
        cin >> n;
    }
    return n;
}

int getRange() {            // Takes Input For M(Range) And Check For Errors
    int m;
    cout << "Enter a range for the secret code values: ";
    cin >> m;
    
    while (cin.fail() or m < 0) {       // Prevents input errors and reasks for range
        cout << "Error: Please enter a positive integer for Range: ";
        cin.clear();
        cin.ignore(256,'\n');
        cin >> m;
    }
    return m;
}

int main() {
    
    int n = getLength();            // User input Code Length
    int m = getRange();             // User input Range Value
    
    mastermind game(n, m);
    
    game.playGame();

}
