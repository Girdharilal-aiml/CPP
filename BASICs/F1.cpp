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
        cout << "Name    : " << getName() << endl;
        cout << "ID      : " << getID() << endl;
        cout << "Age     : " << getAge() << endl;
        cout << "CGPA    : " << cgpa << endl;
        cout << "Course  : " << enrolledCourse << endl;
    }
};


// ============================================
// CHILD CLASS 2 — Inheritance from Person
// Teacher IS-A Person
// ============================================
class Teacher : public Person {
private:
    string subject;
    double salary;

public:
    Teacher(string n, int a, string id, string sub, double sal)
        : Person(n, a, id) {
        subject = sub;
        salary = sal;
    }

    string getSubject() { return subject; }

    // POLYMORPHISM — Teacher's own version of showRole()
    void showRole() override {
        cout << "I am a Teacher." << endl;
    }

    // POLYMORPHISM — Teacher's own version of display()
    void display() override {
        cout << "----------------------------------------" << endl;
        cout << "TEACHER RECORD" << endl;
        cout << "Name    : " << getName() << endl;
        cout << "ID      : " << getID() << endl;
        cout << "Age     : " << getAge() << endl;
        cout << "Subject : " << subject << endl;
        cout << "Salary  : " << salary << endl;
    }
};


// ============================================
// SEPARATE CLASS — Course
// Has a Teacher and list of Students
// ============================================
class Course {
private:
    string courseName;
    Teacher* teacher;        // Pointer to a Teacher object
    Student* students[50];   // Array of Student pointers
    int studentCount;

public:
    Course(string name, Teacher* t) {
        courseName = name;
        teacher = t;
        studentCount = 0;
    }

    void enrollStudent(Student* s) {
        if (studentCount < 50) {
            students[studentCount] = s;
            studentCount++;
            cout << s->getName() << " enrolled in " << courseName << endl;
        } else {
            cout << "Course is full!" << endl;
        }
    }

    void displayCourse() {
        cout << "========================================" << endl;
        cout << "COURSE  : " << courseName << endl;
        cout << "TEACHER : " << teacher->getName() << endl;
        cout << "STUDENTS ENROLLED: " << studentCount << endl;
        for (int i = 0; i < studentCount; i++) {
            cout << "  -> " << students[i]->getName()
                 << " (CGPA: " << students[i]->getCGPA() << ")" << endl;
        }
    }
};


// ============================================
// UNIVERSITY CLASS — Brings everything together
// ============================================
class University {
private:
    string uniName;
    Student* students[100];
    Teacher* teachers[50];
    Course*  courses[20];
    int sCount, tCount, cCount;

public:
    University(string name) {
        uniName = name;
        sCount = tCount = cCount = 0;
    }

};

