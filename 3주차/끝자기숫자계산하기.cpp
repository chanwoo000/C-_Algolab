#include<iostream>
using namespace std;
int main(){
    int testCase,number;
    
    cin>> testCase;
    for(int i =0; i<testCase; i++){
        cin>>number;
        int count=1;
        
        for(int i=0; i<number; i++){
            unsigned int a;
            cin>>a;
            count*=a;
            count %= 10;
            }
    cout<<count<<endl;
    }
    return 0;
}