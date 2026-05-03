#include <iostream>
#include <string>
using namespace std;

class Vehicle {
protected:
    string vehicleID;
    string brand;
    int    capacity;

public:
    Vehicle(string id, string b, int c)
        : vehicleID(id), brand(b), capacity(c) {}

    virtual void display() {
        cout << "Vehicle ID : " << vehicleID << endl;
    }

};

