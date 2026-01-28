/*
You need to make a program that works like a Matrix Wizard. First, it will ask the user for
the size of a 2D matrix and then create it using memory magic (dynamic allocation). Next,
the program will fill the matrix with numbers given by the user. After that, it will show off
by doing matrix addition, subtraction, and multiplication (only if the sizes match). Finally,
it will display the results and clean up the memory like a good, tidy wizard.
*/

#include"iostream"
using namespace std;

int main(){
    int c,r;
    cout<<"Enter Column size: ";
    cin>>c;
    cout<<"Enter row size: ";
    cin>>r;
    
    int** arr2D = new int*[r];
    for(int i=0; i<r;i++){
        arr2D[i] = new int[c];
    }

    int** arr22D = new int*[r];
    for( int i = 0; i<r;i++){
        arr22D[i] = new int[c];
    }

    for(int i= 0; i<r;i++){
        for(int j=0;j<c;j++){
            cout<<"Enter ("<<i<<","<<j<<") element"<<endl;
            cin>>arr2D[i][j];
        }
    }

    for(int i= 0; i<r;i++){
        for(int j=0;j<c;j++){
            arr22D[i][j] = arr2D[i][j];
        }
    }

    cout<<"Order of First matrix is ("<<r<<","<<c<<")"<<endl;
    cout<<"Order of Second matrix is ("<<r<<","<<c<<")"<<endl;

    cout<<"First Matrix: "<<endl;
    for(int i= 0; i<r;i++){
        for(int j=0;j<c;j++){
            cout<<""<<i<<","<<j<<"\t"<<endl;
        }
        cout<<"\n";
    }

    


}