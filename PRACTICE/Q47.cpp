// 11. Concepts: Generic Data Structures, Polymorphism, and Standard System Errors.
// You are programming the autonomous management system for a futuristic smart farm.

// 1. The Storage Facility:
// Rule: Design a generic storage entity called Silo. It must contain a fixed array capable of holding exactly 100 items of any one specific data type.
// Rule: Include an integer tracking the current count. Write an addCrop(item) method that adds an item to the array, but silently ignores the action if the Silo is full.

// 2. The Crop System:
// Rule: Create a general concept Crop that requires a calculateYield() method. Create specific Wheat and Corn entities based on this concept.
// Rule: For Corn, if its internal waterLevel variable is a negative number, calling calculateYield() must halt execution and signal a standard C++ system runtime error containing the exact text "Drought failure".

// 3. System Execution (Main):
// Rule: In main(), instantiate a Silo that is capable of holding polymorphic pointers to the general Crop concept.
// Rule: Dynamically create a Corn entity (with a negative water level) and add it to the Silo.
// Rule: Attempt to calculate its yield, providing a safety net to safely capture the standard system error and print its internal message to the screen.

#include "iostream"
#include "stdexcept"
using namespace std;

template <typename T>
class Silo {
    T items[100];
    int count;
public:
    Silo() : count(0) {}
    void addCrop(T item) {
        if (count < 100) {
            items[count++] = item;
        }
    }
    T getCrop(int index) {
        return items[index];
    }
};

class Crop {
public:
    virtual double calculateYield() = 0;
};

class Wheat : public Crop {
public:
    double calculateYield() {
        return 500.0;
    }
};

class Corn : public Crop {
    int waterLevel;
public:
    Corn(int water) : waterLevel(water) {}
    double calculateYield() {
        if (waterLevel < 0) {
            throw runtime_error("Drought failure");
        }
        return 800.0;
    }
};

int main() {
    Silo<Crop*> farmSilo;

    Crop* crop1 = new Wheat();
    Crop* crop2 = new Corn(-5); 

    farmSilo.addCrop(crop1);
    farmSilo.addCrop(crop2);

    for (int i = 0; i < 2; i++) {
        try {
            cout << "Crop " << i << " yield: " << farmSilo.getCrop(i)->calculateYield() << endl;
        }
        catch (runtime_error& e) { 
            cout << "System Alert: " << e.what() << endl;
        }
    }
}