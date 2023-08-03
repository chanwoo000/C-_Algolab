#include<iostream>
using namespace std;

int main() {

    int testcase;
    cin>>testcase;

    for(int i=0; i < testcase; i++){
        int a, b, n;
        int now = 0;
        int cnt = 0;
        cin >> n >> a >> b;
        for(int i = 0; i < n; i++){
            now++;
            cnt++;
            if(cnt >= a && cnt < b){
                cout << cnt << " ";
            }
            else if(cnt == b){
                cout << cnt << " ";
            }
        }
        
    }
}


