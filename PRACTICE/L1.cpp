/*
Level 1 (Very Basic – Class & Object)

Q1:
Create a class Student with:

data members: name, age
a function display() to print details

In main():

create one object
assign values
call display()
*/

#include "iostream"
using namespace std;

class Student{
private:
    string name;
    int age;

public:
    Student(string n, int a) : name(n), age(a) {}

    void display(){
        cout << "Name: " << name << endl;
        cout << "Age : " << age << endl;
    }
};

int main(){
}