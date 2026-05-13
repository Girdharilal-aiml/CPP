/*
Level 5 (Important – Copy Constructor)

Now things get serious.

Q5:
Modify Car class to include:

Default constructor
Parameterized constructor
Copy constructor
display()

In main():

Create object c1 using parameterized constructor
Create c2 as a copy of c1
Display both
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
    void Display(){
        cout << "Brand : " << brand << endl;
        cout << "Price : " << price << endl;
    }
};

int main(){
    Car c1("Mclaren", 221221);
    Car c2(c1);
    c1.Display();
    c2.Display();
}
