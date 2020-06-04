// 색종이 붙이기
#include<bits/stdc++.h>
using namespace std;
const int INF=987654321;
int arr[15][15],cnt_arr[10],n=10,ret=INF;
bool check(int y,int x,int size) {
    if(y+size>10||x+size>10) return false;
    for(int i=y;i<y+size;i++) {
        for(int j=x;j<x+size;j++) if(!arr[i][j]) return false;
    }
    return true;
}
void draw(int y,int x,int size,bool val) {
    for(int i=y;i<y+size;i++) {
        for(int j=x;j<x+size;j++) arr[i][j]=val;
    }
}
void dfs(int y,int x,int cnt) {
    if(cnt>=ret) return;
    if(y>=n) {
        ret=min(ret,cnt);
        return;
    }
    if(x>=n) {
        dfs(y+1,0,cnt);
        return;
    }
    if(arr[y][x]==0) {
        dfs(y,x+1,cnt);
        return;
    }
    for(int i=5;i>=1;i--) {
        if(cnt_arr[i]==5) continue;
        if(!check(y,x,i)) continue;
        cnt_arr[i]++;
        draw(y,x,i,0);
        dfs(y,x+i,cnt+1);
        draw(y,x,i,1);
        cnt_arr[i]--;
    }
    return;
}
int main() {
    for(int i=0;i<10;i++) {
        for(int j=0;j<10;j++) scanf("%d",&arr[i][j]);
    }
    dfs(0,0,0);
    if(ret==INF) printf("-1\n");
    else printf("%d\n",ret);
}