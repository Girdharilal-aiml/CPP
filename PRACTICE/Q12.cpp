/*
Create a program that moonlights as a basic calculator, wielding the power of pointer
arithmetic to crunch numbers like a pro. It should charm the user into entering two integers,
perform addition, subtraction, multiplication, or division (depending on the user's mood),
and then proudly display the result. Use pointers to juggle values between functions and
make the magic happen.
*/

#include"iostream";
using namespace std;

int calculate(int* n1, int* n2){
    char op;
    float result;
    cout<<"Enter operation(+,-,*,/): ";
    cin>>op;
    if(n2 == 0 && op == '/' ){
        return -1;
    }
    if(op=='+'){
        result = n1+n2;
    }else if(op == '-'){
        result = n1-n2;
    }else if(op == '*'){
        result = n1*n2;
    }else if(op == '/'){
        result = n1/n2;
    }else{
        return -2;
    }
    return result;
}

int main(){
    int num1,num2;

    cout<<"Enter first number: ";
    cin>>num1;
    cout<<"Enter second number: ";
    cin>>num2;

    int result = calculate(&num1,&num2);
    if(result==-1){
        cout<<"Infinity";
    }else if(result==-2){
        cout<<"Invalid operation";
    }else{
        cout<<"Result is : "<<result<<"";
    }

}
