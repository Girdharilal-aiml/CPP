#include "iostream"
#include "string"
using namespace std;

class Entity{
public:
    virtual void showRole()  = 0;  
    virtual void display()   = 0;   
    virtual double computePay() = 0;
    virtual ~Entity() {}            
};

class Grade{
private:
    float marks;

public:
    Grade(float m = 0.0) { marks = m; }

    float getMarks() const { return marks; }

    Grade operator+(const Grade& other) const {
        return Grade(marks + other.marks);
    }

    bool operator>(const Grade& other) const {
        return marks > other.marks;
    }

    bool operator==(const Grade& other) const {
        return marks == other.marks;
    }

    friend ostream& operator<<(ostream& out, const Grade& g) {
        out << g.marks << "/100";
        return out;
    }
};

class Address {
private:
    string city;
    string country;

public:
    Address(string c = "karachi", string co = "Pakistan"){
        city = c;
        country = co;
    }

    string getCity() const { return city; }
    string getCountry() const { return country; }

    void display() const {
        cout << city << ", " << country;
    }
};

class Person : public Entity {
};
