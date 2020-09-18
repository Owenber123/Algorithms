//
//  board.cpp
//  Assignment 4A
//
//  Created by Owen Beringer on 11/12/18.
//  Copyright © 2018 Owen Beringer. All rights reserved.
//

#include "board.hpp"
#include <iostream>
#include <limits.h>
#include "d_matrix.hpp"
#include "d_except.hpp"
//#include <list>
#include <fstream>

const int Blank = -1;  // Indicates that a cell is blank

const int SquareSize = 3;  //  The number of cells in a small square
//  (usually 3).  The board has
//  SquareSize^2 rows and SquareSize^2
//  columns.

const int BoardSize = SquareSize * SquareSize;

int numSolutions = 0;


board::board(int sqSize)
: value(BoardSize+1,BoardSize+1)
// Board constructor
{
    clear();
    conflicts.resize(100,10);
}

void board::clear()
// Mark all possible values as legal for each board entry
{
    for (int i = 1; i <= BoardSize; i++)
        for (int j = 1; j <= BoardSize; j++)
        {
            value[i][j] = Blank;
        }
}

void board::clearconflicts()
// Mark all possible values as legal for each board entry
{
    for (int i = 1; i < (BoardSize + 1) * (BoardSize + 1); i++)
        for (int j = 1; j < BoardSize + 1; j++)
        {
            conflicts[i][j] = true;
        }
}

void board::initialize(ifstream &fin)
// Read a Sudoku board from the input file.
{
    char ch;
    
    clear();
    
    for (int i = 1; i <= BoardSize; i++)
        for (int j = 1; j <= BoardSize; j++)
        {
            fin >> ch;
            
            // If the read char is not Blank
            if (ch != '.')
                initializeCell(i,j,ch-'0');   // Convert char to int
        }
    original = value;
    updateConflicts();
}

void board::initializeCell(int i,int j,int val){
    value[i][j] = val;
}

int squareNumber(int i, int j)
// Return the square number of cell i,j (counting from left to right,
// top to bottom.  Note that i and j each go from 1 to BoardSize
{
    // Note that (int) i/SquareSize and (int) j/SquareSize are the x-y
    // coordinates of the square that i,j is in.
    
    return SquareSize * ((i-1)/SquareSize) + (j-1)/SquareSize + 1;
}

ostream &operator<<(ostream &ostr, vector<int> &v)
// Overloaded output operator for vector class.
{
    for (int i = 0; i < v.size(); i++)
        ostr << v[i] << " ";
    cout << endl;
    return ostr;
}

ValueType board::getCell(int i, int j)
// Returns the value stored in a cell.  Throws an exception
// if bad values are passed.
{
    if (i >= 1 && i <= BoardSize && j >= 1 && j <= BoardSize)
        return value[i][j];
    else
        throw rangeError("bad value in getCell");
}

bool board::isBlank(int i, int j)
// Returns true if cell i,j is blank, and false otherwise.
{
    if (i < 1 || i > BoardSize || j < 1 || j > BoardSize)
        throw rangeError("bad value in setCell");
    
    return (getCell(i,j) == Blank);
}

void board::print()
// Prints the current board.
{
    for (int i = 1; i <= BoardSize; i++)
    {
        if ((i-1) % SquareSize == 0)
        {
            cout << " -";
            for (int j = 1; j <= BoardSize; j++)
                cout << "---";
            cout << "-";
            cout << endl;
        }
        for (int j = 1; j <= BoardSize; j++)
        {
            if ((j-1) % SquareSize == 0)
                cout << "|";
            if (!isBlank(i,j))
                cout << " " << getCell(i,j) << " ";
            else
                cout << "   ";
        }
        cout << "|";
        cout << endl;
    }
    
    cout << " -";
    for (int j = 1; j <= BoardSize; j++)
        cout << "---";
    cout << "-";
    cout << endl;
    //printConflicts();
}

void board::setCell(int i,int j,int val){
    if (original[i][j] == Blank)
        value[i][j] = val;
    updateConflicts();
}

void board::clearCell(int i, int j){
    if (original[i][j] == Blank)
        value[i][j] = Blank;
    updateConflicts();
}

void board::printConflicts(){
    cout << "Cell Conflicts: " << endl;
    for (int i = 1; i <= BoardSize; i++){
        for (int j = 1; j <= BoardSize; j++){
            cout << "Cell(" << i << "," << j << "): ";
            for (int k = 1; k <= BoardSize; k++){
                if (!conflicts[(i * BoardSize) + j][k])
                    cout << k << " ";
            }
            cout << endl;
        }
    }
}

bool board::checkRow(int i, int j, int num){
    for (int x = 1; x <= BoardSize; x++){
        if (value[i][x] == num)
            return false;
    }
    return true;
}

bool board::checkCol(int i, int j, int num){
    for (int x = 1; x <= BoardSize; x++){
        if (value[x][j] == num)
            return false;
    }
    return true;
}

bool board::checkSquare(int i, int j, int num){
    int square = squareNumber(i,j);
    vector<int> rowstart = {1,1,1,4,4,4,7,7,7};
    int row = rowstart[square-1];
    int col = ((square-1)%3) * 3 + 1;
    
    for (int x = 0; x < SquareSize; x++){
        for (int y = 0; y < SquareSize; y++){
            if (value[row+x][col+y] == num)
                return false;
        }
    }
    return true;
}

bool board::is_safe(int i, int j, int num){
    return
    checkRow(i, j, num) &&
    checkCol(i, j, num) &&
    checkSquare(i, j, num);
}

void board::updateConflicts(){
    clearconflicts();
    for (int i = 1; i <= BoardSize; i++){
        for (int j = 1; j <= BoardSize; j++){
            for (int k = 1; k <= BoardSize; k++){
                if (!is_safe(i,j,k)){
                    conflicts[(i * BoardSize) + j][k] = false;
                }
            }
        }
    }
}

bool board::is_solved(){
    for (int i = 1; i <= BoardSize; i++){
        for (int j = 1; j <= BoardSize; j++){
            for (int k = 1; k <= BoardSize; k++){
                if (!is_safe(i,j,k))
                    return false;
            }
        }
    }
    return true;
}




