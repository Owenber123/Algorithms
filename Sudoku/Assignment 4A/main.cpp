//
//  main.cpp
//  Assignment 4A
//
//  Created by Owen Beringer on 11/12/18.
//  Copyright © 2018 Owen Beringer. All rights reserved.
//

#include <iostream>
#include <limits.h>
#include "d_matrix.hpp"
#include "d_except.hpp"
#include <list>
#include <fstream>
#include "board.hpp"

using namespace std;




int main() {

    const int SquareSize = 3;  //  The number of cells in a small square
    //  (usually 3).  The board has
    //  SquareSize^2 rows and SquareSize^2
    //  columns.
    
    ifstream fin;
    
    // Read the sample grid from the file.
    string fileName;
    vector<string> files = {"sudoku1.txt","sudoku2.txt","sudoku3.txt"};
    
    for (int i = 0; i < 3; i++){            // Runs on all 3 Sudoku puzzles
        
        fileName = files[i];
        fin.open(fileName.c_str());
        if (!fin)
        {
            cerr << "Cannot open " << fileName << endl;
            exit(1);
        }
    
        try
        {
            board b1(SquareSize);
            
            while (fin && fin.peek() != 'Z')
            {
                b1.initialize(fin);
            }
            cout << "\n\n\nSudoku Board From '" << fileName << "':" << endl;
            b1.print();
            b1.printConflicts();
            bool b = b1.is_solved();
            if (!b){
                cout << "Unable to Solve Board!" << endl;
                b1.print();
            }
        }
        catch  (indexRangeError &ex)
        {
            cout << ex.what() << endl;
            exit(1);
        }
        fin.close();
        
    }
}
