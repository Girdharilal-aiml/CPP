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
        return battery;
    }
};

class DeliveryHub{
public:
    bool clearForTakeOff(Drone d[], int c){
        if(c<=0){
            return false;
        }
        for(int i = 0; i < c; i++){
            if(d[i].getBatteryPercentage() < 15.0){
                return false;
            }
        }
        return true;
    }
};

int main(){
    Drone D[3] = {Drone(20), Drone(80), Drone(16)};
    DeliveryHub DH;
    if(DH.clearForTakeOff(D, 3)){
    }else{
    }
}