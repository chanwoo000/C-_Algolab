#include<iostream>
using namespace std;
int main(){
    int testcase;
    int y, m, d;
    int mm[12] = { 31,28,31,30,31,30,31,31,30,31,30,31};
    int ym[12] = { 31,29,31,30,31,30,31,31,30,31,30,31};

    cin >> testcase;
    for(int i=0; i<testcase; i++){
        unsigned int cnt = 0;
        cin >> y >> m >> d;

        for(int i=1582; i < y; i++){
            if((i%4==0) && ( i% 100 != 0 )||(i%400 ==0)){
                cnt += 366;
            }
            else{
                cnt += 365;
            }  
        }
        
        for(int i=0; i < m-1; i++){
            if((y%4==0) && ( y % 100 != 0) || (y%400 ==0)){
                if(m>2){
                cnt += ym[i];
                }
                else{
                cnt += 31;
                }
            }
            else{
                cnt += mm[i];
            }
        }

        cnt += d;

        cout << (cnt%7+4)%7 << endl;
        }
    }
