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
        else
            cout << "Max cameras reached!" << endl;
    }

    int calculateTotalPower() {
        int total = 0;
        for (int i = 0; i < lightCount;  i++) total += lights[i]->power;
        for (int i = 0; i < acCount;     i++) total += acs[i]->power;
        for (int i = 0; i < cameraCount; i++) total += cameras[i]->power;
        return total;
    }

    void display() {
        cout << "House: "      << name         << endl;
        cout << "Controller: " << controllerID << endl;

        cout << "\nLights:" << endl;
        for (int i = 0; i < lightCount; i++) {
            cout << "  Light " << i+1 << " -> ";
            lights[i]->display();
        }

        cout << "\nAir Conditioners:" << endl;
        for (int i = 0; i < acCount; i++) {
            cout << "  AC " << i+1 << " -> ";
            acs[i]->display();
        }

        cout << "\nSecurity Cameras:" << endl;
        for (int i = 0; i < cameraCount; i++) {
            cout << "  Camera " << i+1 << " -> ";
            cameras[i]->display();
        }

        cout << "\nTotal Lights  : " << lightCount  << endl;
        cout << "Total ACs     : " << acCount      << endl;
        cout << "Total Cameras : " << cameraCount  << endl;
        cout << "Total Power   : " << calculateTotalPower() << "W" << endl;
    }
};


int main() {
    Light l1(800, 10), l2(600, 8);
    AirConditioner ac1(1.5, 1500), ac2(2.0, 2000);
    SecurityCamera c1("1080p", 5), c2("4K", 10);

    House h("Smart Villa", "CTRL-1001");

}