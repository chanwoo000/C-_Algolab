#include<iostream>
#include<cstring>
using namespace std;
int main(){
    int testcase;
        char a[257];
    cin >> testcase;
    for(int i=0; i<testcase; i++){
        cin >> a;
        int cnt=0;
        int t=0;
        if(a[0]>=48 && a[0]<=57){
            cnt++;
            cout << 0 << endl;
        }
        else{
            for(int i=0; i<strlen(a);i++){
            if( (a[i]<=47) || (a[i]>=58 && a[i]<=64) || (a[i]>=91 && a[i]<=94) || (a[i]==96) || (a[i] >=123)){
                cout << 0 <<endl;
                t++;
                break;
                }
            }
        }

        if(cnt==0 && t==0){
            cout << 1 << endl;
        }
    }
    return 0;
}
