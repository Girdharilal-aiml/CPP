/*
Imagine you are tasked with creating a program to manage a library's book inventory. Each
book has attributes such as title, author, publication year, and genre. Design a struct that
effectively represents a book as a real-world entity. Then, write a C++ program that utilizes
this struct to demonstrate the creation, modification, and display of book information.
a) Extend the program to manage multiple books in an array.
b) Implement a function to search for a book by title or author.
c) Allow the user to input new books and update existing book information
interactively.
*/

#include <iostream>
#include <string>
using namespace std;

struct book {
    string t;
    string a;
    int y;
    string g;
};

void show(book x) {
    cout << "Name: " << x.t << endl;
    cout << "Writer: " << x.a << endl;
    cout << "Year: " << x.y << endl;
    cout << "Type: " << x.g << endl;
    cout << "------------" << endl;
}

int main() {
    
    return 0;
}