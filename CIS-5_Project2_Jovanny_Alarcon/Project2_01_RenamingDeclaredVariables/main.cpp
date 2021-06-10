/*
    Author: Jovanny Alarcon
    Date:   June 2nd, 2021  12:00PM
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
using namespace std;   //Library Name-space

//User Libraries

//Global/Universal Constants -- No Global Variables
//Science, Math, Conversions, Higher Dimensioned constants only

//Function Prototypes

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare variables
    ifstream in;
    ofstream out;
    out.open("whowon.txt");
    bool open;
    float finish;
    char cHand[16], //Player 1 unique color per card [0-7], Player 2 unique color per card [8-15]
         display[16], //To display the color of the card for player 1 & 2.
         choice,  //choice to continue the game or not?
         cTemp;   //variable to assign beginning starting hands
    const int SIZE=16;
    int  iHand[16], //Player 1 unique number per card[0-7],  Player 2 unique number per card [8-15]
         palet[16],  //Player 1 cin value choice[0-7], player 2 cin value choice [8-15]
         random[16], //to set random numbers to assign cards, temp values
         random1,   //use temp values from random[16];
         color[16], //To possibly validate user cards and have them resubmit if wrong
         cPalet[16], //Player 1 cin color choice[0-7], player 2 cin color choice [8-15]
         canvas[16], //Player 1 cin canvas change choice[0-7], player 2 cin canvas change choice [8-15]
         canvas1,    //if canvas[16] changes this will actually change the color
         iTemp, tempCol; //variables to assign beginning starting hands
    string hand[16],  //Displays starting player 1 hand[0-7], displays player 2 starting hand [8-15]
           victor=""; 
    enum Colors {V=1,I,B,G,Y,O,R};
    finish=10;
  
    
   
    
    //Process, map inputs to outputs
    
    //Display your initial conditions as well as outputs.
    
    //Exit stage right
    return 0;
}
