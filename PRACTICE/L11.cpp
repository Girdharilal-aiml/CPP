/*
Level 11 (OOP + File Handling)

Q11:
Create a class Student with:
- data members: id, name, marks

1. Implement:
   - Constructor
   - display()

2. Add function:
   saveToFile()
   → store student data in a file "students.txt"

3. Add function:
   readFromFile()
   → read and display all student records

In main():
- Create 2 students
- Save them to file
- Read and display from file

⚠️ Use:
- fstream
- ofstream / ifstream
*/

#include"iostream"
#include"fstream"
using namespace std;

class Student{
private:
   string ID;
   string Name;
   double Marks;

public:
   Student(){}
   Student(string I, string N, double M) : ID(I), Name(N), Marks(M){}

   void DISPLAY(){
      cout << "ID    : " << ID << endl;
      cout << "Name  : " << Name << endl;
      cout << "Marks : " << Marks << endl;
   }

   void SaveToFile(){
      ofstream file("Student.txt", ios::app);

      if(!file){
         cout << "Error File Openning!" << endl;
         return;
      }
      file << ID << " " << Name << " " << Marks << endl;
      file.close();
   }

   static void ReadFromFile(){
      ifstream file("Student.txt");

      if(!file){
         cout << "Error Opening File" << endl;
         return;
      }

      string id;
      string name;
      double marks;

      while(file >> id >> name >> marks){
         cout << "ID: " << id << ", Name: " << name << ", Marks: " << marks << endl;
      }
      file.close();
   }

};

int main(){
   Student s1("3242k", "Girdhari_lal", 99.9);
   Student s2("P323", "GLAL",88);


}