/*
3. Write a program to make a simple calculator performing the four basic operations (+, -, *, /) on
two numbers input by user. The following conditions must be satisfied:
a) A ‘+’ sign must not be used for addition.
b) You can only use a maximum of 3 variables. No more variables are allowed.
c) Your program should ask the user which operation he/she wants to perform and gives the
output accordingly.
*/

#include"iostream"
using namespace std;

int main(){
    float input[2],output;
    char op;

    cout<<"Enter First Number: "<<endl;
    cin>>input[0];

    cout<<"Enter Second Number: "<<endl;
    cin>>input[1];

    cout<<"Enter Operator(-, *, / ,or add(a)): "<<endl;
    cin>>op;

    if(op == 'a')
        output = input[1] - (-input[0]);
    else if(op == '-')
        output = input[1] - input[0];
    else if(op == '*')
        output = input[1] * input[0];
    else if(op == '/')
        output = input[1] / input[0];
    else
        cout<<"Invalid Operation"<<endl;

    
}