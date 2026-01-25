// 5. Write a function that will take a number "n" input by user and will return its factorial.

#include"iostream"
using namespace std;

int main(){
    int n, fact=1;
    cout<<"Enter n: ";
    cin>>n;

    if(n>1){
        for(int i=n;i>=1; i--){
            fact = fact * i;
        }
    }else if( n == 1 || n==0){
        fact = 1;
    }else{
        cout<<"Invalid number:"<<endl;
    }

    cout<<"Factorial is: "<<fact<<""<< endl;

}