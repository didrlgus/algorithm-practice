// 색종이 붙이기
#include<bits/stdc++.h>
using namespace std;

const int INF=987654321;
int arr[15][15],ret=INF,n=10;
int cnt_arr[10];
bool check(int y,int x,int size) {
    if(y+size>n||x+size>n) return false;
    for(int i=y;i<y+size;i++) {
        for(int j=x;j<x+size;j++) if(!arr[i][j]) return false;
    }
    return true;
}
void draw(int y,int x,int size,int val) {
    for(int i=y;i<y+size;i++) {
        for(int j=x;j<x+size;j++) arr[i][j]=val;
    }
}
void dfs(int y,int x,int cnt) {
    if(cnt>=ret) return;
    if(x==n) {
        dfs(y+1,0,cnt);
        return;
    }
    if(y==n) {
        ret=min(ret,cnt);
        return;
    }
    if(arr[y][x]==0) {
        dfs(y,x+1,cnt);
        return;
    }
    for(int i=5;i>=1;i--) {
        if(cnt_arr[i]==5) continue;
        if(check(y,x,i)) {
            cnt_arr[i]++;
            draw(y,x,i,0);
            dfs(y,x+i,cnt+1);
            cnt_arr[i]--;
            draw(y,x,i,1);
        }
    }
    return;
}

int main() {
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) scanf("%d",&arr[i][j]);
    }

    dfs(0,0,0);
    if(ret==INF) printf("-1\n");
    else printf("%d\n",ret);
    return 0;
}