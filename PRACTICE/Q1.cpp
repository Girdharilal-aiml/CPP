// WAP to take 2 numbers and see which is Even and Odd

#include"iostream"
using namespace std;

int main(){
    int a,b;
    cout<<"enter 2 numbers:"<<endl;
    cin>>a;
    cin>>b;
    cout<<a<<" "<<b<<endl;
    if(a%2==0){
        cout<<"Even"<<a<<endl;
    }else{
        cout<<"Odd"<<endl;
    }
    if(b%2==0){
        cout<<"Even"<<b<<endl;
    }else{
        cout<<"Odd"<<endl;
    }
}