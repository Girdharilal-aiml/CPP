/*
=======================================================================
        ULTIMATE C++ OOP MASTER CODE — UNIVERSITY SYSTEM
        Covers EVERY concept you need to master:

        ✅ Static Member & Static Function
        ✅ Constant Member & Constant Function
        ✅ Has-A Relationship & Array of Objects
        ✅ Inheritance (Single, Multi-level, Multiple, Hierarchical)
        ✅ Modes of Inheritance (public, protected, private)
        ✅ Diamond Problem & Virtual Base Class
        ✅ Polymorphism
        ✅ Function Overloading
        ✅ Function Overriding & Virtual Functions
        ✅ Friend Function
        ✅ Friend Class
        ✅ Operator Overloading
=======================================================================
*/

#include "iostream"
#include <string>
using namespace std;


// =======================================================================
// CONCEPT 1: ABSTRACT CLASS + PURE VIRTUAL FUNCTIONS (Abstraction)
// =======================================================================
// This is a contract — any class inheriting this MUST implement these
// Pure virtual function = virtual void func() = 0;
// A class with even ONE pure virtual function becomes abstract (can't make objects)
class Entity {
public:
    virtual void showRole()  = 0;   // pure virtual — MUST be overridden
    virtual void display()   = 0;   // pure virtual — MUST be overridden
    virtual double computePay() = 0; // pure virtual — MUST be overridden
    virtual ~Entity() {}            // always add virtual destructor in abstract classes
};


// =======================================================================
// CONCEPT 2: OPERATOR OVERLOADING
// A separate Grade class — we'll overload + and << operators
// =======================================================================
class Grade {
private:
    float marks;


};


// =======================================================================
// CONCEPT 3: ADDRESS CLASS — demonstrates HAS-A relationship
// A Person HAS-A Address (composition)
// HAS-A = one class contains an OBJECT of another class
// =======================================================================
class Address {
private:
    string city;
    string country;

public:
    Address(string c = "Karachi", string co = "Pakistan") {
        city = c;
        country = co;
    }

    // CONSTANT FUNCTION — 'const' at end means it cannot modify any member
    // Use const on functions that only READ data, never change it
    string getCity()    const { return city; }
    string getCountry() const { return country; }

    void display() const {
        cout << city << ", " << country;
    }
};


// =======================================================================
// CONCEPT 4: BASE CLASS — Person
// Has static members, const members, HAS-A Address
// =======================================================================
class Person : public Entity {
};
