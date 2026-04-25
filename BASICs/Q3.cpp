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
int Job::totalJobs = 0;


class Candidate {
protected:
    string candidateID;
    string name;
    string skills[10];
    int skillCount;
    Job* appliedJobs[20];
    int appliedCount;

public:
    static int totalCandidates;

    Candidate(string id, string n) {
        candidateID  = id;
        name         = n;
        skillCount   = 0;
        appliedCount = 0;
        totalCandidates++;
    }

    string getName() const { return name; }
    string getID()   const { return candidateID; }

    void applyJob(Job* j) {
        appliedJobs[appliedCount++] = j;
        cout << "Candidate " << candidateID
             << " applied to " << j->getJobID() << endl;
    }


};
