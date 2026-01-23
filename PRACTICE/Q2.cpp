// WAP to take username and password, identify the login and confirm which is wrong

#include<iostream>
using namespace std;

int main(){
    int password;
    string username;

    cout<<"Enter Username: ";
    cin>>username;
    cout<<"Enter Password: ";
    cin>>pass;

    if(username== "USER" && pass== 0000){
        cout<<"Access Granted"<<endl;
    }else{
        cout<<"Access Denied"<<endl;
        if(username !="USER" && pass != 0000){
            cout<<"Wrong user and pass"<<endl;
        }
        else if(username!="USER"){
            cout<<"Wrong user"<<endl;
        }else if(pass != 0000){
            cout<<"Wrong pass"<<endl;
        }
    }
}