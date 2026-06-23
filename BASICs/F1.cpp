#include "iostream"
#include <string>
using namespace std;

// ============================================
// ABSTRACTION — Abstract Base Class
// Cannot be instantiated, forces child classes
// to define their own version of showRole()
// ============================================
class Role {
public:
    virtual void showRole() = 0; // Pure virtual function
};



