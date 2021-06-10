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
void srtCrds(int [],int [],int);
//Execution Begins Here

int main(int argc, char** argv) {
    //Declare variables
  
    
    //Initialize variables
    
    //Process, map inputs to outputs
//    void srtCrds(palet,cPalet,size);
    //Display your initial conditions as well as outputs.
    
    //Exit stage right
    return 0;
}

//struct Card {
//    Color c;
//    int   v;
//};
//
//void srtCrds(Card hand[],int size){
//    Color c1 = hand[0].c;
//    int val1 = hand[0].v;

void srtCrds(int a[],int b[],int size){
    //Player 1
    int index1a[size],index1b[size],
            count1=0;
    for (int i=0;i<8;i++){
        if(a[i] != 0){
            index1a[count1]=a[i];
            index1b[count1]=b[i];
            count1++;
        }
    }
    for (int begin=0; begin < count1; begin++){
        int minIndx=begin, minVal=index1a[begin], highC1=index1b[begin];
        for (int i= begin+1; i<=count1;i++){
            if (index1a[i]<minVal){
                minVal=index1a[i];
                highC1=index1b[i];
                minIndx=i;
            }
            else if (index1a[i]==minVal){
                if (index1b[i]>highC1)
                    minVal=index1a[i];
                    highC1=index1b[i];
                    minIndx=i;
            }
        }
        int temp = index1a[minIndx];
             index1a[minIndx]=index1a[begin];
             index1a[begin]=temp;
             temp = index1b[minIndx];
             index1b[minIndx]=index1b[begin];
             index1b[begin]=temp;
    }
    //Player 2
    int index2a[size],index2b[size],
            count2=0;
    for (int i=8;i<16;i++){
        if(a[i] != 0){
            index2a[count2]=a[i];
            index2b[count2]=b[i];
            count2++;
        }
    }
    for (int begin=0; begin < count2; begin++){
        int minIndx=begin, minVal=index2a[begin], highC1=index2b[begin];
        for (int i= begin+1; i<=count2;i++){
            if (index2a[i]<minVal){
                minVal=index2a[i];
                highC1=index2b[i];
                minIndx=i;
            }
            else if (index2a[i]==minVal){
                if (index2b[i]>highC1)
                    minVal=index2a[i];
                    highC1=index2b[i];
                    minIndx=i;
            }
        }
        int temp = index2a[minIndx];
             index2a[minIndx]=index2a[begin];
             index2a[begin]=temp;
             temp = index2b[minIndx];
             index2b[minIndx]=index2b[begin];
             index2b[begin]=temp;
    }
    //Call function for Indigo Rule
//    indigo(index1a,index1b,index2a,index2b,count1,count2);
}
