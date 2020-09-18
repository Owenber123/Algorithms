//
//  Dictionary.cpp
//  Assignment3A
//
//  Created by Owen Beringer on 10/23/18.
//  Copyright © 2018 Owen Beringer. All rights reserved.
//

#include "Dict.hpp"
#include <string>
#include <iostream>
#include <fstream>

ostream& operator<<(ostream& os, const Dictionary& dict){
    double size = dict.words.size();
    for(int i = 0; i < size; i++){
        os << dict.words[i] << endl;
    }
    return os;
}

void Dictionary::read_words() {
    ifstream word_file;
    string str;
    string fileName = "sortdict.txt";
    length = 0;
    word_file.open(fileName);
    
    while(getline(word_file, str)) {
        if (str.size() > 0) {
            words.push_back(str);
            length++;
        }
    }
    word_file.close();
}

void Dictionary::sort_words() {
    string temp;
    int current;
    
    for (int x = 0; x < words.size() - 1; x++) {
        current = x;
        for (int y = x + 1; y < words.size(); y++) {
            if (words[y] < words[current]) {
                current = y;
            }
        }
        temp = words[x];
        words[x] = words[current];
        words[current] = temp;
    }
}


bool Dictionary::word_lookup(int first, int last, string s) {
    int compare;
    
    if (first == last) {
        return s.compare(words[first]) == 0;
    }
    
    while (first < last) {
        int mid = (first + last) / 2;
        compare = s.compare(words[mid]);
        if (compare == 0) {
            return true;
        }
        else if (compare < 0) {
            return word_lookup(first, mid - 1, s);
        }
        else {
            return word_lookup(mid + 1, last, s);
        }
    }
    return false;
}
