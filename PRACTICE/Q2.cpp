// WAP to take username and password, identify the login and confirm which is wrong

#include<iostream>
using namespace std;

int main(){
    int pass;
    string user;

    cout<<"Enter Username: ";
    cin>>user;
    cout<<"Enter Password: ";
    cin>>pass;

    if(user== "USER" && pass== 0000){
        cout<<"Access Granted"<<endl;
    }else{
        cout<<"Access Denied"<<endl;
        
    }
}