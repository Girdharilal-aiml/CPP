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
        cout << "Brand      : " << brand     << endl;
        cout << "Capacity   : " << capacity  << endl;
    }

    virtual ~Vehicle() {}
};


class Truck : public Vehicle {
protected:
    float loadCapacity;  

public:
    Truck(string id, string b, int c, float lc)
        : Vehicle(id, b, c) {
        loadCapacity = lc;
    }

    void display() override {
        cout << "\n[Truck]" << endl;
        Vehicle::display();
    }
};
