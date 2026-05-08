/*
Q2:
Create a class Rectangle with:

data members: length, width
functions:
setValues(l, w)
area() → returns area
perimeter() → returns perimeter

In main():

create object
set values
print area and perimeter
*/

#include "iostream"
using namespace std;

class Rectangle{
private:
    double length;
    double width;

public:
    void setvalues(double l, double w){
        length = l;
        width = w;
    }

    double area(){
        return width * length;
    }

    double perimeter(){
        return 2 * (length + width);
    }
};

int main(){
    Rectangle R1;
    R1.setvalues(12, 12);

}