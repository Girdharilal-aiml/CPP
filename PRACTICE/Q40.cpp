// 26. The Persistent Logger:
// Rule: Open a text file called server_logs.txt in a way that allows you to add new log messages to the very end of the file without erasing the old ones.
// Rule: After adding a new log, move the internal file reading cursor back to the absolute beginning of the file, read all the contents, and print them to the console.

#include "iostream"
#include "fstream"
#include "string"
using namespace std;

int main() {
    
    ofstream logOut("server_logs.txt", ios::app);
    if (logOut.is_open()) {
        logOut << "System started. New Event Occurred.\n";
        logOut.close();
    }
    
    ifstream logIn("server_logs.txt");
    string line;
    
    cout << "--- Current Server Logs ---" << endl;
}