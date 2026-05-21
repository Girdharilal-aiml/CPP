/*
Level 12 (Templates)

Q12:
Create a template class Calculator:

1. Functions:
   - add(a, b)
   - subtract(a, b)
   - multiply(a, b)

2. Should work for:
   - int
   - float
   - double

In main():
- Create Calculator objects for different types
- Test all functions
*/

#include "iostream"
using namespace std;

template <class T>
class Calculator{
public:
    T add(T a, T b){
        return a + b;
    }

    T subtract(T a, T b){
        return a - b;
    }

    T multiply(T a, T b){
        return a * b;
    }
};

int main(){
    Calculator<int> c1;
    Calculator<float> c2;
    Calculator<double> c3;

    cout << "INT:\n";
    cout << c1.add(2, 3) << endl;
    cout << c1.subtract(5, 2) << endl;
    cout << c1.multiply(3, 4) << endl;

    cout << "\nFLOAT:\n";

}