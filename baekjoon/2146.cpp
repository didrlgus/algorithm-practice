// 다리 만들기
#include<bits/stdc++.h>
using namespace std;
const int INF=987654321;
int n,arr[105][105],num=1,ret=INF;
bool visited[105][105];
int dy[]={0,0,1,-1},dx[]={1,-1,0,0};
void dfs(int y,int x,int val) {
    visited[y][x]=true;
    arr[y][x]=val;
    for(int i=0;i<4;i++) {
        int ny=y+dy[i],nx=x+dx[i];
        if(ny<0||nx<0||ny>=n||nx>=n) continue;
        if(!visited[ny][nx]&&arr[ny][nx]) dfs(ny,nx,val);
    }
}
bool check(int y,int x) {
    if(y-1>=0&&!arr[y-1][x]) return true;
    if(y+1<n&&!arr[y+1][x]) return true;
    if(x-1>=0&&!arr[y][x-1]) return true;
    if(x+1<n&&!arr[y][x+1]) return true;
    return false;
}
int bfs(int y,int x,int val) {
    queue<pair<int,int>> q;
    visited[y][x]=true;
    q.push({y,x});
    int level=0;
    while(!q.empty()) {
        int size=q.size();
        while(size--) {
            tie(y,x)=q.front();q.pop();
            if(arr[y][x]&&arr[y][x]!=val) return level-1;
            for(int i=0;i<4;i++) {
                int ny=y+dy[i],nx=x+dx[i];
                if(ny<0||nx<0||ny>=n||nx>=n) continue;
                if(!visited[ny][nx]&&arr[ny][nx]!=val) {
                    visited[ny][nx]=true;
                    q.push({ny,nx});
                }
            }
        }
        level++;
        if(level>=ret+1) break;
    }
    return ret;
}
int main() {
    scanf("%d",&n);
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) scanf("%d",&arr[i][j]);
    }
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            if(arr[i][j]&&!visited[i][j]) {
                dfs(i,j,num);
                num++;
            }
        }
    }
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            if(arr[i][j]&&check(i,j)) {
                fill(&visited[0][0],&visited[0][0]+105*105,false);
                ret=min(ret,bfs(i,j,arr[i][j]));
            }
        }
    }
    printf("%d\n",ret);
    return 0;
}