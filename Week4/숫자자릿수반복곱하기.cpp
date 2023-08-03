#include<iostream>
#include<string>
using namespace std;

int main() {
    int testcase;
    unsigned int number,res;
    cin>>testcase;

    for(int i=0;i<testcase;i++){
        cin >> number;
        while(true){
            res=1;
            while( number >= 10 ){
                if( number%10 != 0 ){
                    res *= (number%10);
                }
                number/=10;
            }
            res *= number;
            number = res;
            if(res < 10)
                break;
        }
        cout << res << endl;
    }
}