// 2. The Banking Gateway
// Design a system for a bank. You have a general concept called Transaction, which contains a transactionID.
// Rule: A "Transaction" is just a conceptual idea; the system must strictly prevent another programmer from creating a direct object of a generic transaction. It can only be a Deposit or a Withdrawal.
// Rule: Every transaction must be able to calculateFee(). However, the mathematical formula for this fee depends entirely on whether it is a deposit or a withdrawal. Force this rule in your architecture.

#include"iostream"
using namespace std;

class Transaction{
private:
    int transactionID;

public:
    Transaction(int id): transactionID(id){}
    virtual double CalculateFee() = 0;
};

class Deposit : public Transaction{
public:
    Deposit(int id) : Transaction(id){}
    double CalculateFee(){
        return 1.5;
    }
};

class Withdraw : public Transaction{
public:
    Withdraw(int id) : Transaction(id){}
    double CalculateFee(){
        return 2.5;
    }
};

int main(){
    Deposit dep(1001);
    Withdraw with(1002);

    cout << "Deposit Fee: " <<  dep.CalculateFee() << endl;
    cout << "Withdrawal Fee: " << with.CalculateFee() << endl;
    return 0;
}