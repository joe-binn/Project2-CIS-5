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
using namespace std;   //Library Name-space

//User Libraries

//Global/Universal Constants -- No Global Variables
//Science, Math, Conversions, Higher Dimensioned constants only


//Function Prototypes
bool linSrch(const int, const int, const char [], const int [], string [], const int, const int);


//Execution Begins Here
int main(int argc, char** argv) {

         
    //Declare variables
    
    
    //Initialize variables
    
    //Process, map inputs to outputs
    linSrch(a[i],b[i],a,b,    h);
    
    //Display your initial conditions as well as outputs.
    
    //Exit stage right
    return 0;
}

bool linSrch(const int color, const int value, const char display[], const int palet[], string hand[], const int start, const int end){
    int index=0;
    int position = -1;
    bool isInHnd = false;
    for (index = start; index < end; index++){
        if (color == display[index]){
            if(value == palet[index]){
                position = index;
                hand[position] = "";
                isInHnd = true;
            }
        }
    }
    return isInHnd;
}

