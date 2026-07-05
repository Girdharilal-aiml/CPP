#include "iostream"
#include "string"
using namespace std;

class Entity{
public:
    virtual void showRole()  = 0;  
    virtual void display()   = 0;   
    virtual double computePay() = 0;
    virtual ~Entity() {}            
};

class Grade{
private:
    float marks;

public:
    Grade(float m = 0.0) { marks = m; }

    float getMarks() const { return marks; }

    Grade operator+(const Grade& other) const {
        return Grade(marks + other.marks);
    }

    bool operator>(const Grade& other) const {
        return marks > other.marks;
    }

    bool operator==(const Grade& other) const {
        return marks == other.marks;
    }

    friend ostream& operator<<(ostream& out, const Grade& g) {
        out << g.marks << "/100";
        return out;
    }
};

class Address {
private:
    string city;
    string country;

public:
    Address(string c = "karachi", string co = "Pakistan"){
        city = c;
        country = co;
    }

    string getCity() const { return city; }
    string getCountry() const { return country; }

    void display() const {
        cout << city << ", " << country;
    }
};

class Person : public Entity {
private:
    string name;
    int age;
    const string CNIC;
    Address address;

protected:
    string id;

public:
    static int totalPersons;

    Person(string n, int a, string cnic, string i, Address addr = Address())
        : CNIC(cnic), address(addr) {
        name = n;
        age  = a;
        id = i;
        totalPersons++;
    }

    string getName() const { return name; }
    int getAge() const { return age; }
    string getCNIC() const { return CNIC; }
    string getID() const { return id; }

    void setName(string n) { name = n; }
    void setAge(int a) {
        if (a > 0 && a < 120) age = a;
        else cout << "Invalid age!\n";
    }

    static int getTotalPersons() { return totalPersons; }

    void showAddress() const {
        cout << "Address : ";
        address.display();
        cout << endl;
    }

    virtual void showRole()       = 0;
    virtual void display()        = 0; 
    virtual double computePay()   = 0;
};

int  Person::totalPersons = 0;

class Calculator {
public:
    int add(int a, int b) {
        return a + b;
    }
    double add(double a, double b) {
        return a + b;
    }
    int add(int a, int b, int c) {
        return a + b + c;
    }
};

class Student : public Person {
private:
    float cgpa;
    string department;
    Grade grade;
    static int totalStudents;

public:
    Student(string n, int a, string cnic, string i,
            float c, string dept, Grade g,
            Address addr = Address())
        : Person(n, a, cnic, i, addr) {
        cgpa       = c;
        department = dept;
        grade      = g;
        totalStudents++;
    }

    float getCGPA() const { return cgpa; }
    string getDepartment() const { return department; }
    Grade getGrade() const { return grade; }

    void setCGPA(float c) {
        if (c >= 0.0 && c <= 4.0) cgpa = c;
        else cout << "Invalid CGPA!\n";
    }

    static int getTotalStudents() { return totalStudents; }

    void showRole() override {
        cout << "Role    : Student" << endl;
    }

    void display() override {
        cout << "----------------------------------------\n";
        cout << "STUDENT RECORD\n";
        cout << "Name    : " << getName()       << endl;
        cout << "ID      : " << getID()         << endl;
        cout << "CGPA    : " << getCGPA()       << endl;
        cout << "Dept    : " << getDepartment() << endl;
        cout << "Grade   : " << getGrade()      << endl;
        showAddress();
        showRole();
    }

    double computePay() override { return 0; }
};

int Student::totalStudents = 0;

class Teacher : public Person {
private:
    string subject;
    double salaryPerHour;
    int hoursWorked;
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

    string getSubject() const { return subject; }
    double getSalaryPerHour() const { return salaryPerHour; }
    int getHoursWorked() const { return hoursWorked; }

    static int getTotalTeachers() { return totalTeachers; }

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

class HeadOfDepartment : public Teacher {
private:
    string department;
    double bonus;

public:
    HeadOfDepartment(string n, int a, string cnic, string i,
                     string dept, double b,
                     Address addr = Address())
        : Teacher(n, a, cnic, i, "", 0, 0, addr) {
        department = dept;
        bonus      = b;
    }

    double computePay() override {
        return Teacher::computePay() + bonus;
    }

    void showRole() override {
        cout << "Role    : Head of Department" << endl;
    }

    void display() override {
        cout << "----------------------------------------\n";
        cout << "HEAD OF DEPARTMENT RECORD\n";
        cout << "Name    : " << getName()         << endl;
        cout << "ID      : " << getID()           << endl;
        cout << "Age     : " << getAge()           << endl;
        cout << "Department : " << department     << endl;
        cout << "Bonus   : Rs." << bonus          << endl;
        showAddress();
        showRole();
    }

};

class Researcher : virtual public Person {
private:
    string researchArea;

public:
    Researcher(string n, int a, string cnic, string i, string area)
        : Person(n, a, cnic, i) {
        researchArea = area;
    }

    string getResearchArea() const { return researchArea; }

    double computePay() override { return 50000; }

    void showRole() override {
        cout << "Role    : Researcher — " << researchArea << endl;
    }

    void display() override {
        cout << "Name    : " << getName() << endl;
        cout << "Research: " << researchArea << endl;
        showRole();
    }
};

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

class AcademicStaff : public VirtualTeacher, public Researcher {
public:
    AcademicStaff(string n, int a, string cnic, string i,
                  string sub, string area)



};


