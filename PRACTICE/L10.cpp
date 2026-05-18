/*
Level 10 (Abstraction - Pure Virtual Function)

Q10:
Create an abstract class Shape:
- pure virtual function:
    virtual void area() = 0;

Create derived classes:
1. Rectangle
2. Circle

Implement area() in both

In main():
- Use Shape* pointer
- Call area()

⚠️ You cannot create object of abstract class
*/

#include"iostream"
using namespace std;

class Shape{
public:
    virtual void Area() = 0;
};

class Rectangle : public Shape{
private:
    int length;

public:
};
