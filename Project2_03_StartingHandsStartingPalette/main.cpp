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
enum Colors {VIOLET=1,INDIGO,BLUE,GREEN,YELLOW,ORANGE,RED};

//Function Prototypes
void strtHnd(const int [],int,char [],int [],int [],string []);

//Execution Begins Here
int main(int argc, char** argv) {
//    for (int i=1; i<=16;i++){ 
//        if(i==1) random=rand1;
//        if(i==2) random=rand2;
//        if(i==3) random=rand3;
//        if(i==4) random=rand4;
//        if(i==5) random=rand5;
//        if(i==6) random=rand6;
//        if(i==7) random=rand7;
//        if(i==8) random=rand8;
//        if(i==9) random=rand9;
//        if(i==10)random=rand10;
//        if(i==11)random=rand11;
//        if(i==12)random=rand12;
//        if(i==13)random=rand13;
//        if(i==14)random=rand14;
//        if(i==15)random=rand15;
//        if(i==16)random=rand16;
        //Every random number generated will be assigned a specific card
//        switch (random){
//            case 49: cTemp = 'R'; iTemp=7;tempCol=R;break; case 48: cTemp = 'R'; iTemp=6;tempCol=R;break;
//            case 47: cTemp = 'R'; iTemp=5;tempCol=R;break; case 46: cTemp = 'R'; iTemp=4;tempCol=R;break;
//            case 45: cTemp = 'R'; iTemp=3;tempCol=R;break; case 44: cTemp = 'R'; iTemp=2;tempCol=R;break;
//            case 43: cTemp = 'R'; iTemp=1;tempCol=R;break; 
//            
//            case 42: cTemp = 'O'; iTemp=7;tempCol=O;break; case 41: cTemp = 'O'; iTemp=6;tempCol=O;break;
//            case 40: cTemp = 'O'; iTemp=5;tempCol=O;break; case 39: cTemp = 'O'; iTemp=4;tempCol=O;break;
//            case 38: cTemp = 'O'; iTemp=3;tempCol=O;break; case 37: cTemp = 'O'; iTemp=2;tempCol=O;break;
//            case 36: cTemp = 'O'; iTemp=1;tempCol=O;break; 
//            
//            case 35: cTemp = 'Y'; iTemp=7;tempCol=Y;break; case 34: cTemp = 'Y'; iTemp=6;tempCol=Y;break;
//            case 33: cTemp = 'Y'; iTemp=5;tempCol=Y;break; case 32: cTemp = 'Y'; iTemp=4;tempCol=Y;break;
//            case 31: cTemp = 'Y'; iTemp=3;tempCol=Y;break; case 30: cTemp = 'Y'; iTemp=2;tempCol=Y;break;
//            case 29: cTemp = 'Y'; iTemp=1;tempCol=Y;break; 
//            
//            case 28: cTemp = 'G'; iTemp=7;tempCol=G;break; case 27: cTemp = 'G'; iTemp=6;tempCol=G;break;
//            case 26: cTemp = 'G'; iTemp=5;tempCol=G;break; case 25: cTemp = 'G'; iTemp=4;tempCol=G;break;
//            case 24: cTemp = 'G'; iTemp=3;tempCol=G;break; case 23: cTemp = 'G'; iTemp=2;tempCol=G;break;
//            case 22: cTemp = 'G'; iTemp=1;tempCol=G;break; 
//            
//            case 21: cTemp = 'B'; iTemp=7;tempCol=B;break; case 20: cTemp = 'B'; iTemp=6;tempCol=B;break;
//            case 19: cTemp = 'B'; iTemp=5;tempCol=B;break; case 18: cTemp = 'B'; iTemp=4;tempCol=B;break;
//            case 17: cTemp = 'B'; iTemp=3;tempCol=B;break; case 16: cTemp = 'B'; iTemp=2;tempCol=B;break;
//            case 15: cTemp = 'B'; iTemp=1;tempCol=B;break; 
//            
//            case 14: cTemp = 'I'; iTemp=7;tempCol=I;break; case 13: cTemp = 'I'; iTemp=6;tempCol=I;break;
//            case 12: cTemp = 'I'; iTemp=5;tempCol=I;break; case 11: cTemp = 'I'; iTemp=4;tempCol=I;break;
//            case 10: cTemp = 'I'; iTemp=3;tempCol=I;break; case 9:  cTemp = 'I'; iTemp=2;tempCol=I;break;
//            case 8:  cTemp = 'I'; iTemp=1;tempCol=I;break;  
//            
//            case 7:  cTemp = 'V'; iTemp=7;tempCol=V;break; case 6:  cTemp = 'V'; iTemp=6;tempCol=V;break;
//            case 5:  cTemp = 'V'; iTemp=5;tempCol=V;break; case 4:  cTemp = 'V'; iTemp=4;tempCol=V;break;
//            case 3:  cTemp = 'V'; iTemp=3;tempCol=V;break; case 2:  cTemp = 'V'; iTemp=2;tempCol=V;break;
//            case 1:  cTemp = 'V'; iTemp=1;tempCol=V;break; 
//        }
        //After the random number generated number has been assigned a case, the program
        //will assign the players character color and value of the card, as well as assigning the starting hand
//        if (i==1){
//            cHand1=cTemp; iHand1=iTemp;
//            color1=tempCol;
//            hand1+=cTemp;hand1+=static_cast<char>(iTemp+48);
//        }
         
    //Declare variables
    
    strtHnd(random,SIZE,cHand,iHand,color,hand);
    //Initialize variables
    
    //Process, map inputs to outputs
    
    //Display your initial conditions as well as outputs.
        
    //Exit stage right
    return 0;
}

    void strtHnd(const int r[],int size,char cHand[],int iHand[], int color[],string hand[]){
        int random; 
        for (int i=0; i<size; i++){
            hand[i]="";
            random=r[i];
            switch (random){
                case 49: cHand[i]='R'; iHand[i]=7; color[i]=RED;hand[i]+=cHand[i];hand[i]+=static_cast<char>(iHand[i]+48);break; 
                case 48: cHand[i]='R'; iHand[i]=6; color[i]=RED;hand[i]+=cHand[i];hand[i]+=static_cast<char>(iHand[i]+48);break; 
                case 47: cHand[i]='R'; iHand[i]=5; color[i]=RED;hand[i]+=cHand[i];hand[i]+=static_cast<char>(iHand[i]+48);break; 
                case 46: cHand[i]='R'; iHand[i]=4; color[i]=RED;hand[i]+=cHand[i];hand[i]+=static_cast<char>(iHand[i]+48);break; 
                case 45: cHand[i]='R'; iHand[i]=3; color[i]=RED;hand[i]+=cHand[i];hand[i]+=static_cast<char>(iHand[i]+48);break; 
                case 44: cHand[i]='R'; iHand[i]=2; color[i]=RED;hand[i]+=cHand[i];hand[i]+=static_cast<char>(iHand[i]+48);break; 
                case 43: cHand[i]='R'; iHand[i]=1; color[i]=RED;hand[i]+=cHand[i];hand[i]+=static_cast<char>(iHand[i]+48);break; 
                
                case 42: cHand[i]='0'; iHand[i]=7; color[i]=ORANGE;hand[i]+=cHand[i];hand[i]+=static_cast<char>(iHand[i]+48);break; 
                case 41: cHand[i]='0'; iHand[i]=6; color[i]=ORANGE;hand[i]+=cHand[i];hand[i]+=static_cast<char>(iHand[i]+48);break; 
                case 40: cHand[i]='0'; iHand[i]=5; color[i]=ORANGE;hand[i]+=cHand[i];hand[i]+=static_cast<char>(iHand[i]+48);break; 
                case 39: cHand[i]='0'; iHand[i]=4; color[i]=ORANGE;hand[i]+=cHand[i];hand[i]+=static_cast<char>(iHand[i]+48);break; 
                case 38: cHand[i]='0'; iHand[i]=3; color[i]=ORANGE;hand[i]+=cHand[i];hand[i]+=static_cast<char>(iHand[i]+48);break; 
                case 37: cHand[i]='0'; iHand[i]=2; color[i]=ORANGE;hand[i]+=cHand[i];hand[i]+=static_cast<char>(iHand[i]+48);break; 
                case 36: cHand[i]='0'; iHand[i]=1; color[i]=ORANGE;hand[i]+=cHand[i];hand[i]+=static_cast<char>(iHand[i]+48);break; 
                
                case 35: cHand[i]='Y'; iHand[i]=7; color[i]=YELLOW;hand[i]+=cHand[i];hand[i]+=static_cast<char>(iHand[i]+48);break; 
                case 34: cHand[i]='Y'; iHand[i]=6; color[i]=YELLOW;hand[i]+=cHand[i];hand[i]+=static_cast<char>(iHand[i]+48);break; 
                case 33: cHand[i]='Y'; iHand[i]=5; color[i]=YELLOW;hand[i]+=cHand[i];hand[i]+=static_cast<char>(iHand[i]+48);break; 
                case 32: cHand[i]='Y'; iHand[i]=4; color[i]=YELLOW;hand[i]+=cHand[i];hand[i]+=static_cast<char>(iHand[i]+48);break; 
                case 31: cHand[i]='Y'; iHand[i]=3; color[i]=YELLOW;hand[i]+=cHand[i];hand[i]+=static_cast<char>(iHand[i]+48);break; 
                case 30: cHand[i]='Y'; iHand[i]=2; color[i]=YELLOW;hand[i]+=cHand[i];hand[i]+=static_cast<char>(iHand[i]+48);break; 
                case 29: cHand[i]='Y'; iHand[i]=1; color[i]=YELLOW;hand[i]+=cHand[i];hand[i]+=static_cast<char>(iHand[i]+48);break; 
                
                case 28: cHand[i]='G'; iHand[i]=7; color[i]=GREEN;hand[i]+=cHand[i];hand[i]+=static_cast<char>(iHand[i]+48);break; 
                case 27: cHand[i]='G'; iHand[i]=6; color[i]=GREEN;hand[i]+=cHand[i];hand[i]+=static_cast<char>(iHand[i]+48);break; 
                case 26: cHand[i]='G'; iHand[i]=5; color[i]=GREEN;hand[i]+=cHand[i];hand[i]+=static_cast<char>(iHand[i]+48);break; 
                case 25: cHand[i]='G'; iHand[i]=4; color[i]=GREEN;hand[i]+=cHand[i];hand[i]+=static_cast<char>(iHand[i]+48);break; 
                case 24: cHand[i]='G'; iHand[i]=3; color[i]=GREEN;hand[i]+=cHand[i];hand[i]+=static_cast<char>(iHand[i]+48);break; 
                case 23: cHand[i]='G'; iHand[i]=2; color[i]=GREEN;hand[i]+=cHand[i];hand[i]+=static_cast<char>(iHand[i]+48);break; 
                case 22: cHand[i]='G'; iHand[i]=1; color[i]=GREEN;hand[i]+=cHand[i];hand[i]+=static_cast<char>(iHand[i]+48);break; 
                
                case 21: cHand[i]='B'; iHand[i]=7; color[i]=BLUE;hand[i]+=cHand[i];hand[i]+=static_cast<char>(iHand[i]+48);break; 
                case 20: cHand[i]='B'; iHand[i]=6; color[i]=BLUE;hand[i]+=cHand[i];hand[i]+=static_cast<char>(iHand[i]+48);break; 
                case 19: cHand[i]='B'; iHand[i]=5; color[i]=BLUE;hand[i]+=cHand[i];hand[i]+=static_cast<char>(iHand[i]+48);break; 
                case 18: cHand[i]='B'; iHand[i]=4; color[i]=BLUE;hand[i]+=cHand[i];hand[i]+=static_cast<char>(iHand[i]+48);break; 
                case 17: cHand[i]='B'; iHand[i]=3; color[i]=BLUE;hand[i]+=cHand[i];hand[i]+=static_cast<char>(iHand[i]+48);break; 
                case 16: cHand[i]='B'; iHand[i]=2; color[i]=BLUE;hand[i]+=cHand[i];hand[i]+=static_cast<char>(iHand[i]+48);break; 
                case 15: cHand[i]='B'; iHand[i]=1; color[i]=BLUE;hand[i]+=cHand[i];hand[i]+=static_cast<char>(iHand[i]+48);break; 
                
                case 14: cHand[i]='I'; iHand[i]=7; color[i]=INDIGO;hand[i]+=cHand[i];hand[i]+=static_cast<char>(iHand[i]+48);break; 
                case 13: cHand[i]='I'; iHand[i]=6; color[i]=INDIGO;hand[i]+=cHand[i];hand[i]+=static_cast<char>(iHand[i]+48);break; 
                case 12: cHand[i]='I'; iHand[i]=5; color[i]=INDIGO;hand[i]+=cHand[i];hand[i]+=static_cast<char>(iHand[i]+48);break; 
                case 11: cHand[i]='I'; iHand[i]=4; color[i]=INDIGO;hand[i]+=cHand[i];hand[i]+=static_cast<char>(iHand[i]+48);break; 
                case 10: cHand[i]='I'; iHand[i]=3; color[i]=INDIGO;hand[i]+=cHand[i];hand[i]+=static_cast<char>(iHand[i]+48);break; 
                case  9: cHand[i]='I'; iHand[i]=2; color[i]=INDIGO;hand[i]+=cHand[i];hand[i]+=static_cast<char>(iHand[i]+48);break; 
                case  8: cHand[i]='I'; iHand[i]=1; color[i]=INDIGO;hand[i]+=cHand[i];hand[i]+=static_cast<char>(iHand[i]+48);break; 
                
                case  7: cHand[i]='V'; iHand[i]=7; color[i]=VIOLET;hand[i]+=cHand[i];hand[i]+=static_cast<char>(iHand[i]+48);break; 
                case  6: cHand[i]='V'; iHand[i]=6; color[i]=VIOLET;hand[i]+=cHand[i];hand[i]+=static_cast<char>(iHand[i]+48);break; 
                case  5: cHand[i]='V'; iHand[i]=5; color[i]=VIOLET;hand[i]+=cHand[i];hand[i]+=static_cast<char>(iHand[i]+48);break; 
                case  4: cHand[i]='V'; iHand[i]=4; color[i]=VIOLET;hand[i]+=cHand[i];hand[i]+=static_cast<char>(iHand[i]+48);break; 
                case  3: cHand[i]='V'; iHand[i]=3; color[i]=VIOLET;hand[i]+=cHand[i];hand[i]+=static_cast<char>(iHand[i]+48);break; 
                case  2: cHand[i]='V'; iHand[i]=2; color[i]=VIOLET;hand[i]+=cHand[i];hand[i]+=static_cast<char>(iHand[i]+48);break; 
                case  1: cHand[i]='V'; iHand[i]=1; color[i]=VIOLET;hand[i]+=cHand[i];hand[i]+=static_cast<char>(iHand[i]+48);break; 
            }
        }
    }