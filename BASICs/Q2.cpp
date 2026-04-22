#include <iostream>
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
    }

};
