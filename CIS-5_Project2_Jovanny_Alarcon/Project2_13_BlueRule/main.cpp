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
void blue(int[],int[]);
//Execution Begins Here
int main(int argc, char** argv) {
    //Declare variables
  
    
    //Initialize variables
    
    //Process, map inputs to outputs
    blue(palet,cPalet);
    //Display your initial conditions as well as outputs.
    
    //Exit stage right
    return 0;
}
void blue(int a[],int b[]){
    int mxCnt1=0;
    for (int color=VIOLET;color<=RED;color++){
        for (int i=0;i<8;i++){
            if(b[i]==color){
                mxCnt1++;i=8;
            }
        }
    }
//Find highest value separately since you can just take your highest card
//Re-using red's rule, might do a function call    
    int hghVal1, highC1;
    hghVal1=a[7];highC1=b[7];
    for(int i=0;i<7;i++){
        if(a[i]>hghVal1){
            hghVal1=a[i];
            highC1=b[i];
        }
        else if (a[i]==hghVal1){
            if(b[i]>highC1)
                highC1=b[i];
        }
    }
    //Player 2
    int mxCnt2=0;
    for (int color=VIOLET;color<=RED;color++){
        for (int i=8;i<16;i++){
            if(b[i]==color){
                mxCnt2++;i=16;
            }
        }
    }
//Find highest value separately since you can just take your highest card
//Re-using red's rule, might do a function call    
    int hghVal2, highC2;
    hghVal2=a[15];highC2=b[15];
    for(int i=0;i<7;i++){
        if(a[i]>hghVal2){
            hghVal2=a[i];
            highC2=b[i];
        }
        else if (a[i]==hghVal2){
            if(b[i]>highC2)
                highC2=b[i];
        }
    }
    //Compares both players hghValest value card
    //To determine who has won the round in Yellow Rule.
    if (mxCnt1 > mxCnt2)
        cout<<"Player 1 is currently winning."<<endl;
    else if (mxCnt1 < mxCnt2)
        cout<<"Player 2 is currently winning."<<endl;
    else if (mxCnt1 == mxCnt2){
        if (hghVal1 > hghVal2)
            cout<<"Player 1 is currently winning."<<endl;
        else if (hghVal1 < hghVal2)
            cout<<"Player 2 is currently winning."<<endl;
        else if (hghVal1 == hghVal2){
            if (highC1>highC2)
                cout<<"Player 1 is currently winning."<<endl;
            else 
                cout<<"Player 2 is currently winning."<<endl;
        }
    }
}
