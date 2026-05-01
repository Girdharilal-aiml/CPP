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
    SecurityCamera* cameras[4];

    int lightCount, acCount, cameraCount;

public:
    House(string n, string id) {
        name         = n;
        controllerID = id;
        lightCount = acCount = cameraCount = 0;
    }

    void addLight(Light* l) {
        if (lightCount < 5)
            lights[lightCount++] = l;
        else
            cout << "Max lights reached!" << endl;
    }

    void addAC(AirConditioner* ac) {
        if (acCount < 3)
            acs[acCount++] = ac;
        else
            cout << "Max ACs reached!" << endl;
    }

    void addCamera(SecurityCamera* c) {
        if (cameraCount < 4)
            cameras[cameraCount++] = c;
    }


};

