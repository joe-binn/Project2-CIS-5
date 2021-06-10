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
#include <vector>      //Standard Template Library
using namespace std;   //Library Name-space

//User Libraries

//Global/Universal Constants -- No Global Variables
//Science, Math, Conversions, Higher Dimensioned constants only
//Function Prototypes
void unirand(int [],int); //function to get unique randoms
void strtHnd(const int [],int,char [],int [],int [],string []);
void firstPly(int [],int [],int [],int [],int&);
void showHnd(string[],int);
void showPal(const char [],const int [],const string[], int);
void ply1Trn(char [],int [],int [],int [],int&);
void ply2Trn(char [],int [],int [],int [],int&);
void red(int [],int []);
void orange(int [],int[]);
void yellow(int [],int[]);
void green(int [],int []);
void blue(int[],int[]);
void srtCrds(int [],int [],int);
void indigo(int [],int [],int [],int [],int,int);

//Execution Begins Here
int main(int argc, char** argv) {
    //Set the Random number seed
    srand(static_cast<unsigned int>(time(0)));
     //Declare variables
    ifstream in;
    ofstream out;
    out.open("whowon.txt");
    bool open;
    float finish;
    char cHand[16], //Player 1 unique color per card [0-7], Player 2 unique color per card [8-15]
         display[16], //To display the color of the card for player 1 & 2.
         choice,  //choice to continue the game or not?
         cTemp;   //variable to assign beginning starting hands
    const int SIZE=16, MAX=49, MIN=0;
    int  iHand[16], //Player 1 unique number per card[0-7],  Player 2 unique number per card [8-15]
         palet[16]={0},  //Player 1 cin value choice[0-7], player 2 cin value choice [8-15]
         random[16], //to set random numbers to assign cards, temp values
         random1,   //use temp values from random[16];
         color[16]={0}, //To possibly validate user cards and have them resubmit if wrong
         cPalet[16]={0}, //Player 1 cin color choice[0-7], player 2 cin color choice [8-15]
         canvas[16], //Player 1 cin canvas change choice[0-7], player 2 cin canvas change choice [8-15]
         canvas1={0},    //if canvas[16] changes this will actually change the color
         turn;       //To set who goes first   
//         iTemp, tempCol; //variables to assign beginning starting hands
    string hand[16],  //Displays starting player 1 hand[0-7], displays player 2 starting hand [8-15]
           victor=""; 
    enum Colors {VIOLET=1,INDIGO,BLUE,GREEN,YELLOW,ORANGE,RED};
    finish=10;
    
    //Initialize variables
    for (int i=0;i<SIZE;i++){
        random[i]=rand()%(MAX-MIN)+MIN+1;
    }
    canvas1=INDIGO;
        
    //Process, map inputs to outputs
    unirand (random,SIZE);
    strtHnd(random,SIZE,cHand,iHand,color,hand);
    firstPly(palet,cPalet,iHand,color,turn);
    cout<<"The current rule is Red. To win you must play the highest value card."<<endl;
    showHnd(hand,SIZE);
    showPal(display, palet, hand, SIZE); 
    if (turn%2==1)
    ply1Trn(display,palet,canvas,cPalet,canvas1);
    else if (turn%2==0)
    ply2Trn(display,palet,canvas,cPalet,canvas1);
    if (canvas1 == RED)
        red(palet,cPalet);
    else if (canvas1 == ORANGE)
        orange(palet,cPalet);
    else if (canvas1 == YELLOW)
        yellow(palet,cPalet);
    else if (canvas1 == GREEN)
        green(palet,cPalet);
    else if (canvas1 == BLUE)
        blue(palet,cPalet);
    else if (canvas1 == INDIGO)
            srtCrds(palet,cPalet,SIZE);
//    else if (canvas1 == VIOLET)
        
   
    //Display your initial conditions as well as outputs.
    
    //Exit stage right
    return 0;
}
void unirand(int r[],int size){
    const int MAX=49,MIN=0;
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

void strtHnd(const int r[],int size,char cHand[],int iHand[], int color[],string hand[]){
    int random;
    enum Colors {VIOLET=1,INDIGO,BLUE,GREEN,YELLOW,ORANGE,RED};
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

            case 42: cHand[i]='O'; iHand[i]=7; color[i]=ORANGE;hand[i]+=cHand[i];hand[i]+=static_cast<char>(iHand[i]+48);break; 
            case 41: cHand[i]='O'; iHand[i]=6; color[i]=ORANGE;hand[i]+=cHand[i];hand[i]+=static_cast<char>(iHand[i]+48);break; 
            case 40: cHand[i]='O'; iHand[i]=5; color[i]=ORANGE;hand[i]+=cHand[i];hand[i]+=static_cast<char>(iHand[i]+48);break; 
            case 39: cHand[i]='O'; iHand[i]=4; color[i]=ORANGE;hand[i]+=cHand[i];hand[i]+=static_cast<char>(iHand[i]+48);break; 
            case 38: cHand[i]='O'; iHand[i]=3; color[i]=ORANGE;hand[i]+=cHand[i];hand[i]+=static_cast<char>(iHand[i]+48);break; 
            case 37: cHand[i]='O'; iHand[i]=2; color[i]=ORANGE;hand[i]+=cHand[i];hand[i]+=static_cast<char>(iHand[i]+48);break; 
            case 36: cHand[i]='O'; iHand[i]=1; color[i]=ORANGE;hand[i]+=cHand[i];hand[i]+=static_cast<char>(iHand[i]+48);break; 

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
void firstPly(int palet[],int cPalet[],int iHand[],int color[],int &turn){
    //Determining who goes first, Current rule RED: Highest Number. If equal best color ROYGBIV; Compare card8 with card16
    palet[7] = iHand[7]; palet[15]=iHand[15];  //Player's 1st card value
    cPalet[7]= color[7]; cPalet[15]=color[15]; //Player's 1st color value
    if (palet[7]>palet[15]){cout<<"Player 2 goes first."<<endl;turn=0;} //Will start with player 2
    else if (palet[7]<palet[15]){cout<<"Player 1 goes first."<<endl;turn=1;} //will start with player 1
    else if (palet[7]==palet[15]){
        if (cPalet[7]>cPalet[15]){cout<<"Player 2 goes first."<<endl;turn=0;} //Will start with player 2
        else if (cPalet[7]<cPalet[15]){cout<<"Player 1 goes first."<<endl;turn=1;} //will start with player 1
    }
}

void showHnd(string h[],int size){
    //Display Hands
    cout<<"Player 1: Your hand is ";
    for (int i=0;i<7;i++)
        cout<<h[i]<<"  ";
    cout<<endl;
    cout<<"Player 2: Your hand is ";
    for (int i=8;i<size-1;i++)
        cout<<h[i]<<"  ";   
    cout<<endl;
}

void showPal(const char a[],const int b[],const string h[], int size){
    //Displays Player 1's Palette as the player adds to it each round
        cout<<"Player 1's Palette: ";
        cout<<h[7]<<"  ";
        for (int i=0;i<7;i++)
            if(a[i] !=0 && b[i] != 0)    
                cout<<a[i]<<b[i]<<"  ";
        cout<<endl;
        //Displays Player 2's Palette as the player adds to it each round
        cout<<"Player 2's Palette: ";
        cout<<h[15]<<"  ";
        for (int i=8;i<size-1;i++)
            if(a[i] !=0 && b[i] != 0)
                cout<<a[i]<<b[i]<<"  ";
        cout<<endl;
}
void ply1Trn(char a[],int b[],int c[],int d[],int &canvas){
    int count=0; //To give a max of 2 turns
    char end;    //To let player end turn after turn 1
    enum Colors {VIOLET=1,INDIGO,BLUE,GREEN,YELLOW,ORANGE,RED};
    for(int i=0;i<7;i++){
        char porc;
        if(b[i]==0 && c[i]==0 && count<2){
            cout<<"Press P to play a card or C to discard to canvas"<<endl;
            cin>>porc;
            while(porc != 'C' && porc != 'P'){
                cout<<"Invalid choice:Select P or C."<<endl;
                cin>>porc;
            }
            if (porc=='P'){
                    cout<<"Type the first uppercase letter of the color then the value."<<endl;
                    cin>>a[i]>>b[i];
                int swap = 0, val=static_cast<int>(a[i]);
                switch(val){ 
                        case 'R':swap = RED;break;case 'O':swap = ORANGE;break;
                        case 'Y':swap = YELLOW;break;case 'G':swap = GREEN;break;
                        case 'B':swap = BLUE; break;case 'I':swap = INDIGO;break;
                        case 'V':swap = VIOLET;break;default:cout << "WRONG COLOR" << endl;
                } d[i]=swap;count++;
            }
            else if (porc=='C'){
                cout<<"Discard a card, type the color"<<endl;
                cin>>c[i];
                canvas=c[i];
                count++;
            }
            if (count==1){
                cout<<"Is it the end of your turn? Type Y or N."<<endl;
                cin>>end;
                while (end != 'Y' && end != 'N'){
                    cout<<"Invalid choice. Enter Y or N."<<endl;
                    cin>>end;
                }
                if (end=='Y')
                    count++;
            }
        }
    }
}

void ply2Trn(char a[],int b[],int c[],int d[],int &canvas){
    int count=0; //To give a max of 2 turns
    char end;    //To let player end turn after turn 1
    enum Colors {VIOLET=1,INDIGO,BLUE,GREEN,YELLOW,ORANGE,RED};
    for(int i=8;i<15;i++){
        char porc;
        if(b[i]==0 && c[i]==0 && count<2){
            cout<<"Press P to play a card or C to discard to canvas"<<endl;
            cin>>porc;
            while(porc != 'C' && porc != 'P'){
                cout<<"Invalid choice:Select P or C."<<endl;
                cin>>porc;
            }
            if (porc=='P'){
                    cout<<"Play the first uppercase letter of the color then the value."<<endl;
                    cin>>a[i]>>b[i];
                int swap = 0, val=static_cast<int>(a[i]);
                switch(val){ 
                        case 'R':swap = RED;break;case 'O':swap = ORANGE;break;
                        case 'Y':swap = YELLOW;break;case 'G':swap = GREEN;break;
                        case 'B':swap = BLUE; break;case 'I':swap = INDIGO;break;
                        case 'V':swap = VIOLET;break;default:cout << "WRONG COLOR" << endl;
                } d[i]=swap;count++;
            }
            else if (porc=='C'){
                cout<<"Discard a card, type the color"<<endl;
                cin>>c[i];
                canvas=c[i];
                count++;
            }
            if (count==1){
                cout<<"Is it the end of your turn? Type Y or N."<<endl;
                cin>>end;
                while (end != 'Y' && end != 'N'){
                    cout<<"Invalid choice. Enter Y or N.";
                    cin>>end;
                }
                if (end=='Y')
                    count++;
            }
        }
    }
}

void red(int a[],int b[]){
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
    
    int hghVal2, highC2;
    hghVal2=a[15];highC2=b[15];
    for(int i=8;i<15;i++){
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
    if (hghVal1>hghVal2)cout<<"Player 1 is winning."<<endl;
    else if (hghVal1<hghVal2)cout<<"Player 2 is winning."<<endl;
    else if (hghVal1==hghVal2){
        if (highC1>highC2)
            cout<<"Player 1 is currently winning."<<endl;
        else
            cout<<"Player 2 is currently winning."<<endl;
    }
}

void orange(int a[],int b[]){
    int mxCnt1=0, hghVal1=0,highC1=0;
    for (int i=1; i<=7;i++){
        int tCount=0,tColor=0,tHigh=i;
        for(int j=0;j<8;j++){
            if(a[j]==i){
                tCount++;
                if (b[j]>tColor)
                    tColor=b[j];
            }
        }
        if (tCount >= mxCnt1){
            mxCnt1=tCount;
            hghVal1=tHigh;
            highC1=tColor;
        }
    }
    
    int mxCnt2=0, hghVal2=0,highC2=0;
    for (int i=1; i<=7;i++){
        int tCount=0,tColor=0,tHigh=i;
        for(int j=8;j<16;j++){
            if(a[j]==i){
                tCount++;
                if (b[j]>tColor)
                    tColor=b[j];
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

void yellow(int a[],int b[]){
    enum Colors {VIOLET=1,INDIGO,BLUE,GREEN,YELLOW,ORANGE,RED};
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

void green(int a[],int b[]){
    int mxCnt1=0,hghVal1=0, highC1=0;
    for(int i=0;i<8;i++){
        if(a[i]%2==0 && a[i] != 0){
            mxCnt1++;
            if(a[i]>hghVal1){
                hghVal1=a[i];
                highC1=b[i];
            }
            else if (a[i]==hghVal1 && a[i]!=0){
                if(b[i]>highC1){
                    hghVal1=a[i];
                    highC1=b[i];
                }
            }
        }
    }
    
    int mxCnt2=0, hghVal2=0, highC2=0;
    for(int i=8;i<16;i++){
        if(a[i]%2==0 && a[i] != 0){
            mxCnt2++;
            if(a[i]>hghVal2){
                hghVal2=a[i];
                highC2=b[i];
            }
            else if (a[i]==hghVal2 && a[i] !=0){
                if(b[i]>highC2){
                    hghVal2=a[i];
                    highC2=b[i];
                }
            }
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

void blue(int a[],int b[]){
    enum Colors {VIOLET=1,INDIGO,BLUE,GREEN,YELLOW,ORANGE,RED};
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
    cout<<a[7]<<b[7]<<" "<<a[0]<<b[0]<<" "<<a[1]<<b[1]<<endl;
    cout<<index1a[0]<<index1b[0]<<" "<<index1a[1]<<index1b[1]<<" "<<index1a[2]<<index1b[2]<<endl;
    cout<<a[15]<<b[15]<<" "<<a[8]<<b[8]<<" "<<a[9]<<b[9]<<endl;
    cout<<index2a[0]<<index2b[0]<<" "<<index2a[1]<<index2b[1]<<" "<<index2a[2]<<index2b[2]<<endl;
    //Call function for Indigo Rule
    indigo(index1a,index1b,index2a,index2b,count1,count2);
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
