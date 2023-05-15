#include<iostream>
using namespace std;
    int main(){
        
        int testcase;
        int k;
        cin>>testcase;
        
        for(int i=0; i<testcase; i++){
            cin>>k;
            for(int j=0; j<k; j++){
                for(int a=0; a<k;a++){
                    
                    if(a==k/2 && j==k/2){
                        cout<<'O';
                    }
                    else if(a==(k-1-j)){
                        cout<<'*';
                    }
                    else if(a==k/2){
                        cout<<'I';
                    }
                    else if(j==k/2){
                        cout<<'+';
                    }
                    else{
                        cout<<'.';
                    }
                }
            cout<<endl;
            }
        }
    }