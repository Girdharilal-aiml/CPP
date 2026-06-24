#include "iostream"
#include <string>
using namespace std;

// ============================================
// ABSTRACTION — Abstract Base Class
// Cannot be instantiated, forces child classes
// to define their own version of showRole()
// ============================================
class Role {
public:
    virtual void showRole() = 0; // Pure virtual function
    virtual void display() = 0;  // Pure virtual function
    virtual ~Role() {}           // Virtual destructor (good practice)
};


// ============================================
// BASE CLASS — Encapsulation in action
// Private data, public getters/setters
// ============================================
class Person : public Role {
private:
    string name;   // private = encapsulated
    int age;
    string id;

public:
    // Constructor
    Person(string n, int a, string i) {
        name = n;
        age = a;
        id = i;
    }

    // Getters (controlled access to private data)
    string getName() { return name; }
    int getAge()     { return age; }
    string getID()   { return id; }

};

