#include "Task.h"
#include <iostream>

using namespace std;
//constructors
Task::Task(string inName, string inDescription, Timeframe inTimeframe, time_t inDueDate){
    name = inName;
    description = inDescription;
    timeframe = inTimeframe;
    dueDate = inDueDate;

    setPriority();
}
Task::Task(const Task &t2){
    name = t2.name;
    description = t2.description;
    timeframe = t2.timeframe;
    dueDate = t2.dueDate;
    priority = t2.priority;
}

//accessors
int Task::getPriority() { return priority; }


void Task::display(){
    tm* due = localtime(&dueDate);
    string string_timeframe;
    switch(timeframe){
        case five_minutes:
            string_timeframe = "five minutes";
            break;
        case thirty_minutes:
            string_timeframe = "thirty minutes";
            break;
        case hours:
            string_timeframe = "an hour/hours";
            break;
        case days:
            string_timeframe = "a day/days";
            break;
        default:
            string_timeframe = "ERROR";
            break;
    }
    cout << "******************" << endl;
    cout << "Name: " << name << endl;
    cout << "Description: " << description << endl;
    cout << "Due Date: " <<  due->tm_mon + 1 << "/" << due->tm_mday << "/" << due->tm_year + 1900 << endl;
    cout << "Timeframe: "  << string_timeframe << endl;
    cout << "******************" << endl;
    cout << "Priority: " << priority << endl;
    cout << endl;
}

string Task::toString(){
    string outputString = "";

    outputString += name;
    outputString += ",";
    outputString += description;
    outputString += ",";
    outputString += to_string(timeframe);
    outputString += ",";
    outputString += to_string(dueDate);
    outputString += ",\n";

    return outputString;
}

string Task::getName(){ return name; }
string Task::getDescription(){ return description; }
string Task::getTimeframe(){ return to_string(timeframe); }
string Task::getDueDate(){
    tm* due = localtime(&dueDate);
    return (to_string(due->tm_mon + 1) + "/" + to_string(due->tm_mday) + "/" + to_string(due->tm_year + 1900));
}

//mutators
void Task::setName(string inName){name = inName;}
void Task::setDescription(string inDescription){description = inDescription;}
void Task::setTimeframe(Timeframe inTimeframe){timeframe = inTimeframe;}
void Task::setDueDate(time_t inDueDate){dueDate = inDueDate;}

//utility functions
void Task::setPriority(){
    int tempPriority = 0;

    time_t now = time(0);
    double difference = difftime(dueDate, now);

    //Due yesterday or today
    if(difference < SECS_IN_DAY){
        switch(timeframe){
            case five_minutes:
                priority = 0;
                break;
            case thirty_minutes:
                priority = 2;
                break;
            case hours:
                priority = 4;
                break;
            case days:
                priority = 9;
                break;
        }
    }
    //Due this week
    else if(difference < SECS_IN_WEEK){
        switch(timeframe){
            case five_minutes:
                priority = 1;
                break;
            case thirty_minutes:
                priority = 3;
                break;
            case hours:
                priority = 5;
                break;
            case days:
                priority = 10;
                break;
        }
    }
    //Due Later
    else{
        switch(timeframe){
            case five_minutes:
                priority = 6;
                break;
            case thirty_minutes:
                priority = 7;
                break;
            case hours:
                priority = 8;
                break;
            case days:
                priority = 9;
                break;
        }
    }
}

//operators
Task& Task::operator=(const Task& t2){
    name = t2.name;
    description = t2.description;
    timeframe = t2.timeframe;
    dueDate = t2.dueDate;
    setPriority();
    return *this;
}

bool Task::operator<(const Task& t2){
    return priority < t2.priority;
}