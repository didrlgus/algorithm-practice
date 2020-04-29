// 1012.유기농 배추
#include<bits/stdc++.h>

using namespace std;

int tc,m,n,k;
int arr[55][55];
int visited[55][55];

int dy[]={0,0,1,-1}, dx[]={1,-1,0,0};
queue<pair<int,int>> q;

void bfs(int y,int x) {
    // 시작점 방문
    visited[y][x]=true;
    q.push({y,x});

    while(!q.empty()) {
        tie(y,x)=q.front();
        q.pop();

        for(int i=0;i<4;i++) {
            int ny=y+dy[i],nx=x+dx[i];

            if(ny<0 || ny>=n || nx<0 || nx>=m) continue;

            if(!visited[ny][nx] && arr[ny][nx]==1) {
                visited[ny][nx]=true;
                q.push({ny,nx});
            }
        }
    }
}

int main() {

    scanf("%d",&tc);

    while(tc--) {
        scanf("%d %d %d",&m,&n,&k);
        fill(&arr[0][0],&arr[0][0]+55*55,0);
        fill(&visited[0][0],&visited[0][0]+55*55,0);

        while(k--) {
            int x,y;
            scanf("%d %d",&x,&y);
            arr[y][x]=1;
        }

        int cnt=0;
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(!visited[i][j] && arr[i][j]==1) {
                    cnt++;
                    bfs(i,j);
                }
            }
        }
        printf("%d\n",cnt);
    }

    return 0;
}