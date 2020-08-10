// 벽 부수고 이동하기
#include<bits/stdc++.h>
using namespace std;
int n,m,arr[1005][1005],visited[1005][1005][3],dy[]={0,0,1,-1},dx[]={1,-1,0,0};
struct p {
    int y,x,crashed;
};
queue<p> q;
int bfs(int y,int x) {
    visited[y][x][0]=1;
    q.push({y,x,0});
    while(!q.empty()) {
        p f=q.front();q.pop();
        y=f.y,x=f.x;
        int c=f.crashed;
        if(y==n-1&&x==m-1) return visited[y][x][c];
        for(int i=0;i<4;i++) {
            int ny=y+dy[i],nx=x+dx[i];
            if(ny<0||nx<0||ny>=n||nx>=m) continue;
            if(visited[ny][nx][c]) continue;
            if(!arr[ny][nx]) {
                visited[ny][nx][c]=visited[y][x][c]+1;
                q.push({ny,nx,c});
            }
            if(arr[ny][nx]&&!c) {
                visited[ny][nx][c+1]=visited[y][x][c]+1;
                q.push({ny,nx,c+1});
            }
        }
    }
    return -1;
}
int main() {
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) scanf("%1d",&arr[i][j]);
    }
    printf("%d\n",bfs(0,0));
    return 0;
}