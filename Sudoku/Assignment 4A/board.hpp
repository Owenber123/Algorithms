//
//  board.hpp
//  Assignment 4A
//
//  Created by Owen Beringer on 11/12/18.
//  Copyright © 2018 Owen Beringer. All rights reserved.
//

#ifndef board_hpp
#define board_hpp

#include <stdio.h>
#include <fstream>
#include "d_matrix.hpp"
#include "d_except.hpp"

using namespace std;

typedef int ValueType; // The type of the value in a cell

class board
// Stores the entire Sudoku board
{
public:
    board(int);
    void clear();
    void clearconflicts();
    void initialize(ifstream &fin);
    void initializeCell(int i,int j,int val);
    void print();
    bool isBlank(int, int);
    ValueType getCell(int, int);
    void setCell(int i,int j,int val);
    void clearCell(int i, int j);
    void printConflicts();
    bool checkRow(int,int,int);
    bool checkCol(int,int,int);
    bool checkSquare(int,int,int);
    bool is_safe(int,int,int);
    void updateConflicts();
    bool is_solved();
    
private:
    
    // The following matrices go from 1 to BoardSize in each
    // dimension, i.e., they are each (BoardSize+1) * (BoardSize+1)
    matrix<bool> conflicts;
    matrix<ValueType> value;
    matrix<ValueType> original;
};



#endif /* board_hpp */
