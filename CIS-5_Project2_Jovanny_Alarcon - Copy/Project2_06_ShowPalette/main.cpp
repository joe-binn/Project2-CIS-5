/*
    Author: Jovanny Alarcon
    Date:   June 2nd, 2021  07:00PM
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
void showPal(const char [],const int [],const string [], int);
//Execution Begins Here
int main(int argc, char** argv) {
    //Declare variables
  
    
    //Initialize variables
    
    //Process, map inputs to outputs
     showPal(display,palet,hand,SIZE);  
    
    
    //Display your initial conditions as well as outputs.
    
    //Exit stage right
    return 0;
}
void showPal(const char a[],const int b[],const string h[], int size){
    //Displays Player 1's Palette as the player adds to it each round
        cout<<"Player 1's Palette: ";
        for (int i=0;i<8;i++)
            if(a[i] !=0 && b[i] != 0)    
                cout<<a[i]<<b[i]<<"  ";
        cout<<endl;
        //Displays Player 2's Palette as the player adds to it each round
        cout<<"Player 2's Palette: ";
        for (int i=8;i<size;i++)
            if(a[i] !=0 && b[i] != 0)
                cout<<a[i]<<b[i]<<"  ";
        cout<<endl;
}