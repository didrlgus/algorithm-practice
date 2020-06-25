// 거울 설치
#include<bits/stdc++.h>
using namespace std;
int n,dist[55][55][5],dy[]={-1,1,0,0},dx[]={0,0,-1,1},ey,ex;
char arr[55][55];
queue<pair<pair<int,int>,int>> q;
bool check(int y,int x) {
    if(y<0||x<0||y>=n||x>=n) return false;
    if(arr[y][x]=='*') return false;
    return true;
}
void bfs() {
    while(!q.empty()) {
        int y=q.front().first.first,x=q.front().first.second,d=q.front().second;q.pop();
        if(ey==y&&ex==x) {
            printf("%d\n",dist[y][x][d]);
            return;
        }
        int ny=y+dy[d],nx=x+dx[d];
        while(check(ny,nx)&&arr[ny][nx]=='.') {
            ny+=dy[d];nx+=dx[d];
        }
        if(check(ny,nx)&&arr[ny][nx]=='!') {        // 거울을 두는 경우, 두지 않는 경우 모두 생각
            dist[ny][nx][d]=dist[y][x][d];          // 거울을 두지 않는 경우
            q.push({{ny,nx},d});
            int nd=d<2?2:0;
            for(int i=nd;i<nd+2;i++) {              // 거울을 두는 경우
                if(dist[ny][nx][i]==-1) {
                    dist[ny][nx][i]=dist[y][x][d]+1;
                    q.push({{ny,nx},i});
                }
            }
        }
    }
}
int main() {
    scanf("%d",&n);
    memset(dist,-1,sizeof(dist));
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            scanf(" %1c",&arr[i][j]);
            if(arr[i][j]=='#') {
                if(q.empty()) {
                    for(int k=0;k<4;k++) {      // 처음 방향을 모르기 때문에 4방향 모두 고려
                        dist[i][j][k]=0;
                        q.push({{i,j},k});
                    }
                } else {
                    ey=i;ex=j;
                }
                arr[i][j]='!';
            }
        }
    }
    bfs();
    return 0;
}