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

class Scholarship;

class Wallet{
private:
    double balance;

public:
    Wallet(double b = 0) { balance = b; }

    double getBalance() const { return balance; }

    friend void addBonus(Wallet& w, double bonus);

    friend class BankAuditor;
};

void addBonus(Wallet& w, double bonus) {
    w.balance += bonus;
    cout << "Bonus added! New balance: Rs." << w.balance << endl;
}

class BankAuditor {
public:
    void auditWallet(const Wallet& w) {
        cout << "Auditing wallet with balance: Rs." << w.balance << endl;
    }

};

class Course{
private:
    string courseName;
    string courseCode;
    Teacher* assignedTeacher;
    Student* students[50];
    int studentCount;
    const int MAX_STUDENTS = 50;

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

    Student* getTopStudent() {
        if (studentCount == 0) return nullptr;
        Student* top = students[0];
        for (int i = 1; i < studentCount; i++) {
            if (students[i]->getCGPA() > top->getCGPA()) {
                top = students[i];
            }
        }
        return top;
    }

    void display() {
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
        if (top) {
            cout << "TOP STUDENT: " << top->getName() << "\n";
        }
    }
};

class University {
private:
    string uniName;
    Student* students[200];
    Teacher* teachers[100];
    Course* courses[50];
    int sCount, tCount, cCount;

public:
    University(string name){
        uniName = name;
        sCount = tCount = cCount = 0;
    }

    void addStudent(Student* s) { students[sCount++] = s; }
    void addTeacher(Teacher* t) { teachers[tCount++] = t; }
    void addCourse(Course* c) { courses[cCount++] = c; }

    void generatePayroll() {
        cout << "\n========================================\n";
        cout << "   PAYROLL REPORT\n";
        cout << "========================================\n";
        double total = 0;

        for (int i = 0; i < tCount; i++) {
            cout << teachers[i]->getName()
                 << " — Rs." << teachers[i]->computePay() << "\n";
            total += teachers[i]->computePay();
        }
        cout << "TOTAL PAYROLL: Rs." << total << "\n";
    }

    void generateReport() {
        cout << "\n========================================\n";
        cout << "   UNIVERSITY REPORT\n";
        cout << "========================================\n";

        cout << "Total Persons Created : " << Person::getTotalPersons() << "\n";
        cout << "Total Students        : " << Student::getTotalPersons() << "\n";
        cout << "Total Teachers        : " << Teacher::getTotalPersons() << "\n";

        for (int i = 0; i < tCount; i++) {
            teachers[i]->display();
            cout << endl;
        }
        for (int i = 0; i < sCount; i++) {
            students[i]->display();
            cout << endl;
        }
        for (int i = 0; i < cCount; i++) {
            courses[i]->display();
            cout << endl;
        }
    }
};

int main(){
    cout << "=== Ultimate OOP Demo: University Management System ===\n";    

    cout << "--- OPERATOR OVERLOADING ---\n";
    Grade g1(85.5), g2(90.0);
    Grade g3 = g1 + g2;
    cout << "Grade 1: " << g1 << "\n";
    cout << "Grade 2: " << g2 << "\n";
    cout << "Grade 3: " << g3 << "\n";
    cout << "g2 > g1? " << (g2 > g1 ? "Yes" : "No") << "\n";

    cout << "\n--- FUNCTION OVERLOADING ---\n";
    Calculator calc;
    cout << "add(3,4) = " << calc.add(3, 4) << "\n";
    cout << "add(2.5, 3.1) = " << calc.add(2.5, 3.1) << "\n";
    cout << "add(1,2,3) = " << calc.add(1, 2, 3) << "\n";

    cout << "\n--- FRIEND FUNCTION & CLASS ---\n";
    Wallet w(1000);
    addBonus(w, 500);
    BankAuditor auditor;
    auditor.auditWallet(w);
    cout << "\n";

    Address addr1("Lahore", "Pakistan");
    Address addr2("Islamabad", "Pakistan");

    Teacher* t1 = new Teacher("Dr. Smith", 45, "12345-6789012-3", "T001",
                              "Mathematics", 1000, 20, addr1);
    Teacher* t2 = new Teacher("Dr. Johnson", 50, "98765-4321098-7", "T002",
                                "Physics", 1200, 15, addr2);        
    
    HeadOfDepartment hod("Dr. Williams", 55, "55555-5555555-5", "HOD01",
                                                 "Computer Science", 20000, addr1);
    AcademicStaff as1("Dr. Brown", 40, "11111-2222222-3", "AS001", 
                                            "Chemistry", "Organic Chemistry");                  


    Student s1("Alice", 20, "22222-3333333-4", "S001", 3.8, "Computer Science", 88, addr2);
    Student s2("Bob", 22, "33333-4444444-5", "S002", 3.5, "Mathematics", 82, addr1);     
    Student s3("Charlie", 21, "44444-5555555-6", "S003", 3.2, "Physics", 75, addr2);
    Student s4("Diana", 19, "55555-6666666-7", "S004", 3.9, "Computer Science", 91, addr1);

    Course c1("Data Structures", "CS101", &t1);
    Course c2("Quantum Mechanics", "PH101", &t2);

    c1.enrollStudent(&s1);
    c1.enrollStudent(&s2);
    c2.enrollStudent(&s3);
    c2.enrollStudent(&s4);

    University uni("FAST NUCES");
    uni.addTeacher(t1);
    uni.addTeacher(t2);
    uni.addStudent(&s1);
    uni.addStudent(&s2);
    uni.addStudent(&s3);
    uni.addStudent(&s4);
    uni.addCourse(&c1);
    uni.addCourse(&c2);

    uni.generatePayroll();
    uni.generateReport();
    
    cout << "\n--- POLYMORPHISM DEMO (Virtual Functions)---\n";
    Entity* staff[4];



}