// 15. RPG Character Classes: In a game, an Entity has a healthPool variable. A Warrior is an Entity. A Mage is an Entity.
// Rule: A Paladin combines the abilities of both a Warrior and a Mage.
// Rule: Write the class definitions to ensure that when a Paladin takes damage, the system doesn't get confused about which healthPool to deduct from (they must share a single health pool in memory).

#include "iostream"
using namespace std;

class Entity{
protected:
    double HealthPool;

public:
    Entity(double HP) : HealthPool(HP){}
    double getHealth(){
        return HealthPool;
    }
};

class Warrior : virtual public Entity{
public:
    Warrior(double dp) : Entity(dp){}
};

class Mage : virtual public Entity{
public:
    Mage(double dp) : Entity(dp){}
}; 

class Paladin : public Warrior, public Mage{
public:
    Paladin(double dp) : Entity(dp), Warrior(dp), Mage(dp){}
    void damage(double s){
        if(s < HealthPool){
            HealthPool = HealthPool - s;
        }
    }
};

int main(){
}