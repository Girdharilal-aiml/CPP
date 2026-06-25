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

    // Setters (controlled modification)
    void setName(string n) { name = n; }
    void setAge(int a) {
        if (a > 0) age = a;  // validation
        else cout << "Invalid age!" << endl;
    }
};


// ============================================
// CHILD CLASS 1 — Inheritance from Person
// Student IS-A Person
// ============================================
class Student : public Person {
private:
    float cgpa;
    string enrolledCourse;

public:
    // Constructor calls parent constructor
    Student(string n, int a, string id, float c, string course)
        : Person(n, a, id) {   // <-- This calls Person's constructor
        cgpa = c;
        enrolledCourse = course;
    }

    float getCGPA() { return cgpa; }
    void setCGPA(float c) {
        if (c >= 0.0 && c <= 4.0) cgpa = c;
        else cout << "Invalid CGPA!" << endl;
    }

    // POLYMORPHISM — Student's own version of showRole()
    void showRole() override {
        cout << "I am a Student." << endl;
    }

    // POLYMORPHISM — Student's own version of display()
    void display() override {
        cout << "----------------------------------------" << endl;
        cout << "STUDENT RECORD" << endl;
    }
};



