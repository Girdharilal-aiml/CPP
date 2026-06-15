// 24. The Overheating Engine:
// Rule: Create a custom OverheatError entity containing a currentTemp integer (it does not need to inherit from system errors).
// Rule: If an Engine entity hits 120 degrees, signal this custom object. Capture the object in main() and extract the currentTemp integer to display it.

#include"iostream"
using namespace std;

class OverheatError {
public:
    int currentTemp;
};

class Engine {
public:
    void Run(int temp){
        if (temp >= 120) {
            throw OverheatError{temp};
        }
        cout << "Engine running at " << temp << " degrees." << endl;
    }
};

int main() {
    Engine myEngine;
    try {
        myEngine.Run(130);
    }
    catch (const OverheatError& e) {
        cout << "Overheat error! Current temperature: " << e.currentTemp << " degrees." << endl;
    }
}