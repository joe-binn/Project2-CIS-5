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
const int    MAX=49,
             MIN=0;
//Function Prototypes
void unirand(int [],int); //function to get unique randoms
void selSrt(int [],int);
void prntAry(int [],int,int);


//Execution Begins Here
int main(int argc, char** argv) {
    //Set the Random number seed
    srand(static_cast<unsigned int>(time(0)));
    //Declare variables
    const int SIZE=16;
    int random[SIZE],
        random1;
    
    //Initialize variables
    int count=0;
    for (int i=0;i<SIZE;i++){
        random[i]=rand()%(MAX-MIN)+MIN+1;
        cout<<random[i]<<" ";
        count++;
    }
    cout<<endl;
//    selSrt(random,SIZE);
//    prntAry(random,SIZE,10);
//    cout<<endl;
    unirand (random,SIZE);
//    prntAry(random,SIZE,10);
//    cout<<endl;
//    selSrt(random,SIZE);
//    prntAry(random,SIZE,10);
//        prntAry(random,SIZE,10);
//    Process, map inputs to outputs
    cout<<endl;
    for (int i=0;i<SIZE;i++)
        cout<<random[i]<<" ";
//    Display your initial conditions as well as outputs.
    
    //Exit stage right
    return 0;
}


void unirand(int r[],int size){
    bool unique;
    do{
            unique=false;
        for (int i=0;i<size;i++){
            for (int j=i+1;j<size;j++){
                if (r[i]==r[j]){
                    r[j]=(rand()%(MAX-MIN))+MIN+1;
                    i=-1;j=size;
                    unique=true;
                    continue;
                }
            
            }
        }
    }while(unique);
}

void selSrt(int a[],int size){
    for (int begin=0; begin < size-1; begin++){
        int minIndx=begin, minVal=a[begin];
        for (int i= begin+1; i<size;i++){
            if (a[i]<minVal){
                minVal=a[i];
                minIndx=i;
            }
        }
        int temp = a[minIndx];
             a[minIndx]=a[begin];
             a[begin]=temp;
    }
}

void prntAry(int a[],int size,int perLine){
    for (int i=0; i<size; i++){
        cout<<a[i]<<" ";
//        if ((i+1)%perLine==0)cout<<endl;
    }
}