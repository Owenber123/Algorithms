//
//  Dictionary.hpp
//  Assignment3A
//
//  Created by Owen Beringer on 10/23/18.
//  Copyright © 2018 Owen Beringer. All rights reserved.
//

#ifndef Dict_hpp
#define Dict_hpp

#include <string>
#include <vector>

using namespace std;


class Dictionary {
    
public:
    Dictionary() {};
    int length;
    void read_words();
    void sort_words();
    bool word_lookup(int first, int last, string s);
    friend ostream& operator<< (ostream& os, const Dictionary& dictionary);
    
private:
    vector<string> words;
};


#endif /* Dictionary_hpp */
