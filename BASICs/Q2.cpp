#include "iostream"
#include <string>
using namespace std;

class Freelancer {
protected:
    string name;
    double baseRating;
    int completedProjects;
    double earnings;

public:
    Freelancer(string n, double r, int p)
        : name(n), baseRating(r), completedProjects(p), earnings(0) {}

    virtual void calculateEarnings() = 0;

    virtual void display() {
        cout << "------------------------"   << endl;
        cout << "Name     : " << name        << endl;
        cout << "Rating   : " << baseRating  << endl;
        cout << "Projects : " << completedProjects << endl;
        cout << "Earnings : Rs." << earnings << endl;
        if (baseRating < 3)
            cout << "Status   : Needs Improvement" << endl;
    }

    virtual ~Freelancer() {}
};


class AIEngineer : public Freelancer {
public:
    AIEngineer(string n, double r, int p)
        : Freelancer(n, r, p) {}

    void calculateEarnings() override {
        double bonus = 0;
        if (completedProjects >= 5)
            bonus = 15000;       
        earnings = (baseRating * 10000) + bonus;

        if (completedProjects >= 5)
            baseRating += 0.5;
    }

    void display() override {
        cout << "\n[AI Engineer]" << endl;
        Freelancer::display(); 
    }
};


class DataScientist : public Freelancer {
public:
    DataScientist(string n, double r, int p)
        : Freelancer(n, r, p) {}

    void calculateEarnings() override {
        double bonus = 0;
        if (completedProjects >= 5)
            bonus = 12000;        
        earnings = (baseRating * 8000) + bonus;

        if (completedProjects >= 5)
            baseRating += 0.3;
    }

    void display() override {
        cout << "\n[Data Scientist]" << endl;
        Freelancer::display();
    }
};


class FullStackDev : public Freelancer {
public:
    FullStackDev(string n, double r, int p)
        : Freelancer(n, r, p) {}

    void calculateEarnings() override {
        double bonus = 0;
    }

};


