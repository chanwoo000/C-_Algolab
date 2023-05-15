#include<iostream>
using namespace std;
int main(){

    int testcase;
    cin>>testcase;
    int n;
    
    for(int i = 0; i < testcase; i++){

        int pre = 0;
        int count=0;
        int zero=0;
        cin >> n;
        
        for(int j=0; j<n; j++){
            
            int number;
            cin >> number;

            if (j==0){
                pre=number;
                zero = 0;
                continue;
            }
            
            if(pre<number){
                zero = 1;     
            }

            if(pre == number){
                continue;
            }
                

            if(zero==1 && pre>number){
                zero = 0;
                count=count+1;
                pre=number;
                continue;
            }

            pre = number;
        }
        cout << count << endl;
    }
    
}