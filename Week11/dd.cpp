#include<iostream>
using namespace std;
class Book{
    private:
    int isbn;
    public:
    Book(int isbn){
        this -> isbn = isbn;
    }
    void display(){
        cout << this-> isbn << endl;
    }
};

int main(){
    Book b1 = 91131100;
    b1.display();
    b1 = 911842;
    b1.display();

    return 0;
}