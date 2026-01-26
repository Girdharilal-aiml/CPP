/*
Write a C++ program to check whether a given number is prime or not. Allow the user to input a
number and display whether it's prime or not?
*/

#include"iostream"
using namespace std;

int main(){
    int a,b;
    cout<<"enter 2 numbers:"<<endl;
    cin>>a;
    cin>>b;
    cout<<a<<" "<<b<<endl;
    if(a%2==0){
        cout<<"Even"<<" "<<a<<endl;
    }else{
        cout<<"Odd"<<" "<<a<<endl;
    }
    if(b%2==0){
        cout<<"Even"<<" "<<b<<endl;
    }else{
        cout<<"Odd"<<" "<<b<<endl;
    }
}