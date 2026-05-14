/*
Level 7 (Dynamic Memory + Deep Copy)

Q7:
Modify Car class:

1. Change:
   string brand;
   → string* brand;

2. Implement:
   - Default constructor
   - Parameterized constructor (use new)
   - Copy constructor (deep copy)
   - Destructor (delete memory)
   - display() function

3. In main():
   - Create object c1 using parameterized constructor
   - Create c2 as copy of c1
   - Display both

⚠️ Important:
- Use new to allocate memory
- Use delete in destructor
- Copy constructor must perform deep copy
*/

#include"iostream"
using namespace std;

class Car{
private:
    string* Brand;
    double price;

public:
    Car(){
        Brand = new string("Unknown");
        price = 0;
    }
    Car(string B, double p){
        Brand = new string(B);
        price = p;
    }
    Car(const Car &obj){
        Brand = obj.Brand;
        price = obj.price;
    }
    ~Car(){
    }


};

