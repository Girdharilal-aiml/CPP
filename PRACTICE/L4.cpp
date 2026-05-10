/*
Level 4 (Now we step up – Constructor Types)

Q4:
Modify the Car class to include:

Default constructor → sets:
brand = "Unknown"
price = 0
Parameterized constructor (like you already did)
display() function

In main():

Create:
one object using default constructor
one object using parameterized constructor
Display both
*/

#include "iostream"
using namespace std;

class Car{
private:
    string brand;
    double price;

public:
    Car(){
        brand = "Unknown";
        price = 0;
    }

    Car(string brand, double price){
        this->brand = brand;
    }
    
};
