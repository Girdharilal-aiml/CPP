/*
Imagine you are working on a project where the efficient generation of odd numbers is crucial.
Your task is to write a C++ function that prints an odd number after every sequence of 5 even
numbers in the range provided by the user. The catch is that you need to optimize the program for
both correctness and efficiency.

for example :
Start range: 0
ending range: 20
ouput:
0
2
4
6
8
9
10
12
14
16
18
19
20
*/

#include<iostream>
using namespace std;

int main(){
    int SR,ER, count=0, odd=0;          // SR == Starting range    && ER == Ending range

    cout<<"Enter Starting Range: ";
    cin>>SR;
    cout<<"Enter Ending Range: ";
    cin>>ER;
    
    odd+=SR;

    for(int i = SR ; i<ER ; i++){
        if(i%2==0){
            cout<<i<<endl;
            count++;
        }
        odd++;
        if(count%5==0){
            cout<<odd<<endl;
        }
    }
    

}

