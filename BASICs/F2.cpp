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

class Researcher : virtual public Person {
private:
    string researchArea;

public:
    Researcher(string n, int a, string cnic, string i, string area)
        : Person(n, a, cnic, i) {
        researchArea = area;
    }

    string getResearchArea() const { return researchArea; }

    double computePay() override { return 50000; } // flat stipend

    void showRole() override {
        cout << "Role    : Researcher — " << researchArea << endl;
    }

    void display() override {
        cout << "Name    : " << getName() << endl;
        cout << "Research: " << researchArea << endl;
        showRole();
    }
};

// Teacher must ALSO be virtual for diamond fix
// But we already defined Teacher — let's make a VirtualTeacher for demo
class VirtualTeacher : virtual public Person {
private:
    string subject;

public:
    VirtualTeacher(string n, int a, string cnic, string i, string sub)
        : Person(n, a, cnic, i) {
        subject = sub;
    }

    double computePay() override { return 70000; }

    void showRole() override {
        cout << "Role    : Virtual Teacher — " << subject << endl;
    }

    void display() override {
        cout << "Name    : " << getName() << endl;
        cout << "Subject : " << subject   << endl;
        showRole();
    }
};

// AcademicStaff inherits from BOTH — diamond resolved via virtual
class AcademicStaff : public VirtualTeacher, public Researcher {
public:
    // Must call Person constructor directly in diamond situation
    AcademicStaff(string n, int a, string cnic, string i,
                  string sub, string area)
        : Person(n, a, cnic, i),             // called ONCE due to virtual
          VirtualTeacher(n, a, cnic, i, sub),
          Researcher(n, a, cnic, i, area) {}

    double computePay() override {
        return VirtualTeacher::computePay() + Researcher::computePay();
    }

    void showRole() override {
        cout << "Role    : Academic Staff (Teacher + Researcher)" << endl;
    }

    void display() override {
        cout << "----------------------------------------\n";
        cout << "ACADEMIC STAFF\n";
        cout << "Name    : " << getName()      << endl;
        cout << "Total Pay: Rs." << computePay()<< endl;
        showRole();
    }
};


// =======================================================================
// CONCEPT 10: FRIEND FUNCTION & FRIEND CLASS
// =======================================================================

// Forward declaration (needed so Scholarship knows about Student)
class Scholarship;

// FRIEND CLASS — Scholarship can access private members of Student
// Declared inside Student... but Student is already defined above.
// So let's make a simpler demo class:

class Wallet {
private:
    double balance;  // private — normally no one can touch this

public:
    Wallet(double b) { balance = b; }
    double getBalance() const { return balance; }

    // FRIEND FUNCTION declaration — this non-member function
    // can access Wallet's private members
    friend void addBonus(Wallet& w, double amount);

    // FRIEND CLASS declaration — BankAuditor can access Wallet's private data
    friend class BankAuditor;
};

// FRIEND FUNCTION definition — not a member of Wallet, but has private access
void addBonus(Wallet& w, double amount) {
    w.balance += amount;   // accessing private 'balance' — only works because friend
    cout << "Bonus added! New balance: Rs." << w.balance << endl;
}

// FRIEND CLASS — all functions in BankAuditor can access Wallet's private data
class BankAuditor {
public:
    void audit(Wallet& w) {
        // Accessing private balance directly because BankAuditor is a friend
        cout << "[AUDIT] Wallet balance is: Rs." << w.balance << endl;
    }
};


// =======================================================================
// CONCEPT 11: ARRAY OF OBJECTS — Course has array of Student objects
// HAS-A relationship at scale
// =======================================================================
class Course {
private:
    string   courseName;
    string   courseCode;
    Teacher* assignedTeacher;     // HAS-A pointer to Teacher
    Student* students[50];        // ARRAY OF OBJECT POINTERS
    int      studentCount;
    const int MAX_STUDENTS = 50;  // const member

public:
    Course(string name, string code, Teacher* t) {
        courseName      = name;
        courseCode      = code;
        assignedTeacher = t;
        studentCount    = 0;
    }

    bool enrollStudent(Student* s) {
        if (studentCount < MAX_STUDENTS) {
            students[studentCount++] = s;
            return true;
        }
        cout << "Course full!\n";
        return false;
    }

    // Find student with highest CGPA
    Student* getTopStudent() {
        if (studentCount == 0) return nullptr;
        Student* top = students[0];
        for (int i = 1; i < studentCount; i++) {
            if (students[i]->getCGPA() > top->getCGPA())
                top = students[i];
        }
        return top;
    }

