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

//accessors
int Task::getPriority(){ return priority; }
void Task::display(){

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