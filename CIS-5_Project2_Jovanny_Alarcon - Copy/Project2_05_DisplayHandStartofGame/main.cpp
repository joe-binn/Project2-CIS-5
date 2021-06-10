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
void showHnd(string[],int);

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare variables
    const int SIZE=16;
    string hand[SIZE];
    
    //Initialize variables
    
    //Process, map inputs to outputs
    showHnd(hand,SIZE);
    //Display your initial conditions as well as outputs.
    
    //Exit stage right
    return 0;
}
void showHnd(string h[],int size){
    cout<<"The current rule is Red. To win you must play the highest value card."<<endl;
    //Display Hands
    cout<<"Player 1: Your hand is ";
    for (int i=0;i<8;i++)
        cout<<h[i]<<"  ";
    cout<<endl;
    cout<<"Player 2: Your hand is ";
    for (int i=8;i<size;i++)
        cout<<h[i]<<"  ";         
}