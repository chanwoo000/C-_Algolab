#include<iostream>
using namespace std;
int main(){
    int testcase;
    cin >> testcase;
    int a, b, c, d;
    int e, f, g, h;
    
    for(int i=0; i<testcase; i++){
        int x, y;
        cin >> a >> b >> c >> d;
        cin >> e >> f >> g >> h;  
        if( c < e || g < a || h < b || d < f){
            cout << ((c - a) * (d - b))+((g - e) * (h  - f));
            cout << " " ;
            cout << ((c - a)*2 + (d - b)*2 )+((g - e)*2 + (h  - f)*2) << endl;
        }

        else{
            x = min(c, g) - max(a, e);
            y = min(h, d) - max(b, f);
            cout << (((c - a) * (d - b))+((g - e) * (h  - f))) - x*y;
            cout << " " ;
            cout << (((c - a)*2 + (d - b)*2 )+((g - e)*2 + (h  - f)*2)) - (2*x + 2*y) << endl;          
        }
    }
    return 0;
}