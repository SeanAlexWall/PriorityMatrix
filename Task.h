#include <ctime>
#include <iostream>
#include "utility.h"

using namespace std;

class Task{

private:
  //Member Variables
    time_t dueDate;
    string name;
    string description;
    Timeframe timeframe;
    int priority;
  //Member Functions
    void setPriority();
public:
  //Member Variables
    //No public member variables
  //Member Functions
    //Constructors
      //No Default Constructor
      //Overloaded Constructor
      Task(string inName, string inDescription, Timeframe inTimeframe, time_t inDueDate);
      //Copy Constructor
      Task(const Task &t2);
    //Accessors
      int getPriority();
      void display();
      string toString();
      string getName();
      string getDescription();
      string getTimeframe();
      string getDueDate();

    //Mutators
      void setDueDate(time_t inDueDate);
      void setName(string inName);
      void setDescription(string inDescription);
      void setTimeframe(Timeframe inTimeframe);
      void complete();

    //operators
      Task& operator=(const Task&);
      bool operator< (const Task&);
};