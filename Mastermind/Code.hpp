//
//  Code.hpp
//  Project 1A
//
//  Created by Owen Beringer and Ben Logan on 9/20/18.
//  Copyright © 2018 Owen Beringer. All rights reserved.
//
//  This function holds the class declaration for Code Class which contains the necessary
//            variables and functions for the game Mastermind

//  Class Code

#ifndef Code_hpp
#define Code_hpp

#include <vector>
#include <stdio.h>
using namespace std;


class Code {
public:
    Code(int lengthN, int rangeM){                  // Constructor
        codeLengthN = lengthN;                      // Initializes Code Length
        codeRangeM = rangeM;                        // Initializes Code Range
    };
    void PrintSC();                                 // Prints Secret Code for grading purposes
    int checkCorrect(Code &player);                 // Returns correct digits in correct location
    int checkIncorrect(Code &player);               // Returns correct digits in wrong location
    void randCode();                                // Creates Secret Code Randomly
    vector<int> CodeVect;                           // Players Guess Vector
    void setUserCode();                             // Sets guess code

private:
    int codeLengthN;                                // Secret Code Length
    int codeRangeM;                                 // Secret Code Values Range
};

#endif /* Code_hpp */
