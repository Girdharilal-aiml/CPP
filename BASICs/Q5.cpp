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
    string resolution;
    int    power;

    SecurityCamera(string r, int p) {
        resolution = r;
        power      = p;
    }

    void display() {
        cout << "Resolution: " << resolution
             << ", Power: " << power << "W" << endl;
    }
};

class House {
private:
    string name;
    string controllerID;

    Light*          lights[5];
    AirConditioner* acs[3];


public:





};

