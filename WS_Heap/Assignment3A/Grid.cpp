//
//  Grid.cpp
//  Assignment3A
//
//  Created by Owen Beringer on 10/23/18.
//  Copyright © 2018 Owen Beringer. All rights reserved.
//

#include "Grid.hpp"
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

void Grid::read_letters() {
    int n;
    string filename;
    cout << "Enter size of Word Search: ";
    cin >> n;
    if (n == 15)
        filename = "input15.txt";
    else if (n == 30)
        filename = "input30.txt";
    else if (n == 50)
        filename = "input50.txt";
    
    ifstream word_file(filename);
    
    if (!word_file) {
        cout << "No word file found." << endl;
    }
    
    word_file >> width >> length;
    mat.resize(width,length);
    for (int i = 0; i < length; i++){
        for (int j = 0; j < width; j++){
            word_file >> mat[i][j];
        }
    }
    word_file.close();
}
