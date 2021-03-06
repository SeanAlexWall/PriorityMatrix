#include <string>
#include <vector>
#include "Task.h"

using namespace std;

class Matrix{
private:
  //Member Variables
    vector<Task> tasks;
  //Member Functions
    int binarySearch(int, int, int);
    int intbuilder(string);
public:
  //Member Variables
    //No public member variables
  //Member Functions
    //Constructors
      Matrix();
      //No Overloaded Constructors
      //No Copy Constructor
    //Accessors
      //No Accessors
    //Mutators
      //No Mutators
    //Utility
      void addTask();
      void deleteTask();
      void completeTask();
      void editTask();
      void showTasks();
      void saveToFile();
};