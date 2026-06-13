// 22. Sensor Calibration: Design a Sensor entity with a readData() method.
// Rule: If the sensor reads a negative value, halt flow and signal a standard C++ system runtime error object containing the message "Negative reading detected".
// Rule: Safely capture this specific type of system error in main() and print its embedded message using its built-in explanation method.

#include"iostream"
#include"stdexcept"
using namespace std;

class Sensor{
public:
    void readData(int value){
        if(value < 0){
        }
    }
};

