/*
Level 9 (Inheritance + Polymorphism)

Q9:
Create a base class Shape:
- virtual function: area()
  → print "Calculating area"

Create two derived classes:

1. Rectangle
   - data: length, width
   - override area() → print rectangle area

2. Circle
   - data: radius
   - override area() → print circle area

In main():
- Create:
    Rectangle r(10,5);
    Circle c(7);

- Use base class pointer:
    Shape* ptr;

- Assign and call:
    ptr = &r;
    ptr->area();

    ptr = &c;
    ptr->area();

⚠️ Must use:
- inheritance
- virtual function
- runtime polymorphism
*/

#include"iostream"
using namespace std;

class Shape{
public:
    virtual void AREA() = 0;
};

class Rectangle : public Shape{
private:
    float lenght;
    float width;

public:
    Rectangle(float l, float w) : lenght(l), width(w){}

    void AREA() override{
        cout << "Area of Rectangle : " << lenght * width << endl;
    }
};

class Circle : public Shape{
private:
    float radius;

public:
    Circle(float r) : radius(r){}

    void AREA() override{
        cout << "Area of Circle : " << 3.14 * radius * radius << endl;
    }
};

int main(){
    Circle c1(3);
    Rectangle r1(3,3);


}
