#include"iostream"
#include"string"
using namespace std;

class Role{
public:
    virtual void showRole()=0;
    virtual void display()=0;
    virtual ~Role() {}
};

class Person : public Role{
private:
    string name;
    int age;
    string id;

public:
    Person(string n, int a, string i){
        name = n;
        age = a;
        id = i;
    }

    string getName() { return name; }
    int getAge() { return age; } 
    string getID() { return id; }

    void setName(string n) { name = n;}
    void setAge(int a){
        if (a > 0) age = a;
        else cout << "Invalid age!" << endl;
    }

};

class Student : public Person{
private:
    float cgpa;
    string enrolledCourse;

public:
    Student(string n, int a, string i, float c, string course) : Person(n,a,i), cgpa(c), enrolledCourse(course){}

    float getCGPA() { return cgpa; }
    void setCGPA(float c){
        if (c >= 0.0 && c <= 4.0) cgpa = c;
        else cout << "Invalid CGPA!" << endl;
    }

    void showRole() override {
        cout << "I am a Student. " << endl;
    }

    void display() override {
        cout << "----------------------------------------" << endl;
        cout << "STUDENT RECORD" << endl;
        cout << "Name    : " << getName() << endl;
        cout << "ID      : " << getID() << endl;
        cout << "Age     : " << getAge() << endl;
        cout << "CGPA    : " << cgpa << endl;
        cout << "Course  : " << enrolledCourse << endl;
        cout << "----------------------------------------" << endl;
    }
};


class Teacher : public Person{
private:
    string subject;
    double salary;

public:
    Teacher(string n, int a, string i,string sub, double sal) : Person(n,a,i), subject(sub), salary(sal){}

    string getsubject() { return subject; }

    void showRole() override {
        cout << "I am a Teacher. " << endl;
    }

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

class Course{
private:
    string courseName;
    Teacher* teacher;
    Student* students[50];
    int studentCount;

public:
    Course(string name, Teacher* t){
        courseName = name;
        teacher = t;
        studentCount = 0;
    }

    void enrollStudent(Student* s){
        if(studentCount < 50){
            students[studentCount] = s;
            studentCount++;
            cout << s->getName() << " enrolled in " << courseName << endl;
        }
        else{
            cout << "Course is full!" << endl;
        }
    }

    void displayCourse(){
        cout << "========================================" << endl;
        
    }
};
