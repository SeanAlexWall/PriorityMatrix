#include <iostream>
#include <fstream>
#include "Matrix.h"

using namespace std;

//Default constructor
Matrix::Matrix(){
    ifstream inFile;
    inFile.open(SAVE_FILE, ios::binary);
    string line;
    string wordBuilder = "";
    string taskInfo[4];
    int infoNum = 0;
    if(inFile.is_open()){
        while(getline(inFile, line)){
            for(int i = 0; i < line.length(); i++){

                if(line[i] == ','){
                    taskInfo[infoNum] = wordBuilder;
                    wordBuilder = "";
                    infoNum ++;
                }
                else{
                    wordBuilder += line[i];
                }
            }
            infoNum = 0;
            //Create new task;
            time_t newTime = intbuilder(taskInfo[3]);
            Task newTask(taskInfo[0], taskInfo[1], (Timeframe)((char)taskInfo[2][0] - '0'), newTime);
            //add to vector;
            int priority = newTask.getPriority();
            int index = binarySearch(priority, 0, tasks.size());
            //Insertion based on binary sort
            tasks.insert(tasks.begin() + index, newTask);
        }
    }

}
int Matrix::intbuilder(string inString){
    int outInt = 0;
    for(int i = 0; i < inString.length(); i++){
        outInt = outInt * 10;
        outInt += (inString[i] - '0');
    }
    return outInt;
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
    priority = newTask.getPriority();
    index = binarySearch(priority, 0, tasks.size());
    //Insertion based on binary sort
    tasks.insert(tasks.begin() + index, newTask);
    saveToFile();
    cout << "Saved to File" << endl;
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

void Matrix::saveToFile(){
    ofstream outFile;
    outFile.open(SAVE_FILE, ios::binary);
    string outputString = "";
    for(int i = 0; i < tasks.size(); i++){
        outputString += tasks[i].toString();
    } 
    outFile << outputString;   
    outFile.close();
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
