#include "iostream"
#include "string"
using namespace std;

class Light {
public:
    int brightness; 
    int power;   

    Light(int b, int p) {
        brightness = b;
        power      = p;
    }

    void display() {
        cout << "Brightness: " << brightness
             << " lumens, Power: " << power << "W" << endl;
    }
};


class AirConditioner {
public:
    float tonnage;
    int   power;

    AirConditioner(float t, int p) {
        tonnage = t;
        power   = p;
    }

    void display() {
        cout << "Tonnage: " << tonnage
             << " Ton, Power: " << power << "W" << endl;
    }
};


class SecurityCamera {
public:

};

