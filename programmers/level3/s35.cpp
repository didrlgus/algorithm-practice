// N-Queen
#include <bits/stdc++.h>

using namespace std;

// 열
bool col[15];
// 왼쪽 아래에서 오른쪽 위로의 대각선 (/)
bool cross1[30];
// 오른쪽 위에서 왼쪽 아래로의 대각선 (\)
bool cross2[30];

int N;
int cnt=0;
void func(int row) {
    if(row>=N) {
        cnt++;
        return;
    }
    // (row, i) 좌표에 퀸을 놓을 예정
    for (int i=0; i<N; i++) {
        // 열, 대각선1, 대각선2 상에 퀸이 하나라도 놓여져 있으면 continue, (현재 row,col 좌표로 /,\ 대각선 표현 가능)
        if (col[i] || cross1[i+row] || cross2[row-i+N-1]) continue;

        col[i]=true;
        cross1[i+row]=true;
        cross2[row-i+N-1]=true;

        func(row+1);

        col[i]=false;
        cross1[i+row]=false;
        cross2[row-i+N-1]=false;
    }
}

int solution(int n) {
    int answer = 0;
    N=n;

    func(0);
    answer=cnt;

    return answer;
}

int main() {

    int n=4;
    int result=solution(n);
    printf("%d\n",result);

    return 0;
}