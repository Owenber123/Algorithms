//
//  mastermind.hpp
//  Project 1A
//
//  Created by Owen Beringer on 9/25/18.
//  Copyright © 2018 Owen Beringer. All rights reserved.
//

#ifndef mastermind_hpp
#define mastermind_hpp

#include "Code.hpp"
#include "Response.hpp"
#include <stdio.h>

class mastermind {
public:
    mastermind(int length, int range):SecretCode(length, range){
        codeLength = length;
        codeRange = range;
    }
    mastermind():SecretCode(5, 10){
        codeLength = 5;
        codeRange = 10;
    }
    void PrintSC();
    Code humanGuess();
    Response getResponse(Code guess);
    bool isSolved(Response& re);
    void playGame();
    
private:
    int codeLength;
    int codeRange;
    Code SecretCode;
};


#endif /* mastermind_hpp */
