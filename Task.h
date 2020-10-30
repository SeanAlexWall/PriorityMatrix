#include <ctime>
#include <string>
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
      Task(string inName, string inDescription, Timeframe inTimeframe, time_t inDueDate);
      //No Copy Constructor
    //Accessors
      int getPriority();
      void display();
    //Mutators
      void setDueDate(time_t inDueDate);
      void setName(string inName);
      void setDescription(string inDescription);
      void setTimeframe(Timeframe inTimeframe);
      void complete();
};