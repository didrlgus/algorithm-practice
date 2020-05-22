// 파이프 옮기기 1
#include<bits/stdc++.h>

using namespace std;

int n;
int arr[25][25];
int cnt;

// 가로 체크
bool check1(int y,int x) {
    return x+1<n&&!arr[y][x+1];
}
// 세로 체크
bool check2(int y,int x) {
    return y+1<n&&!arr[y+1][x];
}
// 대각 체크
bool check3(int y,int x) {
    return y+1<n&&x+1<n&&!arr[y+1][x+1];
}

// 가로 0 세로 1 대각 2
int dfs(int y,int x,int status) {
    if(y==n-1&&x==n-1) return 1;
    int cnt=0;
    if(status==0) {                                     // 가로
        if(check1(y,x)) {
            cnt+=dfs(y,x+1,0);
        }
        if(check1(y,x)&&check2(y,x)&&check3(y,x)) {
            cnt+=dfs(y+1,x+1,2);
        }
    } else if(status==1) {                              // 세로
        if(check2(y,x)) {
            cnt+=dfs(y+1,x,1);
        }
        if(check1(y,x)&&check2(y,x)&&check3(y,x)) {
            cnt+=dfs(y+1,x+1,2);
        }
    } else {                                            // 대각
        if(check1(y,x)) {
            cnt+=dfs(y,x+1,0);
        }
        if(check2(y,x)) {
            cnt+=dfs(y+1,x,1);
        }
        if(check1(y,x)&&check2(y,x)&&check3(y,x)) {
            cnt+=dfs(y+1,x+1,2);
        }
    }
    return cnt;
}

int main() {
    scanf("%d",&n);

    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            scanf("%d",&arr[i][j]);
        }
    }
    printf("%d\n",dfs(0,1,0));      // 끝점 y,x좌표, 상태(가로(0),세로(1),대각(2))
    return 0;
}