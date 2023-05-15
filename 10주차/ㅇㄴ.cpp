#include <iostream>
using namespace std;

char othello[9][9];
int dir[8][2] = {
    {-1, -1},
    {0, -1},
    {1, -1},
    {1, 0},
    {1, 1},
    {0, 1},
    {-1, 1},
    {-1, 0},
};

int main() {
    int size = 8;
    int t;
    cin >> t;

    while (t--) {
        for(int x = 1; x <= size; x++) {
            for(int y = 1; y <= size; y++) {
                othello[x][y] = '+';
            }
        }   
        othello[4][4] = 'O';
        othello[5][5] = 'O';
        othello[4][5] = 'X';
        othello[5][4] = 'X';

        int count;
        cin >> count;
        int w_cnt = 0, b_cnt = 0;
        
        char seq;
        seq = 'X';
        while (count--) {
            int i,j;

            cin >> i;
            cin >> j;
            othello[i][j] = seq;
            
            for(int d = 0; d < 8; d++){
                int change_cnt = 0;
                int move_x = i;
                int move_y = j;
                while(true){
                    move_x += dir[d][0];
                    move_y += dir[d][1];
                    
                    if(move_x >= 9 || move_y >= 9 || move_x <= 0 || move_y <= 0) {
                        change_cnt = 0;
                        break;   
                    }
                    else if(othello[move_x][move_y] == '+'){
                        change_cnt = 0;
                        break;
                    }

                    else if(othello[move_x][move_y] == seq){
                        break;
                    } 

                    else{
                        change_cnt++;
                    }
                }
                for(int c = 1; c <= change_cnt; c++){
                    int update_i = i + dir[d][0] * c;
                    int update_j = j + dir[d][1] * c;
                    
                    if(update_i >= 9 || update_j >= 9 || update_i <= 0 || update_j <= 0) {
                        change_cnt = 0;
                        break;   
                    }
                    othello[update_i][update_j] = seq;
                }
            }
            if(seq == 'X') seq = 'O';
            
            else if(seq == 'O') seq = 'X';   
        }
        for(int x = 1; x <= size; x++){
            for(int y = 1; y <= size; y++){
                if(othello[x][y] == 'X') b_cnt++;
                if(othello[x][y] == 'O') w_cnt++;       
            }
        }
        cout << b_cnt << " " << w_cnt << "\n";
        for(int x = 1; x <= size; x++){
            for(int y = 1; y <= size; y++){
                cout << othello[x][y];
            }
            cout << "\n";
        }
    }
}