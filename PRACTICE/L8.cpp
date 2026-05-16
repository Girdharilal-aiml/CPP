/*
Level 8 (Operator Overloading)

Q8:
Create a class Complex with:
- data members: real, imag

1. Implement:
   - Constructor
   - display()

2. Overload + operator to add two complex numbers

3. In main():
   - Create two objects
   - Add them using + operator
   - Display result

Example:
(2 + 3i) + (1 + 4i) = (3 + 7i)
*/

#include"iostream"
using namespace std;

class Complex{
private:
   int real;
   int imag;

public:
   Complex(){}
   Complex(int r, int i) : real(r), imag(i){}

   Complex operator+(const Complex &obj){
      Complex temp;
   }

};


