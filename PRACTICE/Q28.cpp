// 14. The University Persona: At a university, you have a Person entity with an idNumber. A Student is a Person. An Employee is a Person.
// Rule: A TeachingAssistant acts as both a Student and an Employee simultaneously, combining the traits of both.
// Crucial Rule: Even though a TA combines two roles, they are still a single physical human being. Your architecture must ensure that a TeachingAssistant only has one idNumber in memory to prevent ambiguous data.
// Rule: Ensure the TA's constructor bypasses the intermediate roles to directly initialize the idNumber of the core Person.

#include "iostream"
using namespace std;

class Person{
protected:
public:
};



