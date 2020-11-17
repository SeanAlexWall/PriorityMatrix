#include <iostream>
#include <fstream>
#include <algorithm>
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
            tasks.push_back(newTask);
        }
    }
    inFile.close();
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
        return binarySearch(key, middle + 1, right);
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
    int choiceInt;
    cout << "Delete which task?" << endl;
    for(int i = 0; i < tasks.size(); i++){
        cout << "* " << "[" << i << "] " << tasks[i].getName() << " *"<< endl; 
    }
    cin >> choiceInt;
    tasks.erase(tasks.begin() + choiceInt);
    saveToFile();
    cout << "Deleted" << endl;
}

void Matrix::completeTask(){
    
}

void Matrix::editTask(){
    int choiceInt;
    cout << "Edit which task?" << endl;
    for(int i = 0; i < tasks.size(); i++){
        cout << "* " << "[" << i << "] " << tasks[i].getName() << " *"<< endl; 
    }
    cin >> choiceInt;
    int editInt;
    Task editedTask(tasks[choiceInt]);
    do{
        cout << endl;
        cout << "     Edit Task     " << endl;
        cout << "*******************" << endl;
        cout << "[0] Name: " << editedTask.getName() << endl;
        cout << "[1] Description: " << editedTask.getDescription() << endl;
        cout << "[2] Due Date: " << editedTask.getDueDate() << endl;
        cout << "[3] Timeframe: " << editedTask.getTimeframe() << endl;
        cout << "[4] Save" << endl;
        cout << "[5] Cancel" << endl;

        cout << " >> ";
        cin >> editInt;

        string inName;
        string inDescription;
        int inDay, inMonth, inYear;
        time_t rawtime;
        tm* timeinfo;
        time_t inDueDate;
        int intTF;
        switch(editInt){
            case 0:
                cin.get();
                cout << "Enter new Name >> ";
                getline(cin, inName);
                editedTask.setName(inName);
                break;
            case 1:
                cin.get();
                cout << "Enter new description" << endl;
                getline(cin, inDescription);
                editedTask.setDescription(inDescription);
                break;
            case 2:
                cout << "Enter New Due Year >> ";
                cin >> inYear;
                cout << "Enter New Due Month >> ";
                cin >> inMonth;
                cout << "Enter New Due Day >> ";
                cin >> inDay;
                //Make date;
                time(&rawtime);
                timeinfo = localtime(&rawtime);
                timeinfo->tm_year = inYear - 1900;
                timeinfo->tm_mon = inMonth - 1;
                timeinfo->tm_mday = inDay;
                inDueDate = mktime(timeinfo);
                editedTask.setDueDate(inDueDate);
                break;
            case 3:
                cout << "About how long will it take?" << endl;
                cout << "[0] Five Minutes, [1] Thirty Minutes, [2] An Hour/Hours, [3] A Day/Days" << endl;
                cout << ">> ";
                cin >> intTF;
                editedTask.setTimeframe((Timeframe)intTF);
                break;
            case 4:
                tasks[choiceInt] = editedTask;
                std::sort(tasks.begin(), tasks.end());
                saveToFile();
                cout << "Saved";
                break;
            case 5:
                cout << "Cancelled " << endl;
                return;
                break;
            default:
                break;
        }
        // cin.get();
        // cin.get();
    }while(!(editInt == 4 || editInt == 5));
}

void Matrix::showTasks(){
    for(int i = 0; i < tasks.size(); i++){
        tasks[i].display();
    }
}
