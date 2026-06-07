// 13. The Print Spooler:
// Rule: Design a generic Spooler entity. It holds an array of 5 generic jobs.
// Rule: Provide an addJob(document) function that increments a counter when a job is added, alongside a getJobCount() function to return the current number of jobs.

#include "iostream"
using namespace std;

template <typename T>
class Spooler{
private:
    T Document[5];
    int count = 0;
public:
    void addJob(T Documents){
        if(count < 5){
            Document[count++] = Documents;
        }
    }

    int getJobCount(){
        return count;
    }
};

int main(){
    Spooler<string> Files;

    Files.addJob("F1");
    Files.addJob("F2");

}