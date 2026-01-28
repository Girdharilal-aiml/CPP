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
    
    int** arr12D = new int*[r];
    for(int i=0; i<r;i++){
        arr12D[i] = new int[c];
    }

    int** arr22D = new int*[r];
    for( int i = 0; i<r;i++){
        arr22D[i] = new int[c];
    }

    for(int i= 0; i<r;i++){
        for(int j=0;j<c;j++){
            cout<<"Enter ("<<i<<","<<j<<") element"<<endl;
            cin>>arr12D[i][j];
        }
    }

    for(int i= 0; i<r;i++){
        for(int j=0;j<c;j++){
            arr22D[i][j] = arr12D[i][j];
        }
    }

    cout<<"Order of First matrix is ("<<r<<","<<c<<")"<<endl;
    cout<<"Order of Second matrix is ("<<r<<","<<c<<")"<<endl;

    int** arr32D = new int*[r];
    for(int i=0; i<r;i++){
        arr32D[i] = new int[c];
    }

    int** arr42D = new int*[r];
    for(int i=0; i<r;i++){
        arr42D[i] = new int[c];
    }
    int** arr52D = new int*[r];
    for(int i=0; i<r;i++){
        arr52D[i] = new int[c];
    }

    for(int i=0; i<r ; i++){
        for(int j=0; j<c ; j++){
            arr32D[i][j] = arr12D[i][j] + arr22D[i][j];
        }
    }
    for(int i=0; i<r ; i++){
        for(int j=0; j<c ; j++){
            arr42D[i][j] = arr12D[i][j] - arr22D[i][j];
        }
    }
    if(r=c){
       for(int i=0; i<r ; i++){
        for(int j=0; j<c ; j++){
            arr52D[i][j] = arr12D[i][j] * arr22D[i][j];
            }
        } 
    }

    








    cout<<"First Matrix: "<<endl;
    for(int i= 0; i<r;i++){
        for(int j=0;j<c;j++){
            cout<<""<<arr12D[i][j]<<"\t";
        }
        cout<<"\n";
    }
    cout<<"Second Matrix: "<<endl;
    for(int i= 0; i<r;i++){
        for(int j=0;j<c;j++){
            cout<<""<<arr22D[i][j]<<"\t";
        }
        cout<<"\n";
    }
    cout<<"Addition Matrix: "<<endl;
    for(int i= 0; i<r;i++){
        for(int j=0;j<c;j++){
            cout<<""<<arr32D[i][j]<<"\t";
        }
        cout<<"\n";
    }
    cout<<"Subtraction Matrix: "<<endl;
    for(int i= 0; i<r;i++){
        for(int j=0;j<c;j++){
            cout<<""<<arr42D[i][j]<<"\t";
        }
        cout<<"\n";
    }
    cout<<"Multiplication Matrix: "<<endl;
    for(int i= 0; i<r;i++){
        for(int j=0;j<c;j++){
            cout<<""<<arr52D[i][j]<<"\t";
        }
        cout<<"\n";
    }



    for(int i=0;i<r;i++){
            free(arr12D[i]);
    }
    free(arr12D);

    for(int i=0;i<r;i++){
            free(arr22D[i]);
    }
    free(arr22D);

    for(int i=0;i<r;i++){
            free(arr32D[i]);
    }
    free(arr32D);

    for(int i=0;i<r;i++){
            free(arr42D[i]);
    }
    free(arr42D);

    for(int i=0;i<r;i++){
            free(arr52D[i]);
    }
    free(arr52D);
    
}