#include "iostream"
#include "string"
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
        cout << "Load Cap   : " << loadCapacity << " tons" << endl;
    }
};

class Van : public Vehicle {
private:
    int passengerCapacity;

public:
    Van(string id, string b, int c, int pc)
        : Vehicle(id, b, c) {
        passengerCapacity = pc;
    }

    void display() override {
        cout << "\n[Van]" << endl;
        Vehicle::display();
        cout << "Passengers : " << passengerCapacity << endl;
    }
};

class Bike : public Vehicle {
private:
    float fuelEfficiency; 

public:
    Bike(string id, string b, int c, float fe)
        : Vehicle(id, b, c) {
        fuelEfficiency = fe;
    }

    void display() override {
        cout << "\n[Bike]" << endl;
        Vehicle::display();
        cout << "Fuel Eff   : " << fuelEfficiency << " km/L" << endl;
    }
};


class RefrigeratedTruck : public Truck {
private:
    float temperature; 

public:
    RefrigeratedTruck(string id, string b, int c,
                      float lc, float temp)
        : Truck(id, b, c, lc) {
        temperature = temp;
    }

    void display() override {
        cout << "\n[Refrigerated Truck]" << endl;
        Vehicle::display();
        cout << "Load Cap   : " << loadCapacity  << " tons" << endl;
        cout << "Temp       : " << temperature   << " C"    << endl;
    }
};


class Driver {
protected:
    string name;
    string licenseType;

public:
    Driver(string n, string lt)
        : name(n), licenseType(lt) {}

    virtual void display() {
        cout << "Driver     : " << name        << endl;
        cout << "License    : " << licenseType << endl;
    }

    virtual ~Driver() {}
};


class DeliveryAgent : public Vehicle, public Driver {
private:
    string assignedRoute;

public:
    DeliveryAgent(string vid, string brand, int cap,
                  string dname, string license,
                  string route)
        : Vehicle(vid, brand, cap),
          Driver(dname, license) {
        assignedRoute = route;
    }

    void display() override {
        cout << "\n[Delivery Agent]" << endl;
        Vehicle::display();
        Driver::display();
        cout << "Route      : " << assignedRoute << endl;
    }
};


