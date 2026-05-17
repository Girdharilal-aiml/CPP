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
*/




