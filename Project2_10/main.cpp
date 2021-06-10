/*
    Author: Jovanny Alarcon
    Date:   May 17th, 2021  1:00PM
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
void indigo(int [],int [],int [],int [],int,int);
//Execution Begins Here
int main(int argc, char** argv) {
    //Declare variables
    
    
    //Initialize variables
    
    //Process, map inputs to outputs
        indigo(index1a,index1b,index2a,index2b,count1,count2);
    //Display your initial conditions as well as outputs.
    
    //Exit stage right
    return 0;
}
void indigo(int a[],int b[],int c[],int d[],int count1,int count2){
    int mxCnt1=1, hghVal1=a[0],highC1=b[0],totadd1=0;
    for (int i=0; i<count1;i++){
        int add=1,tCount=1,tColor=a[0],tHigh=b[0], j;
        for ( j=i+1;j<=count1;j++){
            if ((a[i]+add)==a[j]){
                tCount++;
                add++;
                totadd1++;
                tHigh= a[j];
                tColor= b[j];
            }
        }
        if (totadd1==0 && i==count1-1){
            hghVal1=a[0];highC1=b[0];
            for(int k=1;k<=count1;k++){
                if(a[k]>hghVal1){
                    tHigh= a[k];
                    tColor=b[k];
                }
            }
        }
        if(tCount>mxCnt1 || (tCount == mxCnt1 && tHigh>hghVal1)){
                mxCnt1=tCount;
                hghVal1=tHigh;
                highC1=tColor;
        }
    }
    
    int mxCnt2=1, hghVal2=c[0],highC2=d[0],totadd2=0;
    for (int i=0; i<count1;i++){
        int add=1,tCount=1,tColor=c[0],tHigh=d[0], j;
        for ( j=i+1;j<=count1;j++){
            if ((c[i]+add)==c[j]){
                tCount++;
                add++;
                totadd2++;
                tHigh= c[j];
                tColor= d[j];
            }
        }
        if (totadd2==0 && i==count1-1){
            hghVal2=c[0];highC2=d[0];
            for(int k=1;k<=count1;k++){
                if(c[k]>hghVal2){
                    tHigh=c[k];
                    tColor=d[k];
                }
            }
        }
        if(tCount>mxCnt2 || (tCount == mxCnt2 && tHigh>hghVal2)){
                mxCnt2=tCount;
                hghVal2=tHigh;
                highC2=tColor;
        }
    }
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

