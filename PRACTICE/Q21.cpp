// 7. E-commerce Discount Engine
// Rule: Write a generic utility named cheaperItem that takes two objects of the exact same type. 
// It should use the .getFinalPrice() method of both objects and return the object that is numerically cheaper.

#include "iostream"
using namespace std;

class CheaperItems{
private:
    double itemprice;
public:
    CheaperItems(){}
    CheaperItems(double IP) : itemprice(IP){}
    double getprice(){
        return itemprice;
    }
};

template<typename CP>
CP getFinalPrice(CP A, CP B){
    if(A.getprice() < B.getprice()){
        return A.getprice();
    }else{
        return B.getprice();
    }
}
