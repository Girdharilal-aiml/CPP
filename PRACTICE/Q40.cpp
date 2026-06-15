// 26. The Persistent Logger:
// Rule: Open a text file called server_logs.txt in a way that allows you to add new log messages to the very end of the file without erasing the old ones.
// Rule: After adding a new log, move the internal file reading cursor back to the absolute beginning of the file, read all the contents, and print them to the console.

#include "iostream"
