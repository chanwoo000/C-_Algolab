#include<iostream>
using namespace std;
int main(){
    
    int testcase, number;
    cin>>testcase;

    for(int i=0; i<testcase;i++){
        cin>>number;
        int a;
        int scissors = 0;
        int rock = 0;
        int paper = 0;

            for(int i = 0; i<number;i++){
                cin>>a;
                if(a==1)
                scissors++;
                else if(a==2)
                rock++;
                else if(a==3)
                paper++;
            }

        if(scissors==number || rock==number || paper==number){
            cout<< 0 << endl;
        }
        else if(scissors>=1 && rock>=1 && paper>=1){
            cout<< 0 << endl;
        }
        else if(scissors>=paper && rock==0){
            cout<< scissors << endl;
        }
        else if(rock>=scissors && paper==0){
            cout<< rock << endl;
        }
        else if(paper>=rock && scissors==0){
            cout<< paper << endl;
        }
        else if(scissors<paper && rock==0){
            cout<< scissors << endl;
        }
        else if(rock<scissors && paper==0){
            cout<< rock << endl;
        }
        else if(paper<rock && scissors==0){
            cout<< paper << endl;
        }
        
    }
    return 0;
}
    