    void displayCourse() {
        cout << "========================================\n";
        cout << "COURSE   : " << courseName << " (" << courseCode << ")\n";
        cout << "TEACHER  : " << assignedTeacher->getName() << "\n";
        cout << "STUDENTS : " << studentCount << "\n";
        for (int i = 0; i < studentCount; i++) {
            cout << "  [" << i+1 << "] "
                 << students[i]->getName()
                 << " | CGPA: " << students[i]->getCGPA()
                 << " | Grade: " << students[i]->getGrade() << "\n";
        }
        Student* top = getTopStudent();
        if (top)
            cout << "TOP STUDENT: " << top->getName() << "\n";
    }
};


// =======================================================================
// CONCEPT 12: UNIVERSITY — The master class
// Uses arrays of objects, polymorphism, static members
// =======================================================================
class University {
private:
    string   uniName;
    Student* students[200];
    Teacher* teachers[100];
    Course*  courses[50];
    int sCount, tCount, cCount;

public:
    University(string name) {
        uniName = name;
        sCount = tCount = cCount = 0;
    }

    void addStudent(Student* s) { students[sCount++] = s; }
    void addTeacher(Teacher* t) { teachers[tCount++] = t; }
    void addCourse (Course*  c) { courses[cCount++]  = c; }

    // POLYMORPHISM in action — using base class pointer
    // Same function call, different behavior based on actual object type
    void generatePayroll() {
        cout << "\n========================================\n";
        cout << "   PAYROLL REPORT\n";
        cout << "========================================\n";
        double total = 0;

        // Entity* can point to Teacher, HOD, AcademicStaff — all work!
        for (int i = 0; i < tCount; i++) {
            cout << teachers[i]->getName()
                 << " — Rs." << teachers[i]->computePay() << "\n";
            total += teachers[i]->computePay();
        }
        cout << "TOTAL PAYROLL: Rs." << total << "\n";
    }

    void generateReport() {
        cout << "\n========================================\n";
        cout << "   UNIVERSITY REPORT: " << uniName << "\n";
        cout << "========================================\n";

        // Static member access
        cout << "Total Persons Created : " << Person::getTotalPersons() << "\n";
        cout << "Total Students        : " << Student::getTotalStudents() << "\n";
        cout << "Total Teachers        : " << Teacher::getTotalTeachers() << "\n";

        cout << "\n--- TEACHERS ---\n";
        for (int i = 0; i < tCount; i++)
            teachers[i]->display();   // virtual dispatch — calls correct display()

        cout << "\n--- STUDENTS ---\n";
        for (int i = 0; i < sCount; i++)
            students[i]->display();

        cout << "\n--- COURSES ---\n";
        for (int i = 0; i < cCount; i++)
            courses[i]->displayCourse();
    }
};


