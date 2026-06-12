// 21. The Login Firewall: Design a SecuritySystem entity with a method authenticate(string password).
// Rule: If the password length is less than 8 characters, the system must immediately halt its normal execution flow and signal an error by ejecting the exact text message: "Password too short".
// Rule: In your main() function, execute this method and safely capture this exact text message, printing it to the screen without crashing the program.

#include"iostream"
using namespace std;

class SecuritySystem{
public:
    void authenticate(string password){
        if(password.length() < 8){
            throw "password too short" ;
        }
        cout << "Authentication Successful..." << endl;
    }
};

int main(){
}