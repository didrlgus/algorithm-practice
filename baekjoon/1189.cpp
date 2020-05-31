// 컴백홈
#include<bits/stdc++.h>
using namespace std;
int n,m,k;
char arr[10][10];
int dy[]={0,0,1,-1},dx[]={1,-1,0,0};
bool visited[10][10];
int dfs(int y,int x,int dis) {
    if(y==0&&x==m-1) {
        if(k==dis) return 1;
        return 0;
    }
    int ret=0;
    for(int i=0;i<4;i++) {
        int ny=y+dy[i],nx=x+dx[i];
        if(ny<0||nx<0||ny>=n||nx>=m||arr[ny][nx]=='T') continue;
        if(!visited[ny][nx]&&arr[ny][nx]=='.') {
            visited[ny][nx]=true;
            ret+=dfs(ny,nx,dis+1);
            visited[ny][nx]=false;
        }
    }
    return ret;
}
int main() {
    scanf("%d %d %d",&n,&m,&k);
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) scanf(" %1c",&arr[i][j]);
    }
    visited[n-1][0]=1;
    printf("%d\n",dfs(n-1,0,1));
    return 0;
}