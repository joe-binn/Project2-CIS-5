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
void giveUp(char &, int &);

//Execution Begins Here
int main(int argc, char** argv) {

         
    //Declare variables
    
    
    //Initialize variables
    
    //Process, map inputs to outputs
//    giveUp(choice, turn);
    //Display your initial conditions as well as outputs.
        
    //Exit stage right
    return 0;
}

void giveUp(char &choice, int &turn){
    cout << "Do you resign?" << endl;
        cin >> choice;
        while (choice != 'Y' && choice !='N'){
            cout << "Error Wrong Selection. Repeat, Y or N?" << endl;
            cin >> choice;
        }
        turn++;
}