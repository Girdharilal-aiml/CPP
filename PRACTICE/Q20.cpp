// 6. HR Performance Tracker
// Rule: Write a generic utility named getTopPerformer that takes two objects of the exact same type. 
// Inside the function, compare them using their .getKPI() method and return the object with the higher KPI.

#include "iostream"
using namespace std;

class Tracker{
private:
    double KPI;
public:
    Tracker(){}
    Tracker(double kp) : KPI(kp){}
    virtual double getkpi(){
        return KPI;
    }
};

template<typename K>
K getTopPerformer(K a, K b){
}
