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
/*Bad bad -100 points*/


//Function Prototypes
void shuffle(vector<int> &, vector<int> &);
void uniRand(const vector<int>, vector<int> &, int = 16);
void strtHnd(const vector<int>,int,char [],int [],int [],string []);
void firstPly(int [],int [],int [],int [],int&);
void show(string[],int);
void show(const char [],const int [],const string[], int);
void plyrTrn(char [], int [], char [], int [], string [], const char [], const int [], int &,int = 0, int = 7);
void crntRul(const int);
void red(const int [], const int []);
void orange(const int [],const int[]);
void yellow(const int [],const int[]);
void green(const int [], const int []);
void blue(const int[], const int[]);
void srtCrds(const int [],const int [],int);
void indigo(int [],int [],int [],int [],const int,const int);
void violet(const int [], const int []);
bool giveUp(const int);
int  turnCnt(int);
void gameEnd(const int, const int, ifstream&, ofstream&, string&, bool&);
bool linSrch(const char, const int, string [],const char[], const int[], const int, const int);



//Execution Begins Here
int main(int argc, char** argv) {
    //Set the Random number seed
    srand(static_cast<unsigned int>(time(0)));
     //Declare variables
    vector<int> random(49),
                setCrds(16);
    ifstream in;
    ofstream out;
    out.open("WinnerWinnerChickenDinner.txt");
    bool open;
    float finish;
    char canvas[16] = {0},  //Player 1 cin canvas change choice[0-7], player 2 cin canvas change choice [8-15]  
         display[16],       //To display the color of the card for player 1 & 2.
         cHand[16],         //Player 1 unique color per card [0-7], Player 2 unique color per card [8-15]
         cTemp;             //variable to assign beginning starting hands
    const int SIZE  = 16, 
              MAX   = 49, 
              MIN   = 0;
    int  palet[16]  = {0}, //Player 1 cin value choice[0-7], player 2 cin value choice [8-15]
         cPalet[16] = {0}, //Player 1 cin color choice[0-7], player 2 cin color choice [8-15]
         color[16]  = {0}, //To possibly validate user cards and have them resubmit if wrong
         canvas1    = {0}, //if canvas[16] changes this will actually change the color
         iHand[16],        //Player 1 unique number per card[0-7],  Player 2 unique number per card [8-15]
         random1,          //use temp values from random[16];
         turn;             //To set who goes first   
//         iTemp, tempCol; //variables to assign beginning starting hands
    string hand[16],       //Displays starting player 1 hand[0-7], displays player 2 starting hand [8-15]
           victor = ""; 
    enum Colors {VIOLET=1, INDIGO, BLUE, GREEN, YELLOW, ORANGE, RED};
    finish = 10;
    
    //Initialize variables
    canvas1 = RED;
        
    //Process, map inputs to outputs
    shuffle(random, setCrds);
    strtHnd(setCrds,SIZE,cHand,iHand,color,hand);
    firstPly(palet,cPalet,iHand,color,turn);
    show(hand,SIZE);
    
    //Display your initial conditions as well as outputs.
    do{
        show(display, palet, hand, SIZE); 
        if (turn % 2 == 1)
        plyrTrn(display, palet, canvas, cPalet, hand, cHand, iHand, canvas1);
        else if (turn %2 == 0)
        plyrTrn(display, palet, canvas, cPalet, hand, cHand, iHand, canvas1, 8, 15);
        if (canvas1       ==  RED)
            red(palet, cPalet);
        else if (canvas1  ==  ORANGE)
            orange(palet, cPalet);
        else if (canvas1  ==  YELLOW)
            yellow(palet, cPalet);
        else if (canvas1  ==  GREEN)
            green(palet, cPalet);
        else if (canvas1  ==  BLUE)
            blue(palet, cPalet);
        else if (canvas1  ==  INDIGO)
            srtCrds(palet, cPalet, SIZE);
        else if (canvas1  ==  VIOLET)
            violet(palet, cPalet);
        turn = turnCnt(turn);
    }while(giveUp(turn));
    gameEnd(turn, finish, in, out, victor, open);    
    
    cout << "Is it though?" << endl;
    return 0;
}

