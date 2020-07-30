// Two Dots
#include<bits/stdc++.h>
using namespace std;
int n,m,sy,sx,dy[]={0,0,1,-1},dx[]={1,-1,0,0};
char arr[55][55],s_char;
bool flag,visited[55][55];
void dfs(int y,int x,int cnt) {
    if(flag) return;
    visited[y][x]=true;
    for(int i=0;i<4;i++) {
        int ny=y+dy[i],nx=x+dx[i];
        if(ny<0||nx<0||ny>=n||nx>=m) continue;
        if(cnt>=3&&ny==sy&&nx==sx) {
            flag=true;
            return;
        }
        if(!visited[ny][nx]&&arr[ny][nx]==s_char) dfs(ny,nx,cnt+1);
    }
}
int main() {
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) scanf(" %1c",&arr[i][j]);
    }
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            sy=i,sx=j;
            s_char=arr[i][j];
            flag=false;
            memset(visited,0,sizeof(visited));
            dfs(i,j,0);
            if(flag) {
                printf("Yes\n");
                exit(0);
            }
        }
    }
    printf("No\n");
    return 0;
}