#include<iostream>
using namespace std;
int main(){
    int testcase;
    cin >> testcase;
    
    for(int i = 0; i < testcase; i++){
        
        int x1, y1;
        int x2, y2;
        int a, b, c, d;
        cin >> a >> b >> c >> d;

        if(a>d && b>d)
            cout << 0 << " " << (b-a)+(d-c)<<endl ;
        else if(c>b && d>b)
            cout << 0 << " " << (b-a)+(d-c)<<endl ;

        //if( a<=c && b>=c || a<=d && c<=a){
        if((c>=a && c<=b)||(a>=c && a<=d)){
            if(a<c)
                x1 = c;
            else if(a==c)
                x1 = a;
            else if(a>c)
                x1 = a;

            if(b<d)
                y1 = b;
            else if(b==d)
                y1 = b;
            else if(b>d)
                y1 = d;

            if(a>c)
                x2 = c;
            else if(a==c)
                x2 = a;
            else if(a<c)
                x2 = a;

            if(b<d)
                y2 = d;
            else if(b==d)
                y2 = b;
            else if(b>d)
                y2 = b;
        
        cout << y1 - x1 << " " << y2 - x2 << endl;
        }
    }
}