// 9. Cyber Security Network:
// Rule: Design a method isNetworkStable(nodes, count) that accepts an array of Server objects.
// Rule: Traverse the array. If any server returns a value greater than 500 from .getPing(), the network is unstable (return false). If all are fine, return true.

#include "iostream"
using namespace std;

class Server{
private:
    int ping;
public:
    Server(int p) : ping(p){}
};

