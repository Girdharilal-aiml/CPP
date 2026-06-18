// 30. The Fleet Backup System (The Final Boss):
// Rule: Write a system that takes an array of exactly 10 GasVehicle objects and writes the entire array to a file as a single raw block of memory bytes in one single operation.
// Rule: If the file fails to open during this process, halt execution by signaling an error using a simple text message string. Capture this error safely in main().

#include "iostream"
#include "fstream"
using namespace std;

struct GasVehicle {
    int id;
    double tankSize;
};

int main() {
    GasVehicle fleet[10];
    for (int i = 0; i < 10; i++) {
        fleet[i] = {100 + i, 50.0 + (i * 2)};
    }

    try {
        ofstream fleetOut("fleet.dat", ios::binary);




    } 
}