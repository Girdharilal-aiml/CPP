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
