// 그림
#include<bits/stdc++.h>
using namespace std;
int n,m,arr[505][505],dy[]={0,0,1,-1},dx[]={1,-1,0,0},cnt,ret;
bool visited[505][505];
int dfs(int y,int x) {
    visited[y][x]=true;
    int ret=0;
    for(int i=0;i<4;i++) {
        int ny=y+dy[i],nx=x+dx[i];
        if(ny<0||nx<0||ny>=n||nx>=m) continue;
        if(!visited[ny][nx]&&arr[ny][nx]) ret+=(dfs(ny,nx)+1);
    }
    return ret;
}
int main() {
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) scanf("%d",&arr[i][j]);
    }
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if(!visited[i][j]&&arr[i][j]) {
                cnt++;
                ret=max(ret,dfs(i,j)+1);
            }
        }
    }
    printf("%d\n%d\n",cnt,ret);
    return 0;
}