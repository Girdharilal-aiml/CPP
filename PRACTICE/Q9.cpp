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
    book lib[50];
    int n = 3;

    lib[0].t = "Harry Potter";
    lib[0].a = "JK Rowling";
    lib[0].y = 1997;
    lib[0].g = "Fantasy";
    
    lib[1].t = "Sherlock Holmes";
    lib[1].a = "Arthur Conan Doyle";
    lib[1].y = 1887;
    lib[1].g = "Mystery";
    
    lib[2].t = "The Hobbit";
    lib[2].a = "JRR Tolkien";
    lib[2].y = 1937;
    lib[2].g = "Fantasy";
    
    int choice;
    
    do {
        cout << "\n1. See all books\n";
        cout << "2. Add book\n";
        cout << "3. Change book\n";
        cout << "4. Find book\n";
        cout << "5. Exit\n";
        cout << "What to do? ";
        cin >> choice;
        
        if(choice == 1) {
            for(int i=0; i<n; i++) {
                cout << "Book " << i+1 << ":\n";
                show(lib[i]);
            }
        }
        
        else if(choice == 2) {
            if(n < 50) {
                cin.ignore();
                cout << "Book name: ";
                getline(cin, lib[n].t);
                cout << "Writer name: ";
                getline(cin, lib[n].a);
                cout << "Year: ";
                cin >> lib[n].y;
                cin.ignore();
                cout << "Type: ";
                getline(cin, lib[n].g);
                n++;
                cout << "Book added!\n";
            } else {
                cout << "No space!\n";
            }
        }
        
        else if(choice == 3) {
            int num;
            cout << "Book number to change: ";
            cin >> num;
            
            if(num>=1 && num<=n) {
                num--;
                cin.ignore();
                cout << "New name (" << lib[num].t << "): ";
                getline(cin, lib[num].t);
                cout << "New writer (" << lib[num].a << "): ";
                getline(cin, lib[num].a);
                cout << "New year (" << lib[num].y << "): ";
                cin >> lib[num].y;
                cin.ignore();
                cout << "New type (" << lib[num].g << "): ";
                getline(cin, lib[num].g);
                cout << "Changed!\n";
            } else {
                cout << "Wrong number!\n";
            }
        }
        
       
        
    } while(choice != 5);
    
    return 0;
}