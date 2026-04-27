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

    void updateSkills(string newSkills[], int count) {
        for (int i = 0; i < count; i++)
            skills[skillCount++] = newSkills[i];
    }

    void displayCandidateInfo() {
        cout << "Candidate " << candidateID
             << " applications: ";
        for (int i = 0; i < appliedCount; i++)
            cout << appliedJobs[i]->getJobID() << " ";
        cout << endl;
    }
};
int Candidate::totalCandidates = 0;

class TrainingProgram {
private:
    string programID;
    string courseName;
    Candidate* assignedCandidates[20];
    int candidateCount;

public:
    TrainingProgram(string id, string course) {
        programID      = id;
        courseName     = course;
        candidateCount = 0;
    }

    string getID()   const { return programID; }
    string getName() const { return courseName; }

    void assignCandidate(Candidate* c) {
        assignedCandidates[candidateCount++] = c;
        cout << "TrainingProgram " << programID
             << " assigned to Candidate "
             << c->getID() << endl;
    }

    void executeProgram() {
        for (int i = 0; i < candidateCount; i++)
            cout << "TrainingProgram " << programID
                 << " executed for Candidate "
                 << assignedCandidates[i]->getID() << endl;
    }

    void generateReport() {
        cout << "Training Report for: " << courseName << endl;
    }
};

class JobRoutine {
private:
    string routineID;
    string name;
    Job*             jobs[20];
    Candidate*       candidates[20];
    TrainingProgram* trainingPrograms[20];
    int jCount, cCount, tCount;

public:
    JobRoutine(string id, string n) {
        routineID = id;
        name      = n;
        jCount = cCount = tCount = 0;
    }

    void addJob(Job* j)                    { jobs[jCount++] = j; }
    void addCandidate(Candidate* c)        { candidates[cCount++] = c; }
    void addTrainingProgram(TrainingProgram* t) { trainingPrograms[tCount++] = t; }

    void execute() {
        cout << "JobRoutine \"" << name << "\" executed:" << endl;

        for (int i = 0; i < jCount; i++)
            cout << "Job " << jobs[i]->getJobID()
                 << " status: " << jobs[i]->getStatus() << endl;

        for (int i = 0; i < cCount; i++)
            candidates[i]->displayCandidateInfo();

        for (int i = 0; i < tCount; i++)
            trainingPrograms[i]->executeProgram();
    }
};

class CandidateUser : public Candidate {
private:
    string userID;

public:

};

