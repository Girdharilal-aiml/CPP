/*
Level 6 (Destructor + Real OOP Trap)

Q6:
Modify Car class:

Add a destructor
Print message:
"Car object destroyed"

In main():

Create 2 objects inside a block { }
Observe destructor calls
*/

#include"iostream"
using namespace std;

class Car{
private:
    string brand;
    double price;

public:
    Car(){

    }
    Car(string b, double p) : brand(b), price(p){}
    Car(const Car &obj){
        brand = obj.brand;
        price = obj.price;
    }
    ~Car(){
        cout << "Car Object Destroyed" << endl;
    }
};
