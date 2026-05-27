// 1. The Smart Thermostat
// Design a RoomHeater entity containing targetTemperature and maxLimit.
// Rule: Write a function increaseTemp(double degrees). 
// It must only increase the temperature if degrees is positive AND the resulting temperature does not exceed maxLimit. 
// If it succeeds, return true; otherwise, do not change the temperature and return false.

#include "iostream"
using namespace std;

class RoomHeater{
private:
    double targetTemperature;
    double maxLimit;

public:
    RoomHeater(double t, double ml) : targetTemperature(t), maxLimit(ml) {}


};
