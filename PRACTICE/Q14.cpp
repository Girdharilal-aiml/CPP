/*
Time to code a program that manages an ever-growing hungry integer array! The array
starts small with a size of 5, but every time you keep stuffing it with numbers and it gets
full, it will double in size to satisfy its appetite. Once you're done feeding it all the elements,
the array will go on a diet and shrink down to perfectly fit the number of elements it holds.
No wasted space, no extra fluff—just a happy, well-fed array.
*/

#include <iostream>
using namespace std;

int main() {
    int capacity = 5;
    int count = 0;

    int* arr = new int[capacity];

    int value;
    char choice;

    do {
        cout << "Enter number: ";
        cin >> value;

        if (count == capacity) {
            capacity *= 2;

            int* newArr = new int[capacity];

            for (int i = 0; i < count; i++) {
                newArr[i] = arr[i];
            }

            delete[] arr;
            arr = newArr;
        }

        arr[count] = value;
        count++;

        cout << "Add more? (y/n): ";
        cin >> choice;

    } while (choice == 'y');

    int* finalArr = new int[count];
    for (int i = 0; i < count; i++) {
        finalArr[i] = arr[i];
    }

     delete[] arr;
    arr = finalArr;

    cout << "\nFinal Array:\n";
    for (int i = 0; i < count; i++) {
        cout << arr[i] << " ";
    }

    delete[] arr;
    return 0;

}
