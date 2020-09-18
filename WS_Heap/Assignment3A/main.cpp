//
//  main.cpp
//  Assignment3A
//
//  Created by Owen Beringer on 10/23/18.
//  Copyright © 2018 Owen Beringer and Ben Logan. All rights reserved.
//

#include "Dict.hpp"
#include "Grid.hpp"
#include "iostream"
#include "fstream"
#include "d_matrix.hpp"
#include "d_except.hpp"
#include "heap.hpp"
#include <string>

using namespace std;

void checkDict(Dictionary &dict, const Grid &grd,int x, int y, const int dirx, const int diry) {
    const int wordLeng = 5;
    string word;
    int wordSize;
    int grdsize = grd.mat.cols();
    const int first = 0;
    int row = x;
    int colum = y;
    string letter = grd.mat[row][colum];
    word += letter;
    while (word.length() <= grd.mat.cols()) {
        if (word.length() >= wordLeng) {
            wordSize = (int)(word.size() - 1);
            if (dict.word_lookup(first, dict.length, word)){
                cout << "found: " << word << endl;
            }
        }
        row = (row + dirx);
        colum = (colum + diry);
        if (row < 0)
            row = grdsize + row;
        if (row >= grdsize)
            row = row - grdsize;
        if (colum < 0)
            colum = grdsize + colum;
        if (colum >= grdsize)
            colum = colum - grdsize;
        letter = grd.mat[row][colum];
        word = word +letter;
        
    }
}

void findMatches(Dictionary& dict, const Grid& grd){
    vector<int> range = {-1,0,1};
    for (int j = 0; j < grd.mat.cols(); j++) {
        for (int i = 0; i < grd.mat.cols(); i++) {
            for (auto x:range) {
                for (auto y:range) {
                    if (x==0 && y == 0) {}
                    else {
                        checkDict(dict, grd, j, i, x, y);
                    }
                }
            }
        }
    }
}

void search(int type){
    Grid grid;
    grid.read_letters();
    Dictionary dict;
    cout << dict;
    dict.read_words();
    if (type == 1)
        dict.selection_sort_words();
    else if (type == 2)
        dict.quick_sort_words();
    findMatches(dict, grid);
}

int main() {
    int type;
    cout << "Enter 1 for Selection Sort or 2 for Heap Sort: ";
    cin >> type;
    search(type);
}
