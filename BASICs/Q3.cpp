#include <iostream>
#include <string>
using namespace std;

class Job {
private:
    string jobID;
    string title;
    string company;
    string requiredSkills[10];
    int skillCount;
    string status;

public:
    static int totalJobs;  

    Job(string id, string t, string c) {
        jobID   = id;
        title   = t;
        company = c;
    }



};
