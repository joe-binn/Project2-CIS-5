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
void gameEnd(const int, const int, ifstream&, ofstream&, string&, bool&);

//Execution Begins Here
int main(int argc, char** argv) {

         
    //Declare variables
    
    
    //Initialize variables
    
    //Process, map inputs to outputs
    
    //Display your initial conditions as well as outputs.
    gameEnd(turn, finish, in, out, victor, open);    
    //Exit stage right
    return 0;
}
void gameEnd(const int turn, const int finish, ifstream &in, ofstream &out, string &victor, bool &open){
    turn % 2 == 0 ? out<<"Congratulations Player 1. You have won the game.":
                    out<<"Congratulations Player 2. You have won the game.";
    //closing the file so I can read in the input from that file
    out.close();
    //Opening the Input file
    in.open("whowon.txt");
    //verifying to see if input file successfully opened with a bool variable (redundant...)
    if (in)open=true;else open=false;
    if (open)cout<<""; else cout<<"Error"<<endl;
    //To get the entire contents of the file
    getline(in,victor);
    //Display the string just acquired
    cout<< victor <<endl;
    //Closing input file
    in.close();
    cout<<fixed<<setprecision(2)<<showpoint;
    cout<<"Game completion: "<<setw(6)<<pow(finish,2)<<"%";
    //Exit stage right
    exit(0);
}


