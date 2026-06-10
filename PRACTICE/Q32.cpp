// 18. The Zoo Enclosure: You have a base concept Animal that must be able to makeSound(). Lion and Monkey are specific animals.
// Rule: Write a main() function that creates an array capable of holding 3 pointers to the general Animal concept. Assign a Lion and a Monkey dynamically (using new) to this array, and trigger their sounds via a loop.

#include "iostream"
using namespace std;

class Animal{
};

class Lion : public Animal{
};

