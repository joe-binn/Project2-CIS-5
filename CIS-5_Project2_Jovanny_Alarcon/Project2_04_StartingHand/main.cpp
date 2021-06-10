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
void firstPly(int [],int [],int [],int [],int&);
//Execution Begins Here
int main(int argc, char** argv) {
    //Declare variables
    const int SIZE=16;
    int palet[SIZE],cPalet[SIZE],iHand[SIZE],color[SIZE], turn;
    
    //Initialize variables
    
    //Process, map inputs to outputs
    firstPly(palet,cPalet,iHand,color,turn);
    //Display your initial conditions as well as outputs.
    
    //Exit stage right
    return 0;
}

void firstPly(int palet[],int cPalet[],int iHand[],int color[],int &turn){
    //Determining who goes first, Current rule RED: Highest Number. If equal best color ROYGBIV; Compare card8 with card16
    palet[7] = iHand[7]; palet[15]=iHand[15];  //Player's 1st card value
    cPalet[7]= color[7]; cPalet[15]=color[15]; //Player's 1st color value
    if (palet[7]>palet[15]){cout<<"Player 2 goes first."<<endl;turn=0;} //Will start with player 2
    else if (palet[7]<palet[15]){cout<<"Player 1 goes first."<<endl;turn=1;} //will start with player 1
    else if (palet[7]==palet[15]){
        if (cPalet[7]>cPalet[15]){cout<<"Player 2 goes first."<<endl;turn=0;} //Will start with player 2
        else if (cPalet[7]<cPalet[15]){cout<<"Player 1 goes first."<<endl;turn=1;} //will start with player 1
    }
}