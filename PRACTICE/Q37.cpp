// 23. The ATM Withdrawal (Custom Error Entity):
// Rule: Create a highly specialized error entity named InsufficientFundsError that integrates into the standard C++ error hierarchy. It must override the built-in explanation method to provide a custom warning message when called.
// Rule: In an Account class, write a withdraw(double amount) function. If the amount exceeds the balance, halt execution and signal this specific InsufficientFundsError object.

#include"iostream"
#include"stdexcept"
using namespace std;

class InsufficientFundsError : public runtime_error {
public:
    InsufficientFundsError() : runtime_error("Insufficient funds for withdrawal") {}
};

class Account {
private:
public: 
    
};
