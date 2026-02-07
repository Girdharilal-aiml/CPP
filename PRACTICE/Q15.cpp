/*
1. Design a Book class for a library system with attributes:
   - title
   - author
   - price

   Requirements:
   - Default constructor → "Untitled", "Anonymous", price = 0.0
   - Parameterized constructor → set all values
   - Copy constructor → duplicate a book
   - Constructor with default arguments → only title required,
     author = "Unknown", price = 0.0
   - Create objects using all constructors and display details
*/

#include"iostream"
using namespace std;

class Book{
private:
    string Title;
    string Author;
    double Price;

public:
    Book(){

    }
    Book(string Title, string Author, double Price){
        this->Author = Author;
        this->Title = Title;
        this->Price = Price;
    }
    
};

int main(){

}