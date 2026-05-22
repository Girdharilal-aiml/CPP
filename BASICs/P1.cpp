#include"iostream"
#include"string"
using namespace std;

class Role{
public:
    virtual void showRole()=0;
    virtual void display()=0;
    virtual ~Role() {}
};

class Person : public Role{
private:
    string name;

public:
   

};
