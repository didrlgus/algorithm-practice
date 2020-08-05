// 연구소 2
#include<bits/stdc++.h>
using namespace std;
const int INF=987654321;
int n,m,arr[55][55],dy[]={0,0,1,-1},dx[]={1,-1,0,0},clean_cnt,ret=INF;
queue<pair<int,int>> q;
bool visited[55][55];
int bfs() {
    int level=0,erase_cnt=0;
    while(!q.empty()) {
        int size=(int)q.size();
        while(size--) {
            int y=q.front().first,x=q.front().second;q.pop();
            for(int i=0;i<4;i++) {
                int ny=y+dy[i],nx=x+dx[i];
                if(ny<0||nx<0||ny>=n||nx>=n) continue;
                if(!visited[ny][nx]&&arr[ny][nx]!=-1) {
                    q.push({ny,nx});
                    visited[ny][nx]=true;
                    erase_cnt++;
                }
            }
        }
        level++;
    }
    if(erase_cnt==clean_cnt-m) return level-1;
    return -1;
}
void go(int height,int virus_cnt) {
    if(virus_cnt==m) {
        memset(visited,0,sizeof(visited));
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                if(arr[i][j]==-2) {
                    visited[i][j]=true;
                    q.push({i,j});
                }
            }
        }
        int val=bfs();
        if(val!=-1) ret=min(ret,val);
        return;
    }
    for(int i=height;i<n;i++) {
        for(int j=0;j<n;j++) {
            if(arr[i][j]!=2) continue;
            arr[i][j]=-2;
            go(i,virus_cnt+1);
            arr[i][j]=2;
        }
    }
}
int main() {
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            scanf("%d",&arr[i][j]);
            if(arr[i][j]==1) arr[i][j]=-1;
            if(arr[i][j]!=-1) clean_cnt++;
        }
    }
    go(0,0);
    if(ret==INF) printf("-1\n");
    else printf("%d\n",ret);
    return 0;
}