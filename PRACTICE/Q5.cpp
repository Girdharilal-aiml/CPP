/*
4. Write a program to take an integer array as an input from user and count all the even and odd
numbers in that list and print the counts.
*/

#include"iostream"
using namespace std;

int main(){
    int n, even=0, odd=0;
    cout<<"Enter size of array: "<<endl;
    cin>>n;
    int* arr = new int[n];
    for(int i = 0; i<n ;i++){
        cout<<"Enter Number arr["<<i<<"]: ";
        cin>>arr[i];
    }
    for(int i = 0; i<n ;i++){
        if(arr[i]%2 == 0){
            even++;
        }else{
            odd++;
        }
    }

    cout<<"TOTAL EVEN COUNT: "<<even<<""<<endl;
    cout<<"TOTAL ODD COUNT: "<<odd<<""<<endl;

}