// 12. The Task Queue:
// Rule: Write a storage entity ProcessQueue. It must contain an array of size 5 to hold tasks of any one specific data type.
// Rule: Write a function enqueue(task) that adds to the array, but silently ignores the addition if the queue has already reached its limit of 5.

#include "iostream"
using namespace std;

template<typename T>
class ProcessQueue{
private:
    T TASKS[5];
    int count = 0;
public:
    void Enqueue(T TASK){
    }


};

