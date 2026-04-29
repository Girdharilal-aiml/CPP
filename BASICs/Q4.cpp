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
    }

};

