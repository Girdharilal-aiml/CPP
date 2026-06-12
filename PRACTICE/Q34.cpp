// 20. The Secure Cloud Balancer:
// Rule: Create a general concept Node. Create a DatabaseNode entity that implements it.
// Rule: Create a generic storage utility (like in Question 11) capable of holding polymorphic pointers to the general Node concept.
// Rule: In main(), instantiate this storage, create two dynamic DatabaseNode entities, and add them to the storage.

#include "iostream"
using namespace std;

class Node{
public:
    virtual double getGPU() = 0;
};

class DataBaseNode : public Node{
public:
    double getGPU() override{
        return 85.5;
    }
};

template<typename T>
class Storage{

};
