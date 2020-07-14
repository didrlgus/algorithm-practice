// 빙산
#include<bits/stdc++.h>
using namespace std;
int n,m,arr[305][305],tmp[305][305],dy[]={0,0,1,-1},dx[]={1,-1,0,0},ret,y,x;
queue<pair<int,int>> q;
bool visited[305][305];
void melting() {
    while(!q.empty()) {
        tie(y,x)=q.front();q.pop();
        for(int i=0;i<4;i++) {
            int ny=y+dy[i],nx=x+dx[i];
            if(arr[ny][nx]==0) tmp[y][x]--;
            if(tmp[y][x]==0) break;
        }
    }
}
void dfs(int y,int x) {
    visited[y][x]=true;
    for(int i=0;i<4;i++) {
        int ny=y+dy[i],nx=x+dx[i];
        if(ny<0||nx<0||ny>=n||nx>=m) continue;
        if(!visited[ny][nx]&&arr[ny][nx]>0) dfs(ny,nx);
    }
}
int main() {
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            scanf("%d",&arr[i][j]);
            if(arr[i][j]) q.push({i,j});
        }
    }
    while(!q.empty()) {
        memcpy(tmp,arr,sizeof(arr));
        melting();
        memcpy(arr,tmp,sizeof(tmp));
        ret++;
        int cnt=0;
        memset(visited,false,sizeof(visited));
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(!visited[i][j]&&arr[i][j]>0) {
                    dfs(i,j);
                    cnt++;
                }
                if(cnt>1) {
                    printf("%d\n",ret);
                    return 0;
                }
                if(arr[i][j]>0) q.push({i,j});
            }
        }
    }
    printf("0\n");
    return 0;
}