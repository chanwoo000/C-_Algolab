#include<iostream>
using namespace std;
class A{
    public:
    static int num;
    A(){
        ++num;
    }
    ~A(){
        --num;
    }
};
int A::num = 0;
int main(){
    int a1[3], *p;
    int n;
    cin >> n;
    cout << A::num <<endl;
    p = new A[n];
    cout << a1[0].num << endl;
    delete[] p;
    cout << A::num << endl;
    return 0;
    }