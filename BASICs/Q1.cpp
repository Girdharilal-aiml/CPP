#include <iostream>
#include <string>
using namespace std;

class DataPlan {
private:
    string name;
    double dataLimit;
    double dataUsed;

public:
    static int totalPlans;

    DataPlan(string n, double limit, double used) {
        name      = n;
        dataLimit = limit;
        dataUsed  = used;
        totalPlans++; 
    }

    DataPlan(const DataPlan& other) {
        name      = other.name;
        dataLimit = other.dataLimit;
        dataUsed  = 0;   
    }

};

