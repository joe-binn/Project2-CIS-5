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
#include <vector>
using namespace std;   //Library Name-space

//User Libraries

//Global/Universal Constants -- No Global Variables
//Science, Math, Conversions, Higher Dimensioned constants only


//Function Prototypes
void shuffle(vector<int> &);
void uniRand(const vector<int>, int = 16);

//Execution Begins Here
int main(int argc, char** argv) {
    //Set Random seed
    srand(static_cast<unsigned int>(time(0)));
         
    //Declare variables
    vector<int> random(49); 
    
    //Initialize variables
    
    //Process, map inputs to outputs
    shuffle(random);
    //Display your initial conditions as well as outputs.
    
    //Exit stage right
    return 0;
}

void shuffle(vector<int> &random) {
    const int MAX = 49,
              MIN = 0;
    for (int index = 0; index < random.size(); index++){
        random[index] = index + 1;
        cout << random[index] << " ";
    }
    cout << endl;
    int numShfl = 100000000;
    for (int i = 0; i < numShfl; i++){
        int temp, rand1, rand2;
//        do{
            rand1 = rand() % (MAX - MIN) + MIN;
//            cout << rand1 << endl;
            rand2 = rand() % (MAX - MIN) + MIN;
//            cout << rand2 << endl;
//        }while(rand1 == rand2);
        temp          = random[rand1];
        random[rand1] = random[rand2];
        random[rand2] = temp;
    }
    
    for (int index = 0; index < random.size(); index++){
        cout << random[index] << " ";
    }
    cout << endl;
    uniRand(random,16);
}
void uniRand(const vector<int> assign, int size){
    vector<int> cards(16);
    for (int i = 0; i < size; i++){
        cards[i] = assign[i];
        cout << cards[i] << " ";
    }
}