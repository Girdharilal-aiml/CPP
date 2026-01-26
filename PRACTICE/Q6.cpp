// Write a function that will take a number "n" input by user and will return its factorial.

#include"iostream"
using namespace std;

int fact(int n){
    
}

int main(){
    int n;
    cout<<"Enter n: ";
    cin>>n;
    int factorial = fact(n);
    if(n<0){
        cout<<"Invalid!"<<endl;
    }else{
        cout<<"Factorial is: "<<factorial<<""<< endl;
    }

}