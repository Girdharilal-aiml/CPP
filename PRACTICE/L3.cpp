/*
Level 3 (Now real OOP starts – Constructors + Multiple Objects)

Q3:
Create a class Car with:

data members: brand, price
a constructor to initialize values
a function display()

In main():

create 2 objects with different values
display both
*/

#include "iostream"
using namespace std;

class Car{
private:
    string brand;
    double price;

public:
    Car(string b, double p) : brand(b), price(p){}
    
    void Display(){
        cout << "Brand : " << brand << endl;
        cout << "Price : " << price << endl;
        cout << "========================" << endl;
    }

};

int main(){
    Car c1("Toyota", 21.22);
    Car c2("Suzuki", 3231);

    c1.Display();
    
    c2.Display();
}