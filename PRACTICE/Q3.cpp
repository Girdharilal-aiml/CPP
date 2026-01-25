/*
2. Create a C++ program to handle student marks management. The program should allow users to
input marks for students in four courses: PF, OOP, DLD & ICT. It should then calculate the total
marks, average marks, and determine the grade for each student based on their average.
Use the following grading metrics:
90 or above: Grade A
80-89: Grade B
70-79: Grade C
60-69: Grade D
Below 60: Grade F
*/

#include<iostream>
using namespace std;

int main(){
    float PF,OOP,DLD,ICT,Average,Total;
    char Grade;

    cout<<"Enter PF marks: "<<endl;
    cin>>PF;
    cout<<"Enter OOP marks: "<<endl;
    cin>>OOP;
    cout<<"Enter DLD marks: "<<endl;
    cin>>DLD;
    cout<<"Enter ICT marks: "<<endl;
    cin>>ICT;

    Total = PF+OOP+DLD+ICT;
    Average = Total/4;
    cout<<"Total marks: "<<Total<<endl;
    cout<<"Average marks: "<<Average<<endl;
    if(Average>=90)
        Grade = 'A';
    else if(Average>=80 && Average<=89)
        Grade = 'B';
    else if(Average>=70 && Average<=79)
        Grade = 'C';
    else if(Average>=60 && Average<=69)
        Grade = 'D';
    else if(Average<=60)
        Grade = 'F';

    cout<<Grade<<endl;

    
}
