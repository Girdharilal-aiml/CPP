// 18. The Zoo Enclosure: You have a base concept Animal that must be able to makeSound(). Lion and Monkey are specific animals.
// Rule: Write a main() function that creates an array capable of holding 3 pointers to the general Animal concept. Assign a Lion and a Monkey dynamically (using new) to this array, and trigger their sounds via a loop.

#include "iostream"
using namespace std;

class Animal{
public:
    virtual void MakeSound() = 0;
};

class Lion : public Animal{
public: 
    void MakeSound() override{
        cout << "ROAR..." << endl;
    }
};

class Monkey : public Animal{
public: 
    void MakeSound() override{
        cout << "SCREAM..." << endl;
    }
};

int main(){
    Animal* Sound[3];
    Sound[0] = new Lion();
    Sound[1] = new Monkey();
    
    
    
}