// 25. Network Timeout Fallbacks: A connectServer() function might halt and signal an integer (like error code 404) OR it might signal a text string (like "Timeout").
// Rule: Write the execution logic in main() to safely attempt the connection, providing one safety net for the integer, a separate safety net for the string, and a final universal safety net to catch literally anything else that might halt the flow.

#include "iostream"
using namespace std;
