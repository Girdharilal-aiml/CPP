/*
Create a program that moonlights as a basic calculator, wielding the power of pointer
arithmetic to crunch numbers like a pro. It should charm the user into entering two integers,
perform addition, subtraction, multiplication, or division (depending on the user's mood),
and then proudly display the result. Use pointers to juggle values between functions and
make the magic happen.
*/

#include"iostream";
using namespace std;

int calculate(int* n1, int* n2);

int main(){
    int num1,num2;
    char op;

    cout<<"Enter first number: ";
    cin>>num1;
    cout<<"Enter second number: ";
    cin>>num2;
    cout<<"Enter operation(+,-,*,/): ";
    cin>>num1;

    int result = calculate(&num1,&num2);

    cout<<"Result is : "<<result<<"";
}
