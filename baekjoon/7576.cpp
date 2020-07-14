// 토마토
#include<bits/stdc++.h>
using namespace std;
int n,m,arr[1005][1005],dy[]={0,0,1,-1},dx[]={1,-1,0,0},z_cnt,ret,y,x;
queue<pair<int,int>> q;
bool visited[1005][1005];
void bfs() {
    int size=(int)q.size();
    while(size--) {
        tie(y,x)=q.front();q.pop();
        for(int i=0;i<4;i++) {
            int ny=y+dy[i],nx=x+dx[i];
            if(ny<0||nx<0||ny>=n||nx>=m) continue;
            if(!visited[ny][nx]&&arr[ny][nx]==0) {
                visited[ny][nx]=true;
                q.push({ny,nx});
                z_cnt--;
            }
        }
    }
}
int main() {
    scanf("%d %d",&m,&n);
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            scanf("%d",&arr[i][j]);
            if(arr[i][j]==1) {
                q.push({i,j});
                visited[i][j]=true;
            } else if(arr[i][j]==0) z_cnt++;
        }
    }
    while(!q.empty()) {
        if(z_cnt==0) break;
        bfs();
        ret++;
    }
    printf("%d\n",!z_cnt?ret:-1);
    return 0;
}