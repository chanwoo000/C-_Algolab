#include <iostream>
#include <string>

using namespace std;

int main() {
    string a;
    int testcase, j;
    cin >> testcase;
    for(int i = 0; i < testcase; i++){
        int num;
        cin >> num;
        a = "1";
        j = 1;

        while(a.length() < num){
            j++;
            a += to_string(j);
            }
        
        cout << a[num-1] <<endl;
        
        }
}

