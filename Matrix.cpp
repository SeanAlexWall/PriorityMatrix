#include <iostream>
#include "Matrix.h"

using namespace std;

//Default constructor
Matrix::Matrix(){

}

void Matrix::addTask(){
    string inName, inDescription;
    int inIntTimeframe;
    Timeframe inTimeframe;
    int month, day, year;
    time_t rawtime;
    tm* timeinfo;
    time_t inDueDate;
    int priority;
    int index;
    
    //Gather info
    cin.get();
    cout << "Enter Task Name " << endl;
    cout << ">> ";
    getline(cin, inName);
    cout << "Enter Description " << endl;
    cout << ">> ";
    getline(cin, inDescription);
    cout << "Enter Due Year >> ";
    cin >> year;
    cout << "Enter Due Month >> ";
    cin >> month;
    cout << "Enter Due Day >> ";
    cin >> day;
    cout << "About how long will it take?" << endl;
    cout << "[0] Five Minutes, [1] Thirty Minutes, [2] An Hour/Hours, [3] A Day/Days" << endl;
    cout << ">> ";
    cin >> inIntTimeframe;
    inTimeframe = (Timeframe)inIntTimeframe;  

    //Make date;
    time(&rawtime);
    timeinfo = localtime(&rawtime);
    timeinfo->tm_year = year - 1900;
    timeinfo->tm_mon = month - 1;
    timeinfo->tm_mday = day;
    inDueDate = mktime(timeinfo);

    //Create new task;
    Task newTask(inName, inDescription, inTimeframe, inDueDate);
    //add to vector;
    //TODO: binarysort
    priority = newTask.getPriority();
    index = binarySearch(priority, 0, tasks.size());
    //TODO: Insertion based on binary sort
    cout << "found index" << endl;
    tasks.insert(tasks.begin() + index, newTask);
    
}

int Matrix::binarySearch(int key, int left, int right){
    int middle = (left + right)/2;

    if(left == right){
        return left;
    }
    if(key < tasks[middle].getPriority()){
        return binarySearch(key, left, middle);
    }
    else if(key > tasks[middle].getPriority()){
        return binarySearch(key, middle, right);
    }
    else {
        return middle;
    }
}

void Matrix::deleteTask(){

}

void Matrix::completeTask(){

}

void Matrix::editTask(){

}

void Matrix::showTasks(){
    for(int i = 0; i < tasks.size(); i++){
        tasks[i].display();
    }
}
