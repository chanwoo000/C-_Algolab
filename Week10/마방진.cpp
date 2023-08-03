#include<iostream>
using namespace std;
int main(){
    int t, n;
    cin >> t;
    for(int k=0; k<t; k++){
        cin >> n;
        int cnt = 1;
        int mbj[n][n];
        int j = 0;
        int i = n/2;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                mbj[i][j] = 0;
            }
        }
        mbj[j][i] = cnt;

        for(int q=1; q<n*n; q++){
            j--;i++;cnt++;
            if(j<0 && i>=n){
                j+=2; i--;
            }
            if(j<0){
                j = n-1;
            }
            if(i>=n){
                i = 0;
            }
            if(mbj[j][i] != 0){
                j+=2;
                i--;
            }
            mbj[j][i] = cnt;
        }
        for(int a=0; a<n; a++){
            for(int b=0; b<n; b++){
                cout << mbj[a][b] << " ";
            }
            cout << endl;
        }
    }
}