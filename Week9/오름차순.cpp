#include<iostream>
using namespace std;
int main(){
    int testcase, numcase;
    int data[100];
    cin >> testcase;
    for(int i=0; i<testcase; i++){
        cin >> numcase;
        int sc = 0;
        int size = 1; 
        int cnt = 0;
        for(int i=0; i<numcase; i++){cin >> data[i];}
            for(int i=0; i<numcase; i++){
                
                if(i == 0 && data[i]>data[i+1]){
                    size=0;
                }
                
                if(i != (numcase-1) && data[i] <= data[i+1]){
                    cnt += data[i];
                    size = 1;
                }
                
                if(i != (numcase-1) && data[i]>data[i+1] && size == 1){
                    cnt += data[i];
                    sc ++;
                    size = 0;
                }

                if(i == (numcase-1) && data[i]>=data[i-1]){
                    if(size==1){
                        cnt += data[i];
                        sc++;
                    }
                    else{
                        continue;
                    }              
                }
            }
        cout << sc << " " << cnt << endl;
    }
}