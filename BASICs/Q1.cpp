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
    }


};

