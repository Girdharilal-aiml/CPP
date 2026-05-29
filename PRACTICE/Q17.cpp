// 3. The Coffee Machine
// Design an EspressoMachine entity with waterLevel and coffeeBeansLevel.
// Rule: Write a brew(int shots) function. One shot requires 30ml of water and 15g of beans. 
// Before brewing, validate that there is strictly enough of both resources simultaneously. 
// If so, deduct the resources and return true; otherwise, return false.

#include "iostream"
using namespace std;

class EspressoMachine{
private:
    double waterLevel;
    double coffeeBeansLevel;

public:
    EspressoMachine(double water, double beans) : waterLevel(water), coffeeBeansLevel(beans) {}
    bool brew(int shots){
        double requiredWater = shots * 30;
        double requiredBeans = shots * 15;
        if(waterLevel >= requiredWater && coffeeBeansLevel >= requiredBeans){
            waterLevel -= requiredWater;
            coffeeBeansLevel -= requiredBeans;
            return true;
        }else{
            return false;
        }
    }  
};

int main(){
    EspressoMachine machine(500, 200); 
    int shots = 3;
    if(machine.brew(shots)){
}