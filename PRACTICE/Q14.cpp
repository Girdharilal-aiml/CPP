/*
Time to code a program that manages an ever-growing hungry integer array! The array
starts small with a size of 5, but every time you keep stuffing it with numbers and it gets
full, it will double in size to satisfy its appetite. Once you're done feeding it all the elements,
the array will go on a diet and shrink down to perfectly fit the number of elements it holds.
No wasted space, no extra fluff—just a happy, well-fed array.
*/

#include"iostream"
using namespace std;

int main(){
    int n=5, i=0, count=0;
    int* arr = new int[n];

    do{
    
        cout<<"Enter '0' to exit!"<<endl;
        cout<<"Enter numbers at "<<i<<":";
        cin>>arr[i];
        i++;
        count++;
        if(count%5==0){
            n=n*2;
        }


    }while(arr[i] = 0 );

    


    delete[] arr;
}