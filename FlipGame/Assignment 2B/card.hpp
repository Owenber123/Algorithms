//
//  card.hpp
//  Assignment 2B
//
//  Created by Owen Beringer on 10/16/18.
//  Copyright © 2018 Owen Beringer. All rights reserved.
//

#ifndef card_hpp
#define card_hpp

#include <stdio.h>
#include <string>
using namespace std;

class card {
public:
    card(){};
    card(string val, string st, int valuenum) { value = val; suit = st; num = valuenum;};
    card(card& card);
    void setval(string val);
    void setsuit(string st);
    string getsuit();
    string getval();
    int getnum();
    friend ostream& operator<< (ostream& ostr, card& card);
    
private:
    string value;
    string suit;
    int num;
};





#endif /* card_hpp */