void shuffle(vector<int> &random, vector<int> &setCrds) {
    const int MAX = 49,
              MIN = 0;
    for (int index = 0; index < random.size(); index++){
        random[index] = index + 1;
    }
    int numShfl = 100000000;
    for (int i = 0; i < numShfl; i++){
        int temp, rand1, rand2;
        do{
            rand1 = rand() % (MAX - MIN) + MIN;
//            cout << rand1 << endl;
            rand2 = rand() % (MAX - MIN) + MIN;
//            cout << rand2 << endl;
        }while(rand1 == rand2);
        temp          = random[rand1];
        random[rand1] = random[rand2];
        random[rand2] = temp;
    }
    uniRand(random, setCrds, 16);
}

void uniRand(const vector<int> assign, vector<int> &setCrds, int size){
    vector<int> cards(16);
    for (int i = 0; i < size; i++){
        setCrds[i] = assign[i];
    }
}

void strtHnd(const vector<int> r, int size, char cHand[], int iHand[], int color[],string hand[]){
    int random;
    enum Colors { VIOLET=1 , INDIGO, BLUE, GREEN, YELLOW, ORANGE, RED};
    for (int i = 0; i < size; i++){
        hand[i] = "";
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
    palet[7] = iHand[7]; palet[15] = iHand[15];  //Player's 1st card value
    cPalet[7] = color[7]; cPalet[15] = color[15]; //Player's 1st color value
    if (palet[7] > palet[15]){cout  <<  "Player 2 goes first."  <<  endl; turn=0;} //Will start with player 2
    else if (palet[7] < palet[15]){cout  <<  "Player 1 goes first."  <<  endl; turn=1;} //will start with player 1
    else if (palet[7]  ==  palet[15]){
        if (cPalet[7] > cPalet[15]){cout  <<  "Player 2 goes first."  <<  endl; turn=0;} //Will start with player 2
        else if (cPalet[7] < cPalet[15]){cout  <<  "Player 1 goes first."  <<  endl; turn=1;} //will start with player 1
    }
}

void show(string h[],int size){
    //Display Hands
    cout << "Player 1: Your hand is ";
    for (int i=0;i<7;i++)
        cout << h[i] << "  ";
    cout << endl;
    cout << "Player 2: Your hand is ";
    for (int i=8;i<size-1;i++)
        cout << h[i] << "  ";   
    cout << endl;
}

void show(const char a[],const int b[],const string h[], int size){
    //Displays Player 1's Palette as the player adds to it each round
    cout << endl << endl;
    cout << "__________________________________________________" << endl;
    cout << "Player 1's Palette: ";
    cout << h[7] << "  ";
    for (int i=0;i<7;i++)
        if(a[i] !=0 && b[i] != 0)    
            cout << a[i] << b[i] << "  ";
    cout << endl;
    //Displays Player 2's Palette as the player adds to it each round
    cout << "Player 2's Palette: ";
    cout << h[15] << "  ";
    for (int i=8;i<size-1;i++)
        if(a[i] !=0 && b[i] != 0)
            cout << a[i] << b[i] << "  ";
    cout << endl 
         << "__________________________________________________";
    cout << endl << endl;
}

//Function initializes display which shows 
void plyrTrn(char a[], int b[], char c[], int d[],  string h[], const char cHand[], const int iHand[], int &canvas,int start, int end){
    int count = 0; //To give a max of 2 turns
    char endTurn;    //To let player end turn after turn 1
    enum Colors {VIOLET = 1, INDIGO, BLUE, GREEN, YELLOW, ORANGE, RED};
    if (start  ==  0){
        cout  <<  "It is now Player 1's turn."  <<  endl;
    }
    else{
        cout  <<  "It is now Player 2's turn."  <<  endl;
    }
    crntRul(canvas); //Function call to display the current rule 
    
    for(int i = start; i < end; i++){
        int dummy; // When player discards to canvas this absorbs the value since only the color is needed
        char porc;
        if(b[i]  ==  0 && c[i]  ==  0 && count < 2){
            cout <<  "Press P to play a card or C to discard to canvas"  <<  endl;
            cin >> porc;
            while (porc != 'C' && porc != 'P'){
                cout  <<  "Invalid choice: Select P or C."  <<  endl;
                cin >> porc;
            }
            if (porc  ==  'P'){
                do{
                        cout  <<  "Type the first uppercase letter of the color then the value."  <<  endl;
                        cin >> a[i] >> b[i];
                        if (!(b[i] > 0 && b[i] < 8)){
                            cout << "Value of the card must be between 1-7. Retype the card." << endl;
                            cin >> a[i] >> b[i];
                        }
                    int swap = 0, val = static_cast<int>(a[i]);
                    switch(val){ 
                        case 'R':swap = RED;break;case 'O':swap = ORANGE;break;
                        case 'Y':swap = YELLOW;break;case 'G':swap = GREEN;break;
                        case 'B':swap = BLUE; break;case 'I':swap = INDIGO;break;
                        case 'V':swap = VIOLET;break;default:cout  <<  "WRONG COLOR"  <<  endl;
                    } d[i] = swap; count++;
                }while(!linSrch( a[i], b[i], h, cHand, iHand, start, end));
            }
            else if (porc  ==  'C'){
                cout  <<  "Discard a card, type the color"  <<  endl;
                cin >> c[i];
                int swap = 0, val = static_cast<int>(c[i]);
                switch(val){ 
                    case 'R':swap = RED;break;case 'O':swap = ORANGE;break;
                    case 'Y':swap = YELLOW;break;case 'G':swap = GREEN;break;
                    case 'B':swap = BLUE; break;case 'I':swap = INDIGO;break;
                    case 'V':swap = VIOLET;break;default:cout  <<  "WRONG COLOR"  <<  endl;
                } 
                c[i] = swap;
                canvas = c[i];
                cin >> dummy;
                count++;
            }
            if (count  ==  1){
                cout  <<  "Is it the end of your turn? Type Y or N."  <<  endl;
                cin >> endTurn;
                while (endTurn != 'Y' && endTurn != 'N'){
                    cout  <<  "Invalid choice. Enter Y or N."  <<  endl;
                    cin >> endTurn;
                }
                if (endTurn  ==  'Y')
                    count++;
            }
        }
    }
}

void crntRul(const int canvas){
    enum Colors {VIOLET=1,INDIGO,BLUE,GREEN,YELLOW,ORANGE,RED};
    if (canvas  ==  RED)
        cout << "The current rule is Red. To win you must play the highest value card."  << endl;
    else if (canvas  ==  ORANGE)
        cout << "The current rule is Orange. To win you must have the most cards of one number."  << endl;
    else if (canvas  ==  YELLOW)
        cout << "The current rule is Yellow. To win you must have the most cards of one color."  << endl;
    else if (canvas  ==  GREEN)
        cout << "The current rule is Green. To win you must have the most even cards."  << endl;
    else if (canvas  ==  BLUE)
        cout << "The current rule is Blue. To win you must have the most differing colors. (ROYGBIV). " << endl;
    else if (canvas  ==  INDIGO)
        cout << "The current rule is Indigo. To win you must have the largest run of cards (i.e. [1,2,3] or [3,4,5], etc.)" << endl;
    else if (canvas  ==  VIOLET)    
        cout << "The current rule is Violet. To win you must have the most cards with values less than 4." << endl;
}

void red(const int a[], const int b[]){
    int hghVal1, highC1;
    hghVal1=a[7];highC1=b[7];
    for(int i=0;i<7;i++){
        if(a[i]>hghVal1){
            hghVal1=a[i];
            highC1=b[i];
        }
        else if (a[i] == hghVal1){
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
        else if (a[i] == hghVal2){
            if(b[i]>highC2)
                highC2=b[i];
        }
    }
//Compares both players hghValest value card
    if (hghVal1>hghVal2)cout << "Player 1 is winning." << endl;
    else if (hghVal1<hghVal2)cout << "Player 2 is winning." << endl;
    else if (hghVal1 == hghVal2){
        if (highC1>highC2)
            cout << "Player 1 is currently winning." << endl;
        else
            cout << "Player 2 is currently winning." << endl;
    }
}

void orange(const int a[],const int b[]){
    int mxCnt1=0, hghVal1=0,highC1=0;
    for (int i=1; i<=7;i++){
        int tCount=0,tColor=0,tHigh=i;
        for(int j=0;j<8;j++){
            if(a[j] == i){
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
            if(a[j] == i){
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
        cout << "Player 1 is currently winning." << endl;
    else if (mxCnt1 < mxCnt2)
        cout << "Player 2 is currently winning." << endl;
    else if (mxCnt1  ==  mxCnt2){
        if (hghVal1 > hghVal2)
            cout << "Player 1 is currently winning." << endl;
        else if (hghVal1 < hghVal2)
            cout << "Player 2 is currently winning." << endl;
        else if (hghVal1  ==  hghVal2){
            if (highC1>highC2)
                cout << "Player 1 is currently winning." << endl;
            else 
                cout << "Player 2 is currently winning." << endl;
        }
    }
}

void yellow(const int a[],const int b[]){
    enum Colors {VIOLET=1,INDIGO,BLUE,GREEN,YELLOW,ORANGE,RED};
    int mxCnt1=0, hghVal1=0,highC1=0;
    for (int color=VIOLET; color<=RED;color++){
        int tCount=0,tColor=color,tHigh=0;
        for(int j=0;j<8;j++){
            if(b[j] == color){
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
            if(b[j] == color){
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
        cout << "Player 1 is currently winning." << endl;
    else if (mxCnt1 < mxCnt2)
        cout << "Player 2 is currently winning." << endl;
    else if (mxCnt1  ==  mxCnt2){
        if (hghVal1 > hghVal2)
            cout << "Player 1 is currently winning." << endl;
        else if (hghVal1 < hghVal2)
            cout << "Player 2 is currently winning." << endl;
        else if (hghVal1  ==  hghVal2){
            if (highC1>highC2)
                cout << "Player 1 is currently winning." << endl;
            else 
                cout << "Player 2 is currently winning." << endl;
        }
    }
}

void green(const int a[],const int b[]){
    int mxCnt1=0,hghVal1=0, highC1=0;
    for(int i=0;i<8;i++){
        if(a[i] %2 == 0 && a[i] != 0){
            mxCnt1++;
            if(a[i]>hghVal1){
                hghVal1=a[i];
                highC1=b[i];
            }
            else if (a[i] == hghVal1 && a[i]!=0){
                if(b[i]>highC1){
                    hghVal1=a[i];
                    highC1=b[i];
                }
            }
        }
    }
    
    int mxCnt2=0, hghVal2=0, highC2=0;
    for(int i=8;i<16;i++){
        if(a[i] %2 == 0 && a[i] != 0){
            mxCnt2++;
            if(a[i]>hghVal2){
                hghVal2=a[i];
                highC2=b[i];
            }
            else if (a[i] == hghVal2 && a[i] !=0){
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
        cout << "Player 1 is currently winning." << endl;
    else if (mxCnt1 < mxCnt2)
        cout << "Player 2 is currently winning." << endl;
    else if (mxCnt1  ==  mxCnt2){
        if (hghVal1 > hghVal2)
            cout << "Player 1 is currently winning." << endl;
        else if (hghVal1 < hghVal2)
            cout << "Player 2 is currently winning." << endl;
        else if (hghVal1  ==  hghVal2){
            if (highC1>highC2)
                cout << "Player 1 is currently winning." << endl;
            else 
                cout << "Player 2 is currently winning." << endl;
        }
    }
}

void blue(const int a[],const int b[]){
    enum Colors {VIOLET=1,INDIGO,BLUE,GREEN,YELLOW,ORANGE,RED};
    int mxCnt1=0;
    for (int color=VIOLET;color<=RED;color++){
        for (int i=0;i<8;i++){
            if(b[i] == color){
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
        else if (a[i] == hghVal1){
            if(b[i]>highC1)
                highC1=b[i];
        }
    }
    //Player 2
    int mxCnt2=0;
    for (int color=VIOLET;color<=RED;color++){
        for (int i=8;i<16;i++){
            if(b[i] == color){
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
        else if (a[i] == hghVal2){
            if(b[i]>highC2)
                highC2=b[i];
        }
    }
    //Compares both players hghValest value card
    //To determine who has won the round in Yellow Rule.
    if (mxCnt1 > mxCnt2)
        cout << "Player 1 is currently winning." << endl;
    else if (mxCnt1 < mxCnt2)
        cout << "Player 2 is currently winning." << endl;
    else if (mxCnt1  ==  mxCnt2){
        if (hghVal1 > hghVal2)
            cout << "Player 1 is currently winning." << endl;
        else if (hghVal1 < hghVal2)
            cout << "Player 2 is currently winning." << endl;
        else if (hghVal1  ==  hghVal2){
            if (highC1>highC2)
                cout << "Player 1 is currently winning." << endl;
            else 
                cout << "Player 2 is currently winning." << endl;
        }
    }
}


void srtCrds(const int a[],const int b[],int size){
    //Player 1
    int index1a[size/2] = {0};
    int index1b[size/2] = {0};
    int num_cards       = 0;
    
    for (int i = 0; i < 8; i++){
        if(a[i] != 0){
            index1a[num_cards] = a[i];
            index1b[num_cards] = b[i];
            num_cards++;
        }
    }
    for (int begin = 0; begin < num_cards; begin++){
        int minIndx = begin;
        
        for (int i = begin + 1; i < num_cards; i++){
            
            if (index1a[i] < index1a[minIndx]){
                minIndx = i;
            }
            else if (index1a[i]  ==  index1a[minIndx]){
                if (index1b[i] > index1b[minIndx])
                    minIndx = i;
            }
        }
        //Swap
        int temp = index1a[minIndx];
        index1a[minIndx] = index1a[begin];
        index1a[begin]   = temp;
        temp             = index1b[minIndx];
        index1b[minIndx] = index1b[begin];
        index1b[begin]   = temp;
    }
    //Player 2
    int index2a[size/2] = {0};
    int index2b[size/2] = {0};
    int num_cards2      = 0;
    for (int i = 8; i < 16; i++){
        if(a[i] != 0){
            index2a[num_cards2] = a[i];
            index2b[num_cards2] = b[i];
            num_cards2++;
        }
    }
     for (int begin = 0; begin < num_cards2; begin++){
        int minIndx = begin;
        
        for (int i = begin + 1; i < num_cards2; i++){
            
            if (index2a[i] < index2a[minIndx]){
                minIndx = i;
            }
            else if (index2a[i]  ==  index2a[minIndx]){
                if (index2b[i] > index2b[minIndx])
                    minIndx = i;
            }
        }
        int temp         = index2a[minIndx];
        index2a[minIndx] = index2a[begin];
        index2a[begin]   = temp;
        temp             = index2b[minIndx];
        index2b[minIndx] = index2b[begin];
        index2b[begin]   = temp;
    }
//    Call function for Indigo Rule
    indigo(index1a,index1b,index2a,index2b,num_cards,num_cards2);
}

void indigo(int a[],int b[],int c[],int d[],int count1,int count2){
    int mxCnt1=1, hghVal1=a[0],highC1=b[0],totadd1=0;
    for (int i=0; i<count1;i++){
        int add=1,tCount=1,tColor=a[0],tHigh=b[0], j;
        for ( j=i+1;j<=count1;j++){
            if ((a[i]+add) == a[j]){
                tCount++;
                add++;
                totadd1++;
                tHigh= a[j];
                tColor= b[j];
            }
        }
        if (totadd1 == 0 && i == count1-1){
            hghVal1=a[0];highC1=b[0];
            for(int k=1;k<=count1;k++){
                if(a[k]>hghVal1){
                    tHigh= a[k];
                    tColor=b[k];
                }
            }
        }
        if(tCount>mxCnt1 || (tCount  ==  mxCnt1 && tHigh>hghVal1)){
                mxCnt1=tCount;
                hghVal1=tHigh;
                highC1=tColor;
        }
    }
    
    int mxCnt2=1, hghVal2=c[0],highC2=d[0],totadd2=0;
    for (int i=0; i<count1;i++){
        int add=1,tCount=1,tColor=c[0],tHigh=d[0], j;
        for ( j=i+1;j<=count1;j++){
            if ((c[i]+add) == c[j]){
                tCount++;
                add++;
                totadd2++;
                tHigh= c[j];
                tColor= d[j];
            }
        }
        if (totadd2 == 0 && i == count1-1){
            hghVal2=c[0];highC2=d[0];
            for(int k=1;k<=count1;k++){
                if(c[k]>hghVal2){
                    tHigh=c[k];
                    tColor=d[k];
                }
            }
        }
        if(tCount>mxCnt2 || (tCount  ==  mxCnt2 && tHigh>hghVal2)){
                mxCnt2=tCount;
                hghVal2=tHigh;
                highC2=tColor;
        }
    }
    if (mxCnt1 > mxCnt2)
        cout << "Player 1 is currently winning." << endl;
    else if (mxCnt1 < mxCnt2)
        cout << "Player 2 is currently winning." << endl;
    else if (mxCnt1  ==  mxCnt2){
        if (hghVal1 > hghVal2)
            cout << "Player 1 is currently winning." << endl;
        else if (hghVal1 < hghVal2)
            cout << "Player 2 is currently winning." << endl;
        else if (hghVal1  ==  hghVal2){
            if (highC1>highC2)
                cout << "Player 1 is currently winning." << endl;
            else 
                cout << "Player 2 is currently winning." << endl;
        }
    }
}

void violet(const int a[],const int b[]){
    int mxCnt1=0,hghVal1=0, highC1=0;
    for(int i=0;i<8;i++){
        if(a[i]<=3){
            mxCnt1++;
            if(a[i]>hghVal1){
                hghVal1=a[i];
                highC1=b[i];
            }
            else if (a[i] == hghVal1 && a[i]!=0){
                if(b[i]>highC1){
                    hghVal1=a[i];
                    highC1=b[i];
                }
            }
        }
    }
    
    int mxCnt2=0, hghVal2=0, highC2=0;
    for(int i=8;i<16;i++){
        if(a[i]<=3){
            mxCnt2++;
            if(a[i]>hghVal2){
                hghVal2=a[i];
                highC2=b[i];
            }
            else if (a[i] == hghVal2 && a[i] !=0){
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
        cout << "Player 1 is currently winning." << endl;
    else if (mxCnt1 < mxCnt2)
        cout << "Player 2 is currently winning." << endl;
    else if (mxCnt1  ==  mxCnt2){
        if (hghVal1 > hghVal2)
            cout << "Player 1 is currently winning." << endl;
        else if (hghVal1 < hghVal2)
            cout << "Player 2 is currently winning." << endl;
        else if (hghVal1  ==  hghVal2){
            if (highC1>highC2)
                cout << "Player 1 is currently winning." << endl;
            else 
                cout << "Player 2 is currently winning." << endl;
        }
    }
}

bool giveUp(const int turn){
    cout << endl << endl;
    char choice;
    if (turn % 2 == 1)
        cout  <<  "Player 1, do you resign?"  <<  endl;
    else
        cout  <<  "Player 2, do you resign?"  <<  endl;
        cin >> choice;
        while (choice != 'Y' && choice !='N'){
            cout  <<  "Error Wrong Selection. Repeat, Y or N?"  <<  endl;
            cin >> choice;
        }
        if (choice  ==  'N')
            return true;
        else 
            return false;
}

int turnCnt(int turn){
    static int nextPlr = turn;
    static int check = 0;
    nextPlr++;
    check++;
    if (nextPlr - check  ==  0)
        cout << "End of turn: " << nextPlr  << "." << endl;
    else
        cout << "End of turn: " << nextPlr - 1 << "." << endl;
    return nextPlr;
}

void gameEnd(const int turn, const int finish, ifstream &in, ofstream &out, string &victor, bool &open){
    turn % 2 == 0 ? out<<"Congratulations Player 1. You have won the game.":
                    out<<"Congratulations Player 2. You have won the game.";
    //closing the file so I can read in the input from that file
    out.close();
    //Opening the Input file
    in.open("WinnerWinnerChickenDinner.txt");
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
    cout << "The end is nigh!" << endl;
}

bool linSrch(const char color, const int value, string hand[], const char cHand[],const int iHand[], const int start,  const int end){
    int index;
    int position = -1;
    bool isInHnd = false;
    for (index = start; index < end; index++){
        if (color == cHand[index]){
            if(value == iHand[index]){
                position = index;
                hand[position] = "";
                isInHnd = true;
                cout << index << endl;
            }
        }
        else if (position == -1 && index == end - 1)
            cout << " This card is not in your hand. Play another card. ";
    }
    return isInHnd;
}
