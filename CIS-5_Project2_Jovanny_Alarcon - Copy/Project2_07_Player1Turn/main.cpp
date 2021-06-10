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
void ply1Trn(int [],int [],int [],int [],int&);


//Execution Begins Here
//cout<<"It is Player 1s Turn."<<endl;
//            if (palet1 == 0 && canvas1==0){
//                cout<<"Press p to play a card of c to discard to canvas"<<endl;
//                cin>>palorcan;
//                if (palorcan=='p'){
//                    cout<<"Play the value then the color"<<endl;
//                    cin>>palet1>>display1;
//                int swap = 0, val=static_cast<int>(display1);
//                switch(val){ 
//                        case 'R':swap = R;break;case 'O':swap = O;break;
//                        case 'Y':swap = Y;break;case 'G':swap = G;break;
//                        case 'B':swap = B; break;case 'I':swap = I;break;
//                        case 'V':swap = V;break;default:cout << "WRONG COLOR" << endl;
//                    } cPalet1=swap;
//                }
//                else if (palorcan=='c'){
//                    cout<<"Discard a card, type the color"<<endl;
//                    cin>>canvas1;
//                    canvas=canvas1;
//                }
//                cout<<"Is it the end of your turn? Type y or n."<<endl;
//                cin>>end;
//            }
//            
//            if ((end=='n' || end =='0') && palet2 == 0 && canvas2==0){
//                cout<<"Press p to play a card of c to discard to canvas"<<endl;
//                cin>>palorcan;
//                if (palorcan=='p'){
//                    cout<<"Play the value then the color"<<endl;
//                    cin>>palet2>>display2;
//                int swap = 0, val=static_cast<int>(display2);
//                switch(val){ 
//                        case 'R':swap = R;break;case 'O':swap = O;break;
//                        case 'Y':swap = Y;break;case 'G':swap = G;break;
//                        case 'B':swap = B; break;case 'I':swap = I;break;
//                        case 'V':swap = V;break;default:cout << "WRONG COLOR" << endl;
//                    } cPalet2=swap;
//                }
//                else if (palorcan=='c'){
//                    cout<<"Discard a card, type the color"<<endl;
//                    cin>>canvas2;
//                    canvas=canvas2;
//                }
//                cout<<"Is it the end of your turn? Type y or n."<<endl;
//                cin>>end;
//            }
        
int main(int argc, char** argv) {
    //Declare variables
  
    
    //Initialize variables
    
    //Process, map inputs to outputs
    ply1Trn(display,palet,canvas,cPalet,canvas1);
    //Display your initial conditions as well as outputs.
    
    //Exit stage right
    return 0;
}
void ply1Trn(int a[],int b[],int c[],int d[],int &canvas){
    int count=0; //To give a max of 2 turns
    char end;    //To let player end turn after turn 1
    for(int i=0;i<8;i++){
        char porc;
        if(b[i]==0 && c[i]==0 && count<2){
            cout<<"Press p to play a card or c to discard to canvas"<<endl;
            cin>>porc;
            while(porc != 'c' && porc != 'p'){
                "Invalid choice:Select p or c."<<endl;
                cin>>porc;
            }
            if (porc=='p'){
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
            else if (porc=='c'){
                cout<<"Discard a card, type the color"<<endl;
                cin>>c[i];
                canvas=c[i];
                count++;
            }
            if (count==1){
                cout<<"Is it the end of your turn? Type y or n."<<endl;
                cin>>end;
                while (end != 'y' && end != 'n'){
                    cout<<"Invalid choice. Enter y or n.";
                    cin>>end;
                }
                if (end=='y')
                    count++;
            }
        }
    }
}
