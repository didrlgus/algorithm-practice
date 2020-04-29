// 미로 탐색
#include<bits/stdc++.h>

using namespace std;

int n,m;
int a[110][110];
int visited[110][110];

int dy[]={0,0,1,-1};
int dx[]={1,-1,0,0};

queue<pair<int,int>> q;

void bfs(int y,int x) {
    visited[y][x]=1;
    q.push({y,x});

    while(!q.empty()) {
        tie(y,x)=q.front();
        q.pop();
        
        for(int i=0;i<4;i++) {
            int ny=y+dy[i];
            int nx=x+dx[i];

            if(ny<0 || ny>=n || nx<0 || nx>=m) continue;
            if(!visited[ny][nx] && a[ny][nx]==1) {
                visited[ny][nx]=visited[y][x]+1;
                q.push({ny,nx});
            }
        }
    }
}


int main() {

    cin>>n>>m;

    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) scanf("%1d",&a[i][j]);
    }

    bfs(0,0);

    printf("%d\n",visited[n-1][m-1]);

    return 0;
}