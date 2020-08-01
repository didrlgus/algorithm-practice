// 공주님을 구해라!
#include<bits/stdc++.h>
using namespace std;
const int INF=987654321;
int n,m,t,gram,arr[105][105],dy[]={0,0,1,-1},dx[]={1,-1,0,0},visited[105][105],visited2[105][105];
vector<int> wall;
queue<pair<int,int>> q,q2,q3;
int bfs1(int y,int x) {
    visited[y][x]=1;
    q.push({y,x});
    while(!q.empty()) {
        tie(y,x)=q.front();q.pop();
        if(y==n-1&&x==m-1) return visited[y][x]-1;
        for(int i=0;i<4;i++) {
            int ny=y+dy[i],nx=x+dx[i];
            if(ny<0||nx<0||ny>=n||nx>=m) continue;
            if(!visited[ny][nx]&&arr[ny][nx]==0) {
                visited[ny][nx]=visited[y][x]+1;
                q.push({ny,nx});
            }
        }
    }
    return INF;
}
int bfs2(int y,int x) {
    visited2[y][x]=1;
    q2.push({y,x});
    int g_dist=-1;
    int gy=gram/1000,gx=gram%1000;
    while(!q2.empty()) {
        tie(y,x)=q2.front();q2.pop();
        if(y==gy&&x==gx) {
            g_dist=visited2[y][x]-1;
            break;
        }
        for(int i=0;i<4;i++) {
            int ny=y+dy[i],nx=x+dx[i];
            if(ny<0||nx<0||ny>=n||nx>=m) continue;
            if(!visited2[ny][nx]&&arr[ny][nx]!=1) {
                visited2[ny][nx]=visited2[y][x]+1;
                q2.push({ny,nx});
            }
        }
    }
    if(g_dist==-1) return INF;
    for(auto it:wall) arr[it/1000][it%1000]=0;
    memset(visited2,0,sizeof(visited2));
    visited2[gy][gx]=1;
    q3.push({gy,gx});
    while(!q3.empty()) {
        tie(gy,gx)=q3.front();q3.pop();
        if(gy==n-1&&gx==m-1) return g_dist+visited2[gy][gx]-1;
        for(int i=0;i<4;i++) {
            int ny=gy+dy[i],nx=gx+dx[i];
            if(ny<0||nx<0||ny>=n||nx>=m) continue;
            if(!visited2[ny][nx]&&arr[ny][nx]==0) {
                visited2[ny][nx]=visited2[gy][gx]+1;
                q3.push({ny,nx});
            }
        }
    }
    return INF;
}
int main() {
    scanf("%d%d%d",&n,&m,&t);
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            scanf("%d",&arr[i][j]);
            if(arr[i][j]==1) wall.push_back(i*1000+j);
            if(arr[i][j]==2) gram=i*1000+j;
        }
    }
    int ret1=bfs1(0,0),ret2=bfs2(0,0);
    if(ret1==INF&&ret2==INF) printf("Fail\n");
    else {
        int ret=min(ret1,ret2);
        if(ret>t) printf("Fail\n");
        else printf("%d\n",ret);
    }
    return 0;
}