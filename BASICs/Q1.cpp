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
        totalPlans++;      
    }

    void display() {
        cout << "------------------------" << endl;
        cout << "Name       : " << name      << endl;
        cout << "Data Limit : " << dataLimit << " GB" << endl;
        cout << "Data Used  : " << dataUsed  << " GB" << endl;
    }
};

int DataPlan::totalPlans = 0;

int main() {
    DataPlan p1("Ali", 50.0, 30.0);   
    DataPlan p2 = p1;                
    p2.display();                    

    cout << "\n--- Original Plan ---" << endl;
    p1.display();

    cout << "\n--- Copied Plan ---" << endl;
    p2.display();

    cout << "\nTotal Plans: " << DataPlan::totalPlans << endl;

    return 0;
}
