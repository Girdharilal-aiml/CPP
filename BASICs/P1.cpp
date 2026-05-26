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
        cout << "COURSE            : " << courseName << endl;
        cout << "TEACHER           : " << teacher->getName() << endl;
        cout << "STUDENTS ENROLLED : " << studentCount << endl;
        
        for(int i = 0; i < studentCount; i++){
            cout << "  -> " << students[i]->getName() << " (CGPA: " << students[i]->getCGPA() << ")" << endl;
        }
    }
};

class University{
private:
    string uniName;
    Student* students[100];
    Teacher* teachers[50];
    Course* courses[20];
    int sCount, tCount, cCount;

public:
    University(string name){
        uniName = name;
        sCount = tCount = cCount = 0;
    }

    void addStudent(Student* s){ students[sCount++] = s; }
    void addTeachers(Teacher* t){ teachers[tCount++] = t; }
    void addCourses(Course* c){ courses[cCount++] = c; }

    void generateReport() {
        cout << "\n=========================================" << endl;
        cout << "   UNIVERSITY REPORT: " << uniName << endl;
        cout << "=========================================" << endl;

        cout << "\n--- TEACHERS ---" << endl;
        for (int i = 0; i < tCount; i++){
            teachers[i]->display();
            teachers[i]->showRole();
        }

        cout << "\n--- STUDENTS ---" << endl;
        for (int i = 0; i < sCount; i++){
            students[i]->display();
            students[i]->showRole();
        }

        cout << "\n--- COURSES ---" << endl;
        for (int i = 0; i < cCount; i++){
            courses[i]->displayCourse();
        }
    }
};

int main(){
    Teacher t1("Dr smith", 45 , "T001", "Computer Science", 75000);
    Teacher t2("Dr Johnson", 50 , "T002", "Mathematics", 80000);

    Student s1("Alice", 20, "S001", 3.8, "Computer Science");
    Student s2("Bob", 22, "S002", 3.5, "Mathematics");
    Student s3("Charlie", 21, "S003", 3.9, "Computer Science");

    Course c1("Data Structures", &t1);
    Course c2("Calculus", &t2);

    c1.enrollStudent(&s1);
    c2.enrollStudent(&s2);
    c1.enrollStudent(&s3);

    University uni("Tech University");

    uni.addTeachers(&t1);






}   