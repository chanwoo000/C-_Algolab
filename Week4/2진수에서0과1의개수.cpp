#include<iostream>
#include<bitset>

using namespace std;

int main(){
    
    int testcase;
    cin >> testcase;
    unsigned int num;
    

    for(int i=0; i<testcase; i++){
        int count0=0;
        int count1=0;
        cin>>num;
        while(num>0){
            if(num % 2 == 0){
                count0 ++;
            }
            else{
                count1 ++;
            }
            num /= 2;
        }
        cout << count0 << " " << count1 << endl;
    }
    return 0;
}