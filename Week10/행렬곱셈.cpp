#include<iostream>
using namespace std;
int main(){
    int testcase;
    int r, s ,t;
    cin >> testcase;
    for(int k=0; k<testcase; k++){
        cin >> r >> s >> t;
        int arr1[r][s];
        int arr2[s][t];
        int arr3[r][t];

        for(int i=0; i<r; i++){
            for(int j=0; j<s; j++){
                cin >> arr1[i][j];
            }
        }

        for(int i=0; i<s; i++){
            for(int j=0; j<t; j++){
                cin >> arr2[i][j];
            }
        }
        

        for(int T=0; T<t; T++){
            for(int R=0; R<r; R++){
                int cnt = 0;
                for(int S=0; S<s; S++){
                    cnt += arr1[R][S] * arr2[S][T];
                }
                arr3[R][T] = cnt;
            }
        }
        

        for(int i=0; i<r; i++){
            for(int j=0; j<t; j++){
                cout << arr3[i][j] << " ";
            }
            cout << endl;
        }
    }
}
