/*
You are hired as a billing manager at K-Electric. Your task is to calculate the monthly bill
according to the units consumed. Write a program to input electricity unit charge and calculate the
total electricity bill according to the given condition:
For first 50 units Rs. 0.50/unit
For next 100 units Rs. 0.75/unit
For next 100 units Rs. 1.20/unit
For unit above 250 Rs. 1.50/unit
An additional surcharge of 20% is added to the bill.
*/

#include"iostream"
using namespace std;

int main(){
    float bill=0;
    int unit_consumed;

    cout<<"Enter the number of units consumed: ";
    cin>>unit_consumed;

    if(unit_consumed>0 && unit_consumed<=50){
        bill = 0.50*unit_consumed;
    }else if(unit_consumed>50 && unit_consumed<=150){
        bill = ((unit_consumed-50)*0.75) + (50*0.50);
    }else if(unit_consumed>150 && unit_consumed<=250){
        bill = ((unit_consumed-150)*1.20) + (50*0.50) + (100*0.75);
    }else if(unit_consumed>250){
        bill = ((unit_consumed-250)*1.50) + (50*0.50) + (100*0.75) + (100*1.20);

    }else{
        cout<<"Invalid Consumption!"<<endl;
    }

    bill = bill + bill*0.20;

    cout<<"Total Electricity Bill (Including Surcharge): Rs"<<bill<<" "<<endl;

}
