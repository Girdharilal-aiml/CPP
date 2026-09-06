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
private:
    string name;
    int age;
    const string CNIC;    // CONSTANT MEMBER — set once, never changes (like ID)
    Address address;      // HAS-A relationship — Person HAS-A Address

protected:
    // 'protected' = accessible in child classes but not outside
    string id;

public:
    // STATIC MEMBER — belongs to the CLASS, not any single object
    // All Person objects SHARE this one variable
    // Use case: counting how many Person objects have been created
    static int totalPersons;

    // Constructor — notice const member CNIC must be initialized in initializer list
    Person(string n, int a, string cnic, string i, Address addr = Address())
        : CNIC(cnic), address(addr) {   // const member initialized here
        name = n;
        age  = a;
        id   = i;
        totalPersons++;   // every time a Person is made, count goes up
    }

    // Getters — marked const because they only read
    string getName() const { return name; }
    int    getAge()  const { return age; }
    string getCNIC() const { return CNIC; }
    string getID()   const { return id; }

    // Setters
    void setName(string n) { name = n; }
    void setAge(int a) {
        if (a > 0 && a < 120) age = a;
        else cout << "Invalid age!\n";
    }

    // STATIC FUNCTION — can only access static members
    // Called on CLASS, not object: Person::getTotalPersons()
    static int getTotalPersons() {
        return totalPersons;
    }

    // Display address using HAS-A object
    void showAddress() const {
        cout << "Address : ";
        address.display();
        cout << endl;
    }

    // These are still pure virtual (inherited from Entity)
    // Person doesn't implement them — child classes will
    virtual void showRole()     = 0;
    virtual void display()      = 0;
    virtual double computePay() = 0;
};

// Static member must be defined OUTSIDE the class
int Person::totalPersons = 0;


// =======================================================================
// CONCEPT 5: FUNCTION OVERLOADING
// Same function name, different parameters
// Decided at COMPILE TIME (not runtime)
// =======================================================================
class Calculator {
public:
    // Three functions with SAME name but DIFFERENT parameters
    int add(int a, int b) {
        return a + b;
    }
    double add(double a, double b) {
        return a + b;
    }
    int add(int a, int b, int c) {
        return a + b + c;
    }
    // Compiler decides WHICH add() to call based on arguments you pass
};

