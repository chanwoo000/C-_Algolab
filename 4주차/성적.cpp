#include<iostream>
#include<string>

using namespace std;
int main(){
    
    int testcase;
    int number;
    
    
    cin>>testcase;

    for(int i=0; i<testcase; i++){
        cin>>number;
        int num;
        int A=0;
        int B=0;
        int C=0;
        int D=0;
        int F=0;
        
        for(int i=0; i<number; i++){
            cin>>num;
                    
            if(num>=90 && num<=100){
                    A=A+1;
                }
            else if (num>=80 && num<=89){
                    B=B+1;
                }
            else if ( num>=70 && num<=79){
                    C=C+1;
                }
            else if( num >=60 && num<=69){
                    D=D+1;
                }
            else if( num >= 1 && num <=59){
                    F=F+1;
                }     
        }
        cout<<A<<" "<<B<<" "<<C<<" "<<D<<" "<<F<<endl;
        
    }
    return 0;
}