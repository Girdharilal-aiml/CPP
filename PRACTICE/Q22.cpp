// 8. The Space Fleet Shield Check: A Mothership entity manages smaller fighters.
// Rule: Write a method checkFleetShields(fighters, size) that accepts an array of Fighter objects.
// Rule: If the size is 0 or less, return false. Loop through the array. If any ship in the array has a .getShieldLevel() less than 20.0, the fleet is vulnerable (return false). Otherwise, return true.

#include "iostream"
using namespace std;

class Fighters{
private:
    double shield;
public:
    Fighters(double s) : shield(s){}
    double getShieldLevel(){
        return shield;
    }
};

class Mothership{
public:
    Mothership(){}
    bool checkFleetShield(Fighters fight[], int s){
        if(s<=0){
            return false;
        }
        for(int i = 0; i<s; i++){
            if(fight[i].getShieldLevel() < 20){
                return false;
            }
        }
        return true;
    }
};

int main(){
    Fighters Fleet[3] = {Fighters(100), Fighters(200), Fighters(21)};
    Mothership base;
}