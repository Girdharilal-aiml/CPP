// 16. Smart Home Gadgets: A base Device has a serialNumber set via its constructor. A Camera and a Microphone are both Devices.
// Rule: A SmartDisplay combines both a Camera and a Microphone. Write the constructor for SmartDisplay to demonstrate how it properly initializes the serialNumber in the core Device base class without causing duplicate data.

#include "iostream"
using namespace std;

class Device{
protected:
    int SerialNumber;
    
public:
};

class Camera : virtual public Device{
public:
};
