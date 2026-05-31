
// 5. The Real Estate App
// Rule: Write a generic utility tool named findBetterProperty. It must accept any two objects, provided they are of the exact same data type.
// Rule: Inside this utility, call a method .getSquareFootage() on both objects and return the object that has the larger value.

#include "iostream"
using namespace std;

class Property{
    double squareFootage;
public:
    Property(double sqft) : squareFootage(sqft) {}
    virtual double getSquareFootage() {
        return squareFootage;
    }
};

template<typename T>
T findBetterProperty(T a, T b){
    if(a.getSquareFootage() > b.getSquareFootage()){
        return a;
    }else{
        return b;
    }
}

int main(){
    Property p1(15000.00);
    Property p2(20000.00);

    Property better = findBetterProperty(p1, p2);
    cout << "Better Property Square Footage: " << better.getSquareFootage() << " sqft" << endl;

}