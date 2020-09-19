// 아기상어 2
#include<bits/stdc++.h>
using namespace std;
int n,m,dy[]={0,0,1,-1,-1,-1,1,1},dx[]={1,-1,0,0,-1,1,-1,1},ret;
bool arr[55][55],visited[55][55];
int bfs(int y,int x) {
    queue<pair<int,int>> q;
    visited[y][x]=true;
    q.push({y,x});
    int level=0;
    while(!q.empty()) {
        int size=q.size();
        while(size--) {
            tie(y,x)=q.front();q.pop();
            if(arr[y][x]) return level;
            for(int i=0;i<8;i++) {
                int ny=y+dy[i],nx=x+dx[i];
                if(ny<0||nx<0||ny>=n||nx>=m) continue;
                if(!visited[ny][nx]) {
                    visited[ny][nx]=true;
                    q.push({ny,nx});
                }
            }
        }
        level++;
    }
    return -1;
}
int main() {
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) scanf("%d",&arr[i][j]);
    }
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if(!arr[i][j]) {
                memset(visited,false,sizeof(visited));
                ret=max(ret,bfs(i,j));
            }
        }
    }
    printf("%d\n",ret);
    return 0;
}