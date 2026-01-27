/*
You are tasked with building a simple product management system for an online store that
does the following stuff:
a) Create a function that allows the addition of a new product to the system. The function
should take parameters such as product name, price, quantity, and any other relevant
details.
b) Implement a function that takes a product ID as input and displays detailed information
about the product, including its name, price, quantity in stock, and any other relevant
details.
c) Design a function that enables the update of product information. It should take a
product ID as well as the new details (e.g., updated price, quantity, etc.) and modify the
existing product's information accordingly.
d) Create a function that removes a product from the system based on its product ID.
Ensure that the inventory is updated after the removal.
*/

#include <iostream>
#include <string>
using namespace std;

struct Item {
    int id;
    string name;
    float price;
    int qty;
};

Item shop[100];
int cnt = 3;

void addItem() {
    shop[cnt].id = cnt + 100;
    cout << "Name: "; cin >> shop[cnt].name;
    cout << "Price: "; cin >> shop[cnt].price;
    cout << "Qty: "; cin >> shop[cnt].qty;
    cnt++;
}

void showItem(int pid) {
    for(int i=0; i<cnt; i++) {
        if(shop[i].id == pid) {
            cout << "ID: " << shop[i].id << endl;
            cout << "Name: " << shop[i].name << endl;
            cout << "Price: " << shop[i].price << endl;
            cout << "Qty: " << shop[i].qty << endl;
            return;
        }
    }
    cout << "Not found\n";
}

void updateItem(int pid) {
    for(int i=0; i<cnt; i++) {
        if(shop[i].id == pid) {
            cout << "New name: "; cin >> shop[i].name;
            cout << "New price: "; cin >> shop[i].price;
            cout << "New qty: "; cin >> shop[i].qty;
            return;
        }
    }
    cout << "Not found\n";
}

void deleteItem(int pid) {
    for(int i=0; i<cnt; i++) {
        if(shop[i].id == pid) {
            for(int j=i; j<cnt-1; j++) {
                shop[j] = shop[j+1];
            }
            cnt--;
            return;
        }
    }
    cout << "Not found\n";
}

int main() {
    shop[0] = {100, "Phone", 500, 10};
    shop[1] = {101, "Book", 15, 30};
    shop[2] = {102, "Pen", 2, 100};
    
    int ch, pid;
    
    
    
    return 0;
}