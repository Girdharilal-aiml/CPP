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
    int age;
    string id;

public:
    Person(string n, int a, string i){
        name = n;
        age = a;
        id = i;
    }

    string getName() { return name; }
    int getAge() { return age; } 
    string getID() { return id; }

    void setName(string n) { name = n;}
    void setAge(int a){
        if (a > 0) age = a;
        else cout << "Invalid age!" << endl;
    }

};

