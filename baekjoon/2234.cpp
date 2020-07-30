// 성곽
#include<bits/stdc++.h>
using namespace std;
const int INF=-987654321;
int n,m,arr[55][55],dy[]={0,-1,0,1},dx[]={-1,0,1,0},land,ret=INF;
bool visited[55][55];
queue<pair<int,int>> q;
int bfs(int y,int x) {
    visited[y][x]=true;
    q.push({y,x});
    int cnt=1;
    while(!q.empty()) {
        tie(y,x)=q.front();q.pop();
        int wall=1;
        for(int i=0;i<4;i++) {
            if(!(arr[y][x]&wall)) {
                int ny=y+dy[i],nx=x+dx[i];
                if(ny<0||nx<0||ny>=n||nx>=m) continue;
                if(!visited[ny][nx]) {
                    visited[ny][nx]=true;
                    q.push({ny,nx});
                    cnt++;
                }
            }
            wall=(wall<<1);
        }
    }
    return cnt;
}
int main() {
    scanf("%d%d",&m,&n);
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) scanf("%d",&arr[i][j]);
    }
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if(!visited[i][j]) {
                land++;
                ret=max(ret,bfs(i,j));
            }
        }
    }
    printf("%d\n%d\n",land,ret);
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            for(int wall=1;wall<16;wall=(wall<<1)) {
                if((arr[i][j]&wall)) {
                    memset(visited,0,sizeof(visited));
                    arr[i][j]-=wall;
                    ret=max(ret,bfs(i,j));
                    arr[i][j]+=wall;
                }
            }
        }
    }
    printf("%d\n",ret);
    return 0;
}