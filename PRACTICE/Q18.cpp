// 4. The Freelance Platform
// Create a general User entity containing an email.
// Rule: The system must strictly prevent creating a plain User.
// Rule: Create two specific entities: Client and Freelancer. Both must implement a getPlatformRating() method, but the logic for calculating the rating is unique to each entity.

#include "iostream"
using namespace std;

class User{
private:
    string email;
public:
    User(string email) : email(email) {}
    virtual double getPlatformRating() = 0; 
};

class Client : public User{
public:
    Client(string email) : User(email){}
    double getPlatformRating() override {
        return 4.5;
    }
};

class Freelancer : public User{
public:
    Freelancer(string email) : User(email){}
    double getPlatformRating() override{
        return 5.0;
    }
};

int main(){
    Client client("client@example.com");


}
