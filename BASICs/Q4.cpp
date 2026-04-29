#include "iostream"
#include <string>
using namespace std;

class Laptop {
private:
    string brand;
    string model;
    int price;
    string RAM;

public:
    static int totalLaptops;
    static int totalPrice;

    Laptop(string b, string m, int p, string r) {
        brand  = b;
        model  = m;
        price  = p;
        RAM    = r;
        totalLaptops++;
        totalPrice += price;
    }

    Laptop(const Laptop& other) {
        brand  = other.brand;
        model  = other.model;
        price  = other.price;
        RAM    = other.RAM;
        totalLaptops++;
        totalPrice += price; 
    }

    void display() {
        cout << model << ": " << brand
             << ", Price: " << price
             << ", RAM: " << RAM << endl;
    }

    static void showTotals() {
        cout << "\nTotal number of laptops: " << totalLaptops << endl;
        cout << "Total price of all laptops: " << totalPrice  << endl;
    }
};

int Laptop::totalLaptops = 0;
int Laptop::totalPrice   = 0;

int main() {
    Laptop l1("Dell",   "Inspiron",  60000, "8GB");
    Laptop l2("HP",     "Pavilion",  70000, "16GB");
    Laptop l3 = l1;   // copy constructor called

    cout << "Laptop 1: ";  l1.display();
    cout << "Laptop 2: ";  l2.display();
}