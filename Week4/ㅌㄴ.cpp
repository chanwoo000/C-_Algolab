#include <iostream>
using namespace std;

int** createArray(int n); // 배열 생성 함수

int main() {
    int testcase; // 테스트 케이스 수
    int a, b, n; // 입력받은 값들
    cin >> testcase;
    for (int test_case = 0; test_case < testcase; test_case++) {
        cin >> n >> a >> b;
        int **arr = createArray(n);
        int *result = new int[n * n];
        int x = -1;  int y = 0;
        int cnt = 0;
        int next = 1;
        int tmp = n;
        while (cnt < n * n) {
            for(int i = 0; i < tmp; i++) { 
                x += next;
                result[cnt++] = arr[y][x];
            }
            tmp--;
            if (tmp < 1) break;
            int i = 0;
            while (i < tmp) {
                y += next;
                result[cnt++] = arr[y][x];
                i++;
            }         
            next = -next;
        }
        for (int i = a - 1; i < b; i++)
            cout << result[i] << " ";
        cout << endl;
    }
}

int** createArray(int n) {
    int **arr = new int*[n];
    int i = 1;
    while (i <= n) {
    arr[i - 1] = new int[n];
    int j = 1;
    while (j <= n) {
        arr[i - 1][j - 1] = (i - 1) * n + j;
        j++;
    }
    i++;
}

    return arr;
}