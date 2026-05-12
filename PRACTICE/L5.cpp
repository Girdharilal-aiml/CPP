/*
Level 5 (Important – Copy Constructor)

Now things get serious.




// #include "iostream"
// using namespace std;

// class Car{
// private:
//     string brand;
//     double price;

// public:
//     Car(){
//         brand = "Unknown";
//         price = 0;
//     }

//     Car(string brand, double price){
//         this->brand = brand;
//         this->price = price;
//     }

//     Car(const Car &obj){
//         brand = obj.brand;
//         price = obj.price;
//     }
    
//     void display(){
//         cout << "Brand : " << brand << endl;
//         cout << "Price : " << price << endl;
//         cout << "========================" << endl;
//     }
// };

// int main(){
//     Car c1("Suzuki", 3231);
//     Car c2 = c1;

//     c1.display();
//     c2.display();
// }