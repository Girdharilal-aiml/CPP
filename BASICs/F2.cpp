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


// =======================================================================
// CONCEPT 6: SINGLE INHERITANCE — Student inherits from Person
// Mode: public inheritance (most common)
// public inheritance = public stays public, protected stays protected
// =======================================================================
class Student : public Person {
private:
    float cgpa;
    string department;
    Grade grade;              // HAS-A Grade object
    static int totalStudents; // counts only students

public:
    Student(string n, int a, string cnic, string i,
            float c, string dept, float marks,
            Address addr = Address())
        : Person(n, a, cnic, i, addr), grade(marks) {
        cgpa       = c;
        department = dept;
        totalStudents++;
    }

    float  getCGPA()       const { return cgpa; }
    string getDepartment() const { return department; }
    Grade  getGrade()      const { return grade; }

    void setCGPA(float c) {
        if (c >= 0.0 && c <= 4.0) cgpa = c;
        else cout << "Invalid CGPA!\n";
    }

    static int getTotalStudents() { return totalStudents; }

    // FUNCTION OVERRIDING — Student gives its OWN version of showRole()
    // 'override' keyword is good practice — tells compiler we're overriding
    void showRole() override {
        cout << "Role    : Student" << endl;
    }

    void display() override {
        cout << "----------------------------------------\n";
        cout << "STUDENT RECORD\n";
        cout << "Name    : " << getName()       << endl;
        cout << "ID      : " << getID()         << endl;
        cout << "CNIC    : " << getCNIC()        << endl;
        cout << "Age     : " << getAge()         << endl;
        cout << "CGPA    : " << cgpa             << endl;
        cout << "Dept    : " << department       << endl;
        cout << "Grade   : " << grade            << endl;  // uses overloaded <<
        showAddress();
        showRole();
    }

    // computePay not applicable for student — return 0
    double computePay() override { return 0; }
};
int Student::totalStudents = 0;


// =======================================================================
// CONCEPT 7: HIERARCHICAL INHERITANCE
// Both Teacher and Admin inherit from Person (one parent, many children)
// =======================================================================
class Teacher : public Person {
private:
    string subject;
    double salaryPerHour;
    int    hoursWorked;
    static int totalTeachers;

public:
    Teacher(string n, int a, string cnic, string i,
            string sub, double sal, int hours,
            Address addr = Address())
        : Person(n, a, cnic, i, addr) {
        subject       = sub;
        salaryPerHour = sal;
        hoursWorked   = hours;
        totalTeachers++;
    }

    string getSubject()      const { return subject; }
    double getSalaryPerHour()const { return salaryPerHour; }
    int    getHoursWorked()  const { return hoursWorked; }

    static int getTotalTeachers() { return totalTeachers; }

    // computePay = salary x hours
    double computePay() override {
        return salaryPerHour * hoursWorked;
    }

    void showRole() override {
        cout << "Role    : Teacher" << endl;
    }

    void display() override {
        cout << "----------------------------------------\n";
        cout << "TEACHER RECORD\n";
        cout << "Name    : " << getName()         << endl;
        cout << "ID      : " << getID()           << endl;
        cout << "Age     : " << getAge()           << endl;
        cout << "Subject : " << subject            << endl;
        cout << "Pay     : Rs." << computePay()    << endl;
        showAddress();
        showRole();
    }
};
int Teacher::totalTeachers = 0;


// =======================================================================
// CONCEPT 8: MULTI-LEVEL INHERITANCE
// Person → Teacher → HeadOfDepartment (grandchild)
// =======================================================================
class HeadOfDepartment : public Teacher {
private:
    string department;
    double bonus;

public:
    HeadOfDepartment(string n, int a, string cnic, string i,
                     string sub, double sal, int hours,
                     string dept, double bon,
                     Address addr = Address())
        : Teacher(n, a, cnic, i, sub, sal, hours, addr) {
        department = dept;
        bonus      = bon;
    }

    // Multi-level: HOD gets Teacher's pay PLUS bonus
    double computePay() override {
        return Teacher::computePay() + bonus;   // calls parent's computePay()
    }

    void showRole() override {
        cout << "Role    : Head of Department — " << department << endl;
    }

    void display() override {
        cout << "----------------------------------------\n";
        cout << "HOD RECORD\n";
        cout << "Name    : " << getName()       << endl;
        cout << "Dept    : " << department      << endl;
        cout << "Total Pay: Rs." << computePay()<< endl;
        showRole();
    }
};


// =======================================================================
// CONCEPT 9: DIAMOND PROBLEM & VIRTUAL BASE CLASS
//
//         Person
//        /      \
//   Teacher    Researcher
//        \      /
//       AcademicStaff        ← inherits from BOTH
//
// Problem: AcademicStaff gets TWO copies of Person
// Fix: use 'virtual' keyword in intermediate classes
// =======================================================================
