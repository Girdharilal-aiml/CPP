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
        status  = "Active";
        skillCount = 0;
        totalJobs++;
    }

    string getJobID()  const { return jobID; }
    string getTitle()  const { return title; }
    string getStatus() const { return status; }

    void postJob() {
        cout << "Job " << jobID << " posted by " << company << endl;
    }

    void closeJob() {
        status = "Closed";
        cout << "Job " << jobID << " closed." << endl;
    }

    void displayJobDetails() {
        cout << "Job " << jobID
             << " | " << title
             << " | Status: " << status << endl;
    }
};
