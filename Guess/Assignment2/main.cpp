
//  Created by Benjamin Logan & Owen Beringer
//  Algorithms - Project 1(a)
//  September 18, 2018



#include <vector>
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <unordered_map>
#include <string>
#include <ctime>

using namespace std;

class Code {
public:
    void PrintSC();                                 // Prints secret code for grading purposes
    int checkCorrect(Code &userCode);               // Returns correct digits in correct location
    int checkIncorrect(Code &userCode);             // Returns correct digits in wrong location
    void randCode();                                // Creates secret code randomly
    void humanGuess();                              // Asks user for guess with retry
    void winner(Code &userCode);                    // Outputs if the user is a winner
    Code(int lengthN, int rangeM){                  // Constructor
        codeLengthN = lengthN;                      // Initializes Code Length
        codeRangeM = rangeM;                        // Initializes Code Range
    };
    
private:
    int codeLengthN;                        // Secret Code Length
    int codeRangeM;                         // Secret Code Values Range
    vector<int> codeV;                      // Players Guess Vector
    
    
};

void Code::randCode() {                     // Generates A Random Secret Code
    srand((unsigned int) time(0));
    
    for (int x = 0; x < codeLengthN; x++){
        int num = (rand() % 5);
        codeV.push_back(num);
    }  // end for
    
} //end randCode

void Code::PrintSC() {                      // Prints Out Secret Key
    cout << "\nSecret Code: ";
    
    for(int i = 0; i < codeLengthN; i++){
        cout << codeV[i];
        if (i < codeLengthN - 1) {
            cout << ",";
        } // end if
    } // end for
    cout<<"\n\n";
}

void Code::humanGuess() {                   // Prompts user to input a guess and adds it to a vector
    int input;
    cout << codeRangeM;
    cout << "Enter " << codeLengthN << " integers from 0 to " << codeRangeM << ":\n";
    
    for (int x = 0; x < codeLengthN; x++) {
        cin >> input;
        while (cin.fail() or input > codeRangeM or input < 0) {                                     // Error Handling
            cout << "Error: Please enter a integer from 0 to " << codeRangeM << ": ";
            cin.clear();
            cin.ignore(256,'\n');
            cin >> input;
        } // end while
        codeV.push_back(input);
    } // end for
}

int Code::checkCorrect(Code &userCode) {              // Checks how many of the players guesses are correct and returns value(order matters)
    int count = 0;
    
    for (int check = 0; check < codeLengthN; check++) {
        
        if(codeV[check] == userCode.codeV[check]) {
            count++;
            userCode.codeV[check] = -1;
            
        } //end if
    } // end for
    return count;
} // end checkCorrect

int Code::checkIncorrect(Code &userCode) {            // Checks the amount of correct responses in the wrong place
    int count = 0;
    
    for (int i = 0; i < codeLengthN; i++){
        for (int j = 0; j < sizeof(userCode.codeV); j++){
            if (userCode.codeV[i] == -1) {break;}
            else {
                if (userCode.codeV[j] == codeV[i]) {
                    count++;
                    userCode.codeV[j] = -2;
                    continue;
                }
            }
        }
    }
    return count;
}


int getLength() {                                      // Takes Input For N (Length) And Check For Errors
    int n;
    cout << "Welcome to Mastermind: \n\nEnter the Length of the Secret Code: ";
    cin >> n;
    
    while (cin.fail() or n < 0) {
        cout << "Error: Please enter a positive integer for Length: ";
        cin.clear();
        cin.ignore(256,'\n');
        cin >> n;
    } // end while
    return n;
} // end getLength


int getRange() {                                        // Takes Input For M(Range) And Check For Errors
    int m;
    cout << "Enter a range for the secret code values: ";
    cin >> m;
    
    while (cin.fail() or m < 0) {
        cout << "Error: Please enter a positive integer for Range: ";
        cin.clear();
        cin.ignore(256,'\n');
        cin >> m;
    } // end while
    return m;
} // end getRange


int main() {
    int n = getLength();
    int m = getRange();
    
    Code secretCode(n,m);
    Code userCode(n,m);
    cout << n << m;
    secretCode.randCode();
    secretCode.PrintSC();
    cout << n << m<<"\n";
    userCode.humanGuess();
    //code1.winner(player);
    
    cout<<secretCode.checkCorrect(userCode);
    cout<<secretCode.checkIncorrect(userCode);
}
