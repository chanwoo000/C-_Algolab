#include<iostream>
using namespace std;
int main(){
    int testcase;
    cin >> testcase;
    for(int i=0; i<testcase; i++){
        int arr[101]={0,};
        int max = 0;
        int a = 1;
        while(a != 0){
            cin >> a;
            if(a>=0 && a<=100){
            arr[a]++;
            }
        }
        for(int i=1; i<101; i++){
            if(arr[i] >= arr[max]){
                max = i;
            }
            else{
                continue;
            }
        }
        cout << max << endl;
    }
}