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
        Title = "Untitled";
        Author = "Anonymous";
        Price = 0.0;
    }
    Book(string Title, string Author = "Unknown", double Price = 0.0){
    this->Title = Title;
    this->Author = Author;
    this->Price = Price;
    }
    Book(const Book &b) {
        Title = b.Title;
        Author = b.Author;
        Price = b.Price;
    }
    void display() {
        cout << "Title: " << Title << endl;
        cout << "Author: " << Author << endl;
        cout << "Price: " << Price << endl;
    }
    
};

int main(){
    Book B1("Rich Dad Poor Dad", "Robin J.Kyosaki", 300);
    Book B2 = B1;

    cout<<"Original Book"<<endl;
    B1.display();

    cout<<"Original Book"<<endl;
    B2.display();
}