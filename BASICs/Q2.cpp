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



};


