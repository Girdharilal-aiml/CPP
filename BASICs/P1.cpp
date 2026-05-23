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
    }
};
