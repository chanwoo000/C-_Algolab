#include<iostream>
#include<string>
using namespace std;
int main(){
    int testcase;
    cin >> testcase;
    for( int i = 0; i < testcase; i++){
        int number;
        cin >> number;
        string K = "";
        int a = 0;
        
        while(K.length()<number){
            K += to_string(++a);
            }
        cout << K[number-1] << endl;
    }
}