// =======================================================================
// MAIN — Brings EVERYTHING together
// =======================================================================
int main() {
    cout << "=== ULTIMATE C++ OOP DEMO ===\n\n";

    // --- OPERATOR OVERLOADING DEMO ---
    cout << "--- OPERATOR OVERLOADING ---\n";
    Grade g1(78.5), g2(85.0);
    Grade g3 = g1 + g2;             // uses overloaded +
    cout << "Grade 1 : " << g1 << "\n";  // uses overloaded <<
    cout << "Grade 2 : " << g2 << "\n";
    cout << "Combined: " << g3 << "\n";
    cout << "g2 > g1 ? " << (g2 > g1 ? "Yes" : "No") << "\n\n";

    // --- FUNCTION OVERLOADING DEMO ---
    cout << "--- FUNCTION OVERLOADING ---\n";
    Calculator calc;
    cout << "add(3,4)       = " << calc.add(3, 4)       << "\n";
    cout << "add(2.5, 3.1)  = " << calc.add(2.5, 3.1)   << "\n";
    cout << "add(1,2,3)     = " << calc.add(1, 2, 3)     << "\n\n";

    // --- FRIEND FUNCTION & FRIEND CLASS DEMO ---
    cout << "--- FRIEND FUNCTION & CLASS ---\n";
    Wallet w(5000);
    addBonus(w, 1500);      // friend function accessing private data
    BankAuditor auditor;
    auditor.audit(w);       // friend class accessing private data
    cout << "\n";

    // --- CREATING OBJECTS WITH HAS-A (Address) ---
    Address addr1("Karachi", "Pakistan");
    Address addr2("Lahore", "Pakistan");

    // --- HIERARCHICAL INHERITANCE: Teacher & Student both from Person ---
    Teacher t1("Sir Ahmed", 45, "42101-1234567-1", "T001",
               "OOP", 2000, 40, addr1);
    Teacher t2("Ma'am Sana", 38, "42101-7654321-2", "T002",
               "DS", 2200, 40, addr2);

    // --- MULTI-LEVEL INHERITANCE: HOD is a Teacher is a Person ---
    HeadOfDepartment hod("Dr. Bilal", 52, "42101-1111111-3", "H001",
                         "AI", 3000, 40, "CS Department", 15000, addr1);

    // --- DIAMOND PROBLEM SOLUTION: AcademicStaff ---
    AcademicStaff as1("Dr. Zara", 41, "42101-2222222-4", "AS001",
                      "Machine Learning", "Neural Networks");

    // --- STUDENTS ---
    Student s1("Ali",   20, "42101-3333333-5", "S001", 3.5, "CS",   78.5, addr1);
    Student s2("Sara",  19, "42101-4444444-6", "S002", 3.8, "AI",   85.0, addr1);
    Student s3("Hamza", 21, "42101-5555555-7", "S003", 2.9, "CS",   65.0, addr2);
    Student s4("Zara",  20, "42101-6666666-8", "S004", 3.2, "DS",   72.0, addr2);

    // --- COURSES — HAS-A Teacher, ARRAY OF Student pointers ---
    Course c1("OOP in C++",      "CS201", &t1);
    Course c2("Data Structures", "CS301", &t2);

    c1.enrollStudent(&s1);
    c1.enrollStudent(&s2);
    c2.enrollStudent(&s3);
    c2.enrollStudent(&s4);

    // --- UNIVERSITY ---
    University uni("FAST NUCES Karachi");
    uni.addTeacher(&t1);
    uni.addTeacher(&t2);
    uni.addStudent(&s1);
    uni.addStudent(&s2);
    uni.addStudent(&s3);
    uni.addStudent(&s4);
    uni.addCourse(&c1);
    uni.addCourse(&c2);

    // Generate full reports
    uni.generatePayroll();
    uni.generateReport();

    // --- POLYMORPHISM DEMO — Base class pointer, different behaviors ---
    cout << "\n--- POLYMORPHISM DEMO (virtual dispatch) ---\n";
    Entity* staff[4];
    staff[0] = &t1;    // Teacher
    staff[1] = &t2;    // Teacher
    staff[2] = &hod;   // HeadOfDepartment
    staff[3] = &as1;   // AcademicStaff

    for (int i = 0; i < 4; i++) {
        staff[i]->showRole();   // calls correct version for each object
        cout << "Pay: Rs." << staff[i]->computePay() << "\n\n";
    }

    // --- STATIC MEMBER DEMO ---
    cout << "--- STATIC MEMBER ---\n";
    cout << "Total Person objects ever created: "
         << Person::getTotalPersons() << "\n";
    cout << "Total Students: " << Student::getTotalStudents() << "\n";
    cout << "Total Teachers: " << Teacher::getTotalTeachers() << "\n";

    return 0;
}

/*
=======================================================================
CONCEPT SUMMARY — WHERE TO FIND EACH THING IN THIS CODE:

1. STATIC MEMBER/FUNCTION     → Person::totalPersons, getTotalPersons()
                                Student::totalStudents, Teacher::totalTeachers

2. CONST MEMBER/FUNCTION      → const string CNIC in Person
                                getAge() const, getName() const etc.
                                MAX_STUDENTS in Course

3. HAS-A RELATIONSHIP         → Person HAS-A Address
                                Course HAS-A Teacher*, Student*[]
                                Student HAS-A Grade

4. ARRAY OF OBJECTS           → Student* students[50] in Course
                                Student* students[200] in University

5. SINGLE INHERITANCE         → Student : public Person
6. HIERARCHICAL INHERITANCE   → Student & Teacher both from Person
7. MULTI-LEVEL INHERITANCE    → Person→Teacher→HeadOfDepartment
8. MULTIPLE INHERITANCE       → AcademicStaff from VirtualTeacher+Researcher

9. PUBLIC MODE INHERITANCE    → class Student : public Person
   (protected/private modes change what child can access from parent)
   protected mode → parent's public becomes protected in child
   private mode   → parent's public becomes private in child

10. DIAMOND PROBLEM           → Virtual base class: virtual public Person
                                AcademicStaff calls Person() once directly

11. POLYMORPHISM              → Entity* staff[] array in main()
                                showRole() and computePay() behave differently

12. FUNCTION OVERLOADING      → Calculator::add() — 3 versions
13. FUNCTION OVERRIDING       → showRole(), display(), computePay() with override
14. VIRTUAL FUNCTIONS         → virtual void showRole() = 0 in Entity

15. FRIEND FUNCTION           → addBonus(Wallet&, double) — accesses private
16. FRIEND CLASS              → BankAuditor — full private access to Wallet

17. OPERATOR OVERLOADING      → Grade: +, >, ==, << all overloaded
=======================================================================
*/
