// 19. The Gadget Comparer: Create a base Gadget concept that must provide getBatteryLife(). Create Phone and Tablet entities that implement this.
// Rule: In main(), use a generic utility function (like the one from Question 5) to compare two Phone objects and return the one with the better battery life.

#include "iostream"
using namespace std;

class Gadget{
public:
    Gadget(){}
    virtual int GetBatteryLife() = 0;
};

class Phone : public Gadget{
private:
    int BatteryLife;
public:
    Phone(int BL) : BatteryLife(BL){}
    int GetBatteryLife() override{
        return BatteryLife;
    }
};

class Tablet : public Gadget{
private:
    int BatteryLife;
public:
    Tablet(int BL) : BatteryLife(BL){}
    int GetBatteryLife() override{
        return BatteryLife;
    }
};

template<typename T>
T betterBattery(T a, T b){
    if(a.GetBatteryLife() > b.GetBatteryLife()){
        return a;
    }
}
