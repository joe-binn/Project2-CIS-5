/*
    Author: Jovanny Alarcon
    Date:   June 2nd, 2021  03:10PM
    Purpose: C++ Template to be used in all programs
    Version:First and Last
 */

//System Libraries
#include <iostream>    //Input/Output Library
#include <ctime>       //Time Library
#include <cstdlib>     //Random Seed and Random Function
#include <string>      //String Library
#include <iomanip>     //IO Stream Manipulator Library
#include <fstream>     //IO File Library
#include <cmath>       //Math Library
#include <vector>
using namespace std;   //Library Name-space

//User Libraries

//Global/Universal Constants -- No Global Variables
//Science, Math, Conversions, Higher Dimensioned constants only


//Function Prototypes
void winChck(const int, const int, const int, const int, const int, const int );
//Execution Begins Here
int main(int argc, char** argv) {
    //Set Random seed
    srand(static_cast<unsigned int>(time(0)));
         
    //Declare variables
    winChck(mxCnt1,mxCnt2,hghVal1,hghVal2,highC1,highC2);
    //Initialize variables
    
    //Process, map inputs to outputs
    //Display your initial conditions as well as outputs.
    
    //Exit stage right
    return 0;
}

void winChck(const int mxCnt1, const int mxCnt2, const int hghVal1, const int hghVal2, const int highC1, const int highC2){
    //To determine who has won the round in Orange Rule.
    if (mxCnt1 > mxCnt2)
        cout << "Player 1 is currently winning." << endl;
    else if (mxCnt1 < mxCnt2)
        cout << "Player 2 is currently winning." << endl;
    else if (mxCnt1  ==  mxCnt2){
        if (hghVal1 > hghVal2)
            cout << "Player 1 is currently winning." << endl;
        else if (hghVal1 < hghVal2)
            cout << "Player 2 is currently winning." << endl;
        else if (hghVal1  ==  hghVal2){
            if (highC1>highC2)
                cout << "Player 1 is currently winning." << endl;
            else 
                cout << "Player 2 is currently winning." << endl;
        }
    }
}