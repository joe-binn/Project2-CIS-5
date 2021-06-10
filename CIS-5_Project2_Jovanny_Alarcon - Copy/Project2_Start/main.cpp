 /*
    Author: Jovanny Alarcon
    Date:   May 17th, 2021  1:30PM
    Purpose: Generating Cards
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

//Execution Begins Here
int main(int argc, char** argv) {
    //Set the Random number seed
     srand(static_cast<unsigned int>(time(0)));
     
    //Declare variables & Initialized Variable
     ifstream in;
     ofstream out;
     bool open;
     float finish;
    char choice;
    char cHand1=0,cHand2=0,cHand3=0,cHand4=0,cHand5=0,cHand6=0,cHand7=0,cHand8=0, //Player 1 unique color per card
         cHand9=0,cHand10=0,cHand11=0,cHand12=0,cHand13=0,cHand14=0,cHand15=0,cHand16=0; // Player 2 unique color per card
    char display1,display2,display3,display4,display5,display6,display7,display8, //To display the color of the card
         display9,display10,display11,display12,display13,display14,display15,display16; //To display the color of the card
    int  iHand1=0,iHand2=0,iHand3=0,iHand4=0,iHand5=0,iHand6=0,iHand7=0,iHand8=0,   //Player 1 unique number per card
         iHand9=0,iHand10=0,iHand11=0,iHand12=0,iHand13=0,iHand14=0,iHand15=0,iHand16=0,  //Player unique number per card
         palet1=0,palet2=0,palet3=0,palet4=0,palet5=0,palet6=0,palet7=0,palet8,    //Player 1 cin value choice 
         palet9=0,palet10=0,palet11=0,palet12=0,palet13=0,palet14=0,palet15=0,palet16;//player 2 cin value choice
    string hand1="",hand2="",hand3="",hand4="",hand5="",hand6="",hand7="",hand8="", //Displays starting player 1 hand
           hand9="",hand10="",hand11="",hand12="",hand13="",hand14="",hand15="",hand16=""; //displays player 2 starting hand
    
    //Initialize variables
    out.open("whowon.txt");
    string victor="";
    enum Colors {V=1,I,B,G,Y,O,R};
    finish=10;
    int rand1,rand2,rand3,rand4,rand5,rand6,rand7,rand8,
        rand9,rand10,rand11,rand12,rand13,rand14,rand15,rand16,
        random;
    int color1,color2,color3,color4,color5,color6,color7,color8,  //To possibly validate user cards and have them resubmit if wrong
         color9,color10,color11,color12,color13,color14,color15,color16;
    int cPalet1=0,cPalet2=0,cPalet3=0,cPalet4=0,cPalet5=0,cPalet6=0,cPalet7=0,cPalet8,
        cPalet9=0,cPalet10=0,cPalet11=0,cPalet12=0,cPalet13=0,cPalet14=0,cPalet15=0,cPalet16;
    int canvas1=0,canvas2=0,canvas3=0,canvas4=0,canvas5=0,canvas6=0,canvas7=0,canvas8=0,
        canvas9=0,canvas10=0,canvas11=0,canvas12=0,canvas13=0,canvas14=0,canvas15=0,canvas16=0,
        canvas;
    char cTemp;
    int  iTemp, tempCol;
    
     //Assigning 16 random numbers for the for loop
    rand1=rand()%49+1;
    do{rand2=rand()%49+1;} while(rand2 == rand1);
    do{rand3=rand()%49+1;} while(rand3 == rand1 || rand3 == rand2);
    do{rand4=rand()%49+1;} while(rand4 == rand1 || rand4 == rand2 || rand4 == rand3);
    do{rand5=rand()%49+1;} while(rand5 == rand1 || rand5 == rand2 || rand5 == rand3 || rand5 == rand4);
    do{rand6=rand()%49+1;} while(rand6 == rand1 || rand6 == rand2 || rand6 == rand3 || rand6 == rand4 || rand6 == rand5);
    do{rand7=rand()%49+1;} while(rand7 == rand1 || rand7 == rand2 || rand7 == rand3 || rand7 == rand4 || rand7 == rand5 || rand7 == rand6);
    do{rand8=rand()%49+1;} while(rand8 == rand1 || rand8 == rand2 || rand8 == rand3 || rand8 == rand4 || rand8 == rand5 || rand8 == rand6 || rand8 == rand7);
    do{rand9=rand()%49+1;} while(rand9 == rand1 || rand9 == rand2 || rand9 == rand3 || rand9 == rand4 || rand9 == rand5 || rand9 == rand6 || rand9 == rand7 && rand9 != rand8);
    do{rand10=rand()%49+1;}while(rand10 == rand1 || rand10 == rand2 || rand10 == rand3 || rand10 == rand4 || rand10 == rand5 || rand10 == rand6 || rand10 == rand7 || rand10 == rand8 || rand10 == rand9);
    do{rand11=rand()%49+1;}while(rand11 == rand1 || rand11 == rand2 || rand11 == rand3 || rand11 == rand4 || rand11 == rand5 || rand11 == rand6 || rand11 == rand7 || rand11 == rand8 || rand11 == rand9 || rand11 == rand10);
    do{rand12=rand()%49+1;}while(rand12 == rand1 || rand12 == rand2 || rand12 == rand3 || rand12 == rand4 || rand12 == rand5 || rand12 == rand6 || rand12 == rand7 || rand12 == rand8 || rand12 == rand9 || rand12 == rand10 || rand12 == rand11);
    do{rand13=rand()%49+1;}while(rand13 == rand1 || rand13 == rand2 || rand13 == rand3 || rand13 == rand4 || rand13 == rand5 || rand13 == rand6 || rand13 == rand7 || rand13 == rand8 || rand13 == rand9 || rand13 == rand10 || rand13 == rand11 || rand13 == rand12);
    do{rand14=rand()%49+1;}while(rand14 == rand1 || rand14 == rand2 || rand14 == rand3 || rand14 == rand4 || rand14 == rand5 || rand14 == rand6 || rand14 == rand7 || rand14 == rand8 || rand14 == rand9 || rand14 == rand10 || rand14 == rand11 || rand14 == rand12 || rand14 == rand13);
    do{rand15=rand()%49+1;}while(rand15 == rand1 || rand15 == rand2 || rand15 == rand3 || rand15 == rand4 || rand15 == rand5 || rand15 == rand6 || rand15 == rand7 || rand15 == rand8 || rand15 == rand9 || rand15 == rand10 || rand15 == rand11 || rand15 == rand12 || rand15 == rand13 || rand15 == rand14);
    do{rand16=rand()%49+1;}while(rand16 == rand1 || rand16 == rand2 || rand16 == rand3 || rand16 == rand4 || rand16 == rand5 || rand16 == rand6 || rand16 == rand7 || rand16 == rand8 || rand16 == rand9 || rand16 == rand10 || rand16 == rand11 || rand16 == rand12 || rand16 == rand13 || rand16 == rand14 || rand16 == rand15);
    
    //Creating strings for unique cards for each player
    for (int i=1; i<=16;i++){ 
        if(i==1) random=rand1;
        if(i==2) random=rand2;
        if(i==3) random=rand3;
        if(i==4) random=rand4;
        if(i==5) random=rand5;
        if(i==6) random=rand6;
        if(i==7) random=rand7;
        if(i==8) random=rand8;
        if(i==9) random=rand9;
        if(i==10)random=rand10;
        if(i==11)random=rand11;
        if(i==12)random=rand12;
        if(i==13)random=rand13;
        if(i==14)random=rand14;
        if(i==15)random=rand15;
        if(i==16)random=rand16;
        //Every random number generated will be assigned a specific card
        switch (random){
            case 49: cTemp = 'R'; iTemp=7;tempCol=R;break; case 48: cTemp = 'R'; iTemp=6;tempCol=R;break;
            case 47: cTemp = 'R'; iTemp=5;tempCol=R;break; case 46: cTemp = 'R'; iTemp=4;tempCol=R;break;
            case 45: cTemp = 'R'; iTemp=3;tempCol=R;break; case 44: cTemp = 'R'; iTemp=2;tempCol=R;break;
            case 43: cTemp = 'R'; iTemp=1;tempCol=R;break; 
            
            case 42: cTemp = 'O'; iTemp=7;tempCol=O;break; case 41: cTemp = 'O'; iTemp=6;tempCol=O;break;
            case 40: cTemp = 'O'; iTemp=5;tempCol=O;break; case 39: cTemp = 'O'; iTemp=4;tempCol=O;break;
            case 38: cTemp = 'O'; iTemp=3;tempCol=O;break; case 37: cTemp = 'O'; iTemp=2;tempCol=O;break;
            case 36: cTemp = 'O'; iTemp=1;tempCol=O;break; 
            
            case 35: cTemp = 'Y'; iTemp=7;tempCol=Y;break; case 34: cTemp = 'Y'; iTemp=6;tempCol=Y;break;
            case 33: cTemp = 'Y'; iTemp=5;tempCol=Y;break; case 32: cTemp = 'Y'; iTemp=4;tempCol=Y;break;
            case 31: cTemp = 'Y'; iTemp=3;tempCol=Y;break; case 30: cTemp = 'Y'; iTemp=2;tempCol=Y;break;
            case 29: cTemp = 'Y'; iTemp=1;tempCol=Y;break; 
            
            case 28: cTemp = 'G'; iTemp=7;tempCol=G;break; case 27: cTemp = 'G'; iTemp=6;tempCol=G;break;
            case 26: cTemp = 'G'; iTemp=5;tempCol=G;break; case 25: cTemp = 'G'; iTemp=4;tempCol=G;break;
            case 24: cTemp = 'G'; iTemp=3;tempCol=G;break; case 23: cTemp = 'G'; iTemp=2;tempCol=G;break;
            case 22: cTemp = 'G'; iTemp=1;tempCol=G;break; 
            
            case 21: cTemp = 'B'; iTemp=7;tempCol=B;break; case 20: cTemp = 'B'; iTemp=6;tempCol=B;break;
            case 19: cTemp = 'B'; iTemp=5;tempCol=B;break; case 18: cTemp = 'B'; iTemp=4;tempCol=B;break;
            case 17: cTemp = 'B'; iTemp=3;tempCol=B;break; case 16: cTemp = 'B'; iTemp=2;tempCol=B;break;
            case 15: cTemp = 'B'; iTemp=1;tempCol=B;break; 
            
            case 14: cTemp = 'I'; iTemp=7;tempCol=I;break; case 13: cTemp = 'I'; iTemp=6;tempCol=I;break;
            case 12: cTemp = 'I'; iTemp=5;tempCol=I;break; case 11: cTemp = 'I'; iTemp=4;tempCol=I;break;
            case 10: cTemp = 'I'; iTemp=3;tempCol=I;break; case 9:  cTemp = 'I'; iTemp=2;tempCol=I;break;
            case 8:  cTemp = 'I'; iTemp=1;tempCol=I;break;  
            
            case 7:  cTemp = 'V'; iTemp=7;tempCol=V;break; case 6:  cTemp = 'V'; iTemp=6;tempCol=V;break;
            case 5:  cTemp = 'V'; iTemp=5;tempCol=V;break; case 4:  cTemp = 'V'; iTemp=4;tempCol=V;break;
            case 3:  cTemp = 'V'; iTemp=3;tempCol=V;break; case 2:  cTemp = 'V'; iTemp=2;tempCol=V;break;
            case 1:  cTemp = 'V'; iTemp=1;tempCol=V;break; 
        }
        //After the random number generated number has been assigned a case, the program
        //will assign the players character color and value of the card, as well as assigning the starting hand
        if (i==1){
            cHand1=cTemp; iHand1=iTemp;
            color1=tempCol;
            hand1+=cTemp;hand1+=static_cast<char>(iTemp+48);
        }
        if (i==2){
            cHand2=cTemp; iHand2=iTemp;
            color2=tempCol;
            hand2+=cTemp;hand2+=static_cast<char>(iTemp+48);
        }
        if (i==3){
            cHand3=cTemp; iHand3=iTemp;
            color3=tempCol;
            hand3+=cTemp;hand3+=static_cast<char>(iTemp+48);
        }
        if (i==4){
            cHand4=cTemp; iHand4=iTemp;
            color4=tempCol;
            hand4+=cTemp;hand4+=static_cast<char>(iTemp+48);
        }
        if (i==5){
            cHand5=cTemp; iHand5=iTemp;
            color5=tempCol;
            hand5+=cTemp;hand5+=static_cast<char>(iTemp+48);
        }
        if (i==6){
            cHand6=cTemp; iHand6=iTemp;
            color6=tempCol;
            hand6+=cTemp;hand6+=static_cast<char>(iTemp+48);
        }
        if (i==7){
            cHand7=cTemp; iHand7=iTemp;
            color7=tempCol;
            hand7+=cTemp;hand7+=static_cast<char>(iTemp+48);
        }
        if (i==8){
            cHand8=cTemp; iHand8=iTemp;
            color8=tempCol;
            hand8+=cTemp;hand8+=static_cast<char>(iTemp+48);
        }
        if (i==9){
            cHand9=cTemp; iHand9=iTemp;
            color9=tempCol;
            hand9+=cTemp;hand9+=static_cast<char>(iTemp+48);
        }
        if (i==10){
            cHand10=cTemp; iHand10=iTemp;
            color10=tempCol;
            hand10+=cTemp;hand10+=static_cast<char>(iTemp+48);
        }
        if (i==11){
            cHand11=cTemp; iHand11=iTemp;
            color11=tempCol;
            hand11+=cTemp;hand11+=static_cast<char>(iTemp+48);
        }
        if (i==12){
            cHand12=cTemp; iHand12=iTemp;
            color12=tempCol;
            hand12+=cTemp;hand12+=static_cast<char>(iTemp+48);
        }
        if (i==13){
            cHand13=cTemp; iHand13=iTemp;
            color13=tempCol;
            hand13+=cTemp;hand13+=static_cast<char>(iTemp+48);
        }
        if (i==14){
            cHand14=cTemp; iHand14=iTemp;
            color14=tempCol;
            hand14+=cTemp;hand14+=static_cast<char>(iTemp+48);
        }
        if (i==15){
            cHand15=cTemp; iHand15=iTemp;
            color15=tempCol;
            hand15+=cTemp;hand15+=static_cast<char>(iTemp+48);
        }
        if (i==16){
            cHand16=cTemp; iHand16=iTemp;
            color16=tempCol;
            hand16+=cTemp;hand16+=static_cast<char>(iTemp+48);
        }
        
    }           
    //Determining who goes first, Current rule RED: Highest Number. If equal best color ROYGBIV; Compare card8 with card16
    palet8=iHand8; palet16=iHand16;  //Player's 1st card value
    cPalet8=color8; cPalet16=color16; //Player's 1st color value
    int turn; //To determine who's turn it is
    if (palet8>palet16){cout<<"Player 2 goes first."<<endl;turn=0;} //Will start with player 2
    else if (palet8<palet16){cout<<"Player 1 goes first."<<endl;turn=1;} //will start with player 1
    else if (palet8==palet16){
        if (cPalet8>cPalet16){cout<<"Player 2 goes first."<<endl;turn=0;} //Will start with player 2
        else if (cPalet8<cPalet16){cout<<"Player 1 goes first."<<endl;turn=1;} //will start with player 1
    }
    cout<<"The current rule is Red. To win you must play the highest value card."<<endl;
    //Display Hands
    cout<<"Player 1: Your hand is "<<hand1<<", "<<hand2<<", "<<hand3<<", "<<hand4<<", "
                                   <<hand5<<", "<<hand6<<", "<<hand7<<endl;
    cout<<"Player 2: Your hand is "<<hand9<<", "<<hand10<<", "<<hand11<<", "<<hand12<<", "
                                   <<hand13<<", "<<hand14<<", "<<hand15<<endl;
    canvas=R;//canvas rule always starts at Red
    char palorcan,end;
    
    //Do-while loop will go through each player's turn and check if that player
    //is winning by the end of each round.
    do{
        //Displays Player 1's Palette as the player adds to it each round
        cout<<"Player 1's Palette: ";
        cout<<hand8<<", "<<display1<<palet1<<", "<<display2<<palet2<<", "<<display3<<palet3<<", "<<display4<<palet4<<", "
            <<display5<<palet5<<", "<<display6<<palet6<<", "<<display7<<palet7<<endl;
        //Displays Player 2's Palette as the player adds to it each round
        cout<<"Player 2's Palette: ";
        cout<<hand16<<", "<<display9<<palet9<<", "<<display10<<palet10<<", "<<display11<<palet11<<", "<<display12<<palet12<<", "
            <<display13<<palet13<<", "<<display14<<palet14<<", "<<display15<<palet15<<endl;
        end='0';
        //Player 1's turns/rounds
        //Gives the user the option to play 1 or 2 cards
        if (turn%2==1){ 
            cout<<"It is Player 1s Turn."<<endl;
            if (palet1 == 0 && canvas1==0){
                cout<<"Press p to play a card of c to discard to canvas"<<endl;
                cin>>palorcan;
                if (palorcan=='p'){
                    cout<<"Play the value then the color"<<endl;
                    cin>>palet1>>display1;
                int swap = 0, val=static_cast<int>(display1);
                switch(val){ 
                        case 'R':swap = R;break;case 'O':swap = O;break;
                        case 'Y':swap = Y;break;case 'G':swap = G;break;
                        case 'B':swap = B; break;case 'I':swap = I;break;
                        case 'V':swap = V;break;default:cout << "WRONG COLOR" << endl;
                    } cPalet1=swap;
                }
                else if (palorcan=='c'){
                    cout<<"Discard a card, type the color"<<endl;
                    cin>>canvas1;
                    canvas=canvas1;
                }
                cout<<"Is it the end of your turn? Type y or n."<<endl;
                cin>>end;
            }
            
            if ((end=='n' || end =='0') && palet2 == 0 && canvas2==0){
                cout<<"Press p to play a card of c to discard to canvas"<<endl;
                cin>>palorcan;
                if (palorcan=='p'){
                    cout<<"Play the value then the color"<<endl;
                    cin>>palet2>>display2;
                int swap = 0, val=static_cast<int>(display2);
                switch(val){ 
                        case 'R':swap = R;break;case 'O':swap = O;break;
                        case 'Y':swap = Y;break;case 'G':swap = G;break;
                        case 'B':swap = B; break;case 'I':swap = I;break;
                        case 'V':swap = V;break;default:cout << "WRONG COLOR" << endl;
                    } cPalet2=swap;
                }
                else if (palorcan=='c'){
                    cout<<"Discard a card, type the color"<<endl;
                    cin>>canvas2;
                    canvas=canvas2;
                }
                cout<<"Is it the end of your turn? Type y or n."<<endl;
                cin>>end;
            }
        
            if ((end=='n' || end =='0') && palet3 == 0 && canvas3==0){
                cout<<"Press p to play a card of c to discard to canvas"<<endl;
                cin>>palorcan;
                if (palorcan=='p'){
                    cout<<"Play the value then the color"<<endl;
                    cin>>palet3>>display3;
                int swap = 0, val=static_cast<int>(display3);
                switch(val){ 
                        case 'R':swap = R;break;case 'O':swap = O;break;
                        case 'Y':swap = Y;break;case 'G':swap = G;break;
                        case 'B':swap = B; break;case 'I':swap = I;break;
                        case 'V':swap = V;break;default:cout << "WRONG COLOR" << endl;
                    } cPalet3=swap;
                }
                else if (palorcan=='c'){
                    cout<<"Discard a card, type the color"<<endl;
                    cin>>canvas3;
                    canvas=canvas3;
                }
                cout<<"Is it the end of your turn? Type y or n."<<endl;
                cin>>end;
            }
        
            if ((end=='n' || end =='0') && palet4 == 0 && canvas4==0){
                cout<<"Press p to play a card of c to discard to canvas"<<endl;
                cin>>palorcan;
                if (palorcan=='p'){
                    cout<<"Play the value then the color"<<endl;
                    cin>>palet4>>display4;
                int swap = 0, val=static_cast<int>(display4);
                switch(val){ 
                        case 'R':swap = R;break;case 'O':swap = O;break;
                        case 'Y':swap = Y;break;case 'G':swap = G;break;
                        case 'B':swap = B; break;case 'I':swap = I;break;
                        case 'V':swap = V;break;default:cout << "WRONG COLOR" << endl;
                    } cPalet4=swap;
                }
                else if (palorcan=='c'){
                    cout<<"Discard a card, type the color"<<endl;
                    cin>>canvas4;
                    canvas=canvas4;
                }
                cout<<"Is it the end of your turn? Type y or n."<<endl;
                cin>>end;
            }
        
            if ((end=='n' || end =='0') && palet5 == 0 && canvas5==0){
                cout<<"Press p to play a card of c to discard to canvas"<<endl;
                cin>>palorcan;
                if (palorcan=='p'){
                    cout<<"Play the value then the color"<<endl;
                    cin>>palet5>>display5;
                int swap = 0, val=static_cast<int>(display5);
                switch(val){ 
                        case 'R':swap = R;break;case 'O':swap = O;break;
                        case 'Y':swap = Y;break;case 'G':swap = G;break;
                        case 'B':swap = B; break;case 'I':swap = I;break;
                        case 'V':swap = V;break;default:cout << "WRONG COLOR" << endl;
                    } cPalet5=swap;
                }
                else if (palorcan=='c'){
                    cout<<"Discard a card, type the color"<<endl;
                    cin>>canvas5;
                    canvas=canvas5;
                }
                cout<<"Is it the end of your turn? Type y or n."<<endl;
                cin>>end;
            }
        
            if ((end=='n' || end =='0') && palet6 == 0 && canvas6==0){
                cout<<"Press p to play a card of c to discard to canvas"<<endl;
                cin>>palorcan;
                if (palorcan=='p'){
                    cout<<"Play the value then the color"<<endl;
                    cin>>palet6>>display6;
                int swap = 0, val=static_cast<int>(display6);
                switch(val){ 
                        case 'R':swap = R;break;case 'O':swap = O;break;
                        case 'Y':swap = Y;break;case 'G':swap = G;break;
                        case 'B':swap = B; break;case 'I':swap = I;break;
                        case 'V':swap = V;break;default:cout << "WRONG COLOR" << endl;
                    } cPalet6=swap;
                }
                else if (palorcan=='c'){
                    cout<<"Discard a card, type the color"<<endl;
                    cin>>canvas6;
                    canvas=canvas6;
                }
                cout<<"Is it the end of your turn? Type y or n."<<endl;
                cin>>end;
            }
        
            if ((end=='n' || end =='0') && palet7 == 0 && canvas7==0){
                cout<<"Press p to play a card of c to discard to canvas"<<endl;
                cin>>palorcan;
                if (palorcan=='p'){
                    cout<<"Play the value then the color"<<endl;
                    cin>>palet7>>display7;
                int swap = 0, val=static_cast<int>(display7);
                switch(val){ 
                        case 'R':swap = R;break;case 'O':swap = O;break;
                        case 'Y':swap = Y;break;case 'G':swap = G;break;
                        case 'B':swap = B; break;case 'I':swap = I;break;
                        case 'V':swap = V;break;default:cout << "WRONG COLOR" << endl;
                    } cPalet7=swap;
                }
                else if (palorcan=='c'){
                    cout<<"Discard a card, type the color"<<endl;
                    cin>>canvas7;
                    canvas=canvas7;
                }
                cout<<"Is it the end of your turn? Type y or n."<<endl;
                cin>>end;
            }
        }
        
        //Player 2's turns/rounds
        //Gives the user the ability to play 1 or 2 cards
        if (turn%2==0){
            cout<<"It is Player 2s Turn."<<endl;
            if (palet9 == 0 && canvas9==0){
                cout<<"Press p to play a card of c to discard to canvas"<<endl;
                cin>>palorcan;
                if (palorcan=='p'){
                    cout<<"Play the value then the color"<<endl;
                    cin>>palet9>>display9;
                int swap = 0, val=static_cast<int>(display9);
                switch(val){ 
                        case 'R':swap = R;break;case 'O':swap = O;break;
                        case 'Y':swap = Y;break;case 'G':swap = G;break;
                        case 'B':swap = B; break;case 'I':swap = I;break;
                        case 'V':swap = V;break;default:cout << "WRONG COLOR" << endl;
                    } cPalet9=swap;
                }
                else if (palorcan=='c'){
                    cout<<"Discard a card, type the color"<<endl;
                    cin>>canvas9;
                    canvas=canvas9;
                }
                cout<<"Is it the end of your turn? Type y or n."<<endl;
                cin>>end;
            }
            
            if ((end=='n' || end =='0') && palet10 == 0 && canvas10==0){
                cout<<"Press p to play a card of c to discard to canvas"<<endl;
                cin>>palorcan;
                if (palorcan=='p'){
                    cout<<"Play the value then the color"<<endl;
                    cin>>palet10>>display10;
                int swap = 0, val=static_cast<int>(display10);
                switch(val){ 
                        case 'R':swap = R;break;case 'O':swap = O;break;
                        case 'Y':swap = Y;break;case 'G':swap = G;break;
                        case 'B':swap = B; break;case 'I':swap = I;break;
                        case 'V':swap = V;break;default:cout << "WRONG COLOR" << endl;
                    } cPalet10=swap;
                }
                else if (palorcan=='c'){
                    cout<<"Discard a card, type the color"<<endl;
                    cin>>canvas10;
                    canvas=canvas10;
                }
                cout<<"Is it the end of your turn? Type y or n."<<endl;
                cin>>end;
            }
        
            if ((end=='n' || end =='0') && palet11 == 0 && canvas11==0){
                cout<<"Press p to play a card of c to discard to canvas"<<endl;
                cin>>palorcan;
                if (palorcan=='p'){
                    cout<<"Play the value then the color"<<endl;
                    cin>>palet11>>display11;
                int swap = 0, val=static_cast<int>(display11);
                switch(val){ 
                        case 'R':swap = R;break;case 'O':swap = O;break;
                        case 'Y':swap = Y;break;case 'G':swap = G;break;
                        case 'B':swap = B; break;case 'I':swap = I;break;
                        case 'V':swap = V;break;default:cout << "WRONG COLOR" << endl;
                    } cPalet11=swap;
                }
                else if (palorcan=='c'){
                    cout<<"Discard a card, type the color"<<endl;
                    cin>>canvas11;
                    canvas=canvas11;
                }
                cout<<"Is it the end of your turn? Type y or n."<<endl;
                cin>>end;
            }
        
            if ((end=='n' || end =='0') && palet12 == 0 && canvas12==0){
                cout<<"Press p to play a card of c to discard to canvas"<<endl;
                cin>>palorcan;
                if (palorcan=='p'){
                    cout<<"Play the value then the color"<<endl;
                    cin>>palet12>>display12;
                int swap = 0, val=static_cast<int>(display12);
                switch(val){ 
                        case 'R':swap = R;break;case 'O':swap = O;break;
                        case 'Y':swap = Y;break;case 'G':swap = G;break;
                        case 'B':swap = B; break;case 'I':swap = I;break;
                        case 'V':swap = V;break;default:cout << "WRONG COLOR" << endl;
                    } cPalet12=swap;
                }
                else if (palorcan=='c'){
                    cout<<"Discard a card, type the color"<<endl;
                    cin>>canvas12;
                    canvas=canvas12;
                }
                cout<<"Is it the end of your turn? Type y or n."<<endl;
                cin>>end;
            }
        
            if ((end=='n' || end =='0') && palet13 == 0 && canvas13==0){
                cout<<"Press p to play a card of c to discard to canvas"<<endl;
                cin>>palorcan;
                if (palorcan=='p'){
                    cout<<"Play the value then the color"<<endl;
                    cin>>palet13>>display13;
                int swap = 0, val=static_cast<int>(display13);
                switch(val){ 
                        case 'R':swap = R;break;case 'O':swap = O;break;
                        case 'Y':swap = Y;break;case 'G':swap = G;break;
                        case 'B':swap = B; break;case 'I':swap = I;break;
                        case 'V':swap = V;break;default:cout << "WRONG COLOR" << endl;
                    } cPalet13=swap;
                }
                else if (palorcan=='c'){
                    cout<<"Discard a card, type the color"<<endl;
                    cin>>canvas13;
                    canvas=canvas13;
                }
                cout<<"Is it the end of your turn? Type y or n."<<endl;
                cin>>end;
            }
        
            if ((end=='n' || end =='0') && palet14 == 0 && canvas14==0){
                cout<<"Press p to play a card of c to discard to canvas"<<endl;
                cin>>palorcan;
                if (palorcan=='p'){
                    cout<<"Play the value then the color"<<endl;
                    cin>>palet14>>display14;
                int swap = 0, val=static_cast<int>(display14);
                switch(val){ 
                        case 'R':swap = R;break;case 'O':swap = O;break;
                        case 'Y':swap = Y;break;case 'G':swap = G;break;
                        case 'B':swap = B; break;case 'I':swap = I;break;
                        case 'V':swap = V;break;default:cout << "WRONG COLOR" << endl;
                    } cPalet14=swap;
                }
                else if (palorcan=='c'){
                    cout<<"Discard a card, type the color"<<endl;
                    cin>>canvas14;
                    canvas=canvas14;
                }
                cout<<"Is it the end of your turn? Type y or n."<<endl;
                cin>>end;
            }
        
            if ((end=='n' || end =='0') && palet15 == 0 && canvas15==0){
                cout<<"Press p to play a card of c to discard to canvas"<<endl;
                cin>>palorcan;
                if (palorcan=='p'){
                    cout<<"Play the value then the color"<<endl;
                    cin>>palet15>>display15;
                int swap = 0, val=static_cast<int>(display15);
                switch(val){ 
                        case 'R':swap = R;break;case 'O':swap = O;break;
                        case 'Y':swap = Y;break;case 'G':swap = G;break;
                        case 'B':swap = B; break;case 'I':swap = I;break;
                        case 'V':swap = V;break;default:cout << "WRONG COLOR" << endl;
                    } cPalet15=swap;
                }
                else if (palorcan=='c'){
                    cout<<"Discard a card, type the color"<<endl;
                    cin>>canvas15;
                    canvas=canvas15;
                }
                cout<<"Is it the end of your turn? Type y or n."<<endl;
                cin>>end;
            }
        }
        
    
    //Red Card Rule, highest value card
        if (canvas==R){
            //Finds player 1's highest card
            int highest1,tColor1;
            highest1=palet8,tColor1=cPalet8; //Too check for highest value card
            if (palet1>highest1){highest1=palet1;tColor1=cPalet1;}
            else if (palet1==highest1){
                if (cPalet1 > tColor1)tColor1=cPalet1;}
            if (palet2>highest1){highest1=palet2;tColor1=cPalet2;}
            else if (palet2==highest1){
                if (cPalet2 > tColor1)tColor1=cPalet2;}
            if (palet3>highest1){highest1=palet3;tColor1=cPalet3;}
            else if (palet3==highest1){
                if (cPalet3 > tColor1)tColor1=cPalet3;}
            if (palet4>highest1){highest1=palet4;tColor1=cPalet4;}
            else if (palet4==highest1){
                if (cPalet4 > tColor1)tColor1=cPalet4;}
            if (palet5>highest1){highest1=palet5;tColor1=cPalet5;}
            else if (palet5==highest1){
                if (cPalet5 > tColor1)tColor1=cPalet5;}
            if (palet6>highest1){highest1=palet6;tColor1=cPalet6;}
            else if (palet6==highest1){
                if (cPalet6 > tColor1)tColor1=cPalet6;}
            if (palet7>highest1){highest1=palet7;tColor1=cPalet7;}
            else if (palet7==highest1){
                if (cPalet7 > tColor1)tColor1=cPalet7;}
            //Finds player 2's highest card
            int highest2,tColor2;
            highest2=palet16,tColor2=cPalet16;
            if (palet9>=highest2){highest2=palet9;tColor2=cPalet9;}
            else if (palet9==highest2){
                if (cPalet9 > tColor2)tColor2=cPalet9;}
            if (palet10>=highest2){highest2=palet10;tColor2=cPalet10;}
            else if (palet10==highest2){
                if (cPalet10 > tColor2)tColor2=cPalet10;}
            if (palet11>=highest2){highest2=palet11;tColor2=cPalet11;}
            else if (palet11==highest2){
                if (cPalet11 > tColor2)tColor2=cPalet11;}
            if (palet12>=highest2){highest2=palet12;tColor2=cPalet12;}
            else if (palet12==highest2){
                if (cPalet12 > tColor2)tColor2=cPalet12;}
            if (palet13>=highest2){highest2=palet13;tColor2=cPalet13;}
            else if (palet13==highest2){
                if (cPalet13 > tColor2)tColor2=cPalet13;}
            if (palet14>=highest2){highest2=palet14;tColor2=cPalet14;}
            else if (palet14==highest2){
                if (cPalet14 > tColor2)tColor2=cPalet14;}
            if (palet15>=highest2){highest2=palet15;tColor2=cPalet15;}
            else if (palet15==highest2){
                if (cPalet15 > tColor2)tColor2=cPalet15;}
            //Compares both players highest value card
            if (highest1>highest2)cout<<"Player 1 is winning."<<endl;
            else if (highest1<highest2)cout<<"Player 2 is winning."<<endl;
            else if (highest1==highest2){
                if (tColor1>tColor2)
                    cout<<"Player 1 is currently winning."<<endl;
                else
                    cout<<"Player 2 is currently winning."<<endl;
            }
        }

        
    //Orange Card Rule, cards of one number
        if (canvas==O){
            //Find Player 1's max count of 1 color, and highest value and highest color
            int mxCount1=0, //Max count of cards of one number
                highVal1=0, //Highest value from Max Count
                highC1=0;  //Highest color of Highest Value
            for (int i =1; i<=7; i++){
                int tCount=0,tColor=0,tHigh=i; //temp values
                if (palet1 == i){
                    tCount++;
                    if (cPalet1 > highC1)highC1=cPalet1;
                }
                if (palet2 == i){
                    tCount++;
                    if (cPalet2 > highC1)highC1=cPalet2;
                }
                if (palet3 == i){
                    tCount++;
                    if (cPalet3 > highC1)highC1=cPalet3;
                }
                if (palet4 == i){
                    tCount++;
                    if (cPalet4 > highC1)highC1=cPalet4;
                }
                if (palet5 == i){
                    tCount++;
                    if (cPalet5 > highC1)highC1=cPalet5;
                }
                if (palet6 == i){
                    tCount++;
                    if (cPalet6 > highC1)highC1=cPalet6;
                }
                if (palet7 == i){
                    tCount++;
                    if (cPalet7 > highC1)highC1=cPalet7;
                }
                if (palet8 == i){
                    tCount++;
                    if (cPalet8 > highC1)highC1=cPalet8;
                }
                if (tCount>=mxCount1){
                    mxCount1=tCount;
                    highVal1=tHigh;
                }
            }
            //Find Player 2's max count of 1 color, and highest value and highest color
            int mxCount2=0, //Max count of cards of one number
                highVal2=0, //Highest value from Max Count
                highC2=0;  //Highest color of Highest Value
            for (int i =1; i<=7; i++){
                int tCount=0,tColor=0,tHigh=i; //temp values
                if (palet9 == i){
                    tCount++;
                    if (cPalet9 > highC2)highC2=cPalet9;
                }
                if (palet10 == i){
                    tCount++;
                    if (cPalet10 > highC2)highC2=cPalet10;
                }
                if (palet11 == i){
                    tCount++;
                    if (cPalet11 > highC2)highC2=cPalet11;
                }
                if (palet12 == i){
                    tCount++;
                    if (cPalet12 > highC2)highC2=cPalet12;
                }
                if (palet13 == i){
                    tCount++;
                    if (cPalet13 > highC2)highC2=cPalet13;
                }
                if (palet14 == i){
                    tCount++;
                    if (cPalet14 > highC2)highC2=cPalet14;
                }
                if (palet15 == i){
                    tCount++;
                    if (cPalet15 > highC2)highC2=cPalet15;
                }
                if (palet16 == i){
                    tCount++;
                    if (cPalet16 > highC2)highC2=cPalet16;
                }
                if (tCount>=mxCount2){
                    mxCount2=tCount;
                    highVal2=tHigh;
                }
            }
            //To determine who has won the round in Orange Rule.
            if (mxCount1 > mxCount2)
                cout<<"Player 1 is currently winning."<<endl;
            else if (mxCount1 < mxCount2)
                cout<<"Player 2 is currently winning."<<endl;
            else if (mxCount1 == mxCount2){
                if (highVal1 > highVal2)
                    cout<<"Player 1 is currently winning."<<endl;
                else if (highVal1 < highVal2)
                    cout<<"Player 2 is currently winning."<<endl;
                else if (highVal1 == highVal2){
                    if (highC1>highC2)
                        cout<<"Player 1 is currently winning."<<endl;
                    else 
                        cout<<"Player 2 is currently winning."<<endl;
                }
            }
                
        }
    //Yellow Card Rule, cards of one color
        if (canvas==Y){
            //Find Player 1's max count of 1 color, and highest value and highest color
            int mxCount1=0, //Max count of cards of one color
                highVal1=0, //Highest value from Max Count
                highC1=0;  //Highest color of Highest Value
            for (int i =1; i<=7; i++){
                int tCount=0,tColor=i,tHigh=0; //temp values
                if (cPalet1 == i){
                    tCount++;
                    if (palet1 > tHigh)tHigh=palet1;
                }
                if (cPalet2 == i){
                    tCount++;
                    if (palet2 > tHigh)tHigh=palet2;
                }
                if (cPalet3 == i){
                    tCount++;
                    if (palet3 > tHigh)tHigh=palet3;
                }
                if (cPalet4 == i){
                    tCount++;
                    if (palet4 > tHigh)tHigh=palet4;
                }
                if (cPalet5 == i){
                    tCount++;
                    if (palet5 > tHigh)tHigh=palet5;
                }
                if (cPalet6 == i){
                    tCount++;
                    if (palet6 > tHigh)tHigh=palet6;
                }
                if (cPalet7 == i){
                    tCount++;
                    if (palet7 > tHigh)tHigh=palet7;
                }
                if (cPalet8 == i){
                    tCount++;
                    if (palet8 > tHigh)tHigh=palet8;
                }
                if (tCount>=mxCount1){
                    mxCount1=tCount;
                    highC1=tColor;
                    highVal1=tHigh;
                }
            }
            //Find Player 2's max count of 1 color, and highest value and highest color
            int mxCount2=0, //Max count of cards of one number
                highVal2=0, //Highest value from Max Count
                highC2=0;  //Highest color of Highest Value
            for (int i =1; i<=7; i++){
                int tCount=0,tColor=i,tHigh=0; //temp values
                if (cPalet9 == i){
                    tCount++;
                    if (palet9 > tHigh)tHigh=palet9;
                }
                if (cPalet10 == i){
                    tCount++;
                    if (palet10 > tHigh)tHigh=palet10;
                }
                if (cPalet11 == i){
                    tCount++;
                    if (palet11 > tHigh)tHigh=palet11;
                }
                if (cPalet12 == i){
                    tCount++;
                    if (palet12 > tHigh)tHigh=palet12;
                }
                if (cPalet13 == i){
                    tCount++;
                    if (palet13 > tHigh)tHigh=palet13;
                }
                if (cPalet14 == i){
                    tCount++;
                    if (palet14 > tHigh)tHigh=palet14;
                }
                if (cPalet15 == i){
                    tCount++;
                    if (palet15 > tHigh)tHigh=palet15;
                }
                if (cPalet16 == i){
                    tCount++;
                    if (palet16 > tHigh)tHigh=palet16;
                }
                if (tCount>=mxCount1){
                    mxCount2=tCount;
                    highC2=tColor;
                    highVal2=tHigh;
                }
            }
            //To determine who has won the round in Yellow Rule.
            //This is unchanged from the Orange Rule. Since Max Count 
            if (mxCount1 > mxCount2)
                cout<<"Player 1 is currently winning."<<endl;
            else if (mxCount1 < mxCount2)
                cout<<"Player 2 is currently winning."<<endl;
            else if (mxCount1 == mxCount2){
                if (highVal1 > highVal2)
                    cout<<"Player 1 is currently winning."<<endl;
                else if (highVal1 < highVal2)
                    cout<<"Player 2 is currently winning."<<endl;
                else if (highVal1 == highVal2){
                    if (highC1>highC2)
                        cout<<"Player 1 is currently winning."<<endl;
                    else 
                        cout<<"Player 2 is currently winning."<<endl;
                }
            }
                
        }
    //Green Card Rule, even cards
        if (canvas==G){
        //Find number of even cards for player 1, and out of those highest value and that cards color.
            int highest1=0, tColor1=0,even1=0;
            if (palet1 %2==0){even1++;
                if (palet1>highest1){highest1=palet1;tColor1=cPalet1;}
                else if (palet1==highest1){
                    if (cPalet1 > tColor1)tColor1=cPalet1;}}
            if (palet2 %2==0){ even1++;
                if (palet2>highest1){highest1=palet2;tColor1=cPalet2;}
                else if (palet2==highest1){
                    if (cPalet2 > tColor1)tColor1=cPalet2;}}
            if (palet3 %2==0){even1++;
                if (palet3>highest1){highest1=palet3;tColor1=cPalet3;}
                else if (palet3==highest1){
                    if (cPalet3 > tColor1)tColor1=cPalet3;}}
            if (palet4 %2==0){even1++;
                if (palet4>highest1){highest1=palet4;tColor1=cPalet4;}
                else if (palet4==highest1){
                    if (cPalet4 > tColor1)tColor1=cPalet4;}}
            if (palet5 %2==0){even1++;
                if (palet5>highest1){highest1=palet5;tColor1=cPalet5;}
                else if (palet5==highest1){
                    if (cPalet5 > tColor1)tColor1=cPalet5;}}
            if (palet6%2==0){even1++;
                if (palet6>highest1){highest1=palet6;tColor1=cPalet6;}
                else if (palet6==highest1){
                    if (cPalet6 > tColor1)tColor1=cPalet6;}}
            if (palet7%2==0){even1++;
                if (palet7>highest1){highest1=palet7;tColor1=cPalet7;}
                else if (palet7==highest1){
                    if (cPalet7 > tColor1)tColor1=cPalet7;}}
            if (palet8%2==0){even1++;
                if (palet8>highest1){highest1=palet8;tColor1=cPalet8;}
                else if (palet8==highest1){
                    if (cPalet8 > tColor1)tColor1=cPalet8;}}
    //Find number of even cards for player 2, and out of those highest value and that cards color.
    int highest2=0, tColor2=0,even2=0;
            if (palet9 %2==0){even2++;
                if (palet9>highest2){highest2=palet9;tColor2=cPalet9;}
                else if (palet9==highest2){
                    if (cPalet9 > tColor2)tColor2=cPalet9;}}
            if (palet10 %2==0){ even2++;
                if (palet10>highest2){highest2=palet10;tColor2=cPalet10;}
                else if (palet10==highest2){
                    if (cPalet10 > tColor2)tColor2=cPalet10;}}
            if (palet11 %2==0){even2++;
                if (palet11>highest2){highest2=palet11;tColor2=cPalet11;}
                else if (palet11==highest2){
                    if (cPalet11 > tColor2)tColor2=cPalet11;}}
            if (palet12 %2==0){even2++;
                if (palet12>highest2){highest2=palet12;tColor2=cPalet12;}
                else if (palet12==highest2){
                    if (cPalet12 > tColor2)tColor2=cPalet12;}}
            if (palet13 %2==0){even2++;
                if (palet13>highest2){highest2=palet13;tColor2=cPalet13;}
                else if (palet13==highest2){
                    if (cPalet13 > tColor2)tColor2=cPalet13;}}
            if (palet14%2==0){even2++;
                if (palet14>highest2){highest2=palet14;tColor2=cPalet14;}
                else if (palet14==highest2){
                    if (cPalet14 > tColor2)tColor2=cPalet14;}}
            if (palet15%2==0){even2++;
                if (palet15>highest2){highest2=palet15;tColor2=cPalet15;}
                else if (palet15==highest2){
                    if (cPalet15 > tColor2)tColor2=cPalet15;}}
            if (palet16%2==0){even2++;
                if (palet16>highest2){highest2=palet16;tColor2=cPalet16;}
                else if (palet16==highest2){
                    if (cPalet16 > tColor2)tColor2=cPalet16;}}
    //See who wins the current round for rule Green
            if (even1 > even2)
                cout<<"Player 1 is currently winning."<<endl;
            else if (even1 < even2)
                cout<<"Player 2 is currently winning."<<endl;
            else if (even1 == even2){
                if (highest1 > highest2)
                    cout<<"Player 1 is currently winning."<<endl;
                else if (highest1 < highest2)
                    cout<<"Player 2 is currently winning."<<endl;
                else if (highest1 == highest2){
                    if (tColor1>tColor2)
                        cout<<"Player 1 is currently winning."<<endl;
                    else 
                        cout<<"Player 2 is currently winning."<<endl;
                }
            }
        }
    //Blue Card Rule, cards of all different color
        if (canvas==B){
            int unique1 = 0; //counter for unique colors 
            for (int color= V; color <=R; color++ ){
                if (cPalet1 == color){
                    unique1++;continue;
                }
                if (cPalet2 == color){
                    unique1++;continue;
                }
                if (cPalet3 == color){
                    unique1++;continue;
                }
                if (cPalet4 == color){
                    unique1++;continue;
                }
                if (cPalet5 == color){
                    unique1++;continue;
                }
                if (cPalet6 == color){
                    unique1++;continue;
                }
                if (cPalet7 == color){
                    unique1++;continue;
                }
                if (cPalet8 == color){
                    unique1++;continue;
                }  
            }
            //Finds player 1's highest card
            int highest1,tColor1;
            highest1=palet8,tColor1=cPalet8; //Too check for highest value card
            if (palet1>highest1){highest1=palet1;tColor1=cPalet1;}
            else if (palet1==highest1){
                if (cPalet1 > tColor1)tColor1=cPalet1;}
            if (palet2>highest1){highest1=palet2;tColor1=cPalet2;}
            else if (palet2==highest1){
                if (cPalet2 > tColor1)tColor1=cPalet2;}
            if (palet3>highest1){highest1=palet3;tColor1=cPalet3;}
            else if (palet3==highest1){
                if (cPalet3 > tColor1)tColor1=cPalet3;}
            if (palet4>highest1){highest1=palet4;tColor1=cPalet4;}
            else if (palet4==highest1){
                if (cPalet4 > tColor1)tColor1=cPalet4;}
            if (palet5>highest1){highest1=palet5;tColor1=cPalet5;}
            else if (palet5==highest1){
                if (cPalet5 > tColor1)tColor1=cPalet5;}
            if (palet6>highest1){highest1=palet6;tColor1=cPalet6;}
            else if (palet6==highest1){
                if (cPalet6 > tColor1)tColor1=cPalet6;}
            if (palet7>highest1){highest1=palet7;tColor1=cPalet7;}
            else if (palet7==highest1){
                if (cPalet7 > tColor1)tColor1=cPalet7;}
            //Find Player 2's Unique number of colors, and highest value and color from those
            int unique2 = 0; //counter for unique colors 
            for (int color= V; color <=R; color++ ){
                for( ; ; ){
                    if (cPalet9 == color){
                        unique2++;continue;
                    }
                    if (cPalet10 == color){
                        unique2++;continue;
                    }
                    if (cPalet11 == color){
                        unique2++;continue;
                    }
                    if (cPalet12 == color){
                        unique2++;continue;
                    }
                    if (cPalet13 == color){
                        unique2++;continue;
                    }
                    if (cPalet14 == color){
                        unique2++;continue;
                    }
                    if (cPalet15 == color){
                        unique2++;continue;
                    }
                    if (cPalet16 == color){
                        unique2++;continue;
                    }  
                }
            }
            //Finds player 2's highest card
            int highest2,tColor2;
            highest2=palet16,tColor2=cPalet16;
            if (palet9>=highest2){highest2=palet9;tColor2=cPalet9;}
            else if (palet9==highest2){
                if (cPalet9 > tColor2)tColor2=cPalet9;}
            if (palet10>=highest2){highest2=palet10;tColor2=cPalet10;}
            else if (palet10==highest2){
                if (cPalet10 > tColor2)tColor2=cPalet10;}
            if (palet11>=highest2){highest2=palet11;tColor2=cPalet11;}
            else if (palet11==highest2){
                if (cPalet11 > tColor2)tColor2=cPalet11;}
            if (palet12>=highest2){highest2=palet12;tColor2=cPalet12;}
            else if (palet12==highest2){
                if (cPalet12 > tColor2)tColor2=cPalet12;}
            if (palet13>=highest2){highest2=palet13;tColor2=cPalet13;}
            else if (palet13==highest2){
                if (cPalet13 > tColor2)tColor2=cPalet13;}
            if (palet14>=highest2){highest2=palet14;tColor2=cPalet14;}
            else if (palet14==highest2){
                if (cPalet14 > tColor2)tColor2=cPalet14;}
            if (palet15>=highest2){highest2=palet15;tColor2=cPalet15;}
            else if (palet15==highest2){
                if (cPalet15 > tColor2)tColor2=cPalet15;}
          //Find out who is winning the current round in blue  
            if (unique1 > unique2)
                cout<<"Player 1 is currently winning."<<endl;
            else if (unique1 < unique2)
                cout<<"Player 2 is currently winning."<<endl;
            else if (unique1 == unique2){
                if (highest1 > highest2)
                    cout<<"Player 1 is currently winning."<<endl;
                else if (highest1 < highest2)
                    cout<<"Player 2 is currently winning."<<endl;
                else if (highest1 == highest2){
                    if (tColor1>tColor2)
                        cout<<"Player 1 is currently winning."<<endl;
                    else 
                        cout<<"Player 2 is currently winning."<<endl;
                }
            }
            
        }
    //Indigo Card Rule, cards that form a run (i.e. 4,5,6)
        if (canvas==I){
         //This would require a lot of manual coding or sorting 
//            cards(1-7)//sorting no gaps array/function, will develop in part 2
        }
            
    //Violet Card Rule, Cards below 4
        //To determine if Player 1's count for cards below 4, from those get associated highest value card with color
        if (canvas==V){
        int highest1=0, tColor1=0,low1=0;
            if (palet1 <= 3){low1++;
                if (palet1>highest1){highest1=palet1;tColor1=cPalet1;}
                else if (palet1==highest1){
                    if (cPalet1 > tColor1)tColor1=cPalet1;}}
            if (palet2 <= 3){ low1++;
                if (palet2>highest1){highest1=palet2;tColor1=cPalet2;}
                else if (palet2==highest1){
                    if (cPalet2 > tColor1)tColor1=cPalet2;}}
            if (palet3 <= 3){low1++;
                if (palet3>highest1){highest1=palet3;tColor1=cPalet3;}
                else if (palet3==highest1){
                    if (cPalet3 > tColor1)tColor1=cPalet3;}}
            if (palet4 <= 3){low1++;
                if (palet4>highest1){highest1=palet4;tColor1=cPalet4;}
                else if (palet4==highest1){
                    if (cPalet4 > tColor1)tColor1=cPalet4;}}
            if (palet5 <= 3){low1++;
                if (palet5>highest1){highest1=palet5;tColor1=cPalet5;}
                else if (palet5==highest1){
                    if (cPalet5 > tColor1)tColor1=cPalet5;}}
            if (palet6 <= 3){low1++;
                if (palet6>highest1){highest1=palet6;tColor1=cPalet6;}
                else if (palet6==highest1){
                    if (cPalet6 > tColor1)tColor1=cPalet6;}}
            if (palet7 <= 3){low1++;
                if (palet7>highest1){highest1=palet7;tColor1=cPalet7;}
                else if (palet7==highest1){
                    if (cPalet7 > tColor1)tColor1=cPalet7;}}
            if (palet8 <= 3){low1++;
                if (palet8>highest1){highest1=palet8;tColor1=cPalet8;}
                else if (palet8==highest1){
                    if (cPalet8 > tColor1)tColor1=cPalet8;}}
        
        //To determine if Player 2's count for cards below 4, from those get associated highest value card with color
        int highest2=0, tColor2=0,low2=0;
            if (palet9 <= 3){low2++;
                if (palet9>highest2){highest2=palet9;tColor2=cPalet9;}
                else if (palet9==highest2){
                    if (cPalet9 > tColor2)tColor2=cPalet9;}}
            if (palet10 <= 3){ low2++;
                if (palet10>highest2){highest2=palet10;tColor2=cPalet10;}
                else if (palet10==highest2){
                    if (cPalet10 > tColor2)tColor2=cPalet10;}}
            if (palet11 <= 3){low2++;
                if (palet11>highest2){highest2=palet11;tColor2=cPalet11;}
                else if (palet11==highest2){
                    if (cPalet11 > tColor2)tColor2=cPalet11;}}
            if (palet12 <= 3){low2++;
                if (palet12>highest2){highest2=palet12;tColor2=cPalet12;}
                else if (palet12==highest2){
                    if (cPalet12 > tColor2)tColor2=cPalet12;}}
            if (palet13 <= 3){low2++;
                if (palet13>highest2){highest2=palet13;tColor2=cPalet13;}
                else if (palet13==highest2){
                    if (cPalet13 > tColor2)tColor2=cPalet13;}}
            if (palet14 <= 3){low2++;
                if (palet14>highest2){highest2=palet14;tColor2=cPalet14;}
                else if (palet14==highest2){
                    if (cPalet14 > tColor2)tColor2=cPalet14;}}
            if (palet15 <= 3){low2++;
                if (palet15>highest2){highest2=palet15;tColor2=cPalet15;}
                else if (palet15==highest2){
                    if (cPalet15 > tColor2)tColor2=cPalet15;}}
            if (palet16 <= 3){low2++;
                if (palet16>highest2){highest2=palet16;tColor2=cPalet16;}
                else if (palet16==highest2){
                    if (cPalet16 > tColor2)tColor2=cPalet16;}}
    //See who wins the current round for rule Violet
            if (low1 > low2)
                cout<<"Player 1 is currently winning."<<endl;
            else if (low1 < low2)
                cout<<"Player 2 is currently winning."<<endl;
            else if (low1 == low2){
                if (highest1 > highest2)
                    cout<<"Player 1 is currently winning."<<endl;
                else if (highest1 < highest2)
                    cout<<"Player 2 is currently winning."<<endl;
                else if (highest1 == highest2){
                    if (tColor1>tColor2)
                        cout<<"Player 1 is currently winning."<<endl;
                    else 
                        cout<<"Player 2 is currently winning."<<endl;
                }
            }
        }
        cout<<"Repeat?"<<endl;
        cin>>choice;
        while (choice != 'y' && choice !='n'){
            cout<<"Error Wrong Selection. Repeat, y or n?"<<endl;
            cin>>choice;
        }
        turn++;
    }while(choice=='y');
    //Outputting and Inputting into a file.
    turn == 0 ? out<<"Congratulations Player 1. You have won the game.":
                out<<"Congratulations Player 2. You have won the game.";
    //closing the file so I can read in the input from that file
    out.close();
    //Opening the Input file
    in.open("whowon.txt");
    //To get the entire contents of the file
    getline(in,victor);
    //Display the string just acquired
    cout<< victor <<endl;
    //Closing input file
    in.close();
    //verifying to see if input file successfully opened with a bool variable (redundant...)
    if (in)open=true;else open=false;
    if (open)cout<<""; else cout<<"Error"<<endl;
    cout<<fixed<<setprecision(2)<<showpoint;
    cout<<"Game completion: "<<setw(6)<<pow(finish,2)<<"%";
    //Exit stage right
    return 0;
}
