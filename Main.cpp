/* Programmer: Sean Alex Wall
    Program Name: Priority Matrix
    Purpose: To store and organize tasks based on time involved and due date
    Files in this project: Main.cpp, Task.h, Task.cpp, utility.h
*/

//included c/c++ libraries
#include <iostream>

//included .h files
#include "Matrix.h"

using namespace std;
void mainMenu();

int main(){
    Matrix matrix;
    
    mainMenu();


    return 0;
}

void mainMenu(){
    char inputChar;
    do{    
        cout << "******************************" << endl;
        cout << "* Welcome to Priority Matrix *" << endl;
        cout << "*----------------------------*" << endl;
        cout << "* [S/s] Show Tasks           *" << endl;
        cout << "* [A/a] Add Task             *" << endl;
        cout << "* [D/d] Delete Task          *" << endl;
        cout << "* [E/e] Edit Task            *" << endl;
        cout << "* [C/c] Complete Task        *" << endl;
        cout << "* [Q/q] Quit                 *" << endl;
        cout << "******************************" << endl;
        cout << ">> ";
        cin >> inputChar;

        switch(inputChar){
            case 'S':
            case 's':
                break;
            case 'A':
            case 'a':
                break;
            case 'D':
            case 'd':
                break;
            case 'E':
            case 'e':
                break;
            case 'B':
            case 'b':
                break;
            case 'C':
            case 'c':
                break;
            default:
                cout << "Not a valid option" << endl;
                break;
        }
    }while(inputChar != 'q' || inputChar != 'Q');
}