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
void yellow(int [],int[]);
//Execution Begins Here
int main(int argc, char** argv) {
    //Declare variables
  
    
    //Initialize variables
    
    //Process, map inputs to outputs
     yellow(palet,cPalet);
    //Display your initial conditions as well as outputs.
    
    //Exit stage right
    return 0;
}
void yellow(int a[],int b[]){
    int mxCnt1=0, hghVal1=0,highC1=0;
    for (int color=VIOLET; color<=RED;color++){
        int tCount=0,tColor=color,tHigh=0;
        for(int j=0;j<8;j++){
            if(b[j]==color){
                tCount++;
                if (a[j]>tHigh)
                    tHigh=a[j];
            }
        }
        if (tCount >= mxCnt1){
            mxCnt1=tCount;
            hghVal1=tHigh;
            highC1=tColor;
        }
    }
    
    int mxCnt2=0, hghVal2=0,highC2=0;
    for (int color=VIOLET; color<=RED;color++){
        int tCount=0,tColor=color,tHigh=0;
        for(int j=8;j<16;j++){
            if(b[j]==color){
                tCount++;
                if (a[j]>tHigh)
                    tHigh=a[j];
            }
        }
        if (tCount >= mxCnt2){
            mxCnt2=tCount;
            hghVal2=tHigh;
            highC2=tColor;
        }
    }
    //To determine who has won the round in Orange Rule.
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