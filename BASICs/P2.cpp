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
    }
};

