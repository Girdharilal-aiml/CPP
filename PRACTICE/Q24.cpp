// 10. Drone Delivery Swarm: A DeliveryHub entity dispatches drones.
// Rule: Write a method clearForTakeoff(swarm, numDrones) that accepts an array of Drone objects. 
// Iterate through the swarm. If any drone has a .getBatteryPercentage() below 15.0, abort the takeoff (return false).

#include"iostream"
using namespace std;

class Drone{
private:
    double battery;
public:
    Drone(double b) : battery(b){}
    double getBatteryPercentage(){
    }
};

